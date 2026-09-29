/*
 * function: func_021F5904
 * address:  0x021F5904
 * packet:   pkt_ov107_021F5904
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      MB_Init (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_02087988  0x02087988  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A48  0x02082A48  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021F589C  0x021F589C  arm  ov107
 *   func_0208799C  0x0208799C  arm
 *   g_021F6F90  0x021F6F90  data
 *   g_021F6E58  0x021F6E58  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 favoriteColor;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

typedef struct {
    u32 sendbuf[256];
    u32 recvbuf[960];
    MBUserInfo user;
    u16 isMbInitialized;
    int block_size_max;
    int start_mp_busy;
    int is_started_ex;
    u8 padding[28];
} MB_CommCommonWork;

typedef struct {
    u16 *userGameInfo;
    u16 userGameInfoLength;
    u16 padding;
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 KS_Flag;
    u16 CS_Flag;
    u16 beaconPeriod;
    u16 rsv1[4];
    u16 rsv2[8];
    u16 channel;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 rsv[4];
} WMParentParam;

typedef struct {
    WMParentParam parentParam;
    u16 sendBuf[512];
    u8 parentInfoBuf[192];
    u16 p_sendlen;
    u16 p_recvlen;
    void *recvBuf;
    void (*callback_ptr)(void *);
    u8 mpBusy;
    u8 mbIsStarted;
    u8 reserved0[10];
    u16 sendBufSize;
    u16 recvBufSize;
    void *callback;
    void *pInfo;
    u16 mode;
    u16 endReq;
    u16 mpStarted;
    u16 child_bitmap;
    u16 contSend;
    u8 reserved1[2];
    u8 uname[8];
    u8 gname[16];
    u16 currentTgid;
    u8 reserved2[22];
    u16 userGameInfo[64];
    u8 rest[0x1e00 - 0x5e0];
} MBiParam;

typedef struct {
    u16 dmaNo;
    u16 pad;
    void *wmSysBuf;
    int pad2;
    MBiParam *p_parm;
    MB_CommCommonWork *p_com;
} WmBase;

typedef struct {
    u16 w0;
    u16 w2;
    u16 w4;
    u16 w6;
    int w8;
    u16 *gname;
} LifeMp;

extern WmBase g_021F6F90;
extern LifeMp g_021F6E58;

extern u16 func_0208F1B4(void);
extern u32 func_02087988(void);
extern void func_02082A7C(u32 data, void *dest, u32 size);
extern void func_02082A48(u16 data, void *dest, u32 size);
extern void func_02082D44(void *src, void *dest, u32 size);
extern u32 func_021F589C(void);
extern u32 func_0208799C(u32 state);

int func_021F5904(void *work, MBUserInfo *user, u32 ggid, u32 tgid, u32 dma)
{
    u16 *dst;
    MBiParam *p_parm;
    MB_CommCommonWork *p_com;
    WMParentParam *p_parent;
    u32 enabled;
    u16 ch;
    int i;
    u16 *c;

    if (g_021F6F90.p_com != 0 && g_021F6F90.p_com->isMbInitialized != 0)
        return 2;
    p_parm = (MBiParam *)(((u32)work + 0x1f) & ~0x1f);
    p_com = (MB_CommCommonWork *)(((u32)p_parm + 0x1e00 + 0x1f) & ~0x1f);
    if (tgid == 0x10000)
        tgid = func_0208F1B4();
    enabled = func_02087988();
    g_021F6E58.w4 = 0xffff;
    g_021F6E58.w6 = 5;
    g_021F6E58.w2 = 0x28;
    g_021F6E58.w0 = 0x28;
    g_021F6E58.w8 = 1;
    g_021F6F90.dmaNo = dma;
    g_021F6F90.p_parm = p_parm;
    g_021F6F90.p_com = p_com;
    func_02082A7C(0, p_parm, 0x1e00);
    func_02082A48(0, p_com, 0x1340);
    dst = (u16 *)p_parm->uname;
    for (i = 0; i < user->nameLength; i++) {
        ch = user->name[i];
        *dst++ = ch;
    }
    dst = (u16 *)p_parm->gname;
    for (i = 0; i < 16; i++) {
        c = g_021F6E58.gname;
        ch = *c;
        if (ch == 0)
            break;
        g_021F6E58.gname = c + 1;
        *dst++ = ch;
    }
    func_02082D44(user, &p_com->user, 0x16);
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
    p_parent->beaconPeriod = func_021F589C() + 200;
    p_parent->maxEntry = 15;
    p_parm->mpBusy = 0;
    p_parm->mbIsStarted = 0;
    p_com->isMbInitialized = 1;
    p_com->start_mp_busy = 0;
    func_0208799C(enabled);
    return 0;
}
