/*
 * function: VIEWER_MAIN_HandleRowTouch
 * address:  0x021C5280
 * packet:   pkt_ov111_021C5280
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_HitRow  0x021C5264  thumb  ov111
 *   VIEWER_TEXT_SetActorAnim  0x021C6FA0  thumb  ov111
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   VIEWER_MAIN_SetRowDrawEnable  0x021C51E4  thumb  ov111
 *   VIEWER_MAIN_SetBgSlotKind  0x021C4754  thumb  ov111
 *   VIEWER_MAIN_DrawRowBg  0x021C523C  thumb  ov111
 *   VIEWER_MAIN_ToggleFavorite  0x021C513C  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 kind;
    u8 pad1[3];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
} Info;

typedef struct {
    Info *info;
    void *f4;
} Args;

typedef struct {
    u8 pad0[0x98];
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args *args;
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim anim;
    u8 pad3108[0x32C6 - 0x3108];
    u8 b32C6;
    u8 pad32C7[0x32D8 - 0x32C7];
    u32 f32D8;
    u32 f32DC;
    u8 pad32E0[0x32F6 - 0x32E0];
    u8 b32F6;
} Work;

extern void VIEWER_TEXT_SetActorAnim(Anim *a, int idx, u8 x, u8 y);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int VIEWER_MAIN_HitRow(Work *p, int hit);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void VIEWER_MAIN_SetRowDrawEnable(Work *p, int flag);
extern void VIEWER_MAIN_SetBgSlotKind(Work *p, int kind);
extern void VIEWER_MAIN_DrawRowBg(Work *p, int flag);
extern void VIEWER_MAIN_ToggleFavorite(Work *p);

int VIEWER_MAIN_HandleRowTouch(Work *p, int hit)
{
    if (VIEWER_MAIN_HitRow(p, hit) == 1) {
        return 0;
    }
    switch (hit) {
    case 0:
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 9, 1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_020355D8(1);
        return 4;
    case 1:
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 8, 1);
        GFL_USE_PlaySeDefaultVolume(0x556);
        return 5;
    case 2:
        TOUCHPANEL_GetPointCont(&p->f32D8, &p->f32DC);
        VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x17, 1);
        return 3;
    case 3:
        if (p->f3034 != 0) {
            if (p->args->info->f4_6) {
                VIEWER_MAIN_SetRowDrawEnable(p, p->info->f4_4);
                p->info->f4_4 ^= 1;
                VIEWER_MAIN_SetBgSlotKind(p, p->info->kind);
                VIEWER_MAIN_DrawRowBg(p, p->info->f4_4);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x11, 1);
            return 10;
        }
        break;
    case 4:
        if (p->f3034 != 0 && !p->info->f4_4 && p->args->info->f4_6) {
            if (p->h305E == 0) {
                VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x13, 1);
                GFL_USE_PlaySeDefaultVolume(0x648);
                p->b32C6 = 0;
            } else {
                VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x15, 1);
                GFL_USE_PlaySeDefaultVolume(0x649);
                p->b32C6 = 3;
            }
            return 8;
        }
        break;
    case 5:
        if (p->f3034 != 0 && p->args->info->f4_6 && !p->info->f4_4) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            VIEWER_TEXT_SetActorAnim(&p->anim, 5, 9 - p->b32F6 * 2, 1);
            p->b32F6 ^= 1;
        }
        break;
    case 6:
        VIEWER_MAIN_ToggleFavorite(p);
        break;
    case 7:
        if (p->f3034 == 0) {
            return 6;
        }
        break;
    case 8:
        if (p->f3034 == 0) {
            return 7;
        }
        break;
    case 9:
        if (p->f3034 == 0) {
            return 9;
        }
        break;
    }
    return 0;
}
