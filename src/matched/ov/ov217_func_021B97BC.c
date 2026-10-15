/*
 * function: RESEARCH_TOP_StateList
 * address:  0x021B97BC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_TOP_UpdateListObject  0x021B9B08  thumb  ov217
 *   RESEARCH_TOP_IsListObjectDone  0x021B9B80  thumb  ov217
 *   RESEARCH_TOP_GetListObjectMode  0x021B9B90  thumb  ov217
 *
 * Reports the body state of the +0x10 handle: 1 when RESEARCH_TOP_IsListObjectDone() is
 * idle, else the RESEARCH_TOP_GetListObjectMode() code mapped to 2/3/4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_TOP_UpdateListObject(char *p);
extern int RESEARCH_TOP_IsListObjectDone(void *p);
extern u32 RESEARCH_TOP_GetListObjectMode(void *p);
u32 RESEARCH_TOP_StateList(u8 *a0)
{
    RESEARCH_TOP_UpdateListObject((char *)(((struct Obj02554 *)a0)->f10));
    if (RESEARCH_TOP_IsListObjectDone((void *)(((struct Obj02554 *)a0)->f10)) != 0) {
    switch (RESEARCH_TOP_GetListObjectMode((void *)(((struct Obj02554 *)a0)->f10))) {
    case 0:
    return 2;
    case 1:
    return 3;
    case 2:
    return 4;
    }
    return 4;
    }
    return 1;
}
