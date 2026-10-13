/*
 * function: func_021D7C10
 * address: 0x021D7C10
 * packet: pkt_ov120_021D7C10
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 */
#include "../include/Obj22844.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
int func_021D7C10(char *p) { return BUTTON_MAN_UpdateSlots(((struct Obj22844 *)p)->f8); }
