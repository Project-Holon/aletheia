/*
 * function: MAILTOOL_StartWordInput
 * address:  0x021C3FC8
 * packet:   pkt_ov136_021C3FC8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * note:     2026-10-02 only unresolved arm9 Thumb leaf witnesses (02024104, 02024108, 02024450 unmanifested); C is complete
 *
 * symbols:
 *   MAILTOOL_StartWordInput 0x021C3FC8 thumb
 *   PMSI_PARAM_ClearSentence 0x0202428C thumb
 *   PMSI_PARAM_Create 0x02024044 thumb
 *   PMSI_PARAM_SetWord 0x02024104 thumb
 *   PMSI_PARAM_Copy 0x02024570 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMSI_PARAM_InitSentence 0x020242A4 thumb
 *   PMSI_PARAM_SetSentence 0x02024108 thumb
 */
#include "../include/Obj01412.h"
#include "../include/Obj10598.h"
#include "../include/Obj23490.h"
#include "../include/Obj23491.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSI_PARAM_ClearSentence(void *p);
struct Obj;
extern struct Obj *PMSI_PARAM_Create(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void PMSI_PARAM_SetWord(u16 *p, u16 v);
struct Rec8;
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMSI_PARAM_InitSentence(void *obj, u32 id);
extern void PMSI_PARAM_SetSentence(u16 *dst, const u16 *src);
void MAILTOOL_StartWordInput(u8 *ctx, u8 *arg)
{
    u8 *p = *(u8 * *)&((struct Obj01412 *)ctx)->f10;
    u32 k = p[2];
    if (k == 3) {
        PMSI_PARAM_ClearSentence(ctx + 0x14);
        ((struct Obj01412 *)ctx)->f14 = 6;
        ((struct Obj01412 *)ctx)->f16 = 0;
        ((struct Obj01412 *)ctx)->f18 = ((struct Obj23490 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10))->f32;
        ((struct Obj01412 *)ctx)->f8 = PMSI_PARAM_Create(0, 0, 0, 1, ((struct Obj10598 *)arg)->f10, ((struct Obj01412 *)ctx)->f0);
        PMSI_PARAM_SetWord(((struct Obj01412 *)ctx)->f8, ((struct Obj23491 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10))->f32);
    } else if (*(p + k + 0x2e) == 1) {
        PMSI_PARAM_Copy((struct Rec8 *)(ctx + 0x14), (const struct Rec8 *)(p + 0x16 + k * 8));
        ((struct Obj01412 *)ctx)->f8 = PMSI_PARAM_Create(2, 0, ctx + 0x14, 1, ((struct Obj10598 *)arg)->f10, ((struct Obj01412 *)ctx)->f0);
    } else {
        ((struct Obj01412 *)ctx)->f8 = PMSI_PARAM_Create(2, 0, 0, 1, ((struct Obj10598 *)arg)->f10, ((struct Obj01412 *)ctx)->f0);
        if (PMSI_PARAM_IsEnabled((u16 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10 + 0x16 + (*(u8 **)(ctx + 0x10))[2] * 8)))
            PMSI_PARAM_Copy((struct Rec8 *)(ctx + 0x14), (const struct Rec8 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10 + 0x16 + (*(u8 **)(ctx + 0x10))[2] * 8));
        else
            PMSI_PARAM_InitSentence(ctx + 0x14, 0);
        PMSI_PARAM_SetSentence(((struct Obj01412 *)ctx)->f8, (const u16 *)(ctx + 0x14));
    }
}
