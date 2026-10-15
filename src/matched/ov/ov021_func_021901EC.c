/*
 * function: FIELD_MSGBG_Create
 * address:  0x021901EC
 * packet:   pkt_ov021_021901EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   FIELD_MSGBG_KeyWaitInit  0x021931F4  thumb
 *   d_021DDA50  0x021DDA50  data  ov021  a4
 *   TCBL_Create  0x0203101C  arm  arm9
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm  arm9
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm  arm9
 */
#include "../include/Obj01849.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021DDA50[];
struct GfFont;
struct NitroFileHeader;
struct Tcbl;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void FIELD_MSGBG_KeyWaitInit(u32 a);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);

u8 *FIELD_MSGBG_Create(u16 heap, u32 b)
{
    u8 *o = func_02030734(heap, 0x17c, 1, d_021DDA50, 0x1a4);
    ((struct Obj01849 *)o)->f0 = heap;
    ((struct Obj01849 *)o)->f2 = 0xff;
    ((struct Obj01849 *)o)->f4 = 0xff;
    ((struct Obj01849 *)o)->f168 = b;
    ((struct Obj01849 *)o)->f8 = (u32)GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj01849 *)o)->f0);
    ((struct Obj01849 *)o)->fC = PRINTSYS_QUE_Create((void *)(((struct Obj01849 *)o)->f0));
    ((struct Obj01849 *)o)->f164 = (u32)TCBL_Create(((struct Obj01849 *)o)->f0, ((struct Obj01849 *)o)->f0, 1, 4);
    FIELD_MSGBG_KeyWaitInit((u32)(o + 0x160));
    ((struct Obj01849 *)o)->f174 = ARC_UTIL_LoadMember(5, 0xc, 0, heap);
    NNS_G2dGetUnpackedCharacterDataEx((struct NitroFileHeader *)(((struct Obj01849 *)o)->f174), (void **)(o + 0x178));
    return o;
}
