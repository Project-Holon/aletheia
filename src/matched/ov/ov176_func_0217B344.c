/*
 * function: func_0217B344
 * address: 0x0217B344
 * packet: pkt_ov176_0217B344
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14356.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E8A78(void *);
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);
void func_0217B344(int *p) {func_021E8A78(((struct Obj14356 *)p)->f0);MSGDATA_Delete(((struct Obj14356 *)p)->fC);func_020307B0(p);}
