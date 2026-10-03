/*
 * function: func_021DEA8C
 * address:  0x021DEA8C
 * packet:   pkt_ov093_021DEA8C
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
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern u16 func_021D70A8(void *p);

void func_021DEA8C(int a, void *b, int c, int *d)
{
    u8 *r;

    if (c == func_021D775C(2) && *d != 0) {
        r = (u8 *)func_021C88A4(b, 0x23, c);
        func_021C8838(r + 8, 2, 0x3ef);
        func_021C8860(r + 8, c);
        func_021C8860(r + 8, func_021D70A8((void *)a));
        func_021C88C8(b, r);
        *d = 0;
    }
}
