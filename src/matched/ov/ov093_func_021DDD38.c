/*
 * function: func_021DDD38
 * address:  0x021DDD38
 * packet:   pkt_ov093_021DDD38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021E85F8(int id);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, u32 v);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);

void func_021DDD38(void *a, u8 *b, int c, int *d)
{
    u8 *p;
    if (*d != 0 && func_021E85F8(c) != 0) {
        p = func_021C88A4(b, 0x23, c);
        func_021C8838(p + 8, 2, 219);
        func_021C8860(p + 8, c);
        func_021C8860(p + 8, func_021D70A8(a));
        func_021C88C8(b, p);
    }
}
