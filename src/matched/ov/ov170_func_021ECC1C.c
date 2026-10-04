/*
 * function: func_021ECC1C
 * address:  0x021ECC1C
 * packet:   pkt_ov170_021ECC1C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021ED310 0x021ED310 thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 */
#include "../include/Obj00000.h"

typedef struct {
    int pad[9];
    int x24;
} Top;

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021ED310(char *w);
extern void func_021ED588(unsigned char *p);
extern void func_021ED7C4(char *w, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021ECC1C(unsigned char *p)
{
    short xy[2];
    int k;
    if (p[0x18] == 0)
        return;
    func_021EC0B0(WORK(p), 4, &xy[1], &xy[0], 0);
    if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3) {
        k = 0xA;
        xy[0] += 8;
    } else {
        k = *(unsigned char *)(WORK(p) + 0x3DF6);
        xy[0] += 4;
    }
    func_021EC08C(WORK(p), k, xy[1], xy[0], 0);
    if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3) {
        func_021ED310(WORK(p));
        return;
    }
    if (*(void **)(WORK(p) + 0x9FD4) == 0)
        func_021ED588(p);
    func_021ED7C4(WORK(p), 0x24);
}
