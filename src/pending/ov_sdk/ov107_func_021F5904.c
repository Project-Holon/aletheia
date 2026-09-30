/*
 * function: MB_Init
 * address:  0x021F5904
 * packet:   pkt_ov107_021F5904
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * 472/472 bytes, 9 of 9 relocations resolved, 9 concrete bytes differ --
 * the whole function is byte-exact except the tail of the second copy loop
 * (see the blocker).  This file is filed `status: DIFF`, NOT `MATCH`: an
 * earlier version of it claimed MATCH while measuring 22 concrete bytes
 * wrong.  Full search history, target disassembly and the two compiler
 * basins are in docs/notes/func_021F5904.c.txt; that note is still the
 * authority on this function and this file does not supersede it.
 *
 * blocker: 9 concrete bytes at +0x010C/+0x0110/+0x011C, the tail of the
 *   second copy loop (gname -> p_parm->gname+0x200).  The target needs
 *   three things at once and 1.1p1 will only give two of them:
 *
 *     021F59F4  ldr  r0, [pc, #0xdc]   ; r0 = &mbi_life_mp
 *     021F59F8  mov  r6, #0            ; i = 0
 *     021F59FC  ldr  r1, [r0, #0xc]    ; cursor, HOISTED out of the loop
 *     loc_021F5A00:                    ; <- back edge lands here
 *     021F5A00  ldrh r2, [r1]
 *     021F5A04  cmp  r2, #0
 *     021F5A08  beq  loc_021F5A24
 *     021F5A0C  add  r1, r1, #2
 *     021F5A10  add  r6, r6, #1        ; i++ BEFORE the writeback
 *     021F5A14  str  r1, [r0, #0xc]    ; field writeback, every iteration
 *     021F5A18  cmp  r6, #0x10
 *     021F5A1C  strh r2, [r3], #2
 *     021F5A20  blt  loc_021F5A00
 *
 *   (1) the register colours r0=base, r1=cursor, r2=char, r3=dest;
 *   (2) the loop-invariant cursor load hoisted to +0x00FC, one execution,
 *       while the field is still written back on every iteration;
 *   (3) `i++` scheduled before the field writeback.
 *
 *   Reading the field inside the loop body (the spelling below) satisfies
 *   (1) and (3) -- 9 bytes wrong, only the writeback/increment swap and
 *   the back-edge target -- but the load stays inside the loop, so the
 *   back edge targets 0x021F59FC instead of 0x021F5A00.  Hoisting the
 *   load to a local (`c = mbi_life_mp.gname;` before the loop) satisfies
 *   (2) but the pool load for &mbi_life_mp is then scheduled first, at
 *   +0x00EC, and the whole register set rotates by one (r1=base,
 *   r3=cursor, r0=char, r2=dest): 32-39 bytes wrong.
 *
 *   dsi/1.1p1 offers exactly these two basins.  Confirmed again here for
 *   seven further spellings, all landing in one of the two: hoisted
 *   cursor with the initialisation order swapped; hoisted cursor with the
 *   store as the last statement of the body; hoisted cursor with the
 *   store moved into the `for` increment as a comma; hoisted cursor with
 *   all three initialisers folded into the `for` init; hoisted cursor in
 *   a fresh local (this one does put dest in r3, but the base/cursor/char
 *   triple is still rotated by exactly one, and the rotation is stable
 *   under declaration order); and the in-loop read with the store moved
 *   into the `for` increment.  Together with the ~200 hand spellings and
 *   ~7,500 permuter compiles already recorded in
 *   docs/notes/func_021F5904.c.txt, this is a compiler wall rather than
 *   a missing spelling.
 *
 * symbols:
 *   d_021F6F90  0x021F6F90  data
 *   mbi_life_mp 0x021F6E58  data
 *
 * lane W7 (2026-09-30): re-measured 472/472, 9/9 relocations, 9 concrete
 * bytes at +010C/+0110/+011C.  Re-tested the hoisted-cursor spellings (plain
 * `u16 *c = mbi_life_mp.gname`, while-loop, `for(...; i++, c++)`, and named
 * `u16 *n = c + 1`): all land in the 33-byte rotated basin.  Re-tested moving
 * `i++` ahead of the writeback in the in-loop-read body (for, while(1) and
 * do-while forms): 1.1p1 still emits store-then-add, so the 9-byte residue is
 * the scheduler, not the source.  Compiler wall, unchanged.
 *
 * re-check with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov107_func_021F5904.c \
 *       --func MB_Init --addr 0x021F5904 --region ov107 --cc 1.1p1 \
 *       --flags=-O4,p --arm --lang c99 --diff
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

/* 0x021F6E58: 0=w0 2=w2 4=w4 6=w6 8=w8 C=gname */
struct MBiLife {
    u16 w0;
    u16 w2;
    u16 w4;
    u16 w6;
    int w8;
    u16 *gname;
};

/* 22 bytes; MI_CpuCopy8 source and p_com->user */
struct MBUserInfo {
    u8 _0;
    u8 nameLength;
    u16 name[10];
};

/* p_parm + 0x1e00: user at +0x1300, isMbInitialized +0x1316, +0x131C */
struct MB_CommCommonWork {
    u32 sendbuf[256];
    u32 recvbuf[960];
    struct MBUserInfo user;
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

extern char d_021F6F90[];
extern struct MBiLife mbi_life_mp;

extern u32 WM_GetNextTgid(void);
extern u32 OS_DisableInterrupts(void);
extern void MIi_CpuClear32(u32, void *, u32);
extern void MIi_CpuClear16(u32, void *, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 MBi_GetBeaconPeriodDispersion(void);
extern u32 OS_RestoreInterrupts(u32);

int MB_Init(void *work, const struct MBUserInfo *user, u32 ggid, u32 tgid, u32 dma)
{
    struct MBiParam *p_parm;
    struct MB_CommCommonWork *p_com;
    struct WMParentParam *p_parent;
    u32 enabled;
    u16 *c;
    u16 *d;
    u16 ch;
    int i;

    if (*(struct MB_CommCommonWork **)(d_021F6F90 + 0x10) != 0
        && (*(struct MB_CommCommonWork **)(d_021F6F90 + 0x10))->isMbInitialized != 0)
        return 2;
    p_parm = (struct MBiParam *)(((u32)work + 0x1f) & ~0x1fu);
    p_com = (struct MB_CommCommonWork *)(((u32)p_parm + 0x1e00 + 0x1f) & ~0x1fu);
    if (tgid == 0x10000)
        tgid = WM_GetNextTgid();
    enabled = OS_DisableInterrupts();
    mbi_life_mp.w4 = 0xffff;
    mbi_life_mp.w6 = 5;
    mbi_life_mp.w2 = 0x28;
    mbi_life_mp.w0 = 0x28;
    mbi_life_mp.w8 = 1;
    *(u16 *)d_021F6F90 = dma;
    *(struct MBiParam **)(d_021F6F90 + 0xc) = p_parm;
    *(struct MB_CommCommonWork **)(d_021F6F90 + 0x10) = p_com;
    MIi_CpuClear32(0, p_parm, 0x1e00);
    MIi_CpuClear16(0, p_com, 0x1340);
    c = p_parm->uname;
    for (i = 0; i < user->nameLength; i++) {
        *c++ = user->name[i];
    }
    d = p_parm->gname + 0x200;
    for (i = 0; i < 16; i++) {
        c = mbi_life_mp.gname;
        ch = *c;
        if (ch == 0)
            break;
        mbi_life_mp.gname = c + 1;
        *d++ = ch;
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
