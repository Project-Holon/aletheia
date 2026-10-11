/*
 * function: func_0689C364
 * address:  0x0689C364
 * packet:   pkt_ov095_0689C364
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The handed address 0x0689C366 is the second label after the `push {r0-r3}`
 * at 0x0689C364; the function is filed from the push.
 *
 * symbols:
 *   func_021C8810  0x021C8810  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021E8B80  0x021E8B80  thumb
 *   func_0689C284   0x0689C284  thumb  ov095
 */

typedef unsigned short u16;
typedef struct Word { int v; } Word;

extern int func_0689C284(int, Word);
extern void func_021C8838(void *, int, u16);
extern int func_021D5440(void *);
extern void func_021C8860(void *, int);
extern int func_021E8B80(Word);
extern void func_021C8810(void *);

void func_0689C364(int a, Word b, void *c, void *d)
{
    int k;

    k = func_0689C284(a, b);
    if (k >= 0) {
        func_021C8838(d, 2, k);
        func_021C8860(d, func_021D5440(c));
        if (a == 8 || a == 13)
            func_021C8860(d, func_021E8B80(b));
    } else {
        func_021C8810(d);
    }
}
