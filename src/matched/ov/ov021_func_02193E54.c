/*
 * function: func_02193E54
 * address:  0x02193E54
 * packet:   pkt_ov021_02193E54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218609C  0x0218609C  thumb  ov020
 *   func_021860B8  0x021860B8  thumb  ov020
 *   func_02193FD4  0x02193FD4  thumb  ov021
 */
#include "../include/Obj07441.h"
#include "../include/Obj12617.h"

typedef unsigned short u16;
extern void func_0218609C(char *p);
extern void func_021860B8(char *p);
extern void func_02193FD4(u16 *a, void *b);

void func_02193E54(unsigned char *p, unsigned char *q)
{
    int i;

    ((struct Obj12617 *)q)->f0 = 1;
    ((struct Obj12617 *)q)->f2 = p[0];
    if (p[1] == 0) {
        func_0218609C((char *)q);
        q += 8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    } else {
        func_021860B8((char *)q);
        q += 0xf8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    }
}
