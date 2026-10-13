/*
 * function: func_021C60CC
 * address:  0x021C60CC
 * packet:   pkt_ov111_021C60CC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   func_021C6C38  0x021C6C38  thumb  ov111
 *   func_021C6B5C  0x021C6B5C  thumb  ov111
 *   func_021C61EC  0x021C61EC  thumb  ov111
 *   func_021C628C  0x021C628C  thumb  ov111
 *   func_021C6954  0x021C6954  thumb  ov111
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   PMS_DRAW_Print  0x0202DC48  thumb
 *   PMS_DRAW_SetVisible  0x0202DCB0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0xA - 7];
    u16 name[1];
    u8 padC[0x20 - 0xC];
    u32 f20;
    u32 f24;
    u8 pad28[0x48 - 0x28];
    u32 f48;
    u8 pad4C[0x6C - 0x4C];
    u8 f6C[1];
} Info;

typedef struct {
    u8 pad0[0x28];
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x31FC - 0x3038];
    void *f31FC;
    u8 pad3200[0x3210 - 0x3200];
    void *f3210;
    void *f3214;
    u8 pad3218[0x322C - 0x3218];
    void *f322C[26];
    u8 pad3294[0x32B0 - 0x3294];
    void *f32B0;
} Work;

struct CharBuf;
struct Descriptor;
struct Obj0202DC98;
struct PmsDraw;
struct Strbuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void func_021C6C38(Work *p, void *a, int x, int dx, int y, void *s);
extern void func_021C6B5C(Work *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx);
extern void func_021C61EC(Work *p, int k, int flush);
extern void func_021C628C(Work *p, int k, int flush);
extern void func_021C6954(Work *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_Print(u32 a, u32 b, u32 c, u32 d);
extern void PMS_DRAW_SetVisible(struct Obj0202DC98 *o, int i, u32 a1);

void func_021C60CC(Work *p, void **bg, const Info *info)
{
    u8 i;
    void *s;

    for (i = 0; i < 5; i++) {
        BMP_Clear(BMP_WIN_GetBmp(bg[i]), 0);
        if (i != 3 || (i == 3 && info->f4_2)) {
            PRINTSYS_Print(BMP_WIN_GetBmp(bg[i]), 0, 0, p->f322C[i], p->f31FC);
        }
    }
    s = p->f3214;
    STRBUF_SetString(p->f3210, info->name);
    func_021C6C38(p, bg[0], 0x88, 8, 0, p->f3210);
    if (info->f4_2) {
        func_021C6B5C(p, bg[3], 0x88, 8, 0, s, info->f24, 1, 0);
    }
    func_021C61EC(p, info->b6, 0);
    func_021C628C(p, info->f48, 0);
    func_021C6954(p, bg[4], 0xD8, 8, 0, s, info->f20, 7, 1, 1, 0);
    PMS_DRAW_SetNullColorPalette(p->f32B0, 0);
    PMS_DRAW_Print((u32)p->f32B0, (u32)bg[5], (u32)p->info->f6C, 0);
    if (p->f3034 != 0) {
        PMS_DRAW_SetVisible(p->f32B0, 0, 0);
    }
}
