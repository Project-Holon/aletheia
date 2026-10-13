/*
 * file:     unit_021CB93C.c
 * unit:     yes
 * function: func_021CB93C, func_021CB960, func_021CB978, func_021CBAA0
 * address:  0x021CB93C
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
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   procScene                        0x021cb960 arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SEARCHlGetApInfo            0x021CF114  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   g_021DE608                       0x021DE608  data
 *   procError                        0x021CBC44  arm   ov016
 *   endScene                         0x021CBAF4  arm   ov016
 *   DWCi_IPTlCheckTrigger            0x021d6824 arm
 *   DWCi_BTNlSet                     0x021bcb28 arm
 *   DWCi_SceneSetSearch_draw  0x021CBAC4  arm
 */
#include "../../matched/include/G_SearchBss.h"

typedef _Bool bool;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 pad0[0x28];
    u8 state;
    u8 pad1[1];
} tagAPINFO;

extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021CBAA0(void);
extern void DWCi_SceneSetSearch_draw(void);
extern void func_021CBAC8(void);
extern void func_021CB978(void);
extern void DWCi_SNDlStop(void);
extern int DWCi_SEARCHlGetApInfo(void *info);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern void DWCi_BTNlSet(int idx);
void func_021CB960(void);
extern struct SearchBss g_021DE608;


static void procScene(void);


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


/*
 * Call func_021CBAA0, DWCi_SceneSetSearch_draw, func_021CBAC8, func_021CB978.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CB960.c \
 *       --func func_021CB960 --addr 0x021CB960 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CB960(void)
{
    func_021CBAA0();
    DWCi_SceneSetSearch_draw();
    func_021CBAC8();
    func_021CB978();
}


static void procError(void);

static void endScene(void);


static void isEnd(void)
{
    tagAPINFO *info;
    int num;
    int i;

    g_021DE608.Count++;
    if (g_021DE608.Count < 300)
        return;
    DWCi_SNDlStop();
    num = DWCi_SEARCHlGetApInfo(&info);
    if (num == 0) {
        g_021DE608.Choose = 2;
        DWCi_WINlInitEx(15, 1, 1, -1, 0);
        DWCi_SNDlPlay(18);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        return;
    }
    for (i = 0; i < num; i++) {
        if (((tagAPINFO *)((u8 *)info + i * 42))->state != 2)
            break;
    }
    if (i == num) {
        g_021DE608.Choose = 3;
        DWCi_WINlInitEx(14, 1, 1, -1, 0);
        DWCi_SNDlPlay(18);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        return;
    }
    g_021DE608.Choose = 1;
    DWCi_SNDlPlay(15);
    DWCi_ChangeScene(endScene);
}


static void input(void)
{
    if (!DWCi_IPTlCheckTrigger(2)) {
        return;
    }
    DWCi_SNDlStop();
    DWCi_BTNlSet(0);
}
