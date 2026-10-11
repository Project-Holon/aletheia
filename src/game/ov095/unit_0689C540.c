/*
 * file:     unit_0689C540.c
 * function: func_0689C540
 * address:  0x0689C540
 * packet:   pkt_ov095_0689C540
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb
 *   func_021D6314  0x021D6314  thumb
 *   func_021D76BC  0x021D76BC  thumb
 *   func_021D775C  0x021D775C  thumb
 *   func_021E8B80  0x021E8B80  thumb
 *   func_021E8C24  0x021E8C24  thumb
 */

typedef unsigned char u8;

extern int func_021D62C4(void *, int);
typedef struct Word { int v; } Word;
extern Word func_021D6314(void *, int);
extern int func_021E8B80(void);
extern int func_021D775C(int);
extern int func_021E8C24(int);
extern void func_021D76BC(int, int);

void func_0689C540(void *a, void *b)
{
    int k;
    int v;
    u8 x;

    k = 0x11;
    if (func_021D62C4(b, k) != 0) {
        v = func_021D6314(b, k).v;
        x = func_021E8B80();
        if (x == (u8)func_021D775C(0x15)) {
            func_021D76BC(func_021E8C24(v) == 0 ? 0x4b : 0x4c, 1);
        }
    }
    if (func_021D62C4(b, 0x15) != 0) {
        if (func_021D775C(0x16) == 4)
            func_021D76BC(0x4b, 1);
    }
    if (func_021D62C4(b, 0x1f) != 0) {
        if (func_021D775C(0x16) == 4)
            func_021D76BC(0x4b, 1);
    }
}
