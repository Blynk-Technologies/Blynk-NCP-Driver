
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_SHIM_MCU_H
#define RPC_SHIM_MCU_H

#ifdef __cplusplus
extern "C" {
#endif


static inline
RpcStatus rpc_mcu_ping(void) {
  RpcStatus _rpc_res;
  RPC_MUTEX_LOCK();
  /* Send request */
  const uint16_t _rpc_seq = MessageWriter_beginInvoke(RPC_UID_MCU_PING);
  MessageWriter_end();

  /* Wait response */
  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 100);

  rpc_set_status(_rpc_res);
  RPC_MUTEX_UNLOCK();
  return _rpc_res;
}


static inline
bool rpc_mcu_reboot(void) {
  RpcStatus _rpc_res;
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  RPC_MUTEX_LOCK();
  /* Send request */
  const uint16_t _rpc_seq = MessageWriter_beginInvoke(RPC_UID_MCU_REBOOT);
  MessageWriter_end();

  /* Wait response */
  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, RPC_TIMEOUT_DEFAULT);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readBool(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    RPC_MUTEX_UNLOCK();
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  RPC_MUTEX_UNLOCK();
  return _rpc_ret_val;
}


static inline
bool rpc_mcu_hasUID(uint16_t uid) {
  RpcStatus _rpc_res;
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  RPC_MUTEX_LOCK();
  /* Send request */
  const uint16_t _rpc_seq = MessageWriter_beginInvoke(RPC_UID_MCU_HASUID);
  MessageWriter_writeUInt16(uid);
  MessageWriter_end();

  /* Wait response */
  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, RPC_TIMEOUT_DEFAULT);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readBool(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    RPC_MUTEX_UNLOCK();
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  RPC_MUTEX_UNLOCK();
  return _rpc_ret_val;
}

#ifdef __cplusplus
}
#endif

#endif /* RPC_SHIM_MCU_H */
