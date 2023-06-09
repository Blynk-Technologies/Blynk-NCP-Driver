
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_HANDLER_BLYNK_H
#define RPC_HANDLER_BLYNK_H


static
RpcStatus rpc_blynk_getNcpVersion_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* ver; memset(&ver, 0, sizeof(ver)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_getNcpVersion_impl(const char** ver);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_getNcpVersion_impl(&ver);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeString(_rpc_buff, ver);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setVendorPrefix_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* vendor; MessageBuffer_readString(_rpc_buff, &vendor);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_setVendorPrefix_impl(const char* vendor);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_setVendorPrefix_impl(vendor);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setVendorServer_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* host; MessageBuffer_readString(_rpc_buff, &host);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_setVendorServer_impl(const char* host);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_setVendorServer_impl(host);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setFirmwareInfo_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* type; MessageBuffer_readString(_rpc_buff, &type);
  const char* version; MessageBuffer_readString(_rpc_buff, &version);
  const char* build; MessageBuffer_readString(_rpc_buff, &build);
  const char* blynk; MessageBuffer_readString(_rpc_buff, &blynk);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_setFirmwareInfo_impl(const char* type, const char* version, const char* build, const char* blynk);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_setFirmwareInfo_impl(type, version, build, blynk);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_initialize_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* templateID; MessageBuffer_readString(_rpc_buff, &templateID);
  const char* templateName; MessageBuffer_readString(_rpc_buff, &templateName);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_initialize_impl(const char* templateID, const char* templateName);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_initialize_impl(templateID, templateName);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_getHotspotName_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* hotspot; memset(&hotspot, 0, sizeof(hotspot)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_getHotspotName_impl(const char** hotspot);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_getHotspotName_impl(&hotspot);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeString(_rpc_buff, hotspot);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_isConfigured_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_blynk_isConfigured_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_isConfigured_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_configStart_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_blynk_configStart_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_configStart_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_configStop_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_blynk_configStop_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_configStop_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_configReset_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_blynk_configReset_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_configReset_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setConfigTimeout_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t timeout; MessageBuffer_readUInt16(_rpc_buff, &timeout);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_setConfigTimeout_impl(uint16_t timeout);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_setConfigTimeout_impl(timeout);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setConfigSkipLimit_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint8_t count; MessageBuffer_readUInt8(_rpc_buff, &count);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_setConfigSkipLimit_impl(uint8_t count);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_setConfigSkipLimit_impl(count);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setTime_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  int64_t time; MessageBuffer_readInt64(_rpc_buff, &time);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_setTime_impl(int64_t time);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_setTime_impl(time);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_getTime_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* iso8601; memset(&iso8601, 0, sizeof(iso8601)); /* output */
  int64_t time; memset(&time, 0, sizeof(time)); /* output */
  int16_t offset; memset(&offset, 0, sizeof(offset)); /* output */
  const char* tz_abbr; memset(&tz_abbr, 0, sizeof(tz_abbr)); /* output */
  uint8_t dst_status; memset(&dst_status, 0, sizeof(dst_status)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_getTime_impl(const char** iso8601, int64_t* time, int16_t* offset, const char** tz_abbr, uint8_t* dst_status);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_getTime_impl(&iso8601, &time, &offset, &tz_abbr, &dst_status);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeString(_rpc_buff, iso8601);
  MessageBuffer_writeInt64(_rpc_buff, time);
  MessageBuffer_writeInt16(_rpc_buff, offset);
  MessageBuffer_writeString(_rpc_buff, tz_abbr);
  MessageBuffer_writeUInt8(_rpc_buff, dst_status);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_getLocationInfo_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* lat; memset(&lat, 0, sizeof(lat)); /* output */
  const char* lon; memset(&lon, 0, sizeof(lon)); /* output */
  const char* olson_id; memset(&olson_id, 0, sizeof(olson_id)); /* output */
  const char* posix_tz; memset(&posix_tz, 0, sizeof(posix_tz)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_getLocationInfo_impl(const char** lat, const char** lon, const char** olson_id, const char** posix_tz);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_getLocationInfo_impl(&lat, &lon, &olson_id, &posix_tz);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeString(_rpc_buff, lat);
  MessageBuffer_writeString(_rpc_buff, lon);
  MessageBuffer_writeString(_rpc_buff, olson_id);
  MessageBuffer_writeString(_rpc_buff, posix_tz);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_otaUpdateStart_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t chunk; MessageBuffer_readUInt16(_rpc_buff, &chunk);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_otaUpdateStart_impl(uint16_t chunk);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_otaUpdateStart_impl(chunk);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_otaUpdateGetCRC32_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint32_t crc; memset(&crc, 0, sizeof(crc)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_otaUpdateGetCRC32_impl(uint32_t* crc);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_otaUpdateGetCRC32_impl(&crc);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeUInt32(_rpc_buff, crc);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_otaUpdateGetMD5_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  buffer_t digest; memset(&digest, 0, sizeof(digest)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_otaUpdateGetMD5_impl(buffer_t* digest);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_otaUpdateGetMD5_impl(&digest);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBinary(_rpc_buff, digest);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_otaUpdateGetSHA256_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  buffer_t digest; memset(&digest, 0, sizeof(digest)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_blynk_otaUpdateGetSHA256_impl(buffer_t* digest);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_otaUpdateGetSHA256_impl(&digest);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBinary(_rpc_buff, digest);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_factoryReset_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern bool rpc_blynk_factoryReset_impl();
  /* Call the actual function */
  bool _rpc_ret_val = rpc_blynk_factoryReset_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_factoryTestWiFiAP_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t channel; MessageBuffer_readUInt16(_rpc_buff, &channel);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern uint8_t rpc_blynk_factoryTestWiFiAP_impl(uint16_t channel);
  /* Call the actual function */
  uint8_t _rpc_ret_val = rpc_blynk_factoryTestWiFiAP_impl(channel);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeUInt8(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_factoryTestWiFi_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* ssid; MessageBuffer_readString(_rpc_buff, &ssid);
  const char* pass; MessageBuffer_readString(_rpc_buff, &pass);
  int16_t rssi; memset(&rssi, 0, sizeof(rssi)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern uint8_t rpc_blynk_factoryTestWiFi_impl(const char* ssid, const char* pass, int16_t* rssi);
  /* Call the actual function */
  uint8_t _rpc_ret_val = rpc_blynk_factoryTestWiFi_impl(ssid, pass, &rssi);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeInt16(_rpc_buff, rssi);
  MessageBuffer_writeUInt8(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_factoryTestConnect_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern uint8_t rpc_blynk_factoryTestConnect_impl();
  /* Call the actual function */
  uint8_t _rpc_ret_val = rpc_blynk_factoryTestConnect_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeUInt8(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_getState_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern uint8_t rpc_blynk_getState_impl();
  /* Call the actual function */
  uint8_t _rpc_ret_val = rpc_blynk_getState_impl();

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeUInt8(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_virtualWrite_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t vpin; MessageBuffer_readUInt16(_rpc_buff, &vpin);
  buffer_t value; MessageBuffer_readBinary(_rpc_buff, &value);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_virtualWrite_impl(uint16_t vpin, buffer_t value);
  /* Call the actual function */
  rpc_blynk_virtualWrite_impl(vpin, value);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setProperty_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t vpin; MessageBuffer_readUInt16(_rpc_buff, &vpin);
  const char* property; MessageBuffer_readString(_rpc_buff, &property);
  buffer_t value; MessageBuffer_readBinary(_rpc_buff, &value);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_setProperty_impl(uint16_t vpin, const char* property, buffer_t value);
  /* Call the actual function */
  rpc_blynk_setProperty_impl(vpin, property, value);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_syncAll_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern void rpc_blynk_syncAll_impl();
  /* Call the actual function */
  rpc_blynk_syncAll_impl();

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_syncVirtual_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  buffer_t vpins; MessageBuffer_readBinary(_rpc_buff, &vpins);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_syncVirtual_impl(buffer_t vpins);
  /* Call the actual function */
  rpc_blynk_syncVirtual_impl(vpins);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_logEvent_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* event_code; MessageBuffer_readString(_rpc_buff, &event_code);
  const char* description; MessageBuffer_readString(_rpc_buff, &description);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_logEvent_impl(const char* event_code, const char* description);
  /* Call the actual function */
  rpc_blynk_logEvent_impl(event_code, description);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_resolveEvent_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* event_code; MessageBuffer_readString(_rpc_buff, &event_code);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_resolveEvent_impl(const char* event_code);
  /* Call the actual function */
  rpc_blynk_resolveEvent_impl(event_code);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_resolveAllEvents_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* event_code; MessageBuffer_readString(_rpc_buff, &event_code);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_resolveAllEvents_impl(const char* event_code);
  /* Call the actual function */
  rpc_blynk_resolveAllEvents_impl(event_code);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_beginGroup_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  int64_t timestamp; MessageBuffer_readInt64(_rpc_buff, &timestamp);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_beginGroup_impl(int64_t timestamp);
  /* Call the actual function */
  rpc_blynk_beginGroup_impl(timestamp);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_endGroup_handler(MessageBuffer* _rpc_buff) {

  /* Forward decl */
  extern void rpc_blynk_endGroup_impl();
  /* Call the actual function */
  rpc_blynk_endGroup_impl();

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_blynk_setMetadata_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* field; MessageBuffer_readString(_rpc_buff, &field);
  const char* value; MessageBuffer_readString(_rpc_buff, &value);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern void rpc_blynk_setMetadata_impl(const char* field, const char* value);
  /* Call the actual function */
  rpc_blynk_setMetadata_impl(field, value);

  MessageBuffer_reset(_rpc_buff);
  return RPC_STATUS_OK;
}

#endif /* RPC_HANDLER_BLYNK_H */
