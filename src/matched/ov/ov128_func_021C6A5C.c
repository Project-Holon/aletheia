/*
 * function: func_021C6A5C
 * address: 0x021C6A5C
 * packet: pkt_ov128_021C6A5C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021C6A5C(u8 *p) { STRBUF_Delete(((struct Obj00725 *)p)->f1C);STRBUF_Delete(((struct Obj00725 *)p)->f20);STRBUF_Delete(((struct Obj00725 *)p)->f14);STRBUF_Delete(((struct Obj00725 *)p)->f18);BMP_WIN_Delete(((struct Obj00725 *)p)->fC);BMP_WIN_Exit(); }
