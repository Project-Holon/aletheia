/*
 * function: func_021DF150
 * address:  0x021DF150
 * packet:   pkt_ov093_021DF150
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
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_0201BEB8(u16 id, u32 bit);

void func_021DF150(int a, void *b, int c)
{
    u8 t;
    u8 *r;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0) {
        if (func_0201BEB8(func_021D775C(0x12), 0) != 0) {
            t = func_021D775C(3);
            if (func_021D5B40(func_021C7CF4(b, t)) == 0) {
                r = (u8 *)func_021C88A4(b, 0x24, c);
                r[4] = t;
                func_021C88C8(b, r);
            }
        }
    }
}
