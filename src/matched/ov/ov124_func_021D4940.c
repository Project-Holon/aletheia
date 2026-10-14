/*
 * function: CG_HELP_DrawPageText
 * address: 0x021D4940
 * packet: pkt_ov124_021D4940
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D49C6 before next labelled function.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 */
#include "../include/Obj00068.h"
typedef short s16;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void CG_HELP_DrawPageText(char *p,int n)
{
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f24),1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f20),0);
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    PRINTSYS_PrintQueColor(((struct Obj00068 *)p)->f30,(u32)BMP_WIN_GetBmp(((struct Obj00068 *)p)->f24),40,8,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    STRBUF_Delete(q);
    n += 12;
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    PRINTSYS_PrintQueColor(((struct Obj00068 *)p)->f30,(u32)BMP_WIN_GetBmp(((struct Obj00068 *)p)->f20),0,0,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    STRBUF_Delete(q);
    ((struct Obj00068 *)p)->f1C = 1;
}
