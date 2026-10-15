/*
 * function: VIEWER_MAIN_HandleKey
 * address:  0x021C5054
 * packet:   pkt_ov111_021C5054
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_TEXT_SetActorAnim  0x021C6FA0  thumb  ov111
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   VIEWER_MAIN_ToggleFavorite  0x021C513C  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
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
    u8 pad0[4];
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
} Work;

extern void VIEWER_TEXT_SetActorAnim(Anim *a, int idx, u8 x, u8 y);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern void VIEWER_MAIN_ToggleFavorite(Work *p);

int VIEWER_MAIN_HandleKey(Work *p)
{
    u32 key = KEY_GetTrg();

    if (key & 2) {
        if (p->h305E == 0) {
            VIEWER_TEXT_SetActorAnim(&p->anim, 0, 9, 1);
            GFL_USE_PlaySeDefaultVolume(0x551);
            func_020355D8(0);
            return 4;
        }
    } else if (key & 0x400) {
        if (p->h305E == 0 && !p->info->f4_7) {
            VIEWER_TEXT_SetActorAnim(&p->anim, 1, 8, 1);
            GFL_USE_PlaySeDefaultVolume(0x556);
            return 5;
        }
    } else if (key & 0x30) {
        if (p->h305E == 0) {
            VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x17, 1);
            return 3;
        }
    } else if (key & 0x800) {
        if (!p->info->f4_7) {
            VIEWER_MAIN_ToggleFavorite(p);
        }
    } else if (key & 1) {
        if (!p->info->f4_7 && p->f3034 == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x11, 1);
            return 10;
        }
    }
    return 0;
}
