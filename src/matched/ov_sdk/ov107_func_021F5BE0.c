/*
 * function: MBi_StartCommon
 * address:  0x021F5BE0
 * packet:   pkt_ov107_021F5BE0
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_StartCommon (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   func_021F6148 0x021F6148 arm ov107
 *   WM_Initialize 0x0208F370 arm
 *   WM_SetIndCallback 0x0208EAC8 arm
 *   func_021F4628 0x021F4628 thumb ov107
 *   g_021F6F90 0x021F6F90 data
 */

#include "../include/G_WmBase.h"

typedef struct {
    unsigned short dmaNo;
    unsigned short pad;
    void *wmSysBuf;
    int pad2;
    unsigned char *work;
    unsigned char *ext;
} WmBase;

extern struct WmBase g_021F6F90;

extern void func_021F6148(unsigned short time);
extern int WM_Initialize(void *wmSysBuf, void *callback, unsigned short dmaNo);
extern int WM_SetIndCallback(void *callback);
extern void func_021F4628(void);

int MBi_StartCommon(void)
{
    int errcode = 0;

    *(unsigned short *)(g_021F6F90.work + 0x528) = errcode;
    *(unsigned short *)(g_021F6F90.work + 0x52A) = errcode;
    *(unsigned short *)(g_021F6F90.work + 0x526) = errcode;
    *(unsigned short *)(g_021F6F90.work + 0x548) = errcode;
    func_021F6148(0x1E);
    if (*(int *)(((unsigned char *)g_021F6F90.ext) + 0x1320) == 0) {
        do {
            errcode = WM_Initialize(g_021F6F90.wmSysBuf, *(void **)(g_021F6F90.work + 0x508), g_021F6F90.WM_DMA_NO);
        } while (errcode == 4);
        if (errcode != 2) {
            return 8;
        }
        WM_SetIndCallback(*(void **)(g_021F6F90.work + 0x508));
        g_021F6F90.work[0x50D] = 1;
        return 0;
    }
    WM_SetIndCallback(*(void **)(g_021F6F90.work + 0x508));
    g_021F6F90.work[0x50D] = 1;
    func_021F4628();
    return errcode;
}
