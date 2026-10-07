/*
 * file:     unit_021F3D04_p03.c
 * unit:     yes
 * function: func_021F4140, func_021F42A4
 * address:  0x021F4140
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
 *   sUnlockFunc    0x021F6EF4  data
 *   mbss           0x021F6F0C  data
 *   bsendBuff      0x021F6F20  data
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy16   0x02082A60  arm
 *   MBi_calc_cksum  0x021F3CB8  arm  ov107
 *   WM_SetGameInfo  0x02090CD4  arm
 *   d_021F6EF4   0x021F6EF4  data
 */
#include "../../matched/include/G_SUnlock.h"

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

typedef unsigned short u16;

typedef unsigned char u8;

extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, unsigned long size);
extern unsigned short MBi_calc_cksum(unsigned short *buf, int length);
extern int WM_SetGameInfo(void *callback, unsigned short *userGameInfo, unsigned short size,
                          unsigned long ggid, unsigned short tgid, unsigned char attr);
void MBi_InitSendVolatBeacon(void);
extern struct SUnlock d_021F6EF4;


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
