/*
 * file:     mb_gameinfo.c
 * unit:     yes
 * function: MBi_MakeGameInfo, MBi_ReadIconInfo, MB_UpdateGameInfoMember, mystrlen, MB_AddGameInfo, MB_InitSendGameInfoStatus, MBi_ClearSendStatus, MB_SendGameInfoBeacon, MBi_ReadyBeaconSendStatus, MBi_InitSendFixedBeacon, MBi_SendFixedBeacon, MBi_InitSendVolatBeacon, MBi_SendVolatBeacon, MBi_CheckMBParent
 * address:  0x021F3D04
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuClear16   0x02082A48  arm
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   FS_InitFile  0x020788AC  arm
 *   FS_OpenFileEx  0x020789FC  arm
 *   FS_GetFileLength  0x02078A94  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_ReadFile  0x02078B70  arm
 *   MBi_GetGgid  0x021F628C  arm  ov107
 *   MBi_GetTgid  0x021F62A0  arm  ov107
 *   MBi_calc_cksum  0x021F3CB8  arm  ov107
 *   WM_SetGameInfo  0x02090CD4  arm
 *   sMb 0x021F6EF4 data
 *   bsendBuff 0x021F6F20 data
 */
#include "../types.h"

#include "../sdk_fs.h"

#include "../sdk_mb.h"

typedef struct MbGameInfo {
    u8  fixedData[0x358];
    u8  nowPlayerNum;
    u8  pad359;
    u16 nowPlayerFlag;
    u16 changePlayerFlag;
    MBUserInfo member[15];
    u8  userVolatData[8];
    u16 broadcastedPlayerFlag;
    u8  iconDisable;
    u8  fileNo;
    u8  seqNoVolat;
    u8  dataAttr;
    u16 pad4b6;
    u32 ggid;
    struct MbGameInfo *next;
} MbGameInfo;

typedef struct {
    u16 sum;
    u8  fragmentNo;
    u8  fragmentMaxNum;
    u8  size;
    u8  rsv;
    u16 data[0x31];
} MbBeaconFixed;

typedef struct MbBeaconVolat {
    u16 sum;
    u8  nowPlayerNum;
    u8  pad;
    u16 nowPlayerFlag;
    u16 changePlayerFlag;
    MBUserInfo member[4];
    u8  userVolatData[8];
} MbBeaconVolat;

typedef struct MbBeacon {
    u32 ggid;
    union {
        u8 raw;
        struct { u8 lo : 2; u8 hi : 6; } bf;
    } unk4;
    u8  seqNoFixed;
    u8  seqNoVolat;
    u8  beaconNo;
    union {
        MbBeaconFixed fixed;
        MbBeaconVolat volat;
    } data;
} MbBeacon;

typedef struct {
    MbGameInfo *top;
    MbGameInfo *nowGInfop;
    u8 *nowFixedp;
    u8 state;
    u8 pad1;
    u8 seqNoVolat;
    u8 fragmentNo;
    u8 fragmentMaxNum;
    u8 beaconNo;
} MbSendStatus;

#include "../arm9/mi_memory.h"
#include "../arm9/fs_file.h"
#include "mb_wm_base.h"
#include "mb_common.h"
#include "../arm9/wm_etc.h"

void MBi_MakeGameInfo(u8 *gameInfop, const u8 *mbGameRegp, const u8 *parent);
int MBi_ReadIconInfo(char *filePathp, unsigned char *iconp, int char_flag);
void MB_UpdateGameInfoMember(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag);
int mystrlen(const u16 *str);
void MB_AddGameInfo(MbGameInfo *newGameInfop);
void MB_InitSendGameInfoStatus(void);
void MBi_ClearSendStatus(void);
void MB_SendGameInfoBeacon(u32 ggid, u16 tgid, u8 attribute);
int MBi_ReadyBeaconSendStatus(void);
void MBi_InitSendFixedBeacon(void);
void MBi_InitSendVolatBeacon(void);
BOOL MBi_CheckMBParent(void *bssDescp);

