/*
 * function: VIEWER_MAIN_UpdateRowB
 * address:  0x021C49D8
 * packet:   pkt_ov111_021C49D8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_TEXT_SetActorAnim  0x021C6FA0  thumb  ov111
 *   VIEWER_MAIN_SetRowState  0x021C51B4  thumb  ov111
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
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
    u32 f8;
} Sub24;

typedef struct {
    u8 pad0[0x98];
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Sub24 *f24;
    Info *info;
    u8 pad2C[0x305E - 0x2C];
    u16 h305E;
    u8 pad3060[0x3070 - 0x3060];
    Anim anim;
    u8 pad3108[0x32F6 - 0x3108];
    u8 b32F6;
} Work;

extern void VIEWER_TEXT_SetActorAnim(Anim *a, int idx, u8 x, u8 y);
extern void VIEWER_MAIN_SetRowState(Work *p, int flag, int v);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);

void VIEWER_MAIN_UpdateRowB(Work *p, int flag)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 6, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x10, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, GAME_DATA_CheckSaveFlag((int)p->f24->f4, 0x15) + 6, 1);
    } else {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 0, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x16, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 8 - p->b32F6 * 2, 0);
        VIEWER_MAIN_SetRowState(p, p->info->f4_4, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, GAME_DATA_CheckSaveFlag((int)p->f24->f4, 0x16) + 6, 1);
    }
}
