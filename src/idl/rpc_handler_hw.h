
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_HANDLER_HW_H
#define RPC_HANDLER_HW_H


static
RpcStatus rpc_hw_setUartBaudRate_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint32_t baud; MessageBuffer_readUInt32(_rpc_buff, &baud);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_setUartBaudRate_impl(uint32_t baud);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_setUartBaudRate_impl(baud);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_initUserButton_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t gpio; MessageBuffer_readUInt16(_rpc_buff, &gpio);
  bool active_low; MessageBuffer_readBool(_rpc_buff, &active_low);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_initUserButton_impl(uint16_t gpio, bool active_low);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_initUserButton_impl(gpio, active_low);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_initLED_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t gpio; MessageBuffer_readUInt16(_rpc_buff, &gpio);
  bool active_low; MessageBuffer_readBool(_rpc_buff, &active_low);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_initLED_impl(uint16_t gpio, bool active_low);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_initLED_impl(gpio, active_low);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_initRGB_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t gpio_r; MessageBuffer_readUInt16(_rpc_buff, &gpio_r);
  uint16_t gpio_g; MessageBuffer_readUInt16(_rpc_buff, &gpio_g);
  uint16_t gpio_b; MessageBuffer_readUInt16(_rpc_buff, &gpio_b);
  bool common_anode; MessageBuffer_readBool(_rpc_buff, &common_anode);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_initRGB_impl(uint16_t gpio_r, uint16_t gpio_g, uint16_t gpio_b, bool common_anode);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_initRGB_impl(gpio_r, gpio_g, gpio_b, common_anode);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_initARGB_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint16_t gpio; MessageBuffer_readUInt16(_rpc_buff, &gpio);
  uint8_t mode; MessageBuffer_readUInt8(_rpc_buff, &mode);
  uint8_t count; MessageBuffer_readUInt8(_rpc_buff, &count);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_initARGB_impl(uint16_t gpio, uint8_t mode, uint8_t count);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_initARGB_impl(gpio, mode, count);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_setLedBrightness_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  uint8_t value; MessageBuffer_readUInt8(_rpc_buff, &value);

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_setLedBrightness_impl(uint8_t value);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_setLedBrightness_impl(value);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_getWiFiMAC_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* mac; memset(&mac, 0, sizeof(mac)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_getWiFiMAC_impl(const char** mac);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_getWiFiMAC_impl(&mac);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeString(_rpc_buff, mac);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}


static
RpcStatus rpc_hw_getEthernetMAC_handler(MessageBuffer* _rpc_buff) {
  /* Deserialize arguments */
  const char* mac; memset(&mac, 0, sizeof(mac)); /* output */

  if (MessageBuffer_getError(_rpc_buff) || MessageBuffer_availableToRead(_rpc_buff)) {
    return RPC_STATUS_ERROR_ARGS_R;
  }

  /* Forward decl */
  extern bool rpc_hw_getEthernetMAC_impl(const char** mac);
  /* Call the actual function */
  bool _rpc_ret_val = rpc_hw_getEthernetMAC_impl(&mac);

  MessageBuffer_reset(_rpc_buff);
  /* Serialize outputs */
  MessageBuffer_writeString(_rpc_buff, mac);
  MessageBuffer_writeBool(_rpc_buff, _rpc_ret_val);

  if (MessageBuffer_getError(_rpc_buff)) {
    return RPC_STATUS_ERROR_RETS_W;
  }
  return RPC_STATUS_OK;
}

#endif /* RPC_HANDLER_HW_H */
