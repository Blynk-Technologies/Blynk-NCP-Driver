
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_SHIM_MCU_H
#define RPC_SHIM_MCU_H


static inline
RpcStatus rpc_mcu_ping() {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_MCU_PING);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_res;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 100);

  rpc_set_status(_rpc_res);
  return _rpc_res;
}


static inline
bool rpc_mcu_reboot() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_MCU_REBOOT);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, RPC_TIMEOUT_DEFAULT);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readBool(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}


static inline
bool rpc_mcu_hasUID(uint16_t uid) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_MCU_HASUID);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, uid);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, RPC_TIMEOUT_DEFAULT);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readBool(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}

#endif /* RPC_SHIM_MCU_H */
