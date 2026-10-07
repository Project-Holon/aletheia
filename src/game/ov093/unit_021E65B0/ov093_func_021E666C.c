/*
 * function: func_021E666C
 * address:  0x021E666C
 * packet:   pkt_ov093_021E666C
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
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E666C(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(3)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x344);
        func_021C8860((struct S *)(m + 4), c);
        func_021C88C8(b, m);
    }
}
