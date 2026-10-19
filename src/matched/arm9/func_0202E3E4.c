/*
 * function: PMS_DRAW_SetElemVisible
 * address:  0x0202E3E4
 * packet:   pkt_0202E0E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_SetElemVisible.c \
 *       --func PMS_DRAW_SetElemVisible --addr 0x0202E3E4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Obj0202E3E4 {
    u32 f00;
    u32 f04;
    u32 f08[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20[2];
};

typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_MarkTileDirty(u32 bit);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

void PMS_DRAW_SetElemVisible(struct Obj0202E3E4 *obj, u32 a1)
{
    int i;

    obj->f18 = (obj->f18 & ~2) | ((a1 & 1) << 1);
    if (a1 != 0)
        BMP_WIN_MakeScreen((struct Cfg *)obj->f00);
    else
        BMP_WIN_ClearScreen((struct Descriptor *)obj->f00);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct Descriptor *)obj->f00));
    for (i = 0; i < 2; i++) {
        if (obj->f20[i] != 0)
            CLACT_SetActorDrawEnable((struct Obj *)obj->f08[i], a1);
    }
}
