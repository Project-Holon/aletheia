/*
 * function: PMSIV_WORDWIN_Setup
 * address: 0x021BF8F4
 * packet: pkt_ov110_021BF8F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_InitRun 0x02040B94 arm
 *   func_02041300 0x02041300 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   PMSIV_WORDWIN_CreateActors 0x021BF94C thumb ov110
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj01145.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void func_020409B4(u32);
extern void PMSIV_WORDWIN_CreateActors(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
void PMSIV_WORDWIN_Setup(u8 *p) {
    BG_SYS_InitRun(2,32,0,42);
    func_02041300(2,0,0,0,32,32,13);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01145 *)p)->fC),0);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj01145 *)p)->fC));
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01145 *)p)->fC);
    func_020409B4(2); PMSIV_WORDWIN_CreateActors(p); func_02040588(2,0);
}
