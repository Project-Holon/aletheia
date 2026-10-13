/*
 * function: BTL_SICK_BuildCureMessage
 * address:  0x0689C364
 * packet:   pkt_ov095_0689C364
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed address 0x0689C366 is the second label after the `push {r0-r3}`
 * at 0x0689C364; the function is filed from the push.
 *
 * symbols:
 *   BTL_SICK_GetCureStringId   0x0689C284  thumb  ov095
 *   func_0689C3C4   0x0689C3C4  thumb  ov095
 *   func_0689C3D4   0x0689C3D4  thumb  ov095
 *   func_0689C3E4   0x0689C3E4  thumb  ov095
 *   func_0689C3F4   0x0689C3F4  thumb  ov095
 *   func_0689C404   0x0689C404  thumb  ov095
 *   func_0689C414   0x0689C414  thumb  ov095
 */

typedef unsigned short u16;
typedef struct Word { int v; } Word;

extern int BTL_SICK_GetCureStringId(int, Word);
extern void func_0689C3C4(void *, int, u16);
extern int func_0689C3D4(void *);
extern void func_0689C3E4(void *, int);
extern int func_0689C3F4(Word);
extern void func_0689C404(void *, int);
extern void func_0689C414(void *);

void BTL_SICK_BuildCureMessage(int a, Word b, void *c, void *d)
{
    int k;

    k = BTL_SICK_GetCureStringId(a, b);
    if (k >= 0) {
        func_0689C3C4(d, 2, k);
        func_0689C3E4(d, func_0689C3D4(c));
        if (a == 8 || a == 13)
            func_0689C404(d, func_0689C3F4(b));
    } else {
        func_0689C414(d);
    }
}