#pragma opt_lifetimes off

/* .bss of this file starts at 0x021F6EF4 (4-aligned): sMb at +0, bsendBuff at
   +0x2C (0x021F6F20). The compiler emits .bss in reverse declaration order, so
   bsendBuff is declared first. An explicit alignment keeps the compiler from
   addressing bsendBuff as sMb+0x2C (separate literal pool words, as in the
   image); aligned(32) would also make the section 32-aligned and move it. */
static MbBeacon bsendBuff __attribute__((aligned(4)));
static struct {
    void *unused0;
    void *unused1;
    void *unused2;
    void *unused3;
    u32 sendVolatCallbackTiming;
    void (*sendVolatCallback)(u32);
    MbSendStatus mbss;
} sMb;
#define mbss sMb.mbss

static inline void MI_CpuClear16(void *dest, u32 size) { MIi_CpuClear16(0, dest, size); }

static inline void MI_CpuCopy16(const void *src, void *dest, u32 size) { MIi_CpuCopy16(src, dest, size); }

static void MBi_SendFixedBeacon(u32 ggid, u16 tgid, u8 attribute);
static void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u8 attribute);

void MBi_MakeGameInfo(u8 *gameInfop, const u8 *mbGameRegp, const u8 *parent)
{
    int len;
    int icon_disable;
    int icon_disable2;

    MIi_CpuClear16(0, gameInfop, 0x4c0);
    icon_disable = 1;
    gameInfop[0x4b2] = 0;
    if (MBi_ReadIconInfo((char *)(*(const char **)(mbGameRegp + 0xc)), gameInfop, 1))
        icon_disable = 0;
    icon_disable2 = 0;
    if (!MBi_ReadIconInfo((char *)(*(const char **)(mbGameRegp + 0x10)), gameInfop, 0))
        icon_disable2 = 1;
    icon_disable |= icon_disable2;
    if (icon_disable) {
        gameInfop[0x4b2] = 1;
        MIi_CpuClearFast(0, gameInfop, 0x220);
    }
    *(u32 *)(gameInfop + 0x4b8) = *(const u32 *)(mbGameRegp + 0x14);
    if (parent != 0)
        MIi_CpuCopy16(parent, gameInfop + 0x220, 0x16);
    gameInfop[0x236] = mbGameRegp[0x18];
    len = mystrlen(*(const u16 **)(mbGameRegp + 4));
    MIi_CpuCopy16(*(const u16 **)(mbGameRegp + 4), gameInfop + 0x238, (u16)(len * 2));
    MIi_CpuCopy16(*(const u16 **)(mbGameRegp + 8), gameInfop + 0x298, 0xc0);
    gameInfop[0x358] = 1;
    *(u16 *)(gameInfop + 0x35a) = 1;
    *(u16 *)(gameInfop + 0x4b0) = 1;
}

