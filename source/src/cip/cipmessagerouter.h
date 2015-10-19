/*******************************************************************************
 * Copyright (c) 2009, Rockwell Automation, Inc.
 * All rights reserved. 
 *
 ******************************************************************************/
#ifndef OPENER_CIPMESSAGEROUTER_H_
#define OPENER_CIPMESSAGEROUTER_H_

#include "typedefs.h"
#include "ciptypes.h"

static const int kCipMessageRouterClassCode = 0x02;

/** @brief Structure for storing the Response generated by an explict message.
 * 
 *  This buffer will be used for storing the result. The response message will be generated
 *  by assembleLinearMsg. 
 */
extern CipMessageRouterResponse g_message_router_response;

/* public functions */

/** @brief Initialize the data structures of the message router
 *  @return kEipStatusOk if class was initialized, otherwise kEipStatusError
 */
EipStatus CipMessageRouterInit(void);

/** @brief Free all data allocated by the classes created in the CIP stack
 */
void DeleteAllClasses(void);

/** @brief Notify the MessageRouter that an explicit message (connected or unconnected)
 *  has been received. This function will be called from the encapsulation layer.
 *  The CPF structure is already parsed an can be accessed via the global variable:
 *  g_stCPFDataItem.
 *  @param data pointer to the data buffer of the message directly at the beginning of the CIP part.
 *  @param data_length number of bytes in the data buffer
 *  @return  EIP_ERROR on fault
 *           EIP_OK on success           
 */
EipStatus NotifyMR(EipUint8 *data, int data_length);

/*! Register a class at the message router.
 *  In order that the message router can deliver
 *  explicit messages each class has to register.
 *  Will be automatically done when invoking create
 *  createCIPClass.
 *  @param object CIP class to be registered
 *  @return EIP_OK on success
 */
EipStatus RegisterClass(CipClass *object);

#endif /* OPENER_CIPMESSAGEROUTER_H_ */
