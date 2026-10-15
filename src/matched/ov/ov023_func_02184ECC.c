/*
 * function: OEKAKI_CreateWindows
 * address:  0x02184ECC
 * packet:   pkt_ov023_02184ECC
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   TCBL_Create  0x0203101C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   OEKAKI_RefreshNamePlates  0x02185F74  thumb  ov023
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w;
    u8 f;
} Ent;

typedef struct {
    char pad0[0x104];
    u32 win[7];
    char pad120[0xc];
    Ent ent[7];
    u32 f164;
    u32 f168;
    u32 f16c;
    u32 f170;
} W;

extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct Cfg;
struct CharBuf;
struct Tcbl;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 a);
extern void OEKAKI_RefreshNamePlates(u32 *a, int b, W *p);

void OEKAKI_CreateWindows(W *p)
{
    int i;
    u32 w;

    BMP_WIN_Init(0x28);
    p->win[6] = BMP_WIN_Create(0, 2, (u8)1, 0x1b, (u32)4, (u32)0xd, (u32)1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[6])), 0xf);
    p->ent[6].w = p->win[6];
    p->ent[6].f = 0;
    p->win[5] = BMP_WIN_Create(1, 1, (u8)2, 0x1e, (u32)0xf, (u32)0, (u32)1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[5])), 2);
    p->f170 = (u32)TCBL_Create(0x28, 0x28, 0x20, 0x20);
    p->f164 = PRINTSYS_QUE_Create((void *)0x28);
    p->f168 = PRINTSYS_QUE_Create((void *)0x28);
    for (i = 0; i < 5; i++) {
        p->win[i] = BMP_WIN_Create(4, 5, (u8)(i * 4 + 3), 0xa, (u32)2, (u32)0xd, (u32)1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 0);
        p->ent[i].w = p->win[i];
        p->ent[i].f = 0;
        w = p->win[i];
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    }
    OEKAKI_RefreshNamePlates(p->win, 0x44f, p);
}
