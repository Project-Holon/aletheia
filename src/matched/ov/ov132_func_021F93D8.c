/*
 * function: STA_ACTING_PrintText
 * address: 0x021F93D8
 * packet: pkt_ov132_021F93D8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
#include "../include/Obj00832.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ZERO } Zero;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *PRINTSYS_PrintStream(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void STA_ACTING_PrintText(u8 *p, u16 index, u32 speed)
{
    Zero zero;
    if (((struct Obj00832 *)p)->fD8) {
        PRINTSYS_PrintStreamDelete(((struct Obj00832 *)p)->fD8);
        ((struct Obj00832 *)p)->fD8 = 0;
    }
    if (((struct Obj00832 *)p)->fE0) {
        STRBUF_Delete(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00832 *)p)->fD0), 0);
    zero = ZERO;
    ((struct Obj00832 *)p)->fE0 = func_02045EC0(((struct Obj00832 *)p)->fDC, index);
    if (speed != 255) {
        ((struct Obj00832 *)p)->fD8 = PRINTSYS_PrintStream(((struct Obj00832 *)p)->fD0, zero, zero,
            ((struct Obj00832 *)p)->fE0, ((struct Obj00832 *)p)->fD4, speed,
            ((struct Obj00832 *)p)->fCC, 2, ((struct Obj00832 *)p)->f0, zero);
    } else {
        PRINTSYS_PrintQue(((struct Obj00832 *)p)->fE8, (u32)BMP_WIN_GetBmp(((struct Obj00832 *)p)->fD0),
            zero, zero, ((struct Obj00832 *)p)->fE0, *(u32 *)&((struct Obj00832 *)p)->fD4);
        ((struct Obj00832 *)p)->fE4 = 1;
        STRBUF_Delete(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = (void *)zero;
    }
}
