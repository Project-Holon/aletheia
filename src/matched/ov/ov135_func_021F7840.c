/*
 * function: WORLDTRADE_DEPOSIT_DeleteWindows
 * address: 0x021F7840
 * packet: pkt_ov135_021F7840
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj14162.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void WORLDTRADE_DEPOSIT_DeleteWindows(char *p) { int i; WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p+0xfa0)); BMP_WIN_Delete(((struct Obj14162 *)p)->fDE0); for(i=0;i<6;i++) BMP_WIN_Delete(*(void **)((u32)p+(u32)i*4+0xd90)); BMP_WIN_Delete(((struct Obj14162 *)p)->fD40); }
