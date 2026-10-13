/*
 * function: IRC_RANKING_RowExit
 * address: 0x021B89F4
 * packet: pkt_ov106_021B89F4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_Delete 0x020437AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj10254.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj020437AC;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void BMP_Delete(struct Obj020437AC *);
extern void MI_CpuFill8(void *,int,int);
void IRC_RANKING_RowExit(u8 *p) { int i; for(i=0;i<2;i++) CLACT_DeleteActor(*(void **)(p+8+i*4)); CLACT_ReleaseCharacter(((struct Obj10254 *)p)->f14); CLACT_ReleaseCellAnim(((struct Obj10254 *)p)->f18); BMP_Delete(*(struct Obj020437AC * *)&((struct Obj10254 *)p)->f4); MI_CpuFill8(p,0,32); }
