/*
 * file:     unit_021F3D04_p01.c
 * unit:     yes
 * function: func_021F3D04, func_021F3DF4, func_021F3E9C, func_021F3F0C, func_021F3F34, func_021F3F78, func_021F3FA4, func_021F3FC8, func_021F4054, func_021F40F4, func_021F4140, func_021F42A4
 * address:  0x021F3D04
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
 *   MIi_CpuClear16   0x02082A48  arm
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   func_021F3F0C    0x021F3F0C  arm  ov107
 *   func_020788AC  0x020788AC  arm
 *   func_020789FC  0x020789FC  arm
 *   func_02078A94  0x02078A94  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 *   g_021F6EF4     0x021F6EF4  data
 *   d_021F6EF4   0x021F6EF4  data
 *   func_021F4140  0x021F4140  arm  ov107
 *   func_021F42A4  0x021F42A4  arm  ov107
 *   func_021F42D4  0x021F42D4  arm  ov107
 *   g_021F6F20  0x021F6F20  data
 *   func_021F628C  0x021F628C  arm  ov107
 *   func_021F62A0  0x021F62A0  arm  ov107
 *   func_02090CD4  0x02090CD4  arm
 *   func_021F3FA4  0x021F3FA4  arm  ov107
 *   sUnlockFunc    0x021F6EF4  data
 *   mbss           0x021F6F0C  data
 *   bsendBuff      0x021F6F20  data
 *   MBi_calc_cksum  0x021F3CB8  arm  ov107
 *   WM_SetGameInfo  0x02090CD4  arm
 */
#include "../../matched/include/G_SUnlock.h"
#include "../../matched/include/G_MbBeacon.h"

struct FSFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021F3D04;

typedef struct {
    unsigned char b[0x48];
} FSFile;

typedef signed int     s32;

typedef unsigned int   u32_021F3DF4;

typedef struct MBGameInfo {
    unsigned char pad[0x4BC];
    struct MBGameInfo *next;
} MBGameInfo;

typedef unsigned long u32_021F3F78;

typedef struct {
    unsigned short sum;
    unsigned char fragmentNo;
    unsigned char fragmentMaxNum;
    unsigned char size;
    unsigned char rsv;
    unsigned short data[0x31];
} MbBeaconFixed;

typedef struct {
    unsigned long ggid;
    unsigned char dataAttr : 2;
    unsigned char fileNo : 6;
    unsigned char seqNoFixed;
    unsigned char seqNoVolat;
    unsigned char beaconNo;
    union {
        MbBeaconFixed fixed;
        unsigned short raw[0x34];
    } data;
} MbBeacon;

typedef struct {
    void *top;
    unsigned char *nowGInfop;
    unsigned char *nowFixedp;
    unsigned char state;
    unsigned char pad1;
    unsigned char seqNoVolat;
    unsigned char fragmentNo;
    unsigned char fragmentMaxNum;
    unsigned char beaconNo;
} MbSendStatus;

extern void MIi_CpuClear16(u16 data, void *destp, u32_021F3D04 size);
extern void MIi_CpuClearFast(u32_021F3D04 data, void *destp, u32_021F3D04 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32_021F3D04 size);
extern int func_021F3F0C(const u16 *str);
extern void func_020788AC(FSFile *file);
extern int func_020789FC(struct FSFile *file, const char *path, u32_021F3DF4 mode);
extern u32_021F3DF4 func_02078A94(struct FSFile *file);
extern int func_02078A80(FSFile *file);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_021F4140(unsigned long ggid, unsigned short tgid, unsigned char attribute);
extern void func_021F42A4(void);
extern void func_021F42D4(unsigned long ggid, unsigned short tgid, unsigned char attribute);
extern unsigned long func_021F628C(void);
extern unsigned short func_021F62A0(void);
extern int func_02090CD4(void *callback, void *userGameInfo, unsigned short size, unsigned long ggid, unsigned short tgid, unsigned char attr);
extern void func_021F3FA4(void);
extern unsigned short MBi_calc_cksum(unsigned short *buf, int length);
extern int WM_SetGameInfo(void *callback, unsigned short *userGameInfo, unsigned short size,
                          unsigned long ggid, unsigned short tgid, unsigned char attr);
