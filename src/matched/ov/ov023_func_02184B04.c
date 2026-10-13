/*
 * function: OEKAKI_FreeWork
 * address: 0x02184B04
 * packet: pkt_ov023_02184B04
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj09768.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void OEKAKI_FreeWork(char *p)
{
    int i;
    func_020307B0(((struct Obj09768 *)p)->f4288);
    for (i = 0; i < 5; i++)
        STRBUF_Delete(*(void **)(p + 0x18 + i * 4));
    STRBUF_Delete(((struct Obj09768 *)p)->f30);
    STRBUF_Delete(((struct Obj09768 *)p)->f2C);
}
