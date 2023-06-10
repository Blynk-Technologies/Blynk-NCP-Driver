
/* This file is auto-generated. DO NOT EDIT. */

#ifndef RPC_SHIM_HW_H
#define RPC_SHIM_HW_H


static inline
bool rpc_hw_setUartBaudRate(uint32_t baud) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_SETUARTBAUDRATE);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt32(&_rpc_buff, baud);

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
bool rpc_hw_initUserButton(uint16_t gpio, bool active_low) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_INITUSERBUTTON);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, gpio);
  MessageBuffer_writeBool(&_rpc_buff, active_low);

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
bool rpc_hw_initLED(uint16_t gpio, bool active_low) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_INITLED);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, gpio);
  MessageBuffer_writeBool(&_rpc_buff, active_low);

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
bool rpc_hw_initRGB(uint16_t gpio_r, uint16_t gpio_g, uint16_t gpio_b, bool common_anode) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_INITRGB);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, gpio_r);
  MessageBuffer_writeUInt16(&_rpc_buff, gpio_g);
  MessageBuffer_writeUInt16(&_rpc_buff, gpio_b);
  MessageBuffer_writeBool(&_rpc_buff, common_anode);

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
bool rpc_hw_initARGB(uint16_t gpio, uint8_t mode, uint8_t count) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_INITARGB);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt16(&_rpc_buff, gpio);
  MessageBuffer_writeUInt8(&_rpc_buff, mode);
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
bool rpc_hw_setLedBrightness(uint8_t value) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_SETLEDBRIGHTNESS);
  MessageBuffer_writeUInt16(&_rpc_buff, ++_rpc_seq);

  /* Serialize inputs */
  MessageBuffer_writeUInt8(&_rpc_buff, value);

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
bool rpc_hw_getWiFiMAC(const char** mac) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_GETWIFIMAC);
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
    MessageBuffer_readString(&_rsp_buff, mac);
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
bool rpc_hw_getEthernetMAC(const char** mac) {
  RpcStatus _rpc_res;
  /* Prepare return value */
  bool _rpc_ret_val;
  memset(&_rpc_ret_val, 0, sizeof(_rpc_ret_val));

  MessageBuffer _rpc_buff;
  MessageBuffer_init(&_rpc_buff, rpc_output_buff, sizeof(rpc_output_buff));
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_OP_INVOKE);
  MessageBuffer_writeUInt16(&_rpc_buff, RPC_UID_HW_GETETHERNETMAC);
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
    MessageBuffer_readString(&_rsp_buff, mac);
    MessageBuffer_readBool(&_rsp_buff, &_rpc_ret_val);
  }
  if (MessageBuffer_getError(&_rsp_buff) || MessageBuffer_availableToRead(&_rsp_buff)) {
    rpc_set_status(_rpc_res = RPC_STATUS_ERROR_RETS_R);
    return _rpc_ret_val;
  }

  rpc_set_status(_rpc_res);
  return _rpc_ret_val;
}

#endif /* RPC_SHIM_HW_H */
