/*
 * function: MYSTERY_CardViewAnimFade
 * address: 0x021D9138
 * packet: pkt_ov121_021D9138
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 */
#include "../include/Obj02833.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
void MYSTERY_CardViewAnimFade(u8 *p)
{
    switch(((struct Obj02833 *)p)->f20) {
    case 0: ((struct Obj02833 *)p)->f20=1; return;
    case 1:
        ((struct Obj02833 *)p)->f30=(((struct Obj02833 *)p)->f18*32767u)/60u;
        MYSTERY_UTIL_BlendPaletteRange((void *)15,(u16 *)(p+50),((struct Obj02833 *)p)->f30,0,(const u16 *)(p+146),(const u16 *)(p+114));
        MYSTERY_UTIL_BlendPaletteRange((void *)31,(u16 *)(p+82),((struct Obj02833 *)p)->f30,0,(const u16 *)(p+146),(const u16 *)(p+114));
        if((((struct Obj02833 *)p)->f18)++ >60) {
            ((struct Obj02833 *)p)->f18=0;
            ((struct Obj02833 *)p)->f20=2;
            return;
        }
        break;
    case 2: ((struct Obj02833 *)p)->f8=1; break;
    }
}
