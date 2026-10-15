/*
 * function: VIEWER_TEXT_Init
 * address:  0x021C6000
 * packet:   pkt_ov111_021C6000
 * region:   ov111
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
 *   BG_SYS_Init  0x02040C14  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   d_021C8773  0x021C8773  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *win[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
    u8 pad32D0[4];
    u8 f32D4;
} Work;

typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041B6C(u32 bit);
extern u32 PRINTSYS_QUE_Create(void *p);
extern const u8 d_021C8773[8][6];

void VIEWER_TEXT_Init(Work *p)
{
    const u8 (*tbl)[6] = d_021C8773;
    u8 i;

    BMP_WIN_Init(p->heap);
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)BMP_WIN_Create(tbl[i][0], tbl[i][1], tbl[i][2], tbl[i][3], tbl[i][4], tbl[i][5], 1);
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
    }
    BG_SYS_Init(7, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(4, 0x31, 0xD, p->f32D4, p->heap);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, p->heap);
    func_02041B6C(7);
    func_02041B6C(4);
    p->f32CC = (void *)PRINTSYS_QUE_Create((void *)p->heap);
}