/*
 * sdk:      MBi_ReadIconInfo (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
int MBi_ReadIconInfo(char *filePathp, unsigned char *iconp, int char_flag)
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
    FS_InitFile(&file);
    if (!FS_OpenFileEx(&file, filePathp, 1))
        return 0;
    if (size != FS_GetFileLength(&file)) {
        FS_CloseFile(&file);
        return 0;
    }
    FS_ReadFile(&file, iconp, size);
    FS_CloseFile(&file);
    return 1;
}

/*
 * sdk:      MB_UpdateGameInfoMember (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
void MB_UpdateGameInfoMember(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag)
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
void MB_AddGameInfo(MbGameInfo *newGameInfop)
{
    MbGameInfo *gInfop;

    gInfop = mbss.top;
    if (gInfop == 0) {
        mbss.top = newGameInfop;
    } else {
        while (gInfop->next != 0)
            gInfop = gInfop->next;
        gInfop->next = newGameInfop;
    }
    newGameInfop->next = 0;
}

void MB_InitSendGameInfoStatus(void)
{
    mbss.top = 0;
    mbss.nowGInfop = 0;
    mbss.state = 1;
    sMb.sendVolatCallback = 0;
    MBi_ClearSendStatus();
}

void MBi_ClearSendStatus(void)
{
    mbss.pad1 = 0;
    mbss.seqNoVolat = 0;
    mbss.fragmentNo = 0;
    mbss.fragmentMaxNum = 0;
    mbss.beaconNo = 0;
}

/*
 * sdk:      MB_SendGameInfoBeacon (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
void MB_SendGameInfoBeacon(u32 ggid, u16 tgid, u8 attribute)
{
    while (1) {
        switch (mbss.state) {
        case 0:
        case 1:
            if (!MBi_ReadyBeaconSendStatus())
                return;
            break;
        case 2:
            MBi_InitSendFixedBeacon();
            break;
        case 3:
            MBi_SendFixedBeacon(ggid, tgid, attribute);
            return;
        case 4:
            MBi_InitSendVolatBeacon();
            break;
        case 5:
            MBi_SendVolatBeacon(ggid, tgid, attribute);
            return;
        case 6:
            break;
        }
    }
}

/*
 * sdk:      MBi_ReadyBeaconSendStatus (libmb.TWL.HYB.a(mb_gameinfo.o))
 */
int MBi_ReadyBeaconSendStatus(void)
{
    MbGameInfo *nextGameInfop;

    if (mbss.top == 0) {
        u32 ggid = MBi_GetGgid();
        WM_SetGameInfo(0, (u16 *)&bsendBuff, 0x70, ggid, MBi_GetTgid(), 8);
        return 0;
    }
    if (mbss.nowGInfop != 0 && (nextGameInfop = mbss.nowGInfop->next) != 0) {
    } else {
        nextGameInfop = mbss.top;
    }
    mbss.nowGInfop = nextGameInfop;
    MBi_ClearSendStatus();
    mbss.seqNoVolat = mbss.nowGInfop->seqNoVolat;
    mbss.state = 2;
    return 1;
}

void MBi_InitSendFixedBeacon(void)
{
    if (mbss.state != 2)
        return;
    if (mbss.nowGInfop->iconDisable == 0) {
        mbss.fragmentMaxNum = 9;
        mbss.nowFixedp = (u8 *)mbss.nowGInfop;
    } else {
        mbss.fragmentMaxNum = 4;
        mbss.nowFixedp = (u8 *)mbss.nowGInfop + 0x220;
    }
    mbss.state = 3;
}

static void MBi_SendFixedBeacon(u32 ggid, u16 tgid, u8 attribute)
{
    unsigned long lastAddr = (unsigned long)mbss.nowGInfop + 0x358;

    if ((unsigned long)mbss.nowFixedp + 0x62 <= lastAddr) {
        bsendBuff.data.fixed.size = 0x62;
    } else {
        bsendBuff.data.fixed.size = (u8)(lastAddr - (unsigned long)mbss.nowFixedp);
        MI_CpuClear16((void *)((u8 *)bsendBuff.data.fixed.data + bsendBuff.data.fixed.size),
                       (unsigned long)(0x62 - bsendBuff.data.fixed.size));
    }
    MI_CpuCopy16(mbss.nowFixedp, bsendBuff.data.fixed.data, bsendBuff.data.fixed.size);
    {
        MbGameInfo *gi = mbss.nowGInfop;
        bsendBuff.data.fixed.fragmentNo = mbss.fragmentNo;
        bsendBuff.data.fixed.fragmentMaxNum = mbss.fragmentMaxNum;
        bsendBuff.unk4.bf.lo = gi->iconDisable;
        bsendBuff.seqNoFixed = gi->fileNo;
        bsendBuff.seqNoVolat = mbss.seqNoVolat;
        bsendBuff.ggid = gi->ggid;
        bsendBuff.unk4.bf.hi = gi->dataAttr;
        bsendBuff.beaconNo = mbss.beaconNo++;
    }
    bsendBuff.data.fixed.sum = 0;
    bsendBuff.data.fixed.sum = MBi_calc_cksum((u16 *)&bsendBuff.data, sizeof(bsendBuff.data));
    mbss.fragmentNo++;
    if (mbss.fragmentNo < mbss.fragmentMaxNum)
        mbss.nowFixedp += 0x62;
    else
        mbss.state = 4;
    WM_SetGameInfo(0, (u16 *)&bsendBuff, 0x70, ggid, tgid, (u8)(attribute | 3));
}

