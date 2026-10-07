/*
 * function: endScene1
 * address:  0x021CC244
 * packet:   pkt_ov016_021CC244
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_SETTIGNlGet                 0x021cf404 arm
 *   DWCi_BTNlEnd                     0x021bcae4 arm
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetselectap_bss             0x021de60c data
 *   endScene2                        0x021cc2d0 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol endScene1 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CC244.c \
 *       --func endScene1 --addr 0x021CC244 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

typedef struct tagSETTINGINFO {
    unsigned char pad[0xE7];
    unsigned char setting;            /* 0xE7 */
} SETTINGINFO;

/* scenesetselectap.o .bss at 0x021DE60C, members at their vendor offsets */
typedef struct {
    unsigned char  pad0[0x1D];
    unsigned char  state;             /* 0x1D */
    unsigned char  pad1[2];
} SSSA;                               /* 0x20 */

typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    SSSA          *MemSssa;           /* 0x04 */
} SCENESETSELECTAP_BSS;
extern SCENESETSELECTAP_BSS scenesetselectap_bss;

extern bool DWCi_EFFlCheck(int lcd);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene2(void);

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) {
        return;
    }
    if (scenesetselectap_bss.MemSssa->state == 1) {
        if (scenesetselectap_bss.FocusPos == 3 || DWCi_SETTIGNlGet()->setting != 0xFF) {
            DWCi_BTNlEnd();
        }
    }
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene2);
}
