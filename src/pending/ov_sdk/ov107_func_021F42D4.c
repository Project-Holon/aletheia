/*
 * function: MBi_SendVolatBeacon
 * address:  0x021F42D4
 * packet:   pkt_ov107_021F42D4
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen/scheduling.  Logic reconstructed in full (per the
 *   MBi_InitSendVolatBeacon sibling and the insurance layout) and reaches
 *   600 of 612 bytes, but mwcc -O4,p hoists the `SM->unk10` and `SM->unk29`
 *   loads out of source order, uses `and r,r,#0xff` where the original has
 *   `bic r,r,#0xfc` for `(v & 3)`, and quantises `(P->unk4b5 << 2)` as
 *   `lsl #2; and #0xff` instead of the original's fused shift pair
 *   `lsl #0x1a; orr ...,lsr #24`.  Tried plain-u8 vs 6-bit-bitfield for
 *   `unk4hi`/`unk4b5`; the bitfield form reorders the whole prologue block.
 *   Needs an exact scheduling match, not just a correct expression.
 *
 * sdk:      MBi_SendVolatBeacon (libmb.TWL.HYB.a mb_gameinfo.o)
 *
 * symbols:
 *   MBi_InitSendVolatBeacon          0x021F42A4  arm  ov107
 *   MIi_CpuClear16                   0x02082A48  arm
 *   MIi_CpuCopy16                    0x02082A60  arm
 *   MBi_calc_cksum                   0x021F3CB8  arm  ov107
 *   WM_SetGameInfo                   0x02090CD4  arm
 *   sUnlockFunc                      0x021F6EF4  data  ov107
 *   bsendBuff                        0x021F6F20  data  ov107
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct MbGameInfo {
    u8  unk000[0x358];
    u8  unk358;
    u8  unk359;
    u16 unk35a;
    u16 unk35c;
    u8  unk35e[0x4a8 - 0x35e];
    u8  unk4a8[8];
    u16 unk4b0;
    u8  unk4b2;
    u8  unk4b3;
    u8  unk4b4;
    u8  unk4b5;
    u16 unk4b6;
    u32 unk4b8;
} MbGameInfo;

typedef struct MbBeacon {
    u32 unk0;
    u8  unk4;
    u8  unk5;
    u8  unk6;
    u8  unk7;
    u16 unk8;
    u8  unka;
    u8  unkb;
    u16 unkc;
    u16 unke;
    u8  players[0x58];
    u8  unk68[8];
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
extern void MIi_CpuCopy16(void *srcp, void *destp, u32 size);
extern u16 MBi_calc_cksum(u16 *buf, int length);
extern int WM_SetGameInfo(void (*callback)(void *), u16 *userGameInfo,
                          u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr);

static void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u8 attribute)
{
    SUnlock *SM = &sUnlockFunc;
    u16 remainPlayerFlag;
    int setPlayerNum;
    int i;
    u8 v;

    if (SM->unk26 != *(u8 *)((u8 *)SM->p1c + 0x4b4))
        MBi_InitSendVolatBeacon();

    v = (bsendBuff.unk4 & ~3) | 2;
    bsendBuff.unk4 = v;
    bsendBuff.unk5 = *(u8 *)((u8 *)SM->p1c + 0x4b3);
    bsendBuff.unk6 = SM->unk26;
    bsendBuff.unk0 = *(u32 *)((u8 *)SM->p1c + 0x4b8);
    bsendBuff.unk4 = (v & 3) | (u8)(*(u8 *)((u8 *)SM->p1c + 0x4b5) << 2);
    bsendBuff.unk7 = SM->unk29++;
    bsendBuff.unka = *(u8 *)((u8 *)SM->p1c + 0x358);
    bsendBuff.unkc = *(u16 *)((u8 *)SM->p1c + 0x35a);
    bsendBuff.unke = *(u16 *)((u8 *)SM->p1c + 0x35c);

    if (SM->unk10 == 0 && SM->unk14 != 0)
        SM->unk14(*(u32 *)((u8 *)SM->p1c + 0x4b8));

    for (i = 0; i < 8; i++)
        bsendBuff.unk68[i] = *(u8 *)((u8 *)SM->p1c + 0x4a8 + i);

    MIi_CpuClear16(0, bsendBuff.players, 0x58);

    remainPlayerFlag = *(u16 *)((u8 *)SM->p1c + 0x4b0) ^ *(u16 *)((u8 *)SM->p1c + 0x35a);
    setPlayerNum = 0;
    for (i = 0; i < 0xf; i++) {
        if ((2 << i) & remainPlayerFlag) {
            MIi_CpuCopy16((u8 *)SM->p1c + 0x35e + i * 0x16,
                          bsendBuff.players + setPlayerNum * 0x16, 0x16);
            *(u16 *)((u8 *)SM->p1c + 0x4b0) |= (2 << i);
            setPlayerNum++;
            if (setPlayerNum == 4)
                break;
        }
    }

    if (setPlayerNum < 4)
        bsendBuff.players[setPlayerNum * 0x16] &= 0x0f;

    bsendBuff.unk8 = 0;
    bsendBuff.unk8 = MBi_calc_cksum(&bsendBuff.unk8, 0x68);

    if (*(u16 *)((u8 *)SM->p1c + 0x4b0) == *(u16 *)((u8 *)SM->p1c + 0x35a))
        SM->unk24 = 1;

    WM_SetGameInfo(0, (u16 *)&bsendBuff, 0x70, ggid, tgid, attribute | 3);

    if (SM->unk10 == 1 && SM->unk14 != 0)
        SM->unk14(*(u32 *)((u8 *)SM->p1c + 0x4b8));
}
