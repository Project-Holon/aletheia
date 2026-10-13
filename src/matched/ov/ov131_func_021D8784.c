/*
 * function: P_STA_INFO_GetPlaceName
 * address: 0x021D8784
 * packet: pkt_ov131_021D8784
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: arm9 witnesses func_0202F688 / func_0202F6D8 filed (unlabelled Thumb
 *   leaves); 92-byte listing extent includes 2 bytes of alignment padding.
 * symbols:
 *   func_0202F688 0x0202F688 thumb
 *   func_0202F6D8 0x0202F6D8 thumb
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../include/Obj01547.h"

extern unsigned int func_0202F688(unsigned int);
extern unsigned int func_0202F6D8(unsigned int);
typedef unsigned int   u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void P_STA_INFO_GetPlaceName(void *a, unsigned char *p, unsigned int n)
{
    unsigned int bank = func_0202F688(n);
    unsigned int index = func_0202F6D8(n);
    switch (bank) {
    case 89: func_02045EC0(((struct Obj01547 *)p)->f3C, index); break;
    case 92: func_02045EC0(((struct Obj01547 *)p)->f40, index); break;
    case 90: func_02045EC0(((struct Obj01547 *)p)->f44, index); break;
    case 91: func_02045EC0(((struct Obj01547 *)p)->f48, index); break;
    default: func_02045EC0(((struct Obj01547 *)p)->f3C, 0); break;
    }
}
