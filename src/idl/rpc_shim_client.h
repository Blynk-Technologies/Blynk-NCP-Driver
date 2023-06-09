
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_SHIM_CLIENT_H
#define RPC_SHIM_CLIENT_H


static
void rpc_client_blynkVPinChange(uint16_t vpin, buffer_t param) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_BLYNKVPINCHANGE);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, vpin);
  MessageBuffer_writeBinary(&_rpc_buff, param);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static
void rpc_client_blynkStateChange(uint8_t state) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_BLYNKSTATECHANGE);

  /* Serialize inputs */
  MessageBuffer_writeUInt8(&_rpc_buff, state);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static
void rpc_client_processEvent(uint8_t event) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_PROCESSEVENT);

  /* Serialize inputs */
  MessageBuffer_writeUInt8(&_rpc_buff, event);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static
bool rpc_client_otaUpdateAvailable(const char* filename, uint32_t filesize, const char* fw_type, const char* fw_ver, const char* fw_build) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_OTAUPDATEAVAILABLE);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, filename);
  MessageBuffer_writeUInt32(&_rpc_buff, filesize);
  MessageBuffer_writeString(&_rpc_buff, fw_type);
  MessageBuffer_writeString(&_rpc_buff, fw_ver);
  MessageBuffer_writeString(&_rpc_buff, fw_build);

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


static
bool rpc_client_otaUpdateWrite(uint32_t offset, buffer_t chunk, uint32_t crc32) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_OTAUPDATEWRITE);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt32(&_rpc_buff, offset);
  MessageBuffer_writeBinary(&_rpc_buff, chunk);
  MessageBuffer_writeUInt32(&_rpc_buff, crc32);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 5000);
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


static
bool rpc_client_otaUpdateFinish() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_OTAUPDATEFINISH);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 5000);
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


static
void rpc_client_otaUpdateCancel() {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_CLIENT_OTAUPDATECANCEL);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, RPC_TIMEOUT_DEFAULT);

  rpc_set_status(_rpc_res);
  return;
}

#endif /* RPC_SHIM_CLIENT_H */
