/*
 * function: VIEWER_MAIN_DrawSelected
 * address:  0x021C5718
 * packet:   pkt_ov111_021C5718
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   TRCARD_SIGN_SetSeenBefore  0x02008A00  thumb
 *   VIEWER_MAIN_InitInfo  0x021C3EF8  thumb
 *   VIEWER_TEXT_DrawTable  0x021C61EC  thumb
 *   VIEWER_TEXT_DrawList  0x021C628C  thumb
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
} Cfg;

typedef struct {
    Cfg *cfg;
    void *f4;
    u8 pad8[4];
    u32 fC;
    u32 f10;
} Args;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x48 - 7];
    u32 f48;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x24 - 2];
    Args *args;
    Info *info;
    u8 pad2C[0x32C6 - 0x2C];
    u8 b32C6;
} Work;

struct Sub020089A8Obj;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern struct Sub020089A8Obj *TRCARD_SIGN_SetSeenBefore(struct Sub020089A8Obj *obj);
extern void VIEWER_MAIN_InitInfo(Info *info);
extern void VIEWER_TEXT_DrawTable(Work *p, int v, int a);
extern void VIEWER_TEXT_DrawList(Work *p, int v, int a);

void VIEWER_MAIN_DrawSelected(Work *p, int sel, int *seq)
{
    switch (sel) {
    case 3:
        p->b32C6 = 0;
        *seq = 5;
        break;
    case 8:
        if (p->args->cfg->f4_6) {
            *seq = 9;
        }
        break;
    case 9:
        if (p->args->cfg->f4_6) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            p->b32C6 = 0;
            *seq = 6;
        }
        break;
    case 4:
        *seq = 2;
        p->args->fC = 0;
        p->args->f10 = 0;
        break;
    case 5:
        *seq = 3;
        p->args->fC = 0;
        p->args->f10 = 1;
        break;
    case 6:
        if (p->args->cfg->f4_6) {
            TRCARD_SIGN_SetSeenBefore(GAME_DATA_GetSaveBlock21(p->args->f4));
            GFL_USE_PlaySeDefaultVolume(0x548);
            VIEWER_MAIN_InitInfo(p->info);
            VIEWER_TEXT_DrawTable(p, p->info->b6, 1);
        }
        break;
    case 7:
        if (p->args->cfg->f4_6) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            p->info->f48++;
            if (p->info->f48 > 0x18) {
                p->info->f48 = 0;
            }
            VIEWER_TEXT_DrawList(p, p->info->f48, 1);
        }
        break;
    case 10:
        p->b32C6 = 0;
        *seq = 7;
        break;
    }
}