void func_021F3D04(u8 *gameInfop, const u8 *mbGameRegp, const u8 *parent);
int func_021F3DF4(char *filePathp, unsigned char *iconp, int char_flag);
void func_021F3E9C(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag);
int mystrlen(const u16 *str);
void func_021F3F34(MBGameInfo *newGameInfop);
void MB_InitSendGameInfoStatus(void);
void MBi_ClearSendStatus(void);
void func_021F3FC8(unsigned long ggid, unsigned short tgid, unsigned char attribute);
int func_021F4054(void);
void func_021F40F4(void);
void MBi_InitSendVolatBeacon(void);
extern struct SUnlock g_021F6EF4;
extern struct SUnlock d_021F6EF4;
extern struct MbBeacon g_021F6F20;




void func_021F3D04(u8 *gameInfop, const u8 *mbGameRegp, const u8 *parent)
{
    int len;
    int icon_disable;
    int icon_disable2;

    MIi_CpuClear16(0, gameInfop, 0x4c0);
    icon_disable = 1;
    gameInfop[0x4b2] = 0;
    if (func_021F3DF4((char *)(*(const char **)(mbGameRegp + 0xc)), gameInfop, 1))
        icon_disable = 0;
    icon_disable2 = 0;
    if (!func_021F3DF4((char *)(*(const char **)(mbGameRegp + 0x10)), gameInfop, 0))
        icon_disable2 = 1;
    icon_disable |= icon_disable2;
    if (icon_disable) {
        gameInfop[0x4b2] = 1;
        MIi_CpuClearFast(0, gameInfop, 0x220);
    }
    *(u32_021F3D04 *)(gameInfop + 0x4b8) = *(const u32_021F3D04 *)(mbGameRegp + 0x14);
    if (parent != 0)
        MIi_CpuCopy16(parent, gameInfop + 0x220, 0x16);
    gameInfop[0x236] = mbGameRegp[0x18];
    len = func_021F3F0C(*(const u16 **)(mbGameRegp + 4));
    MIi_CpuCopy16(*(const u16 **)(mbGameRegp + 4), gameInfop + 0x238, (u16)(len * 2));
    MIi_CpuCopy16(*(const u16 **)(mbGameRegp + 8), gameInfop + 0x298, 0xc0);
    gameInfop[0x358] = 1;
    *(u16 *)(gameInfop + 0x35a) = 1;
    *(u16 *)(gameInfop + 0x4b0) = 1;
}




/*
 * sdk:      MBi_ReadIconInfo (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
int func_021F3DF4(char *filePathp, unsigned char *iconp, int char_flag)
{
    FSFile file;
    long size;

    if (char_flag)
        size = 0x200;
    else
        size = 0x20;
    if (char_flag)
        iconp += 0x20;
    if (filePathp == 0)
        return 0;
    func_020788AC(&file);
    if (!func_020789FC((struct FSFile *)(&file), filePathp, 1))
        return 0;
    if (size != func_02078A94((struct FSFile *)(&file))) {
        func_02078A80(&file);
        return 0;
    }
    func_02078B70((struct FSFile *)(&file), iconp, size);
    func_02078A80(&file);
    return 1;
}




/*
 * sdk:      MB_UpdateGameInfoMember (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
void func_021F3E9C(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag)
{
    unsigned char playerNum = 1;
    int i;

    MIi_CpuCopy16(member, gameInfop + 0x35E, 0x14A);
    for (i = 0; i < 15; i++) {
        if (nowPlayerFlag & (2 << i))
            playerNum++;
    }
    gameInfop[0x358] = playerNum;
    *(unsigned short *)(gameInfop + 0x35A) = nowPlayerFlag | 1;
    *(unsigned short *)(gameInfop + 0x35C) = changePlayerFlag;
    ((unsigned char *)gameInfop)[0x4B4] = ((unsigned char *)gameInfop)[0x4B4] + 1;
}




int mystrlen(const u16 *str)
{
    int len = 0;

    while (*str++)
        len++;

    return len;
}




/*
 * sdk:      MB_AddGameInfo (libmb.TWL.HYB.a mb_gameinfo.o)
 */
