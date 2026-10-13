/*
 * function: P_STA_SUB_PetHop
 * address: 0x021D7248
 * packet: pkt_ov131_021D7248
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   P_STA_SUB_SetPetOffset 0x021D79A8 thumb ov131
 *   MCSS_SetOfsPosition  0x02015C78  thumb  arm9
 */
#include "../include/Obj05388.h"
#include "../include/Obj23139.h"
typedef struct {int x,y,z;} Vec;
extern const short FX_SinCosTable_[];
extern void P_STA_SUB_SetPetOffset(void *p, unsigned char *q, int radius);
typedef unsigned int   u32;
extern void MCSS_SetOfsPosition(void *p, u32 *src);
int P_STA_SUB_PetHop(unsigned char *p,unsigned char *q) {
 Vec v={0,0,0};
 int s;
 unsigned n;
 float f;
 if(((struct Obj05388 *)q)->f10==0) {
 s=FX_SinCosTable_[((unsigned short)((((struct Obj05388 *)q)->f62<<15)/20)>>4)*2];
 n=((struct Obj23139 *)p)->f3C>>6;
 if(n) f=0.5f+(float)(n<<12); else f=(float)(n<<12)-0.5f;
 v.y=(s<<5)+(int)f;
 P_STA_SUB_SetPetOffset(p,q,v.y);
 }
 MCSS_SetOfsPosition(((struct Obj05388 *)q)->f0,(u32 *)(&v));
 ++((struct Obj05388 *)q)->f62;
 if(((struct Obj05388 *)q)->f62>20) {((struct Obj05388 *)q)->f62=0;return 1;}
 return 0;
}
