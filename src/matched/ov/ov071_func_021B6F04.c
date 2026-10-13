/*
 * function: MONOLITH_TOOL_UpdateLabel
 * address: 0x021B6F04
 * packet: pkt_ov071_021B6F04
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj06183.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Obj;
extern void BMP_OAM_UploadChars(struct Obj *o);
int MONOLITH_TOOL_UpdateLabel(void **p, u8 *q) { if(q[8]==1) { if(func_0201C6C4(p[2], (void *)(*(unsigned *)&((struct Obj06183 *)q)->f0))==0) { BMP_OAM_UploadChars(((struct Obj06183 *)q)->f4); q[8]=0; return 1; } } return 0; }
