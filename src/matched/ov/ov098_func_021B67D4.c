/*
 * function: PDC_MSG_Create
 * address: 0x021B67D4
 * packet: pkt_ov098_021B67D4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02008374's three unused legacy trailing inputs omitted: full getter reads only r0, no forwarding; caller supplies no new values.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02045B38 0x02045B38 arm
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   MSG_SPEED_GetWaitForSpeed 0x02013080 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_020496E4 0x020496E4 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   PDC_MSG_InitBlend 0x021B6C34 thumb ov098
 *   gPdcMsgSrcName 0x021B6E74 data a4
 *   gPdcMsgBgTemplate 0x021B6E24 data a4
 */
#include "../include/Obj01704.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PalAnmSlot;
struct Cfg;
extern const char gPdcMsgSrcName[];
extern const struct BgTemplate gPdcMsgBgTemplate;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern u32 CONFIG_GetTextSpeed(int);
extern signed char MSG_SPEED_GetWaitForSpeed(u32);
extern struct U16Vec *STRBUF_Create(u32, u32);
extern struct WordSet *GF_FONT_Create_EC64(u32);
extern void BG_SYS_SetTileEntry(u32, int, int, int, u8, u8, u8);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern u32 func_020496E4(u32, u32, u32, u32, u32, u16);
extern int BTLV_EFFECT_GetPalanm(void);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16, u16);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void BMP_WIN_DrawFrame(struct Cfg *, u16, u32);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void PDC_MSG_InitBlend(char *, int);
u8 *PDC_MSG_Create(void *a, void *b, void *c, u32 heap)
{
    u8 *p;
    u32 idx;
    p = func_02030734(heap, 0x48, 1, gPdcMsgSrcName, 0x82);
    BG_SYS_InitBgLayer(1, &gPdcMsgBgTemplate, 0);
    ((struct Obj01704 *)p)->f44 = heap;
    ((struct Obj01704 *)p)->f28 = c;
    *(struct MsgBank * *)&((struct Obj01704 *)p)->f20 = func_02045B38(0, 2, 0x56, ((struct Obj01704 *)p)->f44);
    ((struct Obj01704 *)p)->f24 = a;
    ((struct Obj01704 *)p)->f34 = MSG_SPEED_GetWaitForSpeed(CONFIG_GetTextSpeed((int)b));
    *(struct U16Vec * *)&((struct Obj01704 *)p)->f2C = STRBUF_Create(0x100, heap);
    *(struct WordSet * *)&((struct Obj01704 *)p)->f30 = GF_FONT_Create_EC64(heap);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 32, 32, 17);
    BG_SYS_Init(1, 0, 1, 0);
    idx = func_020496E4(11, 89, 1, 0, 0, ((struct Obj01704 *)p)->f44);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 11, 90, ((struct Obj01704 *)p)->f44, 0, 32, 0, 0);
    *(u32 *)&((struct Obj01704 *)p)->f1C = BMP_WIN_Create(1, 1, 19, 30, 4, 0, 0);
    BMP_WIN_MakeScreen(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C);
    BMP_WIN_DrawFrame(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C, idx, 0);
    func_020409B4(1);
    func_02040588(1, 0);
    PDC_MSG_InitBlend((char *)p + 4, *(int *)&((struct Obj01704 *)p)->f1C);
    return p;
}
