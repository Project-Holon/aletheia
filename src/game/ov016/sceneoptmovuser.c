/*
 * file:     sceneoptmovuser.c
 * unit:     yes
 * function: DWCi_SceneOptMovUser, initGraphics, procInit, procInit1, procInit2, procScene, DWCi_SceneOptMovUser_input, DWCi_SceneOptMovUser_draw, endScene, endScene1, endScene2, cbMov
 * address:  0x021C4110
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
 *   DWCi_MOVlGetChild  0x021C11F8  arm  ov016
 *   DWCi_FNTlFormBgEx  0x021D5A58  arm  ov016
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DWCi_FNTlDrawRect  0x021D5E5C  arm  ov016
 *   DWCi_FNTlRenewBg  0x021D5FC4  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovUserWork     0x021DE5C4  data
 *   cbMov  0x021C44D8  arm  ov016
 *   procInit  0x021C4260  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   Error                            0x021DE5C4  data
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   DWCi_MOVlAdmitChild              0x021C11EC  arm
 *   DWCi_MOVlEnd                     0x021C115C  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_MOVlIsEnd                   0x021C11B8  arm
 *   DWCi_SceneOptMenu                0x021C2A3C  arm
 *   DWCi_SceneOptMovComm             0x021C315C  arm
 *   DWCi_SceneOptMovFailure          0x021C3D8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   isUnloaded  0x021de5c4  data
 */
#include "../types.h"

#include "../sdk_mb.h"

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

typedef _Bool bool;

extern char *DWCi_MOVlGetChild(void);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void MIi_CpuClear16();
extern void MIi_CpuCopy16();
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
extern void DWCi_FNTlRenewBg(int x);
extern void DWCi_WINlInitEx(s32 msg, s32 type, bool dark, s32 n, s32 num);
void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(u32 v);
extern bool DWCi_EFFlCheck(int lcd);
extern s8 DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_MOVlChangeCallback(u32 v);
extern void DWCi_WINlEnd(void);
extern int DWCi_WINlIsInit(void);
extern void DWCi_MOVlAdmitChild();
extern void DWCi_MOVlEnd(void);
extern int DWCi_MOVlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptMovComm(void);
extern void DWCi_SceneOptMovFailure(void);
void DWCi_SceneOptMovUser(void);
void DWCi_SceneOptMovUser_input(void);
void DWCi_SceneOptMovUser_draw(void);
extern unsigned char gSceneOptMovUserWork[];
extern unsigned char Error[];
extern unsigned char isUnloaded;

/*
 * sdk:      DWCi_SceneOptMovUser (libdwcutil.TWL.HYB.a sceneoptmovuser.o)
 */

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void cbMov(int state);
void DWCi_SceneOptMovUser(void)
{
    unsigned short buf[11];
    MBUserInfo *info;
    void *bg;

    info = (MBUserInfo *)DWCi_MOVlGetChild();
    bg = DWCi_FNTlFormBgEx(0, 0);
    gSceneOptMovUserWork[1] = 0;
    gSceneOptMovUserWork[0] = 0;
    initGraphics();
    MIi_CpuClear16(0, buf, sizeof(buf));
    MIi_CpuCopy16(info->name, buf, info->nameLength * 2);
    DWCi_FNTlDrawRect(bg, 8, 0x35, 0xF0, 0x1C, 2, 0x480, buf);
    DWCi_FNTlRenewBg((int)bg);
    DWCi_MOVlChangeCallback((u32)cbMov);
    DWCi_WINlInitEx(0x1D, 4, 0, -1, 0);
    DWCi_ChangeScene((u32)procInit);
}

static void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB3B8, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((u32)procInit1);
}

static void procInit1(void)
{
    if (!DWCi_EFFlCheck(0))
        DWCi_ChangeScene((u32)procInit2);
}

static void procInit2(void)
{
    if (DWCi_WINlGet() == -2)
        return;
    DWCi_ChangeScene((u32)procScene);
}



static void procScene(void)
{
    DWCi_SceneOptMovUser_input();
    DWCi_SceneOptMovUser_draw();
    switch (DWCi_WINlGet()) {
    case 0:
        Error[1] = 0;
        DWCi_SNDlPlay(7);
        break;
    case 1:
        Error[1] = 1;
        DWCi_SNDlPlay(0xe);
        break;
    default:
        return;
    }
    DWCi_MOVlChangeCallback(0);
    DWCi_WINlEnd();
    DWCi_ChangeScene((u32)endScene);
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovUser_input.c \
 *       --func DWCi_SceneOptMovUser_input --addr 0x021C4348 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovUser_input(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMovUser_draw.c \
 *       --func DWCi_SceneOptMovUser_draw --addr 0x021C434C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneOptMovUser_draw(void)
{
}

static void endScene(void)
{
    if (DWCi_WINlIsInit())
        return;
    if (Error[1] == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((u32)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (Error[0] == 0 && Error[1] == 1)
        DWCi_MOVlAdmitChild();
    else
        DWCi_MOVlEnd();
    DWCi_ChangeScene((u32)endScene2);
}

static void endScene2(void)
{
    if (Error[0] || !Error[1]) {
        if (!DWCi_MOVlIsEnd())
            return;
    }
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 0x15);
    if (!Error[1]) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_SetParam_(0, 1);
    if (Error[0]) {
        DWCi_ChangeScene((u32)DWCi_SceneOptMovFailure);
        return;
    }
    if (Error[1] == 0) {
        DWCi_GXlInvisible(1, 1);
        DWCi_ChangeScene((u32)DWCi_SceneOptMenu);
        return;
    }
    DWCi_ChangeScene((u32)DWCi_SceneOptMovComm);
}

static void cbMov(int state)
{
    isUnloaded = 1;
}