void MBi_InitSendVolatBeacon(void)
{
    mbss.nowGInfop->broadcastedPlayerFlag = 1;
    mbss.seqNoVolat = mbss.nowGInfop->seqNoVolat;
    mbss.state = 5;
}

static void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u8 attribute)
{
    int i;
    int setPlayerNum;
    u16 remainPlayerFlag;

    if (mbss.seqNoVolat != mbss.nowGInfop->seqNoVolat)
        MBi_InitSendVolatBeacon();

    bsendBuff.unk4.raw = (bsendBuff.unk4.raw & ~3) | 2;
    bsendBuff.seqNoFixed = mbss.nowGInfop->fileNo;
    bsendBuff.seqNoVolat = mbss.seqNoVolat;
    bsendBuff.ggid = mbss.nowGInfop->ggid;
    bsendBuff.unk4.bf.hi = mbss.nowGInfop->dataAttr;
    bsendBuff.beaconNo = mbss.beaconNo++;
    bsendBuff.data.volat.nowPlayerNum = mbss.nowGInfop->nowPlayerNum;
    bsendBuff.data.volat.nowPlayerFlag = mbss.nowGInfop->nowPlayerFlag;
    bsendBuff.data.volat.changePlayerFlag = mbss.nowGInfop->changePlayerFlag;

    if (sMb.sendVolatCallbackTiming == 0 && sMb.sendVolatCallback != 0)
        sMb.sendVolatCallback(mbss.nowGInfop->ggid);

    for (i = 0; i < 8; i++)
        ((u8 *)bsendBuff.data.volat.userVolatData)[i] = mbss.nowGInfop->userVolatData[i];

    MI_CpuClear16(bsendBuff.data.volat.member, sizeof(bsendBuff.data.volat.member));

    remainPlayerFlag = mbss.nowGInfop->broadcastedPlayerFlag ^ mbss.nowGInfop->nowPlayerFlag;
    setPlayerNum = 0;
    for (i = 0; i < 15; i++) {
        if ((2U << i) & remainPlayerFlag) {
            MI_CpuCopy16(&mbss.nowGInfop->member[i], &bsendBuff.data.volat.member[setPlayerNum], sizeof(MBUserInfo));
            mbss.nowGInfop->broadcastedPlayerFlag |= (2 << i);
            setPlayerNum++;
            if (setPlayerNum == 4)
                break;
        }
    }

    if (setPlayerNum < sizeof(bsendBuff.data.volat.member) / sizeof(MBUserInfo))
        bsendBuff.data.volat.member[setPlayerNum].playerNo = 0;

    bsendBuff.data.volat.sum = 0;
    bsendBuff.data.volat.sum = MBi_calc_cksum((u16 *)&bsendBuff.data, sizeof(bsendBuff.data));

    if (mbss.nowGInfop->broadcastedPlayerFlag == mbss.nowGInfop->nowPlayerFlag)
        mbss.state = 1;

    WM_SetGameInfo(0, (u16 *)&bsendBuff, sizeof(bsendBuff), ggid, tgid, attribute | 3);

    if (sMb.sendVolatCallbackTiming == 1 && sMb.sendVolatCallback != 0)
        sMb.sendVolatCallback(mbss.nowGInfop->ggid);
}

BOOL MBi_CheckMBParent(void *bssDescp)
{
    if (*(u16 *)((char *)bssDescp + 0x40) != 1)
        goto ret0;
    if (*(u8 *)((char *)bssDescp + 0x4B) & 2)
        goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
