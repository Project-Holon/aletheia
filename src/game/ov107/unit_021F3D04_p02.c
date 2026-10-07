/*
 * file:     unit_021F3D04_p02.c
 * unit:     yes
 * function: func_021F3FC8, func_021F4054, func_021F40F4
 * address:  0x021F3FC8
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
 *   g_021F6EF4  0x021F6EF4  data
 *   func_021F4140  0x021F4140  arm  ov107
 *   func_021F42A4  0x021F42A4  arm  ov107
 *   func_021F42D4  0x021F42D4  arm  ov107
 *   g_021F6F20  0x021F6F20  data
 *   func_021F628C  0x021F628C  arm  ov107
 *   func_021F62A0  0x021F62A0  arm  ov107
 *   func_02090CD4  0x02090CD4  arm
 *   func_021F3FA4  0x021F3FA4  arm  ov107
 */
#include "../../matched/include/G_SUnlock.h"
#include "../../matched/include/G_MbBeacon.h"

extern void func_021F4140(unsigned long ggid, unsigned short tgid, unsigned char attribute);
extern void func_021F42A4(void);
extern void func_021F42D4(unsigned long ggid, unsigned short tgid, unsigned char attribute);
extern unsigned long func_021F628C(void);
extern unsigned short func_021F62A0(void);
extern int func_02090CD4(void *callback, void *userGameInfo, unsigned short size, unsigned long ggid, unsigned short tgid, unsigned char attr);
extern void func_021F3FA4(void);
void func_021F3FC8(unsigned long ggid, unsigned short tgid, unsigned char attribute);
int func_021F4054(void);
void func_021F40F4(void);
extern struct SUnlock g_021F6EF4;
extern struct MbBeacon g_021F6F20;


/*
 * sdk:      MB_SendGameInfoBeacon (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
void func_021F3FC8(unsigned long ggid, unsigned short tgid, unsigned char attribute)
{
    while (1) {
        switch (((unsigned char *)&g_021F6EF4)[0x24]) {
        case 0:
        case 1:
            if (!func_021F4054())
                return;
            break;
        case 2:
            func_021F40F4();
            break;
        case 3:
            func_021F4140(ggid, tgid, attribute);
            return;
        case 4:
            func_021F42A4();
            break;
        case 5:
            func_021F42D4(ggid, tgid, attribute);
            return;
        case 6:
            break;
        }
    }
}


/*
 * sdk:      MBi_ReadyBeaconSendStatus (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
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


void func_021F40F4(void)
{
    if (((unsigned char *)&g_021F6EF4)[0x24] != 2)
        return;
    if (*(unsigned char *)(*(char **)(((unsigned char *)&g_021F6EF4) + 0x1C) + 0x4B2) == 0) {
        ((unsigned char *)&g_021F6EF4)[0x28] = 9;
        *(void **)(((unsigned char *)&g_021F6EF4) + 0x20) = *(char **)(((unsigned char *)&g_021F6EF4) + 0x1C);
    } else {
        ((unsigned char *)&g_021F6EF4)[0x28] = 4;
        *(void **)(((unsigned char *)&g_021F6EF4) + 0x20) = *(char **)(((unsigned char *)&g_021F6EF4) + 0x1C) + 0x220;
    }
    ((unsigned char *)&g_021F6EF4)[0x24] = 3;
}
