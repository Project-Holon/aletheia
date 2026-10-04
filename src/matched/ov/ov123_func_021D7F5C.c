/*
 * function: func_021D7F5C
 * address: 0x021D7F5C
 * packet: pkt_ov123_021D7F5C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D7F9A follow the return.
 */
#include "../include/Obj13991.h"
typedef unsigned short u16;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
int func_021D7F5C(char *p)
{
    int i, j;
    char *q;
    func_02009448(((struct Obj13991 *)p)->f28);
    q = *(char * *)&((struct Obj13991 *)p)->f20 + 0xc;
    for (i = 0; i < 20; i++) {
        for (j = i + 1; j < 20; j++) {
            if (*(u16 *)(q + i * 2 + 8) != 0 &&
                *(u16 *)(q + j * 2 + 8) == *(u16 *)(q + i * 2 + 8))
                return 0;
        }
    }
    return 1;
}
