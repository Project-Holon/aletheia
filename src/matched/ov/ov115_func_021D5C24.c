/*
 * function: WIFILOGIN_MSG_SetMessage
 * address:  0x021D5C24
 * packet:   pkt_ov115_021D5C24
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFILOGIN_MSG_SetMessageWithIcon  0x021D5C30  thumb  ov115
 */
#include "../include/Obj04466.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void WIFILOGIN_MSG_SetMessageWithIcon(u8 *p, unsigned int a, int b);
void WIFILOGIN_MSG_SetMessage(void *p, int b) { WIFILOGIN_MSG_SetMessageWithIcon(p, ((struct Obj04466 *)p)->f1C, b); }
