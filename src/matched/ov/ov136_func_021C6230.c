/*
 * function: MB_SEQ_StartMessagePrint
 * address: 0x021C6230
 * packet: pkt_ov136_021C6230
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MB_SEQ_StartMessagePrint 0x021C6230 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 */
#include "../include/Obj00127.h"
#include "../include/Obj23559.h"
#include "../include/Obj23560.h"
#include "../include/Obj23561.h"
#include "../include/Obj23562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);

void MB_SEQ_StartMessagePrint(u8 *p)
{
    u32 win = ((struct Obj23559 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->fA8;
    u32 w2;
    w2 = (u32)BMP_WIN_GetBmp((struct Descriptor *)win);
    BMP_Clear((struct CharBuf *)w2, 0xf);
    ((struct Obj23562 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1C8 = PRINTSYS_PrintStream(win, 0, 0, ((struct Obj23560 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8, ((struct Obj00127 *)p)->f18, func_02012FFC(), ((struct Obj23561 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1CC, 0, 0x66, 0xf);
}
