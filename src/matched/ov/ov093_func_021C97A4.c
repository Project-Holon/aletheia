/*
 * function: func_021C97A4
 * address: 0x021C97A4
 * packet: pkt_ov093_021C97A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of trailing alignment padding.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_ClearContFlag 0x021C6110 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_SERVER_FLOW_ClearContFlag(u8 *, u8 *, u32);
int func_021C97A4(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_SERVER_FLOW_ClearContFlag(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}
