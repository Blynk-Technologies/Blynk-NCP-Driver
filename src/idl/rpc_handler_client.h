
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_HANDLER_CLIENT_H
#define RPC_HANDLER_CLIENT_H


static
RpcStatus rpc_client_blynkVPinChange_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t vpin; MessageBuffer_readUInt16(_rpc_buff, &vpin);
  buffer_t param; MessageBuffer_readBinary(_rpc_buff, &param);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_client_blynkVPinChange_impl(uint16_t vpin, buffer_t param);
  /* Call the actual function */
  rpc_client_blynkVPinChange_impl(vpin, param);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_client_blynkStateChange_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint8_t state; MessageBuffer_readUInt8(_rpc_buff, &state);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_client_blynkStateChange_impl(uint8_t state);
  /* Call the actual function */
  rpc_client_blynkStateChange_impl(state);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_client_processEvent_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint8_t event; MessageBuffer_readUInt8(_rpc_buff, &event);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_client_processEvent_impl(uint8_t event);
  /* Call the actual function */
  rpc_client_processEvent_impl(event);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_client_otaUpdateAvailable_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* filename; MessageBuffer_readString(_rpc_buff, &filename);
  uint32_t filesize; MessageBuffer_readUInt32(_rpc_buff, &filesize);
  const char* fw_type; MessageBuffer_readString(_rpc_buff, &fw_type);
  const char* fw_ver; MessageBuffer_readString(_rpc_buff, &fw_ver);
  const char* fw_build; MessageBuffer_readString(_rpc_buff, &fw_build);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_client_otaUpdateAvailable_impl(const char* filename, uint32_t filesize, const char* fw_type, const char* fw_ver, const char* fw_build);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_client_otaUpdateAvailable_impl(filename, filesize, fw_type, fw_ver, fw_build);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_client_otaUpdateWrite_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint32_t offset; MessageBuffer_readUInt32(_rpc_buff, &offset);
  buffer_t chunk; MessageBuffer_readBinary(_rpc_buff, &chunk);
  uint32_t crc32; MessageBuffer_readUInt32(_rpc_buff, &crc32);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_client_otaUpdateWrite_impl(uint32_t offset, buffer_t chunk, uint32_t crc32);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_client_otaUpdateWrite_impl(offset, chunk, crc32);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_client_otaUpdateFinish_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_client_otaUpdateFinish_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_client_otaUpdateFinish_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_client_otaUpdateCancel_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern void rpc_client_otaUpdateCancel_impl();
  /* Call the actual function */
  rpc_client_otaUpdateCancel_impl();

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}

#endif /* RPC_HANDLER_CLIENT_H */
