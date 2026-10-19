/*
 * file:     sceneoptmovdisconnect.c
 * unit:     yes
 * function: DWCi_SceneOptMovDisconnect, initGraphics, DWCi_SceneOptMovDisconnectProcInit, DWCi_SceneOptMovDisconnectProcInit1, DWCi_SceneOptMovDisconnect_procScene, DWCi_SceneOptMovDisconnect_draw, DWCi_SceneOptMovDisconnectEndScene, DWCi_SceneOptMovDisconnectEndScene1, wait
 * address:  0x021C3B8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_CMNlMsgDraw               0x021BD29C  arm  ov016
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
 *   procScene                        0x021C3C94  arm
 *   sceneoptmovdisco_str_20611       0x021DB390  data
 */
#define reg_G2S_DB_BG0CNT (*(volatile unsigned short *)0x04001008)
#define reg_G2S_DB_BG1CNT (*(volatile unsigned short *)0x0400100A)
#define reg_G2_BG1CNT     (*(volatile unsigned short *)0x0400000A)
#define reg_G2_BG2CNT     (*(volatile unsigned short *)0x0400000C)
typedef _Bool bool;

extern void DWCi_CMNlMsgDraw(int);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadBG2Scr(void *src, unsigned long offset, unsigned long size);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu(void);
void DWCi_SceneOptMovDisconnect(void);
void DWCi_SceneOptMovDisconnect_procScene(void);
void DWCi_SceneOptMovDisconnect_draw(void);
/* sceneoptmovdisco .bss */
extern unsigned char Count;
/* the resource file name, the compiler's @20611 in .rodata */
extern char sceneoptmovdisco_str_20611[];

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void endScene(void);
static void endScene1(void);
static void wait(void);


void DWCi_SceneOptMovDisconnect(void)
{
    *(unsigned char *)0x021DE5BC = 0;
    initGraphics();
    DWCi_CMNlMsgDraw(0x21);
    DWCi_ChangeScene(procInit);
}


static void procScene(void);


static void initGraphics(void)
{
    DWCi_CMNlLoadResource(sceneoptmovdisco_str_20611, GX_LoadBG2Scr);
    reg_G2S_DB_BG0CNT = (unsigned short)((reg_G2S_DB_BG0CNT & ~3) | 3);
    reg_G2S_DB_BG1CNT = (unsigned short)((reg_G2S_DB_BG1CNT & ~3) | 3);
    reg_G2_BG1CNT = (unsigned short)((reg_G2_BG1CNT & ~3) | 3);
    reg_G2_BG2CNT = (unsigned short)((reg_G2_BG2CNT & ~3) | 3);
}


static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}


static void procInit1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_MOVlIsEnd())
        return;
    DWCi_ChangeScene(procScene);
}


/*
 * Call wait, DWCi_SceneOptMovDisconnect_draw.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovDisconnect_procScene.c \
 *       --func DWCi_SceneOptMovDisconnect_procScene --addr 0x021C3C94 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovDisconnect_procScene(void)
{
    wait();
    DWCi_SceneOptMovDisconnect_draw();
}


/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovDisconnect_draw.c \
 *       --func DWCi_SceneOptMovDisconnect_draw --addr 0x021C3CA4 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovDisconnect_draw(void)
{
}


static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene1);
}


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    DWCi_ChangeScene(DWCi_SceneOptMenu);
}


static void wait(void)
{
    if (++Count >= 120)
        DWCi_ChangeScene(endScene);
}