void func_021F3F34(MBGameInfo *newGameInfop)
{
    MBGameInfo *gInfop;

    gInfop = g_021F6EF4.list;
    if (gInfop == 0) {
        g_021F6EF4.list = newGameInfop;
    } else {
        while (gInfop->next != 0)
            gInfop = gInfop->next;
        gInfop->next = newGameInfop;
    }
    newGameInfop->next = 0;
}




void MB_InitSendGameInfoStatus(void)
{
    *(u32_021F3F78 *)(((char *)&d_021F6EF4) + 0x18) = 0;
    *(u32_021F3F78 *)(((char *)&d_021F6EF4) + 0x1C) = 0;
    *(u8 *)(((char *)&d_021F6EF4) + 0x24) = 1;
    *(u32_021F3F78 *)(((char *)&d_021F6EF4) + 0x14) = 0;
    MBi_ClearSendStatus();
}




void MBi_ClearSendStatus(void)
{
    ((char *)&d_021F6EF4)[0x25] = 0;
    ((char *)&d_021F6EF4)[0x26] = 0;
    ((char *)&d_021F6EF4)[0x27] = 0;
    ((char *)&d_021F6EF4)[0x28] = 0;
    ((char *)&d_021F6EF4)[0x29] = 0;
}




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



static void *sSendVolatCallback = 0;


static void *sSendVolatCallbackTiming = 0;


static void *mbrsp = 0;


static void *brecvBuffp = 0;


static void (*sLockFunc)(void) = 0;


static void (*sUnlockFunc)(void) = 0;


static MbSendStatus mbss = {0};


extern MbBeacon bsendBuff __attribute__((aligned(32)));



static inline void MI_CpuClear16(void *dest, unsigned long size) { MIi_CpuClear16(0, dest, size); }


static inline void MI_CpuCopy16(const void *src, void *dest, unsigned long size) { MIi_CpuCopy16(src, dest, size); }



static void MBi_SendFixedBeacon(unsigned long ggid, unsigned short tgid, unsigned char attribute)
{
    unsigned long lastAddr = (unsigned long)mbss.nowGInfop + 0x358;

    if ((unsigned long)mbss.nowFixedp + 0x62 <= lastAddr) {
        bsendBuff.data.fixed.size = 0x62;
    } else {
        bsendBuff.data.fixed.size = (unsigned char)(lastAddr - (unsigned long)mbss.nowFixedp);
        MI_CpuClear16((void *)((unsigned char *)bsendBuff.data.fixed.data + bsendBuff.data.fixed.size),
                      (unsigned long)(0x62 - bsendBuff.data.fixed.size));
    }
    MI_CpuCopy16(mbss.nowFixedp, bsendBuff.data.fixed.data, bsendBuff.data.fixed.size);
    bsendBuff.data.fixed.fragmentNo = mbss.fragmentNo;
    bsendBuff.data.fixed.fragmentMaxNum = mbss.fragmentMaxNum;
    bsendBuff.dataAttr = mbss.nowGInfop[0x4B2];
    bsendBuff.seqNoFixed = mbss.nowGInfop[0x4B3];
    bsendBuff.seqNoVolat = mbss.seqNoVolat;
    bsendBuff.ggid = *(unsigned long *)(mbss.nowGInfop + 0x4B8);
    bsendBuff.fileNo = mbss.nowGInfop[0x4B5];
    bsendBuff.beaconNo = mbss.beaconNo++;
    bsendBuff.data.fixed.sum = 0;
    bsendBuff.data.fixed.sum = MBi_calc_cksum((unsigned short *)&bsendBuff.data, sizeof(bsendBuff.data));
    mbss.fragmentNo++;
    if (mbss.fragmentNo < mbss.fragmentMaxNum)
        mbss.nowFixedp += 0x62;
    else
        mbss.state = 4;
    WM_SetGameInfo(0, (unsigned short *)&bsendBuff, 0x70, ggid, tgid, (unsigned char)(attribute | 3));
}



void MBi_InitSendVolatBeacon(void)
{
    *(u16 *)(*(char **)(((char *)&d_021F6EF4) + 0x1C) + 0x4B0) = 1;
    *(u8 *)(((char *)&d_021F6EF4) + 0x26) = *(u8 *)(*(char **)(((char *)&d_021F6EF4) + 0x1C) + 0x4B4);
    *(u8 *)(((char *)&d_021F6EF4) + 0x24) = 5;
}
