/*
 * function: BTLV_CORE_StartYesNoMenu
 * address:  0x021EABC4
 * packet:   pkt_ov093_021EABC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   STRBUF_Create  0x020457B0  arm
 *   BTLV_CORE_BuildMessage  0x021EA55C  thumb  ov093
 *   func_021EAC44  0x021EAC44  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj10116.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct H;
extern void BTLV_CORE_BuildMessage(struct H *p, int a);
extern void func_021EAC44(u32 a, void *b);
extern u32 func_020307B0(void *p);

void BTLV_CORE_StartYesNoMenu(u8 *a, u32 x, u32 y, u32 z)
{
    u32 *t = (u32 *)BTLV_CORE_GetTaskWork(a, 12);

    t[0] = (u32)STRBUF_Create(0x20, (u16)((((struct Obj10116 *)a)->f184 & 0x7fff) | 0x8000));
    t[1] = (u32)STRBUF_Create(0x20, (u16)((((struct Obj10116 *)a)->f184 & 0x7fff) | 0x8000));
    t[2] = z;
    BTLV_CORE_BuildMessage((struct H *)x, (int)((void *)t[0]));
    BTLV_CORE_BuildMessage((struct H *)y, (int)((void *)t[1]));
    func_021EAC44(((struct Obj10116 *)a)->f180, t);
    func_020307B0((void *)t[0]);
    func_020307B0((void *)t[1]);
}
