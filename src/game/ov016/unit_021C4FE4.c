/*
 * file:     unit_021C4FE4.c
 * function: endScene
 * address:  0x021C4FE4
 * packet:   pkt_ov016_021C4F04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Count                            0x021DE5BC  data
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   GX_LoadBG2Scr                    0x0207EB78  arm
 *   endScene                         0x021C3CA8  arm
 *   endScene1                        0x021C5028  arm
 *   initGraphics                     0x021C3BBC  arm
 *   procInit                         0x021C3C28  arm
 *   procInit1                        0x021C3C64  arm
 *   procScene                        0x021C3C94  arm
 *   sceneoptmovdisco_str_20611       0x021DB390  data
 *   wait                             0x021C3D58  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovdisco), symbol endScene (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * layout/symbols_sdk.txt files this copy under sceneoptmovdisco; its bytes equal the object's own
 * function and only the pool words differ (the copy's own data and next scene step).
 * The object that owns this copy is not identified; the C is the same either way.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C4FE4.c \
 *       --func endScene --addr 0x021C4FE4 --region ov016 --cc 1.1p1 --arm --lang c99
 */
typedef _Bool bool;

/* sceneoptmovdisco .bss */
extern unsigned char Count;
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];

extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadBG2Scr(void *src, unsigned long offset, unsigned long size);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SceneOptMenu(void);

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procScene(void);
static void endScene(void);
static void endScene1(void);
static void wait(void);

#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)0x04001008)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)0x0400100A)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)0x0400000A)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)0x0400000C)

static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene1);
}
