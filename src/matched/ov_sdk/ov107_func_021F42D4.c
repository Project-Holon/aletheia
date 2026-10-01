/*
 * function: MBi_SendVolatBeacon
 * address:  0x021F42D4
 * packet:   pkt_ov107_021F42D4
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed (lane 09, 2026-10-01): typed from the DWARF (MBUserInfo 0x16-byte members with a
 *   playerNo:4 bitfield -> `bic #0xf0`; MbBeacon data.volat), no SM local (globals used
 *   directly, which stops the loads hoisting over the bsendBuff stores), unsigned bound
 *   for the `< 4` test (bhs), and a zero-byte `asm { .align 4 }` at the end: the object shows the
 *   asm-mode signature (both counted loops entered by `b` to the bottom test, one home
 *   for `i` across both loops, the member base CSE'd into fp across the call, the
 *   bsendBuff+0x68 pool word). The
 *   ternary-condition idiom alone stops at 110 B. FLAG: no asm instruction in the body;
 *   integrator to judge against a-loop-entered-by-a-branch-to-its-bottom-test... which
 *   names this function.
 *
 * integrator (2026-10-01): the zero-byte `asm { .align 4 }` was removed. The real
 *   NitroSDK source has no asm here, and docs/idioms/a-loop-entered-by-a-branch-to-its-
 *   bottom-test-has-a-ternary-condition.md names this function as one to close with plain C
 *   (ternary loop conditions), reserving the asm reading for bodies with a real asm
 *   instruction. With asm it was EXACT (proves the shape is asm-mode-like codegen); next:
 *   ternary conditions on both loops plus whatever else asm mode changes (no constant
 *   folding of inlined-helper branches, pooled loop zeros).
 * lane 19 (2026-10-01): 111 B -> 22 B with plain C. Ternary conditions on both loops; the
 *   userVolatData store through `((u8 *)arr)[i]` gives the bsendBuff+0x68 pool word and the
 *   `strb r1,[r0,sb]` form; `2U << i` in the test (int in the |=) breaks the CSE of the shift
 *   across the copy call (image recomputes `lsl r0,r8,sb`), which frees fp for the hoisted
 *   member base. Left: i is one web in the image (sb in both loops, setPlayerNum sl); here
 *   loop 1's i is r3 and i/setPlayerNum swap sb/sl. Inert: register/unsigned i, decl order,
 *   `i = setPlayerNum` init, setPlayerNum initialised at its declaration (286 B).
 *   `#pragma opt_lifetimes off` on this body gives EXACT (612 B): the residue is exactly
 *   the live-range split of i. Not fileable (no pragmas); left for the integrator.
 * Closed 2026-10-01 with `#pragma opt_lifetimes off` (lifetime splitting off), read as
 *   the vendor's build setting for this object, not a workaround. Evidence: across all 67
 *   open overlay SDK drafts the pragma closes exactly three, all from libirc irc.o /
 *   irc_internal.o and libmb mb_gameinfo.o; all 20 already-matched functions of those
 *   objects stay EXACT with it, while it breaks 5 of 125 sampled functions from other
 *   objects. Without it the loop variable is split across two registers (residue noted below).
 * sdk:      MBi_SendVolatBeacon (libmb.TWL.HYB.a mb_gameinfo.o)
 *
 * symbols:
 *   MBi_InitSendVolatBeacon          0x021F42A4  arm  ov107
 *   MIi_CpuClear16                   0x02082A48  arm
 *   MIi_CpuCopy16                    0x02082A60  arm
 *   MBi_calc_cksum                   0x021F3CB8  arm  ov107
 *   WM_SetGameInfo                   0x02090CD4  arm
 *   sUnlockFunc                      0x021F6EF4  data
 *   bsendBuff                        0x021F6F20  data
 */

#pragma opt_lifetimes off


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct MBUserInfo {
    u8  favoriteColor : 4;
    u8  playerNo : 4;
    u8  nameLength;
    u16 name[10];
} MBUserInfo;

typedef struct MbGameInfo {
    u8  unk000[0x358];
    u8  nowPlayerNum;
    u8  pad359;
    u16 nowPlayerFlag;
    u16 changePlayerFlag;
    MBUserInfo member[15];
    u8  userVolatData[8];
    u16 broadcastedPlayerFlag;
    u8  unk4b2;
    u8  fileNo;
    u8  seqNoVolat;
    u8  dataAttr;
    u16 unk4b6;
    u32 ggid;
} MbGameInfo;

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
    union { MbBeaconVolat volat; } data;
} MbBeacon;

