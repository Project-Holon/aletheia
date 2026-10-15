/*
 * function: FLD_FACEUP_SetupBg
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
 *   FLD_FACEUP_SaveBgPriorities  0x021F56C0  thumb  ov082
 *   FLD_FACEUP_SaveVisiblePlanes  0x021F56D8  thumb  ov082
 *   func_0207D63C  0x0207D63C  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_ReleaseSysFrame  0x02190378  thumb  ov021
 *   FIELD_MSGBG_RequestSysFrame  0x021904D0  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02040B1C  0x02040B1C  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   gFldFaceupBgTemplate     0x021F58F4  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09918.h"

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

extern const BgTemplate gFldFaceupBgTemplate;

extern void FLD_FACEUP_SaveBgPriorities(u8 *w);
typedef signed int     s32;
struct BgTemplate;
struct NitroFileHeader;
extern void FLD_FACEUP_SaveVisiblePlanes(int *p);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_ReleaseSysFrame(u8 *a);
extern void FIELD_MSGBG_RequestSysFrame(u8 *p);
extern void func_020403F4(u32 i);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern int func_02062B30(void *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);
extern void func_02040E78(u32 index, void *src, u32 size, u32 offset);
extern u32 func_020307B0(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);

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

void FLD_FACEUP_SetupBg(u8 *w, int p)
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

    FLD_FACEUP_SaveBgPriorities(w);
    FLD_FACEUP_SaveVisiblePlanes((int *)w);
    ((struct Obj09918 *)w)->f8 = reg_G2_BG3CNT;
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256,
                         GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x04000);
    func_0207D63C(0x04000050, 8, 4, 0, 16);
    obj = FIELDMAP_GetMsgBg((u8 *)p);
    if (FIELD_MSGBG_ReleaseSysFrame((u8 *)obj) != 0)
        FIELD_MSGBG_RequestSysFrame((u8 *)obj);
    else
        func_020403F4(2);
    tbl = gFldFaceupBgTemplate;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&tbl), 0);
    if (((struct Obj09918 *)w)->fC == 0) {
        a = 4;
        b = 8;
        c = 0;
    } else if (((struct Obj09918 *)w)->fC == 1) {
        a = 5;
        b = 9;
        c = 1;
    } else {
        a = 6;
        b = 10;
        c = 2;
    }
    f = ARC_TOOL_LoadMember(0xbb, a, 0x8015);
    func_02062A4C(f, (void **)(&chr1));
    func_02040B1C(2, chr1->data, chr1->size, 0);
    func_020307B0(f);
    f = ARC_TOOL_LoadMember(0xbb, b, 0x8015);
    func_02062B30(f, (void **)(&scr1));
    BG_SYS_PushTileSource(2, scr1->data, scr1->size, 0);
    func_020307B0(f);
    f = ARC_TOOL_LoadMember(0xbb, c, 0x8015);
    func_02062A98(f, (void **)(&plt));
    func_02040E78(2, plt->data, 0x140, 0);
    func_020307B0(f);
    f = ARC_TOOL_LoadMember(0xbb, 7, 0x8015);
    func_02062A4C(f, (void **)(&chr2));
    func_02040B1C(3, chr2->data, chr2->size, 0);
    func_020307B0(f);
    f = ARC_TOOL_LoadMember(0xbb, 11, 0x8015);
    func_02062B30(f, (void **)(&scr2));
    BG_SYS_PushTileSource(3, scr2->data, scr2->size, 0);
    func_020307B0(f);
    func_0204047C(0, 3);
    func_0204047C(1, 0);
    func_0204047C(2, 2);
    func_0204047C(3, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
}
