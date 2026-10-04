/*
 * function: func_021F3868
 * address:  0x021F3868
 * packet:   pkt_ov059_021F3868
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     twin of ov059 func_021F36C0 plus a heap allocation and a third
 *           row loop; the second loop's counter reuses z's register.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F4080     0x021F4080  data  ov059  a1
 *   d_021F3E74     0x021F3E74  data  a4
 */
#include "../include/Obj20584.h"

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern char d_021F4080[];
extern char d_021F3E74[];

extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(void *a, int b, u16 c, int d);
extern u8 *func_021897BC(void *p, int i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021BE310(void *a, void *b, int c);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern u8 *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);

void func_021F3868(void *a)
{
    int i;
    void *s;
    int z;
    u8 *e;
    int h;
    u8 *w;

    s = (void *)func_02188D2C(a);
    h = (func_02188C84(a) & 0x7FFF) | 0x8000;
    func_02189764(a, 1, h, 0x28);
    w = func_021897BC(a, 1);
    ((struct Obj20584 *)w)->f24 = func_02030734((u16)h, 4, 1, d_021F4080, 0x1D1);
    i = 0;
    func_021BE310(s, d_021F3E74, 0);
    func_021BE4B4(s, 0, 1, 1);
    func_021BE4B4(s, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        e = func_021BE674(s, z, z, i);
        func_021BE6B8(e, z);
        func_021BE6B0(e, 1);
        func_021BE700(s, z, z, i, z);
        e = func_021BE674(s, z, 1, i);
        func_021BE6B8(e, z);
        func_021BE6B0(e, 1);
        func_021BE700(s, z, 1, i, z);
    }
    for (i = 0; i < 3; i++) {
        e = func_021BE674(s, 0, 2, i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 2, i, 0);
    }
}
