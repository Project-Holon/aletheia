/*
 * function: func_021B9788
 * address:  0x021B9788
 * packet:   pkt_ov099_021B9788
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   KEY_GetTrg  0x020362DC  arm
 *   func_021B9CF8  0x021B9CF8  thumb  ov099
 *   func_021BA1FC  0x021BA1FC  thumb  ov099
 */
#include "../include/Obj13676.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021C49A4(u8 *p, unsigned int i);
extern u32 KEY_GetTrg(void);
extern void *func_021B9CF8(char *p, u32 *q, int c);
extern int func_021BA1FC(int *a);

int func_021B9788(int a, int *b)
{
    int v;
    int c;
    int *r;

    c = func_021C49A4((u8 *)b[0], 6);
    if (KEY_GetTrg() & 1) {
        r = func_021B9CF8((char *)a, (u32 *)b, c);
        if (r != 0) {
            if (func_021BA1FC(r) == 1)
                v = func_021C49A4((u8 *)r[0], 4);
            else
                v = 0;
        } else
            v = 0;
        ((struct Obj13676 *)b)->fA = v;
    }
    return 1;
}
