/*
 * function: func_021E4A70
 * address:  0x021E4A70
 * packet:   pkt_ov093_021E4A70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C83CC  0x021C83CC  thumb  ov093
 */
#include "../../../matched/include/Obj01898.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern u32 func_021C83CC(u8 *p);

void func_021E4A70(int u, int a, int b)
{
    u8 k;
    u32 w;
    enum { E_ONE = 1 } e;
    int t;
    u8 *s;

    if (b == func_021D775C(3)) {
        k = func_021D775C(6);
        w = func_021C83CC((u8 *)a);
        e = E_ONE;
        s = func_021C88A4((char *)a, 0xe, b);
        s[0xf] = e;
        s[0x10] = k;
        ((struct Obj01898 *)s)->f4 = e;
        t = e - 3;
        s[0xc] = t;
        ((struct Obj01898 *)s)->f8 = w;
        s[0xe] = 1;
        func_021C88C8((void *)a, s);
        s = func_021C88A4((char *)a, 0xe, b);
        s[0xf] = e;
        s[0x10] = k;
        ((struct Obj01898 *)s)->f4 = 3;
        s[0xc] = t;
        ((struct Obj01898 *)s)->f8 = w;
        s[0xe] = 1;
        func_021C88C8((void *)a, s);
        s = func_021C88A4((char *)a, 0x13, b);
        s[4] = b;
        func_021C88C8((void *)a, s);
    }
}
