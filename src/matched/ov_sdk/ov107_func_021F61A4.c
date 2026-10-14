/*
 * function: MBi_SendMP
 * address:  0x021F61A4
 * packet:   pkt_ov107_021F61A4
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_SendMP (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   func_021F6158 0x021F6158 arm ov107
 *   g_021F6F90 0x021F6F90 data
 *   func_021F4EFC 0x021F4EFC arm ov107
 */

#include "../include/G_WmBase.h"

typedef struct {
    char pad[0x508];
    void *callback;
    char pad2[4];
    unsigned char sending;
} MbWork;

typedef struct {
    unsigned short dmaNo;
    unsigned short pad;
    void *wmSysBuf;
    int pad2;
    unsigned char *work;
} WmBase;

extern struct WmBase g_021F6F90;

extern int func_021F6158(void *callback, unsigned short *sendData, unsigned short sendDataSize, unsigned short arg3, unsigned short pollbmp);
extern void func_021F4EFC(void *arg);

int MBi_SendMP(unsigned short *buf, int len, int pollbmp)
{
    unsigned short size = len;
    unsigned short pollbitmap = pollbmp;
    int errcode;

    if (*(unsigned short *)(g_021F6F90.work + 0x528) == 0 || *(unsigned short *)(g_021F6F90.work + 0x526) == 1) {
        return 1;
    }
    switch (*(unsigned short *)(g_021F6F90.work + 0x524)) {
    case 1:
        errcode = func_021F6158(*(void **)(g_021F6F90.work + 0x508), buf, size, *(unsigned short *)(g_021F6F90.work + 0x52C) == 0 ? 0x3E8 : 0, pollbitmap);
        if (errcode == 2) {
            g_021F6F90.work[0x50C] = 1;
        }
        return errcode == 2 ? 0 : errcode;
    case 2:
        errcode = func_021F6158(func_021F4EFC, buf, size, 0, pollbitmap);
        if (errcode == 2) {
            g_021F6F90.work[0x50C] = 1;
        }
        return errcode == 2 ? 0 : errcode;
    }
    return 1;
}
