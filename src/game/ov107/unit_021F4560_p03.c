/*
 * file:     unit_021F4560_p03.c
 * unit:     yes
 * function: MB_Init, func_021F5ADC, func_021F5B4C, func_021F5BE0, func_021F5CAC, MB_StartParentFromIdle, MBi_CallReset
 * address:  0x021F5904
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   mbi_reject_ggid_mask 0x021F6E6C data
 *   mbi_reject_ggid 0x021F6E68 data
 *   d_021F6F90  0x021F6F90  data
 *   mbi_life_mp 0x021F6E58  data
 *   mbi_life_cam 0x021F6E5A  data
 *   mbi_life_table_no 0x021F6E5C  data
 *   mbi_life_frame 0x021F6E5E  data
 *   mbi_power_save_mode 0x021F6E60  data
 *   _ZZ7MB_InitPvPK6structmmmE4game 0x021F6E64 data
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_021F5ADC 0x021F5ADC arm ov107
 *   d_021F6F90 0x021F6F90 data
 *   func_021F6148 0x021F6148 arm ov107
 *   func_0208F370 0x0208F370 arm
 *   func_0208EAC8 0x0208EAC8 arm
 *   func_021F4628 0x021F4628 arm ov107
 *   func_02082A48  0x02082A48  arm
 *   func_021F1B3C  0x021F1B3C  arm  ov107
 *   func_021F6804  0x021F6804  arm  ov107
 *   func_021F6830  0x021F6830  arm  ov107
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F3F78  0x021F3F78  arm  ov107
 *   func_020885EC  0x020885EC  arm
 *   func_021F1D80  0x021F1D80  arm  ov107
 *   func_021F46C8  0x021F46C8  arm  ov107
 *   WM_Reset     0x0208F400  arm
 *   func_021F6334   0x021F6334  arm
 */
#define MB_WM_OWN_STATICS
#include "mb_wm.h"

/* Initialised data at 0x021F6E58: life-time words and power save here, `game`
   in MB_Init, the reject words after MB_Init. */
static int mbi_power_save_mode = 1;
static u16 mbi_life_frame = 5;
static u16 mbi_life_table_no = 0xffff;
static u16 mbi_life_cam = 0x28;
static u16 mbi_life_mp = 0x28;

