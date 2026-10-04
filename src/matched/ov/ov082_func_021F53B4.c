/*
 * function: func_021F53B4
 * address:  0x021F53B4
 * packet:   pkt_ov082_021F53B4
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: reg_G2_BG3CNT re-read at 0x021F53CA and 0x021F53CE (SDK inline over the register macro)
 *
 * symbols:
 *   func_021F56C0  0x021F56C0  thumb  ov082
 *   func_021F56D8  0x021F56D8  thumb  ov082
 *   func_0207D63C  0x0207D63C  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190378  0x02190378  thumb  ov021
 *   func_021904D0  0x021904D0  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02048F60  0x02048F60  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020409E0  0x020409E0  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   d_021F58F4     0x021F58F4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w[8];
} BgTemplate;

typedef struct {
    u8 _0[0x10];
    u32 size;
    void *data;
} Chr;

typedef struct {
    u8 _0[8];
    u32 size;
    u8 data[4];
} Scr;

typedef struct {
    u8 _0[0xc];
    void *data;
} Plt;

extern const BgTemplate d_021F58F4;

extern void func_021F56C0(u8 *w);
extern void func_021F56D8(u8 *w);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern u32 func_02188C54(u8 *p);
extern int func_02190378(u8 *a);
extern void func_021904D0(u8 *p);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(int, void *, int);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_02062A4C(void *p, Chr **out);
extern int func_02062B30(void *p, Scr **out);
extern int func_02062A98(void *p, Plt **out);
extern void func_02040B1C(u8 index, const void *src, u32 size, u32 tile);
extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_02040E78(u32 index, void *src, u32 size, u32 offset);
extern void func_020307B0(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(u32 which, u32 enable);

#define reg_G2_BG3CNT  (*(volatile u16 *)0x0400000E)

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;
typedef enum { GX_BG_COLORMODE_16 = 0, GX_BG_COLORMODE_256 = 1 } GXBGColorMode;
typedef enum { GX_BG_SCRBASE_0x0000 = 0, GX_BG_SCRBASE_0x1000 = 2 } GXBGScrBase;
typedef enum { GX_BG_CHARBASE_0x00000 = 0, GX_BG_CHARBASE_0x04000 = 1 } GXBGCharBase;

static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode,
                                        GXBGScrBase screenBase, GXBGCharBase charBase)
{
    reg_G2_BG3CNT = (u16)((reg_G2_BG3CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

void func_021F53B4(u8 *w, int p)
{
    BgTemplate tbl;
    Chr *chr1;
    Scr *scr1;
    Plt *plt;
    Chr *chr2;
    Scr *scr2;
    void *f;
    int obj;
    int a;
    int b;
    int c;

    func_021F56C0(w);
    func_021F56D8(w);
    *(u16 *)(w + 8) = reg_G2_BG3CNT;
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256,
                         GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x04000);
    func_0207D63C(0x04000050, 8, 4, 0, 16);
    obj = func_02188C54((u8 *)p);
    if (func_02190378((u8 *)obj) != 0)
        func_021904D0((u8 *)obj);
    else
        func_020403F4(2);
    tbl = d_021F58F4;
    func_0203FCA0(2, &tbl, 0);
    if (*(int *)(w + 0xc) == 0) {
        a = 4;
        b = 8;
        c = 0;
    } else if (*(int *)(w + 0xc) == 1) {
        a = 5;
        b = 9;
        c = 1;
    } else {
        a = 6;
        b = 10;
        c = 2;
    }
    f = func_02048F60(0xbb, a, 0x8015);
    func_02062A4C(f, &chr1);
    func_02040B1C(2, chr1->data, chr1->size, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, b, 0x8015);
    func_02062B30(f, &scr1);
    func_020409E0(2, scr1->data, scr1->size, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, c, 0x8015);
    func_02062A98(f, &plt);
    func_02040E78(2, plt->data, 0x140, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, 7, 0x8015);
    func_02062A4C(f, &chr2);
    func_02040B1C(3, chr2->data, chr2->size, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, 11, 0x8015);
    func_02062B30(f, &scr2);
    func_020409E0(3, scr2->data, scr2->size, 0);
    func_020307B0(f);
    func_0204047C(0, 3);
    func_0204047C(1, 0);
    func_0204047C(2, 2);
    func_0204047C(3, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
}
