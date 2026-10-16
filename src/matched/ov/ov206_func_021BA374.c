/*
 * unit: yes
 * function: ZUKAN_INFO_Update
 * address: 0x021BA374
 * packet: pkt_ov206_021BA374
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: cases 0/6/7 are empty labels inside the 8-entry jump table. The window registers are literal
 *   volatile addresses; the derived 0x04000000 base and 0x800 come from constant derivation.
 * symbols:
 *   ZUKAN_INFO_BlendPalette 0x021BBC9C thumb ov206
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   PM_VOICE_Play 0x02006984 thumb
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   ZUKAN_INFO_FlushSlotWindows 0x021BAF7C thumb ov206
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj00316.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Pt { s16 x; s16 y; };
typedef signed int     s32;
struct S;
extern s32 ZUKAN_INFO_BlendPalette(struct S *p);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern u32 PM_VOICE_Play(u32, u32, u32, u32, u32, u32, u32, u32);
struct Actor;
struct PrintSys;
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);
extern void ZUKAN_INFO_FlushSlotWindows(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
void ZUKAN_INFO_Update(char *p)
{
    if (((struct Obj00316 *)p)->f18 == 0) ZUKAN_INFO_BlendPalette((struct S *)p);
    ((struct Obj00316 *)p)->f64 += 1;
    if (((struct Obj00316 *)p)->f64 == 4) {
        ((struct Obj00316 *)p)->f39 |= 1;
        ((struct Obj00316 *)p)->f64 = 0;
    }
    switch (((struct Obj00316 *)p)->f54) {
    case 0: case 6: case 7: break;
    case 1:
        ((struct Obj00316 *)p)->f60 += 1;
        if (((struct Obj00316 *)p)->f60 == 15) ((struct Obj00316 *)p)->f54 = 2;
        break;
    case 2: {
        int v = ((struct Obj00316 *)p)->f68 - 1;
        ((struct Obj00316 *)p)->f68 = v;
        *(volatile u16 *)0x04000040 = 100;
        *(volatile u16 *)0x04000044 = (u16)(((8 << 8) & 0xFF00) | (v & 0xFF));
        if (((struct Obj00316 *)p)->f68 == 16) {
            *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
            G2x_SetBlendBrightness_((u32)((volatile u16 *)0x04000050), 0x10, 0);
            PM_VOICE_Play(((struct Obj00316 *)p)->fC, ((struct Obj00316 *)p)->fE, 0x40, 0, 0, 0, 0, 0);
            ((struct Obj00316 *)p)->f54 = 3;
        }
        break;
    }
    case 3:
        if (((struct Obj00316 *)p)->f58 != 0) ((struct Obj00316 *)p)->f54 = 4;
        break;
    case 4: {
        struct Pt pt;
        int fx = 0;
        int fy = 0;
        void *obj = *(void **)(p + ((struct Obj00316 *)p)->fB4 * 4 + 0xac);
        CLACT_GetActorPos(obj, &pt);
        pt.x += 1;
        pt.y += 1;
        if (pt.x > 0x80) { pt.x = 0x80; fx = 1; }
        if (pt.y > 0x48) { pt.y = 0x48; fy = 1; }
        CLACT_SetActorPos(*(void **)(p + ((struct Obj00316 *)p)->fB4 * 4 + 0xac), &pt);
        if (fx && fy) ((struct Obj00316 *)p)->f54 = 6;
        break;
    }
    case 5:
        if (((struct Obj00316 *)p)->f5C != 0) {
            PM_VOICE_Play(((struct Obj00316 *)p)->fC, ((struct Obj00316 *)p)->fE, 0x40, 0, 0, 0, 0, 0);
            ((struct Obj00316 *)p)->f54 = 6;
        }
        break;
    }
    if (((struct Obj00316 *)p)->f18 == 0 || ((struct Obj00316 *)p)->f18 == 2) ZUKAN_INFO_FlushSlotWindows(p);
    PRINTSYS_QUE_Main(((struct Obj00316 *)p)->f2C);
}
