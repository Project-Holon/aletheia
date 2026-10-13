/*
 * function: func_021EB378
 * address:  0x021EB378
 * packet:   pkt_ov170_021EB378
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws a window frame from 8x8 tiles, then centres a message in it.  The
 * window size locals are u8 like the getters that return them: as int
 * locals the w - 1 and h - 1 loop guards stop sharing the corner offsets'
 * common subexpressions and the function comes out 20 bytes short.
 *
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   BMP_Clear 0x02043B5C arm
 *   ARC_UTIL_LoadBgCharDataFromArchive 0x02049DB4 arm
 *   BMP_CreateFromBuffer 0x020436FC arm
 *   BMP_Blit 0x020439A0 arm
 *   BMP_Delete 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   STRBUF_Delete 0x02045808 arm
 */

typedef struct {
    unsigned char pad[0x14];
    char *raw;
} Chr;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bmp;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj020437AC;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern unsigned func_020275E4(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void STRBUF_Delete(struct U16Vec *vec);

#define WORK(p) (*(char **)((p) + 0x2C))
#define HEAP 0x804C

void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon)
{
    void *win = *(void **)(WORK(p) + 0x94 + idx * 8);
    void *bmp = BMP_WIN_GetBmp(win);
    unsigned char w;
    unsigned char h;
    Chr *chr;
    void *res;
    char *raw;
    void *t;
    unsigned char i;
    void *str;

    BMP_WIN_GetBgLayer(win);
    BMP_WIN_GetPosX(win);
    BMP_WIN_GetPosY(win);
    w = BMP_WIN_GetWidth(win);
    h = BMP_WIN_GetHeight(win);
    BMP_Clear(bmp, 4);
    res = ARC_UTIL_LoadBgCharDataFromArchive(0x74, 0x3E, 1, (u32)(&chr), HEAP);
    raw = chr->raw;
    frame *= 0x20;

    t = BMP_CreateFromBuffer(raw + frame, 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, 0, 0, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x40), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, 0, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xC0), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, 0, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x100), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x60), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        BMP_Blit(t, bmp, 0, 0, 0, i * 8, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xA0), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, i * 8, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x20), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        BMP_Blit(t, bmp, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
    BMP_Delete(t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xE0), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        BMP_Blit(t, bmp, 0, 0, i * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete(t);

    func_020307B0(res);

    if (icon == 1) {
        res = ARC_UTIL_LoadBgCharDataFromArchive(func_020275E4(), 0x20, 0, (u32)(&chr), HEAP);
        t = BMP_CreateFromBuffer(chr->raw + 0x120, 0x10, 8, 0x20, HEAP);
        BMP_Blit(t, bmp, 0, 0, (w - 3) * 8, 8, 0x10, 8, 5);
        BMP_Delete(t);
        func_020307B0(res);
    }

    str = func_02045EC0(*(void **)(WORK(p) + 0x80), msg);
    TOUCHBAR_PrintAligned((u8 *)(WORK(p) + 0x94 + idx * 8), (void *)(*(void **)(WORK(p) + 0x8C)), w * 8 / 2, 4, (u32)str,
                  *(unsigned *)(WORK(p) + 0x78), col, 2);
    STRBUF_Delete(str);
}
