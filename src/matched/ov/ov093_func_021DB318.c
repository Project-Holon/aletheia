/*
 * function: func_021DB318
 * address:  0x021DB318
 * packet:   pkt_ov093_021DB318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct QF;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);

void func_021DB318(int unused, void *a, int id)
{
    u8 *r;
    void *m;

    m = func_021C7CF4(a, id);
    if (func_021D5444(m) == 0x15f && func_021D59B4(m, 0x13) != 0) {
        r = (u8 *)func_021C88A4(a, 0x39, id);
        r[4] = id;
        r[5] = 0;
        func_021C8838(r + 8, 2, 0xde);
        func_021C8860(r + 8, id);
        func_021C88C8(a, r);
    }
}
