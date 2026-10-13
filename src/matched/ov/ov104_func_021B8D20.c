/*
 * function: IRC_RHYTHM_UpdateParticle
 * address: 0x021B8D20
 * packet: pkt_ov104_021B8D20
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021B8DA2 before 021B8DA4.
 * lever: Declare delta before pos; multiply length by counter in that order.
 * symbols:
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj02453.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
extern void func_0207CA00(Vec *,Vec *,Vec *);
extern int func_0207CBD0(Vec *);
extern void VEC_Normalize(Vec *,Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void IRC_RHYTHM_UpdateParticle(u8 *p) {
 u16 xy[2]; Vec delta; Vec pos; int length;
 if(((struct Obj02453 *)p)->f8) {
  func_0207CA00((Vec *)(p+0x18),(Vec *)(p+0xc),&delta);
  length=func_0207CBD0(&delta); VEC_Normalize(&delta,&delta);
  func_0207CEE4((u32)(length * ((struct Obj02453 *)p)->f24)/ ((struct Obj02453 *)p)->f28,&delta,(Vec *)(p+0xc),&pos);
  xy[0]=pos.x>>12; xy[1]=pos.y>>12;
  if((((struct Obj02453 *)p)->f24)++ > ((struct Obj02453 *)p)->f28) {
   xy[0]=((struct Obj02453 *)p)->f18; xy[1]=((struct Obj02453 *)p)->f1C;
   CLACT_SetActorDrawEnable(((struct Obj02453 *)p)->f0,0); ((struct Obj02453 *)p)->f8=0;
  }
  CLACT_AddActorSurfacePos(((struct Obj02453 *)p)->f0,(const struct Vec2 *)xy,(u16)(((struct Obj02453 *)p)->f4));
 }
}
