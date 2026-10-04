/*
 * function: func_0217546C
 * address:  0x0217546C
 * packet:   pkt_ov011_0217546C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021754B4  0x021754B4  thumb ov011
 *   func_020120D8  0x020120D8  thumb
 *   func_0217538C  0x0217538C  thumb ov011
 *   func_0217545C  0x0217545C  thumb ov011
 */
#include "../include/Obj00566.h"

typedef unsigned char u8;

int func_021754B4(u8 *p, u8 *out);
int func_020120D8(char *p);
void func_0217538C(u8 *p, int a);
void func_0217545C(u8 *p);

void func_0217546C(u8 *p)
{
    u8 buf[4];
    u8 *q;
    int i;

    if (func_021754B4(p, buf) == 1 && func_020120D8((char *)((struct Obj00566 *)p)->f0) == 1) {
        q = p + 0x945;
        i = p[0x154];
        if (q[i] == 0) {
            q[i] = p[0x158];
        }
        func_0217538C(p, 4);
        func_0217545C(p);
    }
}
