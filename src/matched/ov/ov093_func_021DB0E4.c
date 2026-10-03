/*
 * function: func_021DB0E4
 * address:  0x021DB0E4
 * packet:   pkt_ov093_021DB0E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E889C  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021E889C(int u, void *a, int id);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C888C(u8 *p, u32 v);

void func_021DB0E4(int unused, void *a, int id)
{
    u8 *r;

    if (func_021E889C(unused, a, id) != 0) {
        r = (u8 *)func_021C88A4(a, 4, id);
        *(u32 *)r |= 0x800000;
        func_021C8838(r + 4, 1, 0x48);
        func_021C888C(r + 4, 0x56a);
        func_021C88C8(a, r);
    }
}
