/*
 * function: BTL_MAIN_CheckOwnWindowDone
 * address: 0x021BA618
 * packet: pkt_ov093_021BA618
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_IsWindowDone 0x021CDDCC thumb ov093
 */
#include "../include/Obj09944.h"
#include "../include/Obj21017.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Flags;
extern u32 BTL_CLIENT_IsWindowDone(struct Flags *p);
int BTL_MAIN_CheckOwnWindowDone(char *p)
{
    int v;
    if (((struct Obj21017 *)(*(char * *)&((struct Obj09944 *)p)->f0))->f23) {
        v = BTL_CLIENT_IsWindowDone(*(void **)(p + 0x10 + ((struct Obj09944 *)p)->f46C * 4));
        if (v) ((struct Obj09944 *)p)->f444 = 2;
        return v;
    }
    return 0;
}
