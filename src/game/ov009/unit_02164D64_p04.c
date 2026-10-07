/*
 * file:     unit_02164D64_p04.c
 * unit:     yes
 * function: func_021656D0, func_0216576C
 * address:  0x021656D0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA7D4  0x021AA7D4  data ov009
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WCMi_WmifGetAllowedChannel       0x02166de4 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   WCMi_NwmifGetAllowedChannel      0x02731f00 arm
 */
#include "../../matched/include/G_WCMState.h"

typedef struct WCMWork {
    unsigned char pad0[0x12D4];
    unsigned long option;
} WCMWork;

typedef struct WCMState WCMState;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern char *WCMi_GetSystemWork(void);
extern unsigned short WCMi_WmifGetAllowedChannel(void);
extern int OS_IsRunOnTwl(void);
extern unsigned short WCMi_NwmifGetAllowedChannel(void);
unsigned long func_021656D0(unsigned long option);
unsigned short WCM_GetAllowedChannel(void);
extern struct WCMState g_021AA7D4;


unsigned long func_021656D0(unsigned long option)
{
    unsigned long e;
    unsigned long filter;
    unsigned long old_option;

    e = OS_DisableInterrupts();
    filter = 0;
    old_option = ((WCMWork *)g_021AA7D4.work)->option;
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    if ((option & 0x8000) != 0) {
        filter |= 0x3FFE;
        if ((option & 0x3FFE) == 0) {
            option |= 0xA082;
        }
    }
    if ((option & 0x20000) != 0) {
        filter |= 0x10000;
    }
    if ((option & 0x80000) != 0) {
        filter |= 0x40000;
    }
    if ((option & 0x200000) != 0) {
        filter |= 0x100000;
    }
    if ((option & 0x800000) != 0) {
        filter |= 0x400000;
    }
    ((WCMWork *)g_021AA7D4.work)->option = option | (old_option & ~filter);
    OS_RestoreInterrupts(e);
    return old_option;
}


unsigned short WCM_GetAllowedChannel(void)
{
    char *w = WCMi_GetSystemWork();

    if (*(unsigned char *)(w + 0x1000 + 0x2de) >= 3 &&
        *(unsigned char *)(w + 0x1000 + 0x2de) <= 10) {
        switch (*(unsigned char *)(w + 0x1000 + 0x2df)) {
        case 1:
            return WCMi_WmifGetAllowedChannel();
        case 2:
            if (OS_IsRunOnTwl())
                return WCMi_NwmifGetAllowedChannel();
            break;
        }
    }
    return 0;
}
