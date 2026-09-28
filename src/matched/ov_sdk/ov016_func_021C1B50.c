/*
 * function: procInit1
 * address:  0x021C1B50
 * packet:   pkt_ov016_021C1AE8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   dispPushButton                   0x021C1EDC  arm
 *   endScene                         0x021C1D4C  arm
 *   endScene1                        0x021C1D6C  arm
 *   endScene2                        0x021C1DC4  arm
 *   moveFocus                        0x021C1E70  arm
 *   procInit1                        0x021C1B50  arm
 *   procInit2                        0x021C1B90  arm
 *   procScene                        0x021C1BB4  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenemenu.o), symbol procInit1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C1B50.c \
 *       --func procInit1 --addr 0x021C1B50 --region ov016 --cc 1.1p1 --arm --lang c99
 */
typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

/* scenemenu.o .bss at 0x021DE59C, members at their vendor offsets */
typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    void          *Palette;           /* 0x04 */
} SCENEMENU_BSS;
extern SCENEMENU_BSS scenemenu_bss;

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;
extern const SCENEMENU_RODATA scenemenu_rodata;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;
extern const PALETTE_INIT scenemenu_init_20658;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_SceneEnd(void);

static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void moveFocus(int dir);
static void dispPushButton(void);

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(0);
    DWCi_ChangeScene(procInit2);
}
