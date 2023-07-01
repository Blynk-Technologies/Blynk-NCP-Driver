
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_HANDLER_NCP_H
#define RPC_HANDLER_NCP_H


extern "C" void rpc_ncp_ping_impl();

static
RpcStatus rpc_ncp_ping_handler(MessageBuffer* _rpc_buff) {


  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


extern "C" bool rpc_ncp_reboot_impl();

static
RpcStatus rpc_ncp_reboot_handler(MessageBuffer* _rpc_buff) {

  /* Call the actual function */
  bool _rpc_ret_val = rpc_ncp_reboot_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


extern "C" bool rpc_ncp_hasUID_impl(uint16_t uid);

static
RpcStatus rpc_ncp_hasUID_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t uid; MessageBuffer_readUInt16(_rpc_buff, &uid);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Call the actual function */
  bool _rpc_ret_val = rpc_ncp_hasUID_impl(uid);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}

#endif /* RPC_HANDLER_NCP_H */
