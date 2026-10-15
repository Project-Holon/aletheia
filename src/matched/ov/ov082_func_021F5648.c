/*
 * function: FLD_FACEUP_Release
 * address:  0x021F5648
 * packet:   pkt_ov082_021F5648
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: BG3CNT 0x0400000E read-modify-written by the SDK inline G2_SetBG3ControlText; BLDCNT 0x04000050 store
 * symbols:
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   FIELD_PLACE_NAME_RestoreWindow  0x021BC5D4  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_RequestSysFrame  0x021904D0  thumb  ov021
 *   FLD_FACEUP_RestoreBgPriorities  0x021F56E4  thumb  ov082
 *   FLD_FACEUP_RestoreVisiblePlanes  0x021F56FC  thumb  ov082
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetFaceUpWorkPtr  0x02189A60  thumb  ov021
 */
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    char pad[8];
    u16 b0 : 2;
    u16 a : 4;
    u16 b6 : 1;
    u16 c : 1;
    u16 b : 5;
    u16 b13 : 1;
    u16 d : 2;
} Cfg;

typedef unsigned char  u8;
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void BG_SYS_FreeSlot(int a);
extern void FIELD_PLACE_NAME_RestoreWindow(u8 *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void FIELD_MSGBG_RequestSysFrame(u8 *p);
extern void FLD_FACEUP_RestoreBgPriorities(u8 *p);
extern void FLD_FACEUP_RestoreVisiblePlanes(int *p);
extern u32 func_020307B0(void *p);
extern u32 *FIELDMAP_GetFaceUpWorkPtr(int a);

#define reg_G2_BG3CNT  (*(volatile u16 *)0x0400000E)
#define reg_G2_BLDCNT  (*(volatile u16 *)0x04000050)

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;
typedef enum { GX_BG_COLORMODE_16 = 0 } GXBGColorMode;
typedef enum { GX_BG_SCRBASE_0x0000 = 0 } GXBGScrBase;
typedef enum { GX_BG_CHARBASE_0x00000 = 0 } GXBGCharBase;

static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode,
                                        GXBGScrBase screenBase, GXBGCharBase charBase)
{
    reg_G2_BG3CNT = (u16)((reg_G2_BG3CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

void FLD_FACEUP_Release(int a0, Cfg *p)
{
    int t = FIELDMAP_GetPlaceName((u8 *)a0);

    BG_SYS_FreeSlot(2);
    G2_SetBG3ControlText(p->d, p->c, p->b, p->a);
    FIELD_PLACE_NAME_RestoreWindow((u8 *)t);
    FIELD_MSGBG_RequestSysFrame((u8 *)FIELDMAP_GetMsgBg((u8 *)a0));
    reg_G2_BLDCNT = 0;
    FLD_FACEUP_RestoreBgPriorities((u8 *)p);
    FLD_FACEUP_RestoreVisiblePlanes((int *)p);
    func_020307B0(p);
    *FIELDMAP_GetFaceUpWorkPtr(a0) = 0;
}
