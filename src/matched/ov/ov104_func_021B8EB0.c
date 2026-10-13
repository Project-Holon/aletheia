/*
 * function: IRC_RHYTHM_UpdatePulse
 * address: 0x021B8EB0
 * packet: pkt_ov104_021B8EB0
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RHYTHM_BlendPaletteEntry 0x021B89DC thumb ov104
 */
#include "../include/Obj04434.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int     s32;
extern s32 IRC_RHYTHM_BlendPaletteEntry(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
void IRC_RHYTHM_UpdatePulse(u8 *p) {
 int a;
 if(((struct Obj04434 *)p)->fC && ((struct Obj04434 *)p)->f4) {
  a=((struct Obj04434 *)p)->f2+0x400;
  if(a>=0x10000) ((struct Obj04434 *)p)->f2=((struct Obj04434 *)p)->f2-0xfc00;
  else ((struct Obj04434 *)p)->f2=a;
  IRC_RHYTHM_BlendPaletteEntry(15,(u16 *)p,((struct Obj04434 *)p)->f2,5,3,0x6adf,0x55fe);
 }
}
