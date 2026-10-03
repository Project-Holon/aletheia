/*
 * unit:     yes
 * function: func_021E5974, func_021E5A28
 * address:  0x021E5974
 * packet:   pkt_ov093_021E5974
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   d_021F258C     0x021F258C  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct Flag;
struct QQ;
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern u8 func_021B8DDC(u32 x);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern int d_021F258C[];

void func_021E5974(void *a, void *b, int c)
{
    u8 *m;
    int v;

    if (c == func_021D775C(3) && func_021C7F24(b, c) != 0 && func_021C7F4C(b) != 0) {
        v = func_021B8DDC(c);
        m = (u8 *)func_021C88A4(b, 0x29, c);
        m[0x4c] = c;
        func_021C8838(m + 4, 2, 0x302);
        func_021C8860(m + 4, c);
        func_021C8860(m + 4, v);
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x37, c);
        *(u16 *)(m + 4) = (func_021D70A8(a) == 0x171) ? 0x283 : 0x284;
        m[6] = func_021C8010(b, c);
        m[7] = 6;
        *(u32 *)m |= 1 << 24;
        func_021C88C8(b, m);
    }
}

int *func_021E5A28(int *p)
{
    *p = 1;
    return d_021F258C;
}