typedef struct SUnlock {
    u8  pad00[0x10];
    u32 unk10;
    void (*unk14)(u32);
    u32 unk18;
    MbGameInfo *p1c;
    u8  pad20[4];
    u8  unk24;
    u8  pad25;
    u8  unk26;
    u8  pad27[2];
    u8  unk29;
} SUnlock;

extern SUnlock sUnlockFunc;
extern MbBeacon bsendBuff;

extern void MBi_InitSendVolatBeacon(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern u16 MBi_calc_cksum(u16 *buf, int length);
extern int WM_SetGameInfo(void (*callback)(void *), u16 *userGameInfo,
                          u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr);

static inline void MI_CpuClear16(void *dest, u32 size) { MIi_CpuClear16(0, dest, size); }
static inline void MI_CpuCopy16(const void *src, void *dest, u32 size) { MIi_CpuCopy16(src, dest, size); }

static void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u8 attribute)
{
    int i;
    int setPlayerNum;
    u16 remainPlayerFlag;

    if (sUnlockFunc.unk26 != sUnlockFunc.p1c->seqNoVolat)
        MBi_InitSendVolatBeacon();

    bsendBuff.unk4.raw = (bsendBuff.unk4.raw & ~3) | 2;
    bsendBuff.seqNoFixed = sUnlockFunc.p1c->fileNo;
    bsendBuff.seqNoVolat = sUnlockFunc.unk26;
    bsendBuff.ggid = sUnlockFunc.p1c->ggid;
    bsendBuff.unk4.bf.hi = sUnlockFunc.p1c->dataAttr;
    bsendBuff.beaconNo = sUnlockFunc.unk29++;
    bsendBuff.data.volat.nowPlayerNum = sUnlockFunc.p1c->nowPlayerNum;
    bsendBuff.data.volat.nowPlayerFlag = sUnlockFunc.p1c->nowPlayerFlag;
    bsendBuff.data.volat.changePlayerFlag = sUnlockFunc.p1c->changePlayerFlag;

    if (sUnlockFunc.unk10 == 0 && sUnlockFunc.unk14 != 0)
        sUnlockFunc.unk14(sUnlockFunc.p1c->ggid);

    for (i = 0; (i < 8) ? 1 : 0; i++)
        ((u8 *)bsendBuff.data.volat.userVolatData)[i] = sUnlockFunc.p1c->userVolatData[i];

    MI_CpuClear16(bsendBuff.data.volat.member, sizeof(bsendBuff.data.volat.member));

    remainPlayerFlag = sUnlockFunc.p1c->broadcastedPlayerFlag ^ sUnlockFunc.p1c->nowPlayerFlag;
    setPlayerNum = 0;
    for (i = 0; (i < 15) ? 1 : 0; i++) {
        if ((2U << i) & remainPlayerFlag) {
            MI_CpuCopy16(&sUnlockFunc.p1c->member[i], &bsendBuff.data.volat.member[setPlayerNum], sizeof(MBUserInfo));
            sUnlockFunc.p1c->broadcastedPlayerFlag |= (2 << i);
            setPlayerNum++;
            if (setPlayerNum == 4)
                break;
        }
    }

    if (setPlayerNum < sizeof(bsendBuff.data.volat.member) / sizeof(MBUserInfo))
        bsendBuff.data.volat.member[setPlayerNum].playerNo = 0;

    bsendBuff.data.volat.sum = 0;
    bsendBuff.data.volat.sum = MBi_calc_cksum((u16 *)&bsendBuff.data, sizeof(bsendBuff.data));

    if (sUnlockFunc.p1c->broadcastedPlayerFlag == sUnlockFunc.p1c->nowPlayerFlag)
        sUnlockFunc.unk24 = 1;

    WM_SetGameInfo(0, (u16 *)&bsendBuff, sizeof(bsendBuff), ggid, tgid, attribute | 3);

    if (sUnlockFunc.unk10 == 1 && sUnlockFunc.unk14 != 0)
        sUnlockFunc.unk14(sUnlockFunc.p1c->ggid);
}
