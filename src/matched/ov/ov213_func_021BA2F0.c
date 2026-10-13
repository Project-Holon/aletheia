/*
 * function: func_021BA2F0
 * address: 0x021BA2F0
 * packet: pkt_ov213_021BA2F0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   func_021BA014 0x021BA014 thumb ov213
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj14694.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021BA014(u8 *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021BA2F0(u8 *p) {STRBUF_Delete((struct U16Vec *)(((struct Obj14694 *)p)->f18));func_021BA014(p+32);BMP_WIN_Delete((struct Descriptor *)(((struct Obj14694 *)p)->f1C));}
