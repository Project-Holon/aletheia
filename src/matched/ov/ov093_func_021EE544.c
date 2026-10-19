/*
 * function: BTLV_SCU_StepBallWindowClose
 * address:  0x021EE544
 * packet:   pkt_ov093_021EE544
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct C {
    u8 pad00[0x8];
    void *f08;
};

struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

int BTLV_SCU_StepBallWindowClose(int *st, struct C *c)
{
    int a;
    int b;
    int e;
    int f;
    u8 id;

    switch (*st) {
    case 0:
        a = BMP_WIN_GetPosX(c->f08) - 1;
        b = BMP_WIN_GetPosY(c->f08) - 1;
        e = BMP_WIN_GetWidth(c->f08) + 2;
        f = BMP_WIN_GetHeight(c->f08) + 2;
        id = BMP_WIN_GetBgLayer(c->f08);
        BG_SYS_SetTileEntry(id, 0, (u8)a, (u8)b, (u8)e, (u8)f, 0);
        BG_SYS_PushTile(id);
        GFL_USE_PlaySeDefaultVolume(0x547);
        (*st)++;
        break;
    case 1:
        BG_SYS_ChangeScrollImmediate(3, 0, -0x90);
        BG_SYS_ChangeScrollImmediate(3, 3, 0);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