#define WM   (*(u8 **)(d_021F6F90 + 0xC))
#define PBUF (*(u8 **)(d_021F6F90 + 0x10))
extern u32 WM_GetNextTgid(void);
extern u32 OS_DisableInterrupts(void);
extern void MIi_CpuClear32(u32, void *, u32);
extern void MIi_CpuClear16(u32, void *, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 MBi_GetBeaconPeriodDispersion(void);
extern u32 OS_RestoreInterrupts(u32);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_021F5ADC(unsigned short sendSize, unsigned short recvSize, unsigned short entry_num);
extern void func_021F6148(unsigned short time);
extern int func_0208F370(void *wmSysBuf, void *callback, unsigned short dmaNo);
extern int func_0208EAC8(void *callback);
extern void func_021F4628(void);
extern void func_02082A48(u16 data, void *destp, u32 size);
extern void func_021F1B3C(void (*callback)(u16, u32, void *));
extern void func_021F6804(u16 childMaxSize);
extern void func_021F6830(void *buf);
extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern void func_021F3F78(void);
extern int func_020885EC(int fifotag, int proc);
extern void func_021F1D80(u16 type, void *arg);
extern void func_021F46C8(void *arg);
extern int WM_Reset(u32 param);
extern void func_021F6334(u16 apiid, int errcode);
int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
int func_021F5B4C(unsigned short sendSize, unsigned short maxChildren);
int func_021F5BE0(void);
int func_021F5CAC(int channel);
int MB_StartParentFromIdle(int channel);
int MBi_CallReset(void);







int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma)
{
    struct MBiParam *p_parm;
    struct MB_CommCommonWork *p_com;
    struct WMParentParam *p_parent;
    u32 enabled;
    static const u16 *game = L"";
    u16 *c;
    int i;

    if (mbWm.ext != 0 && mbWm.ext->isMbInitialized != 0)
        return 2;
    p_parm = (struct MBiParam *)(((u32)work + 0x1f) & ~0x1fu);
    p_com = (struct MB_CommCommonWork *)(((u32)p_parm + 0x1e00 + 0x1f) & ~0x1fu);
    if (tgid == 0x10000)
        tgid = WM_GetNextTgid();
    enabled = OS_DisableInterrupts();
    mbi_life_table_no = 0xffff;
    mbi_life_frame = 5;
    mbi_life_cam = 0x28;
    mbi_life_mp = 0x28;
    mbi_power_save_mode = 1;
    mbWm.WM_DMA_NO = dma;
    mbWm.work = p_parm;
    mbWm.ext = p_com;
    MIi_CpuClear32(0, p_parm, 0x1e00);
    MIi_CpuClear16(0, p_com, 0x1340);
    c = p_parm->uname;
    for (i = 0; i < user->nameLength; i++) {
        *c++ = user->name[i];
    }
    c = p_parm->gname;
    for (i = 0; i < 16; i++) {
        if (*game == 0)
            break;
        *c++ = *game++;
    }
    MI_CpuCopy8(user, &p_com->user, 0x16);
    if (user->nameLength < 10)
        p_com->user.name[user->nameLength] = 0;
    p_parm->p_sendlen = 0x100;
    p_parm->p_recvlen = 8;
    p_parm->sendBufSize = 0;
    p_parm->recvBufSize = 0;
    p_parm->contSend = 1;
    p_parm->recvBuf = p_com->recvbuf;
    p_parent = &p_parm->parentParam;
    p_parent->entryFlag = 0;
    p_parent->multiBootFlag = 0;
    p_parent->CS_Flag = 1;
    p_parent->KS_Flag = 0;
    p_parent->ggid = ggid;
    p_parent->tgid = tgid;
    p_parent->beaconPeriod = MBi_GetBeaconPeriodDispersion() + 200;
    p_parent->maxEntry = 15;
    p_parm->mpBusy = 0;
    p_parm->mbIsStarted = 0;
    p_com->isMbInitialized = 1;
    p_com->start_mp_busy = 0;
    OS_RestoreInterrupts(enabled);
    return 0;
}





static u32 mbi_reject_ggid = 0xffffffff;

static u32 mbi_reject_ggid_mask = 0xffffffff;



static int MBi_IsCommSizeValid(u16 sendSize, u16 recvSize, u16 entry_num)
{
    if (sendSize > 0x1FE || sendSize < 0xE4)
        return 0;
    if (recvSize > 0x10 || recvSize < 8)
        return 0;
    if ((sendSize + 0x26) * 4 + 0x4A + 0x100 +
            entry_num * ((recvSize + 0x20) * 4 + 0x70) < 0x15E0)
        return 1;
    return 0;
}





