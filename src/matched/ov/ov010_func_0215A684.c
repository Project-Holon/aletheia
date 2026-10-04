/*
 * unit:     yes
 * function: func_0215A684
 * address:  0x0215A684
 * packet:   pkt_ov010_0215A684
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00005.h"

#define W(p) (*(int *)((char *)(p)))
#define S(p, o) (*(unsigned short *)((char *)(*(int *)((char *)(p) + 0x20)) + (o)))
#define I(p, o) (*(int *)((char *)(*(int *)((char *)(p) + 0x20)) + (o)))

void func_0215A684(int *p, unsigned short v)
{
    S(p, 0x106) = v;
}

int func_0215A690(int *p)
{
    unsigned short *q = &S(p, 0x106);
    if (*q == 0) {
        return 1;
    }
    *q = *q - 1;
    return 0;
}

int func_0215A6AC(int *p)
{
    return I(p, 0x108);
}

void func_0215A6B8(int *p, int v)
{
    I(p, 0x108) = v;
}

int func_0215A6C4(int *p)
{
    return I(p, 0x10c);
}

void func_0215A6D0(int *p, int v)
{
    I(p, 0x10c) = v;
}

void func_0215A6DC(int *p, int v)
{
    int i;
    char *q = (char *)*(int *)&((struct Obj00005 *)p)->f20;
    for (i = 0; i < 8; i++) {
        int *e = (int *)(q + i * 4);
        if (e[5] == 0) {
            e[5] = v;
            return;
        }
    }
}
