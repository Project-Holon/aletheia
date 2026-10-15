/*
 * function: BG_SYS_InitBgLayer
 * address:  0x0203FCA0
 * packet:   pkt_0203FCA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_020A7E5C    0x020A7E5C  data
 *   g_02146A44    0x02146A44  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   BG_SYS_ResolveScroll  0x02042218  arm
 *   BG_SYS_RotScale  0x020423D4  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BG_SYS_SetupLayer  0x02042FF8  arm
 *
 * bg_sys.c: initialise one BG layer from its template.  Program BGxCNT of
 * layer bgId (0..3 main, 4..7 sub) through the TwlSDK gx_bgcnt.h inline
 * setters (text layers 0/1/4/5 always; 2/3/6/7 by type: text, affine, or the
 * game's type-2 form, whose OR order is charBase before screenBase and which
 * carries no 0x80 ext-mode bit, so it is not G2_SetBG2Control256x16Pltt),
 * then priority and mosaic, then the layer record in g_02146A44.
 *
 * Closed in wave 16 by the SDK-inline lever with the SDK's ENUM parameter
 * types (GXBGScrSizeText, GXBGColorMode, GXBGScrBase, GXBGCharBase,
 * GXBGExtPltt, GXBGAreaOver).  The same inlines with int parameters give
 * 1860 bytes, 1171 out (the type-0 store cross-jumped into the shared tail);
 * see docs/notes/BG_SYS_InitBgLayer.c.txt for the earlier record.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define REG16(a) (*(volatile u16 *)(a))

#define REG_BG0CNT_A  0x04000008
#define REG_BG1CNT_A  0x0400000A
#define REG_BG2CNT_A  0x0400000C
#define REG_BG3CNT_A  0x0400000E
#define REG_BG0CNT_B  0x04001008
#define REG_BG1CNT_B  0x0400100A
#define REG_BG2CNT_B  0x0400100C
#define REG_BG3CNT_B  0x0400100E

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

struct Bg {
    void *buf;
    u32   bufSize;
    u32   unk_08;
    u32   unk_0c;
    u32   unk_10;
    u8    type;
    u8    unk_15;
    u8    unk_16;
    u8    unk_17;
    u16   unk_18;
    u16   unk_1a;
    u32   unk_1c;
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

struct BgSys {
    u16       heapId;
    u16       unk_02;
    u32       unk_04;
    struct Bg bgs[8];
    u32       unk_168;
    u32       unk_16c;
    u32       unk_170[8];
    u32       unk_190[8];
    u32       unk_1b0[8];
};

extern char g_020A7E5C[];
extern struct BgSys *g_02146A44;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void BG_SYS_FillScrollArea(u32 bgId, u32 which, u32 value);
extern int BG_SYS_ResolveScroll(int a0, int a1);
extern void BG_SYS_RotScale(u32 bgId);
extern void BG_SYS_SetupLayer(u32 bgId, u32 offset, u32 size);
extern void MIi_CpuClear16(u32 value, void *dest, u32 size);


/* TwlSDK nitro/gx/gx_bgcnt.h parameter types; only the type matters here */
typedef enum { SS0 = 0 } GXBGScrSizeText;
typedef enum { SA0 = 0 } GXBGScrSizeAffine;
typedef enum { CM0 = 0 } GXBGColorMode;
typedef enum { SB0 = 0 } GXBGScrBase;
typedef enum { CB0 = 0 } GXBGCharBase;
typedef enum { EP0 = 0 } GXBGExtPltt;
typedef enum { AO0 = 0 } GXBGAreaOver;
typedef int BOOL;
static inline void G2_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_A) |= 0x40;
    } else {
        REG16(REG_BG0CNT_A) &= ~0x40;
    }
}
static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_A) |= 0x40;
    } else {
        REG16(REG_BG1CNT_A) &= ~0x40;
    }
}
static inline void G2_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_A) |= 0x40;
    } else {
        REG16(REG_BG2CNT_A) &= ~0x40;
    }
}
static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_A) |= 0x40;
    } else {
        REG16(REG_BG3CNT_A) &= ~0x40;
    }
}
static inline void G2S_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_B) |= 0x40;
    } else {
        REG16(REG_BG0CNT_B) &= ~0x40;
    }
}
static inline void G2S_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_B) |= 0x40;
    } else {
        REG16(REG_BG1CNT_B) &= ~0x40;
    }
}
static inline void G2S_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2S_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2S_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_B) |= 0x40;
    } else {
        REG16(REG_BG2CNT_B) &= ~0x40;
    }
}
static inline void G2S_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2S_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2S_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_B) |= 0x40;
    } else {
        REG16(REG_BG3CNT_B) &= ~0x40;
    }
}
void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type)
{
    u32 ss = BG_SYS_ResolveScroll(tmpl->unk_10, type);

    switch (bgId) {
    case 0:
        G2_SetBG0Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2_SetBG0Priority(tmpl->unk_19);
        G2_BG0Mosaic(tmpl->unk_1c);
        break;
    case 1:
        G2_SetBG1Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2_SetBG1Priority(tmpl->unk_19);
        G2_BG1Mosaic(tmpl->unk_1c);
        break;
    case 2:
        switch (type) {
        case 0:
        default:
            G2_SetBG2ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2_SetBG2ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2_SetBG2ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2_SetBG2Priority(tmpl->unk_19);
        G2_BG2Mosaic(tmpl->unk_1c);
        break;
    case 3:
        switch (type) {
        case 0:
        default:
            G2_SetBG3ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2_SetBG3ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2_SetBG3ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2_SetBG3Priority(tmpl->unk_19);
        G2_BG3Mosaic(tmpl->unk_1c);
        break;
    case 4:
        G2S_SetBG0Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2S_SetBG0Priority(tmpl->unk_19);
        G2S_BG0Mosaic(tmpl->unk_1c);
        break;
    case 5:
        G2S_SetBG1Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2S_SetBG1Priority(tmpl->unk_19);
        G2S_BG1Mosaic(tmpl->unk_1c);
        break;
    case 6:
        switch (type) {
        case 0:
        default:
            G2S_SetBG2ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2S_SetBG2ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2S_SetBG2ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2S_SetBG2Priority(tmpl->unk_19);
        G2S_BG2Mosaic(tmpl->unk_1c);
        break;
    case 7:
        switch (type) {
        case 0:
        default:
            G2S_SetBG3ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2S_SetBG3ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2S_SetBG3ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2S_SetBG3Priority(tmpl->unk_19);
        G2S_BG3Mosaic(tmpl->unk_1c);
        break;
    }

    g_02146A44->bgs[bgId].unk_18 = 0;
    g_02146A44->bgs[bgId].unk_1c = 0x1000;
    g_02146A44->bgs[bgId].unk_20 = 0x1000;
    g_02146A44->bgs[bgId].unk_24 = 0;
    g_02146A44->bgs[bgId].unk_28 = 0;

    if (tmpl->bufSize != 0) {
        g_02146A44->bgs[bgId].buf = GFL_HEAP_Alloc(g_02146A44->heapId,
                                                 tmpl->bufSize, 0,
                                                 g_020A7E5C, 0x231);
        MIi_CpuClear16(0, g_02146A44->bgs[bgId].buf, tmpl->bufSize);
        g_02146A44->bgs[bgId].bufSize = tmpl->bufSize;
        g_02146A44->bgs[bgId].unk_08 = tmpl->unk_0c;
    } else {
        g_02146A44->bgs[bgId].buf = 0;
        g_02146A44->bgs[bgId].bufSize = 0;
        g_02146A44->bgs[bgId].unk_08 = 0;
    }

    g_02146A44->bgs[bgId].unk_15 = tmpl->unk_10;
    g_02146A44->bgs[bgId].type = (u8)type;
    g_02146A44->bgs[bgId].unk_16 = tmpl->unk_11;

    if (type == 0 && tmpl->unk_11 == 0) {
        g_02146A44->bgs[bgId].unk_17 = 0x20;
    } else {
        g_02146A44->bgs[bgId].unk_17 = 0x40;
    }

    BG_SYS_FillScrollArea(bgId, 0, tmpl->unk_00);
    BG_SYS_FillScrollArea(bgId, 3, tmpl->unk_04);
    BG_SYS_RotScale(bgId);

    g_02146A44->unk_170[bgId] = tmpl->unk_13 << 14;
    g_02146A44->unk_190[bgId] = tmpl->unk_12 << 11;
    g_02146A44->unk_1b0[bgId] = tmpl->unk_14;

    BG_SYS_SetupLayer(bgId, 0, tmpl->bufSize);
}

