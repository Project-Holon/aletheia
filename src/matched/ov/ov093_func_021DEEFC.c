/*
 * function: func_021DEEFC
 * address:  0x021DEEFC
 * packet:   pkt_ov093_021DEEFC
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D70C8  0x021D70C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B48(u8 *p);
extern void func_021D70C8(int a);

void func_021DEEFC(int a, void *b, int c)
{
    u32 *r;

    if (c == func_021D775C(2)) {
        if (func_021D5B48(func_021C7CF4(b, c)) == 0) {
            r = (u32 *)func_021C88A4(b, 0, c);
            r[1] = (r[1] & ~1) | 1;
            func_021D70C8(a);
            func_021C88C8(b, r);
        }
    }
}
