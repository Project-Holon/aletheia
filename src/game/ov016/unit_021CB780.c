/*
 * file:     unit_021CB780.c
 * function: DWCi_SceneSetSearch
 * address:  0x021CB780
 * packet:   pkt_ov016_021CB780
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics                     0x021cb7ec arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_ANIMElInitEx                0x021bc820 arm
 *   DWCi_SEARCHlInit                 0x021cef20 arm
 *   DWCi_SEARCHlBegin                0x021cef84 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetsearch_bss               0x021de608 data
 *   procInit                         0x021cb894 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetsearch.o), symbol DWCi_SceneSetSearch (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB780.c \
 *       --func DWCi_SceneSetSearch --addr 0x021CB780 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern void DWCi_HLlLoadSet(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SEARCHlInit(void);
extern bool DWCi_SEARCHlBegin(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());

/* scenesetsearch.o .bss at 0x021DE608 */
typedef struct {
    unsigned char  Choose;            /* 0x00 */
    unsigned short Count;             /* 0x02 */
} SCENESETSEARCH_BSS;
extern SCENESETSEARCH_BSS scenesetsearch_bss;

static void initGraphics(void);
static void procInit(void);

void DWCi_SceneSetSearch(void)
{
    scenesetsearch_bss.Count = 0;
    scenesetsearch_bss.Choose = 0;
    initGraphics();
    DWCi_COMMENTlDispEx(0x33, -1, 0);
    DWCi_HLlLoadSet();
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x33);
    DWCi_ANIMElInitEx(0);
    DWCi_SEARCHlInit();
    DWCi_SEARCHlBegin();
    DWCi_SNDlPlay(0xa);
    DWCi_ChangeScene(procInit);
}
