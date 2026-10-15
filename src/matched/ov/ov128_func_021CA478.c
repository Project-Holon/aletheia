/*
 * function: WF2DMAP_TOUCH_UpdateSlots
 * address: 0x021CA478
 * packet: pkt_ov128_021CA478
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj06477.h"
#include "../include/Obj08135.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Descriptor;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void WF2DMAP_TOUCH_UpdateSlots(char *p) {u32 i;char *q;void *v;for(i=0;i<64;i++){q=*(char **)(p+i*4+56);if(!q)break;v=((struct Obj06477 *)p)->f34;if(((struct Obj08135 *)q)->f4) {if(!PRINTSYS_QUE_IsExistTarget(v,BMP_WIN_GetBmp(((struct Obj08135 *)q)->f0))) {BMP_WIN_TransferChars(((struct Obj08135 *)q)->f0);((struct Obj08135 *)q)->f4=0;}}}}
