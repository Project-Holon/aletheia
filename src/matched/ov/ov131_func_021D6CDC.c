/*
 * function: P_STA_SUB_FreeWindows
 * address: 0x021D6CDC
 * packet: pkt_ov131_021D6CDC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKEPARTY_SetSlotFlag 0x0201ACDC thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj10508.h"
#include "../include/Obj14066.h"
#include "../include/Obj14067.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void POKEPARTY_SetSlotFlag(void *p, u32 pos, u32 mode);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void P_STA_SUB_FreeWindows(unsigned char *a,unsigned char *b) {
 unsigned char *q=*(unsigned char * *)&((struct Obj14066 *)a)->f8;
 if(q[12]==1) POKEPARTY_SetSlotFlag(((struct Obj14067 *)q)->f0,a[0x1a],(u32)(((struct Obj10508 *)b)->fC));
 BMP_WIN_Delete(((struct Obj10508 *)b)->f1C);
 BMP_WIN_Delete(((struct Obj10508 *)b)->f18);
}
