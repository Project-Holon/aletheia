/*
 * function: func_021E25FC
 * address:  0x021E25FC
 * packet:   pkt_ov093_021E25FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E896C  0x021E896C  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Word { unsigned int v; } Word;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D62C4(void *m, int k);
extern void *func_021C88A4(void *p, int a, int b);
extern u16 func_021D70A8(void *p);
extern Word func_021E896C(int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E25FC(void *a, void *b, int c, int *d)
{
    void *v;
    int *p;

    if (c == func_021D775C(2)) {
        v = func_021C7CF4(b, c);
        if (func_021D62C4(v, 0x19) == 0 && func_021D62C4(v, 2) == 0 && d[6] == 0) {
            p = func_021C88A4(b, 12, c);
            p[1] = 0x19;
            *(Word *)(p + 2) = func_021E896C(5, func_021D70A8(a));
            ((u8 *)p)[12] = 0;
            ((u8 *)p)[15] = c;
            func_021C88C8(b, p);
            d[0] = 0;
            d[1] = 5;
            d[6] = 1;
        }
    }
}
