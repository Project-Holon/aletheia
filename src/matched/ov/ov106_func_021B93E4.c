/*
 * function: func_021B93E4
 * address: 0x021B93E4
 * packet: pkt_ov106_021B93E4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj05282.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v); extern void BMP_OAM_UploadChars(void *);
int func_021B93E4(u8 *p) { if(((struct Obj05282 *)p)->f8 && !func_0201C6C4(((struct Obj05282 *)p)->f20,((struct Obj05282 *)p)->f0)){BMP_OAM_UploadChars(((struct Obj05282 *)p)->f1C);((struct Obj05282 *)p)->f8=0;} if(!((struct Obj05282 *)p)->f8)return 1; return 0; }
