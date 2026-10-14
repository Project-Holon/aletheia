/*
 * function: MB_Init
 * address:  0x021F5904
 * packet:   pkt_ov107_021F5904
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * lane09 wave2 (2026-10-01): EXACT. The name cursor is the function-local
 *   static `game` (_ZZ7MB_InitPvPK6structmmmE4game, .data+0xc), which 1.1p1
 *   treats as non-aliasing, so its load hoists while the store stays in the
 *   loop. The other .data statics (mbi_life_*, mbi_power_save_mode) are
 *   real-initialised file statics so `game` is reached through the
 *   mbi_life_mp anchor. MBUserInfo is an anonymous typedef struct (the
 *   mangled name says PK6struct). The 9 B "compiler wall" of the old notes
 *   (docs/notes/func_021F5904.c.txt) was this missing static.
 *
 * symbols:
 *   gMbWm  0x021F6F90  data
 *   mbi_life_mp 0x021F6E58  data
 *   mbi_life_cam 0x021F6E5A  data
 *   mbi_life_table_no 0x021F6E5C  data
 *   mbi_life_frame 0x021F6E5E  data
 *   mbi_power_save_mode 0x021F6E60  data
 *   _ZZ7MB_InitPvPK6structmmmE4game 0x021F6E64 data
 *
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

/* 22 bytes; MI_CpuCopy8 source and p_com->user */
typedef struct {
    u8 _0;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

/* p_parm + 0x1e00: user at +0x1300, isMbInitialized +0x1316, +0x131C */
struct MB_CommCommonWork {
    u32 sendbuf[256];
    u32 recvbuf[960];
    MBUserInfo user;
    u16 isMbInitialized;
    u16 _p;
    int start_mp_busy;
    int is_started_ex;
};

/* p_parm + 8; sized to 0x14 by 4-byte alignment, which is what puts
   gname at 0x138 rather than 0x13a */
struct WMParentParam {
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 KS_Flag;
    u16 CS_Flag;
    u16 beaconPeriod;
};

struct MBiParam {
    u8 _0[8];
    struct WMParentParam parentParam;
    u8 _10[0x138 - 0x1c];
    /* the 0x400-byte name area: uname is gname[0x1f8], and the second
       copy loop writes gname[0x200..0x20f] */
    u16 gname[0x1e0];
    u8 _4f8[8];
    u16 p_sendlen;
    u16 p_recvlen;
    void *recvBuf;
    u8 _508[4];
    u8 mpBusy;
    u8 mbIsStarted;
    u8 _50e[0x18 - 0xe];
    u16 sendBufSize;
    u16 recvBufSize;
    u8 _51c[0x52c - 0x51c];
    u16 contSend;
    u16 _52e[1];
    u16 uname[4];
};

extern char gMbWm[];
static int mbi_power_save_mode = 1;
static u16 mbi_life_frame = 5;
static u16 mbi_life_table_no = 0xffff;
static u16 mbi_life_cam = 0x28;
static u16 mbi_life_mp = 0x28;

extern u32 WM_GetNextTgid(void);
extern u32 OS_DisableInterrupts(void);
extern void MIi_CpuClear32(u32, void *, u32);
extern void MIi_CpuClear16(u32, void *, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 MBi_GetBeaconPeriodDispersion(void);
extern u32 OS_RestoreInterrupts(u32);

int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma)
{
    struct MBiParam *p_parm;
    struct MB_CommCommonWork *p_com;
    struct WMParentParam *p_parent;
    u32 enabled;
    static const u16 *game = L"";
    u16 *c;
    int i;

    if (*(struct MB_CommCommonWork **)(gMbWm + 0x10) != 0
        && (*(struct MB_CommCommonWork **)(gMbWm + 0x10))->isMbInitialized != 0)
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
    *(u16 *)gMbWm = dma;
    *(struct MBiParam **)(gMbWm + 0xc) = p_parm;
    *(struct MB_CommCommonWork **)(gMbWm + 0x10) = p_com;
    MIi_CpuClear32(0, p_parm, 0x1e00);
    MIi_CpuClear16(0, p_com, 0x1340);
    c = p_parm->uname;
    for (i = 0; i < user->nameLength; i++) {
        *c++ = user->name[i];
    }
    c = p_parm->gname + 0x200;
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
