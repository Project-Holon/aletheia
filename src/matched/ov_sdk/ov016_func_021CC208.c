/*
 * function: endScene
 * address:  0x021CC208
 * packet:   pkt_ov016_021CC208
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_STEPlEnd                    0x021d0580 arm
 *   DWCi_BTNlDisable                 0x021bcb9c arm
 *   DWCi_EFFlWait                    0x021d5790 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetselectap_bss             0x021de60c data
 *   endScene1                        0x021cc244 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol endScene (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CC208.c \
 *       --func endScene --addr 0x021CC208 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

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

extern void DWCi_STEPlEnd(void);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene1(void);

static void endScene(void)
{
    if (scenesetselectap_bss.MemSssa->state == 2) {
        DWCi_STEPlEnd();
    }
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
