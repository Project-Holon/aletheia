/*
 * function: GURU2_MAIN_CountActiveMembers
 * address: 0x021E17EC
 * packet: pkt_ov137_021E17EC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj03304.h"
#include "../include/Obj23809.h"
typedef signed short s16;
int GURU2_MAIN_CountActiveMembers(char *p)
{
    int count = 0;
    unsigned bits = ((struct Obj23809 *)(*(char * *)&((struct Obj03304 *)p)->fDC))->f46;
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}
