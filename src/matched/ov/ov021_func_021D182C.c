/*
 * function: func_021D182C
 * address:  0x021D182C
 * packet:   pkt_ov021_021D182C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The spilled second parameter is a u16 (func_0216DE94 compares its id
 * against func_0216D588's u16): as u32/int its reload from [sp] is hoisted
 * above the struct copy's last store. func_021BBA6C takes the result of
 * func_021BB990 (the bl has no argument setup of its own).
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   d_021DD5F0     0x021DD5F0  data    ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct V3 { u32 a, b, c; };

extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
extern u32 func_021BBA6C(const void *p);
extern void *func_0216DE94(void *map, u32 id);
extern int d_021DD5F0[];

u8 *func_021D182C(u32 a, u16 b, struct V3 *c, u16 d)
{
    void *t = func_02188C7C((void *)a);
    u32 h = func_02188D24((u8 *)a);
    int *w = func_021BB990(-1, (int *)h, d_021DD5F0);
    u8 *p = (u8 *)func_021BBA6C(w);

    *(int **)(p + 0x188) = w;
    *(u16 *)(p + 0x19C) = d;
    *(struct V3 *)(p + 0x18C) = *c;
    *(u32 *)p = (u32)func_0216DE94(t, b);
    return p;
}
