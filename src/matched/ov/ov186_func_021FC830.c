/*
 * function: BR_UTIL_FlushText
 * address: 0x021FC830
 * packet: pkt_ov186_021FC830
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj05502.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
int BR_UTIL_FlushText(u8*p){void*owner=*(void* *)&((struct Obj05502 *)p)->f8;if(p[4]){if(!PRINTSYS_QUE_IsExistTarget(owner,BMP_WIN_GetBmp(*(void* *)&((struct Obj05502 *)p)->f0))){BMP_WIN_TransferChars(*(void* *)&((struct Obj05502 *)p)->f0);p[4]=0;}}if(!p[4])return 1;return 0;}
