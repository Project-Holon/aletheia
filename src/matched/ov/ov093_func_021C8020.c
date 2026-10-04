/*
 * function: func_021C8020
 * address: 0x021C8020
 * packet: pkt_ov093_021C8020
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * symbols:
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D5440(u8 *p);
u8 func_021C8020(u8 *p, u8 v) { return func_021D5440((u8 *)func_021B98AC(*(char *const * *)&((struct Obj00003 *)p)->f8, v)); }
