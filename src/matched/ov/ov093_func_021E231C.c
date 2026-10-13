/*
 * function: func_021E231C
 * address:  0x021E231C
 * packet:   pkt_ov093_021E231C
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
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */
#include "../include/Obj10076.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct QQ;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021E03D8(u8 *a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void func_021E231C(void *u, int a, int b)
{
    void *q;
    u8 *r;

    if (b == BTL_EVENT_GetVar(2)) {
        q = func_021C7CF4((int *)a, b);
        if (BTL_POKEPARAM_HasSick(q, 2) != 0) {
            r = func_021C88A4((char *)a, 0xb, b);
            ((struct Obj10076 *)r)->f4 = 0x19;
            r[0x14] = 1;
            r[8] = b;
            func_021C88C8((void *)a, r);
            func_021E03D8(q, BTL_EVENT_GetFactorKey(u));
        }
    }
}
