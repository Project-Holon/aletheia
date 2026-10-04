/*
 * function: func_021BF658
 * address: 0x021BF658
 * packet: pkt_ov210_021BF658
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BFB8C 0x021BFB8C thumb ov210
 */
#include "../include/Obj25628.h"
extern int func_021B93B8(char *);
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BFB8C(char *, unsigned short, short, int);
void func_021BF658(char *p)
{
    short base = func_021B93B8(*(char * *)&((struct Obj25628 *)p)->f1E0);
    short i;
    for (i = 0; i < 14; i++) {
        func_021BEDF0((int)p, i + 15, 0);
        func_021BEDF0((int)p, i + 29, 0);
        func_021BEDF0((int)p, i + 43, 0);
    }
    for (i = 0; i < 5; i++) {
        func_021BFB8C(p, base + i, i * 40, 1);
        if (base - (i + 1) >= 0)
            func_021BFB8C(p, base - (i + 1), 192 - (i + 1) * 40, 0);
    }
}
