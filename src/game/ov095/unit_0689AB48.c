/*
 * file:     unit_0689AB48.c
 * function: func_0689AB48
 * address:  0x0689AB48
 * packet:   pkt_ov095_0689AB48
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0220270C  0x0220270C  thumb
 */
#include "../../matched/include/Obj21891.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 v;
    u8 b[4];
} E;

typedef struct {
    u32 a[3];
    u32 b[3][4];
} L;

extern void func_0220270C(u32 h, int k, L *l);

int func_0689AB48(int unused, u8 *s)
{
    L l;
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        l.a[i] = (*(E **)(s + 0x7c))[i].v;
        for (j = 0; j < 4; j++)
            l.b[i][j] = (*(E **)(s + 0x7c))[i].b[j];
    }
    func_0220270C(((struct Obj21891 *)s)->fB0, 5, &l);
    return 1;
}
