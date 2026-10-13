/*
 * function: func_021B67D4
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
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02045B38 0x02045B38 arm
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   func_02013080 0x02013080 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020496E4 0x020496E4 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_021B6C34 0x021B6C34 thumb ov098
 *   d_021B6E74 0x021B6E74 data a4
 *   d_021B6E24 0x021B6E24 data a4
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
extern const char d_021B6E74[];
extern const struct BgTemplate d_021B6E24;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern u32 CONFIG_GetTextSpeed(int);
extern signed char func_02013080(u32);
extern struct U16Vec *func_020457B0(u32, u32);
extern struct WordSet *func_0201EC64(u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_020496E4(u32, u32, u32, u32, u32, u16);
extern int func_021F86E0(void);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02045374(struct Cfg *);
extern void BMP_WIN_DrawFrame(struct Cfg *, u16, u32);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B6C34(char *, int);
u8 *func_021B67D4(void *a, void *b, void *c, u32 heap)
{
    u8 *p;
    u32 idx;
    p = func_02030734(heap, 0x48, 1, d_021B6E74, 0x82);
    func_0203FCA0(1, &d_021B6E24, 0);
    ((struct Obj01704 *)p)->f44 = heap;
    ((struct Obj01704 *)p)->f28 = c;
    *(struct MsgBank * *)&((struct Obj01704 *)p)->f20 = func_02045B38(0, 2, 0x56, ((struct Obj01704 *)p)->f44);
    ((struct Obj01704 *)p)->f24 = a;
    ((struct Obj01704 *)p)->f34 = func_02013080(CONFIG_GetTextSpeed((int)b));
    *(struct U16Vec * *)&((struct Obj01704 *)p)->f2C = func_020457B0(0x100, heap);
    *(struct WordSet * *)&((struct Obj01704 *)p)->f30 = func_0201EC64(heap);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_02040C14(1, 0, 1, 0);
    idx = func_020496E4(11, 89, 1, 0, 0, ((struct Obj01704 *)p)->f44);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), 11, 90, ((struct Obj01704 *)p)->f44, 0, 32, 0, 0);
    *(u32 *)&((struct Obj01704 *)p)->f1C = func_020450F0(1, 1, 19, 30, 4, 0, 0);
    func_02045374(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C);
    BMP_WIN_DrawFrame(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C, idx, 0);
    func_020409B4(1);
    func_02040588(1, 0);
    func_021B6C34((char *)p + 4, *(int *)&((struct Obj01704 *)p)->f1C);
    return p;
}
