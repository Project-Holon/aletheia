/*
 * function: isEnd
 * address:  0x021CB978
 * packet:   pkt_ov016_021CB978
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      isEnd (libdwcutil.TWL.HYB.a scenesetsearch.o)
 * symbols:
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SEARCHlGetApInfo            0x021CF114  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   g_021DE608                       0x021DE608  data
 *   procError                        0x021CBC44  arm   ov016
 *   endScene                         0x021CBAF4  arm   ov016
 */

#include "../include/G_SearchBss.h"

typedef _Bool bool;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x28];
    u8 state;
    u8 pad1[1];
} tagAPINFO;

extern struct SearchBss g_021DE608;

extern void DWCi_SNDlStop(void);
extern int DWCi_SEARCHlGetApInfo(void *info);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_BTNlDisable(void);
extern void DWCi_ChangeScene(void (*scene)());

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
