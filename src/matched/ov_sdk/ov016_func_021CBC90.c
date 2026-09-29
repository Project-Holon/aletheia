/*
 * function: DWCi_SceneSetSelectAp
 * address:  0x021CBC90
 * packet:   pkt_ov016_021CBC90
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HEAPlAllocEx                0x021d6414 arm
 *   initGraphics                     0x021cbcf0 arm
 *   DWCi_HLlLoad                     0x021bd674 arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   initObj                          0x021cbdf8 arm
 *   dispFocus                        0x021cc46c arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetselectap_bss             0x021de60c data
 *   procInit                         0x021cbf00 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol DWCi_SceneSetSelectAp (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBC90.c \
 *       --func DWCi_SceneSetSelectAp --addr 0x021CBC90 --region ov016 --cc 1.1p1 --arm --lang c99
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HLlLoad(int idx);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_ChangeScene(void (*scene)());

static void initGraphics(void);
static void initObj(void);
static void dispFocus(void);
static void procInit(void);

void DWCi_SceneSetSelectAp(void)
{
    SSSA *p = DWCi_HEAPlAllocEx(0x20, 4);

    scenesetselectap_bss.MemSssa = p;
    p->state = 0;
    initGraphics();
    DWCi_HLlLoad(1);
    DWCi_COMMENTlDispEx(0x2f, -1, 0);
    DWCi_CMNlStep(0);
    initObj();
    dispFocus();
    DWCi_ChangeScene(procInit);
}
