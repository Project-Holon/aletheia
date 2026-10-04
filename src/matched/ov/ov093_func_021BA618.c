/*
 * function: func_021BA618
 * address: 0x021BA618
 * packet: pkt_ov093_021BA618
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CDDCC 0x021CDDCC thumb ov093
 */
#include "../include/Obj09944.h"
#include "../include/Obj21017.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Flags;
extern u32 func_021CDDCC(struct Flags *p);
int func_021BA618(char *p)
{
    int v;
    if (((struct Obj21017 *)(*(char * *)&((struct Obj09944 *)p)->f0))->f23) {
        v = func_021CDDCC(*(void **)(p + 0x10 + ((struct Obj09944 *)p)->f46C * 4));
        if (v) ((struct Obj09944 *)p)->f444 = 2;
        return v;
    }
    return 0;
}
