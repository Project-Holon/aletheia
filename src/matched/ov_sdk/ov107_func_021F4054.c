/*
 * function: func_021F4054
 * address:  0x021F4054
 * packet:   pkt_ov107_021F4054
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ReadyBeaconSendStatus (libmb.TWL.HYB.a(mb_gameinfo.o))
 *
 * symbols:
 *   g_021F6EF4  0x021F6EF4  data
 *   g_021F6F20  0x021F6F20  data
 *   func_021F628C  0x021F628C  arm  ov107
 *   func_021F62A0  0x021F62A0  arm  ov107
 *   func_02090CD4  0x02090CD4  arm
 *   func_021F3FA4  0x021F3FA4  arm  ov107
 */

#include "../include/G_SUnlock.h"
#include "../include/G_MbBeacon.h"

extern struct SUnlock g_021F6EF4;
extern struct MbBeacon g_021F6F20;
extern unsigned long func_021F628C(void);
extern unsigned short func_021F62A0(void);
extern int func_02090CD4(void *callback, void *userGameInfo, unsigned short size, unsigned long ggid, unsigned short tgid, unsigned char attr);
extern void func_021F3FA4(void);

int func_021F4054(void)
{
    unsigned char *nextGameInfop;

    if (*(int *)(((unsigned char *)&g_021F6EF4) + 0x18) == 0) {
        unsigned long ggid = func_021F628C();
        func_02090CD4(0, ((unsigned char *)&g_021F6F20), 0x70, ggid, func_021F62A0(), 8);
        return 0;
    }
    if (*(unsigned char **)(((unsigned char *)&g_021F6EF4) + 0x1C) != 0 && (nextGameInfop = *(unsigned char **)(*(unsigned char **)(((unsigned char *)&g_021F6EF4) + 0x1C) + 0x4BC)) != 0) {
    } else {
        nextGameInfop = *(unsigned char **)(((unsigned char *)&g_021F6EF4) + 0x18);
    }
    *(unsigned char **)(((unsigned char *)&g_021F6EF4) + 0x1C) = nextGameInfop;
    func_021F3FA4();
    ((unsigned char *)&g_021F6EF4)[0x26] = (*(unsigned char **)(((unsigned char *)&g_021F6EF4) + 0x1C))[0x4B4];
    ((unsigned char *)&g_021F6EF4)[0x24] = 2;
    return 1;
}
