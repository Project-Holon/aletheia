/*
 * function: BTL_SERVER_Update
 * address:  0x021BAB9C
 * packet:   pkt_ov093_021BAB9C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 *   BTL_SERVER_AreRepliesReady  0x021BB798  thumb  ov093
 */
#include "../include/Obj07750.h"

typedef unsigned char  u8;
extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(unsigned char *p);

int BTL_SERVER_Update(int a)
{
    char *p = (char *)a;
    if (((struct Obj07750 *)p)->fED != 2) {
        int (*fp)(int, int) = *(int (**)(int, int))p;
        if (fp(a, a + 4) != 0) {
            BTL_SERVER_SendCommandData((u8 *)a, 9, ((struct Obj07750 *)p)->fB0, 8);
            ((struct Obj07750 *)p)->fED = 2;
        }
    } else {
        if (BTL_SERVER_AreRepliesReady((unsigned char *)p) != 0)
            return 1;
    }
    return 0;
}
