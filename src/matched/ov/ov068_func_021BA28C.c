/*
 * function: OPTION_MENU_PrintTextFromBank
 * address:  0x021BA28C
 * packet:   pkt_ov068_021BA28C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 */
#include "../include/Obj00884.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct Rec3;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32  PRINTSYS_PrintStream(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                          u32 a7, u16 a8, u16 a9);

void OPTION_MENU_PrintTextFromBank(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 t;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00884 *)p)->f10)), (u8)((struct Obj00884 *)p)->f18);
    MSGDATA_ReadString((struct MsgBank *)a1, a2, (void *)(((struct Obj00884 *)p)->f14));
    if (((struct Obj00884 *)p)->f8 != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj00884 *)p)->f8));
        ((struct Obj00884 *)p)->f8 = 0;
    }
    if (a4 == 0) {
        t = ((struct Obj00884 *)p)->f24;
        PRINTSYS_PrintQue((struct PrintSys *)t, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00884 *)p)->f1C), 0, 0,
                      (void *)(((struct Obj00884 *)p)->f14), ((struct Obj00884 *)p)->f4);
        p[0x20] = 1;
        ((struct Obj00884 *)p)->f28 = 2;
        return;
    }
    ((struct Obj00884 *)p)->f8 = PRINTSYS_PrintStream(((struct Obj00884 *)p)->f10, 0, 0, ((struct Obj00884 *)p)->f14,
                                    ((struct Obj00884 *)p)->f4, a3, ((struct Obj00884 *)p)->fC, 0,
                                    ((struct Obj00884 *)p)->f1A, ((struct Obj00884 *)p)->f18);
    ((struct Obj00884 *)p)->f28 = 1;
}
