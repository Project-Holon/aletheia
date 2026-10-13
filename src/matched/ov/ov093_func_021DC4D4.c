/*
 * function: func_021DC4D4
 * address:  0x021DC4D4
 * packet:   pkt_ov093_021DC4D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06260.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern u32 func_021D7D18(int x);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DC4D4(int u, void *a, int b)
{
    u8 *e;
    if (b == func_021D775C(3)
        && func_021D775C(0x46) == 0
        && func_021D775C(0x47) == 0
        && WAZA_TOOL_GetFlag(func_021D775C(0x12), 0) != 0
        && func_021D85C0((int)a, 0x1e) != 0) {
        e = func_021C88A4(a, 0xc, b);
        ((struct Obj06260 *)e)->f0 |= 2 << 22;
        e[0xf] = func_021D775C(4);
        ((struct Obj06260 *)e)->f4 = 5;
        ((struct Obj06260 *)e)->f8 = func_021D7D18(5);
        func_021C8838(e + 0x14, 2, 0x1d8);
        func_021C8860((struct S *)(e + 0x14), e[0xf]);
        func_021C88C8(a, e);
    }
}
