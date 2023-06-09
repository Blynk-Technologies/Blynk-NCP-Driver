
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_HANDLER_SYSTEM_H
#define RPC_HANDLER_SYSTEM_H


static
RpcStatus rpc_system_ping_handler(MessageBuffer* _rpc_buff) {


  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_system_reboot_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_system_reboot_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_system_reboot_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_system_hasUID_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t uid; MessageBuffer_readUInt16(_rpc_buff, &uid);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_system_hasUID_impl(uint16_t uid);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_system_hasUID_impl(uid);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}

#endif /* RPC_HANDLER_SYSTEM_H */
