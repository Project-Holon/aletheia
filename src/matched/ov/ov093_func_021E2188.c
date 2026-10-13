/*
 * function: func_021E2188
 * address:  0x021E2188
 * packet:   pkt_ov093_021E2188
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10073.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTLV_CORE_MakeSlotKind1Empty(void);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E2188(int u, int a, int b)
{
    u8 *r;

    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_HasSick(func_021C7CF4((int *)a, b), 0x23) == 0) {
            r = func_021C88A4((char *)a, 0xc, b);
            ((struct Obj10073 *)r)->f4 = 0x23;
            ((struct Obj10073 *)r)->f8 = BTLV_CORE_MakeSlotKind1Empty();
            r[0xf] = b;
            func_021C8838(r + 0x14, 2, 0x259);
            func_021C8860((struct S *)(r + 0x14), b);
            func_021C88C8((void *)a, r);
        }
    }
}
