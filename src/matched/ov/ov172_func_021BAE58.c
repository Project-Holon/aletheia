/*
 * function: CTVT_DRAW_UpdateCanvasMode
 * address: 0x021BAE58
 * packet: pkt_ov172_021BAE58
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CTVT_DRAW_ShowHelp 0x021BB65C thumb ov172
 *   COMM_TVT_SYS_ToggleViewSwapped 0x021BE0B8 thumb ov172
 *   CTVT_DRAW_UpdateToolButtons 0x021BB54C thumb ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00024.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 KEY_GetTrg(void);
extern u32 CLACT_IsActorAnimActive(struct Actor *);
extern u16 CLACT_GetActorAnimSeq(struct Obj *);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
extern void CTVT_DRAW_ShowHelp(void *ctx, u8 *p, int k);
extern void COMM_TVT_SYS_ToggleViewSwapped(void *);
extern void CTVT_DRAW_UpdateToolButtons(void *ctx, u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void CTVT_DRAW_UpdateCanvasMode(void *p, u8 *q)
{
    if ((KEY_GetTrg() & 1024) && ((struct Obj00024 *)q)->f38 == 0) {
        if (CLACT_IsActorAnimActive(*(struct Actor * *)&((struct Obj00024 *)q)->f6C) == 0 ||
            CLACT_GetActorAnimSeq(*(struct Obj * *)&((struct Obj00024 *)q)->f6C) == 1) {
            *(u32 *)&((struct Obj00024 *)q)->f0 = 5;
            q[4] = 0;
            CTVT_DRAW_ShowHelp(p, q, 1);
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00024 *)q)->f6C, 1);
            GFL_USE_PlaySeDefaultVolume(1644);
        }
    } else if (KEY_GetTrg() & 2) {
        *(u32 *)&((struct Obj00024 *)q)->f0 = 2;
        GFL_USE_PlaySeDefaultVolume(1361);
    }
    if (KEY_GetTrg() & 12) {
        COMM_TVT_SYS_ToggleViewSwapped(p);
        CTVT_DRAW_UpdateToolButtons(p, q);
        GFL_USE_PlaySeDefaultVolume(1647);
    }
}
