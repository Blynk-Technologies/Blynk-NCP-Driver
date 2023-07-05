
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_SHIM_BLYNK_H
#define RPC_SHIM_BLYNK_H


static inline
bool rpc_blynk_getNcpVersion(const char** ver) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_GETNCPVERSION);
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
    MessageBuffer_readString(&_rsp_buff, ver);
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
bool rpc_blynk_setVendorPrefix(const char* vendor) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETVENDORPREFIX);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, vendor);

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
bool rpc_blynk_setVendorServer(const char* host) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETVENDORSERVER);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, host);

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
bool rpc_blynk_setFirmwareInfo(const char* type, const char* version, const char* build, const char* blynk) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETFIRMWAREINFO);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, type);
  MessageBuffer_writeString(&_rpc_buff, version);
  MessageBuffer_writeString(&_rpc_buff, build);
  MessageBuffer_writeString(&_rpc_buff, blynk);

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
bool rpc_blynk_initialize(const char* templateID, const char* templateName) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_INITIALIZE);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, templateID);
  MessageBuffer_writeString(&_rpc_buff, templateName);

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


static inline
bool rpc_blynk_getHotspotName(const char** hotspot) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_GETHOTSPOTNAME);
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
    MessageBuffer_readString(&_rsp_buff, hotspot);
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
bool rpc_blynk_isConfigured() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_ISCONFIGURED);
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
bool rpc_blynk_configStart() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_CONFIGSTART);
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
bool rpc_blynk_configStop() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_CONFIGSTOP);
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
bool rpc_blynk_configReset() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_CONFIGRESET);
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
bool rpc_blynk_setConfigTimeout(uint16_t timeout) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETCONFIGTIMEOUT);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, timeout);

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
bool rpc_blynk_setConfigSkipLimit(uint8_t count) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETCONFIGSKIPLIMIT);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt8(&_rpc_buff, count);

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
bool rpc_blynk_setTime(int64_t time) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETTIME);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeInt64(&_rpc_buff, time);

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
bool rpc_blynk_getTime(const char** iso8601, int64_t* time, int16_t* offset, const char** tz_abbr, uint8_t* dst_status) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_GETTIME);
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
    MessageBuffer_readString(&_rsp_buff, iso8601);
    MessageBuffer_readInt64(&_rsp_buff, time);
    MessageBuffer_readInt16(&_rsp_buff, offset);
    MessageBuffer_readString(&_rsp_buff, tz_abbr);
    MessageBuffer_readUInt8(&_rsp_buff, dst_status);
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
bool rpc_blynk_getLocationInfo(const char** lat, const char** lon, const char** olson_id, const char** posix_tz) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_GETLOCATIONINFO);
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
    MessageBuffer_readString(&_rsp_buff, lat);
    MessageBuffer_readString(&_rsp_buff, lon);
    MessageBuffer_readString(&_rsp_buff, olson_id);
    MessageBuffer_readString(&_rsp_buff, posix_tz);
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
bool rpc_blynk_otaUpdateStart(uint16_t chunk) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_OTAUPDATESTART);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, chunk);

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
bool rpc_blynk_otaUpdateGetCRC32(uint32_t* crc) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_OTAUPDATEGETCRC32);
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
    MessageBuffer_readUInt32(&_rsp_buff, crc);
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
bool rpc_blynk_otaUpdateGetMD5(buffer_t* digest) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_OTAUPDATEGETMD5);
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
    MessageBuffer_readBinary(&_rsp_buff, digest);
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
bool rpc_blynk_otaUpdateGetSHA256(buffer_t* digest) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_OTAUPDATEGETSHA256);
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
    MessageBuffer_readBinary(&_rsp_buff, digest);
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
uint8_t rpc_blynk_otaUpdatePrefetch() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  uint8_t _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_OTAUPDATEPREFETCH);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 30000);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readUInt8(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}


static inline
bool rpc_blynk_factoryReset() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_FACTORYRESET);
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
uint8_t rpc_blynk_factoryTestWiFiAP(uint16_t channel) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  uint8_t _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_FACTORYTESTWIFIAP);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, channel);

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
    MessageBuffer_readUInt8(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}


static inline
uint8_t rpc_blynk_factoryTestWiFi(const char* ssid, const char* pass, int16_t* rssi) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  uint8_t _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_FACTORYTESTWIFI);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, ssid);
  MessageBuffer_writeString(&_rpc_buff, pass);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 15000);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readInt16(&_rsp_buff, rssi);
    MessageBuffer_readUInt8(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}


static inline
uint8_t rpc_blynk_factoryTestConnect() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  uint8_t _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_FACTORYTESTCONNECT);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return _rpc_ret_val;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  MessageBuffer _rsp_buff;
  MessageBuffer_init(&_rsp_buff, NULL, 0);
  _rpc_res = rpc_wait_result(_rpc_seq, &_rsp_buff, 10000);
  if (_rpc_res == RPC_STATUS_OK) {
    /* Deserialize outputs */
    MessageBuffer_readUInt8(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}


static inline
uint8_t rpc_blynk_getState() {
  RpcStatus _rpc_res;
  /* Prepare return value */
  uint8_t _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_GETSTATE);
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
    MessageBuffer_readUInt8(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}


static inline
void rpc_blynk_virtualWrite(uint16_t vpin, buffer_t value) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_VIRTUALWRITE);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, vpin);
  MessageBuffer_writeBinary(&_rpc_buff, value);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_setProperty(uint16_t vpin, const char* property, buffer_t value) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETPROPERTY);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, vpin);
  MessageBuffer_writeString(&_rpc_buff, property);
  MessageBuffer_writeBinary(&_rpc_buff, value);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_syncAll() {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SYNCALL);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_syncVirtual(buffer_t vpins) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SYNCVIRTUAL);

  /* Serialize inputs */
  MessageBuffer_writeBinary(&_rpc_buff, vpins);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_logEvent(const char* event_code, const char* description) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_LOGEVENT);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, event_code);
  MessageBuffer_writeString(&_rpc_buff, description);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_resolveEvent(const char* event_code) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_RESOLVEEVENT);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, event_code);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_resolveAllEvents(const char* event_code) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_RESOLVEALLEVENTS);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, event_code);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_beginGroup(int64_t timestamp) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_BEGINGROUP);

  /* Serialize inputs */
  MessageBuffer_writeInt64(&_rpc_buff, timestamp);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_endGroup() {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_ENDGROUP);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}


static inline
void rpc_blynk_setMetadata(const char* field, const char* value) {
  RpcStatus _rpc_res;
  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_ONEWAY);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_BLYNK_SETMETADATA);

  /* Serialize inputs */
  MessageBuffer_writeString(&_rpc_buff, field);
  MessageBuffer_writeString(&_rpc_buff, value);

  if (MessageBuffer_getError(&_rpc_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_ARGS_W);
    return;
  }

  /* RPC call */
  rpc_send_msg(&_rpc_buff);

  /* Oneway => skip response */
}

#endif /* RPC_SHIM_BLYNK_H */
