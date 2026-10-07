/*
 * function: func_021789C8
 * address:  0x021789C8
 * packet:   pkt_ov014_021789C8
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178A18  0x02178A18  thumb  ov014
 *   func_0208F84C  0x0208F84C  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;
void func_02178138(int a);
void func_0217814C(int a);
void func_02178A18(u8 *m);
int func_0208F84C(void *cb, void *a, void *b, int c, int d);

int func_021789C8(void)
{
    int r;

    if (*(u32 *)(((u8 *)g_021797A8) + 0x1E70) - 4 <= 1)
        return 1;
    func_02178138(3);
    r = func_0208F84C((void *)func_02178A18, ((u8 *)g_021797A8) + 0xF40, ((u8 *)g_021797A8) + 0x1EC4, 1, 0);
    if (r != 2) {
        func_0217814C(r);
        return 0;
    }
    return 1;
}
