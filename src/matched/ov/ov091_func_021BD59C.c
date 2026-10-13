/*
 * function: PLIST_BATTLE_CreateTimerWindows
 * address:  0x021BD59C
 * packet:   pkt_ov091_021BD59C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */
#include "../include/Obj04353.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void PLIST_BATTLE_CreateTimerWindows(char *p)
{
    int s;
    ((struct Obj04353 *)p)->f1FC = BMP_WIN_Create(4, 7, 0x15, 0xB, 3, 0xE, 1);
    ((struct Obj04353 *)p)->f200 = BMP_WIN_Create(4, 0x14, 0x15, 5, 3, 0xE, 1);
    s = (int)func_02045EC0((struct MsgBank *)(((struct Obj04353 *)p)->f134), 0xAD);
    PRINTSYS_PrintQueColor((void *)(((struct Obj04353 *)p)->f140), (int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj04353 *)p)->f1FC), 0, 4, s,
                  ((struct Obj04353 *)p)->f138, 0x3C40);
    STRBUF_Delete((struct U16Vec *)s);
    ((struct Obj04353 *)p)->f204 = 1;
}
