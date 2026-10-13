/*
 * function: SCRIPT_WORK_GetUserWork
 * address:  0x02158FB8
 * packet:   pkt_02158F50
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_GetUserWork.c \
 *       --func SCRIPT_WORK_GetUserWork --addr 0x02158FB8 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17637.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

u32 SCRIPT_WORK_GetUserWork(void *p) { return ((struct Obj17637 *)p)->f3C; }
