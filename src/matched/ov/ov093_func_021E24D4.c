/*
 * function: func_021E24D4
 * address:  0x021E24D4
 * packet:   pkt_ov093_021E24D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 */

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5B68(void *m);
extern int func_021D62C4(void *m, int k);
extern void *func_021C88A4(void *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, unsigned v);
extern void func_021C88C8(void *a, void *b);
typedef unsigned short u16;
extern u16 func_021D70A8(void *p);
typedef unsigned char u8;
extern void func_021E03D8(u8 *a, int b);

void func_021E24D4(void *a, void *b, int c, int *d)
{
    void *v;
    char *p;

    if (c == func_021D775C(2) && d[6] != 0) {
        v = func_021C7CF4(b, c);
        if (func_021D5B68(v) == 0) {
            if (func_021D62C4(v, 0x19) == 0) {
                p = func_021C88A4(b, 4, c);
                func_021C8838(p + 4, 2, 0x2CE);
                func_021C8860(p + 4, c);
                func_021C88C8(b, p);
                func_021E03D8(v, func_021D70A8(a));
            } else {
                p = func_021C88A4(b, 4, c);
                func_021C8838(p + 4, 2, 0x2CB);
                func_021C8860(p + 4, c);
                func_021C88C8(b, p);
            }
        }
    }
}
