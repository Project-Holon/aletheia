/*
 * function: func_021DA9F8
 * address: 0x021DA9F8
 * packet: pkt_ov121_021DA9F8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj05358.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Obj;
extern void BMP_OAM_UploadChars(struct Obj *o);
int func_021DA9F8(u8 *p) { if(((struct Obj05358 *)p)->f8) { if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj05358 *)p)->f20),(void *)(((struct Obj05358 *)p)->f0))==0) { BMP_OAM_UploadChars(((struct Obj05358 *)p)->f1C); ((struct Obj05358 *)p)->f8=0; } } if(((struct Obj05358 *)p)->f8==0) return 1; return 0; }
