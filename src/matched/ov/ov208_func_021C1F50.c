/*
 * function: ZUKAN_DETAIL_AREA_DrawAreaSetTitle
 * address:  0x021C1F50
 * packet:   pkt_ov208_021C1F50
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Bmp;
struct StrObj;
struct U16Vec;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = func_02045EC0((struct MsgBank *)W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = BMP_GetWidth(BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)));
    PRINTSYS_PrintQueColor((void *)W(0x3c), (u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)), (s16)((u16)((int)(w - tw) / 2)), (s16)1, (u32)str, W(4), 0x3c40);
    STRBUF_Delete(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}
