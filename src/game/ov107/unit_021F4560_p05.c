/*
 * file:     unit_021F4560_p05.c
 * unit:     yes
 * function: func_021F6158, func_021F61A4, func_021F628C
 * address:  0x021F6158
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WM_SetMPDataToPortEx             0x0208fcb4 arm
 *   MBi_CheckWmErrcode               0x021f6334 arm
 *   func_021F6158 0x021F6158 arm ov107
 *   g_021F6F90 0x021F6F90 data
 *   func_021F4EFC 0x021F4EFC arm ov107
 *   d_021F6F90   0x021F6F90  data
 */
#include "../../matched/include/G_WmBase.h"

typedef unsigned short u16;

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

typedef unsigned long u32;

extern int WM_SetMPDataToPortEx(void (*callback)(void *), void *arg, u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int func_021F6158(void *callback, unsigned short *sendData, unsigned short sendDataSize, unsigned short arg3, unsigned short pollbmp);
extern void func_021F4EFC(void *arg);
int func_021F61A4(unsigned short *buf, int len, int pollbmp);
u32 MBi_GetGgid(void);
extern struct WmBase g_021F6F90;
extern struct WmBase d_021F6F90;


static int MBi_SetMPData(void (*callback)(void *), u16 *sendData, u16 sendDataSize, u16 unused, u16 pollbmp)
{
    int errcode;

    errcode = WM_SetMPDataToPortEx(callback, 0, sendData, sendDataSize, pollbmp, 1, 3);
    MBi_CheckWmErrcode(0xF, errcode);
    return errcode;
}


/*
 * sdk:      MBi_SendMP (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F61A4(unsigned short *buf, int len, int pollbmp)
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


u32 MBi_GetGgid(void)
{
    return *(u32 *)(*(char **)(((char *)&d_021F6F90) + 0xC) + 8);
}