/*
 * sdk:      MB_SetParentCommParam (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F5B4C(unsigned short sendSize, unsigned short maxChildren)
{
    unsigned long enabled = func_02087988();

    if ((*(unsigned char **)(d_021F6F90 + 0xC))[0x50D] != 0) {
        func_0208799C(enabled);
        return 0;
    }
    if (func_021F5ADC(sendSize, 8, maxChildren) == 0) {
        func_0208799C(enabled);
        return 0;
    }
    *(unsigned short *)(*(unsigned char **)(d_021F6F90 + 0xC) + 0x10) = maxChildren;
    *(unsigned short *)(*(unsigned char **)(d_021F6F90 + 0xC) + 0x500) = sendSize;
    *(unsigned short *)(*(unsigned char **)(d_021F6F90 + 0xC) + 0x502) = 8;
    func_0208799C(enabled);
    return 1;
}





/*
 * sdk:      MBi_StartCommon (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F5BE0(void)
{
    int errcode = 0;

    *(unsigned short *)((u8 *)mbWm.work + 0x528) = errcode;
    *(unsigned short *)((u8 *)mbWm.work + 0x52A) = errcode;
    *(unsigned short *)((u8 *)mbWm.work + 0x526) = errcode;
    *(unsigned short *)((u8 *)mbWm.work + 0x548) = errcode;
    func_021F6148(0x1E);
    if (*(int *)(((unsigned char *)mbWm.ext) + 0x1320) == 0) {
        do {
            errcode = func_0208F370(mbWm.wmSysBuf, *(void **)((u8 *)mbWm.work + 0x508), mbWm.WM_DMA_NO);
        } while (errcode == 4);
        if (errcode != 2) {
            return 8;
        }
        func_0208EAC8(*(void **)((u8 *)mbWm.work + 0x508));
        ((u8 *)mbWm.work)[0x50D] = 1;
        return 0;
    }
    func_0208EAC8(*(void **)((u8 *)mbWm.work + 0x508));
    ((u8 *)mbWm.work)[0x50D] = 1;
    func_021F4628();
    return errcode;
}





/*
 * sdk:      MBi_StartParentCore (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F5CAC(int channel)
{
    int i;
    int ret;
    void (*cb_tmp)(u16, u32, void *);
    u32 enabled;

    enabled = func_02087988();
    *(u16 *)(WM + 0x32) = channel;
    *(u32 *)(d_021F6F90 + 4) = ((u32)PBUF + 0x1f + 0x7d00) & ~0x1f;
    cb_tmp = *(void (**)(u16, u32, void *))(PBUF + 0x1000 + 0x4e4);
    func_02082A48(0, PBUF + 0x1340, 0x69c0);
    func_021F1B3C(cb_tmp);
    *(int *)(PBUF + 0x1000 + 0x318) = *(u16 *)(WM + 0x500) - 6;
    func_021F6804(*(u16 *)(WM + 0x502));
    func_021F6830(PBUF + 0x138 + 0x1400);
    ret = 0;
    for (i = 0; i < 15; i++) {
        *(int *)(PBUF + i * 4 + 0x1000 + 0x4e8) = ret;
        *(signed char *)(PBUF + i + 0x1000 + 0x526) = -1;
    }
    *(u8 *)(PBUF + 0x1000 + 0x524) = ret;
    func_02082A48(ret, PBUF + 0x388 + 0x1400, 0x5d40);
    func_02082BCC(PBUF + 0x354 + 0x1400, ret, 0x1e);
    ret = 1;
    *(u16 *)(WM + 0x500 + 0x24) = ret;
    *(void **)(WM + 0x51c) = (void *)func_021F1D80;
    *(void **)(WM + 0x508) = (void *)func_021F46C8;
    *(u16 *)(WM + 0x34) = *(u16 *)(WM + 0x500);
    *(u16 *)(WM + 0x500 + 0x18) = (*(u16 *)(WM + 0x34) + 0x23) & ~0x1f;
    *(u16 *)(WM + 0x36) = *(u16 *)(WM + 0x502);
    *(u16 *)(WM + 0x500 + 0x1a) = (((*(u16 *)(WM + 0x36) + 0xe) * 15 + 0x29) & ~0x1f) << 1;
    func_021F3F78();
    i = func_021F5BE0();
    func_0208799C(enabled);
    *(int *)(PBUF + 0x7000 + 0x4c8) = func_020885EC(0xf, ret);
    return i;
}



int MB_StartParentFromIdle(int channel)
{
    *(u32 *)(*(char **)(d_021F6F90 + 0x10) + 0x1320) = 1;
    return func_021F5CAC(channel);
}


int MBi_CallReset(void)
{
    int errcode = WM_Reset(*(u32 *)(*(char **)(d_021F6F90 + 0xC) + 0x508));

    func_021F6334(1, errcode);
    return errcode == 2 ? 0 : errcode;
}
