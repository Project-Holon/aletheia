/*
 * function: MBi_SendFixedBeacon
 * address:  0x021F4140
 * packet:   pkt_ov107_021F4140
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      MBi_SendFixedBeacon (TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o))
 *
 * Data witnesses, from `sdkobj.py 0x021F4140 --region ov107 --types`:
 *   0x021F6EF4  sUnlockFunc   send-status base.  Vendor DWARF types it as
 *                              `void (*)(void)`, but MBi_ClearSendStatus and
 *                              MBi_ReadyBeaconSendStatus (both EXACT) read
 *                              +0x0c and +0x18..+0x29 of it, so it is the
 *                              0x2C-byte status struct base.
 *   0x021F6F20  bsendBuff     struct MbBeacon, 0x70 bytes.
 *   0x021F6F2E  bsendBuff+0xe copy/clear destination (inside the payload).
 *   0x021F6F28  bsendBuff+0x8  checksum buffer, i.e. &bsendBuff.checksum.
 * The last two are offsets into bsendBuff, but the vendor emits them as
 * three distinct address constants (three separate pool loads at +0044,
 * +0048 and +0060), so they are spelled as separate base+offset constants
 * here; folding them into struct members makes the compiler CSE the loads
 * and drops the function to 352 bytes.
 *
 * blocker: 63 of 356 concrete bytes still differ, all register colouring and
 *   block scheduling, not data or semantics.  Original: cur=r4, data=r0,
 *   cur+0x358=r7, data+0x62=r3, sUnlockFunc=r7, bsendBuff=r8.  This source
 *   produces cur=r0, data=r3, cur+0x358=r7, data+0x62=r0, sUnlockFunc=r8,
 *   bsendBuff=r7, which permutes every dependent instruction in the tail.
 *   All 8 relocations resolve and the size matches at 356 bytes, so the
 *   witnesses above are settled; only the allocator order is open.  Ruled
 *   out: union/struct-member forms for bsendBuff (CSE the pool loads, 352 B),
 *   a local status pointer (allocates r9/sb), lastAddr = data (70 B),
 *   inverted or >= branches (68-77 B), pointer-typed fields (216-360 B).
 *   Wave 8: also tried the no-code self-assignment lever (`lastAddr = lastAddr;`
 *   after the add) - no movement, still 63 B; and DWARF confirms the only
 *   declared local is `lastAddr`, so named-local levers are unsupported.
 *   Wave 8b: the two loads `cur`/`data` neither cross the Clear16/Copy16 calls
 *   nor the branch join (both die at +0018/+003C), so the r4(callee)/r0(scratch)
 *   assignment is a front-end allocator tie, not a live-range fact.  Swept the
 *   general levers and all land on the identical 63 B unless noted: named
 *   pointer locals for cur/data (63), a named local for `data + 0x62` (63),
 *   init-at-declaration of lastAddr (63), unsigned int/long for lastAddr (63),
 *   no-code self-assignment (63); inlining `cur + 0x358` in the condition (63)
 *   or `data + 0x62` (63); pointer-typed lastAddr (63).  Moving the single
 *   local's assignment to the *intermediate* value (`lastAddr = cur;` then
 *   `lastAddr + 0x358` in the condition) only re-homes the tie (data -> r7,
 *   local -> r0, 64 B).  Compare-polarity and operand-order spellings measure
 *   strictly worse (68-76 B).  No source shape reaches cur=r4/data=r0.
 *
 *   Wave 8b: filed docs/idioms/a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie.md.
 * 2026-10-01 lane08: 63 B.  SDK-shaped body (lastAddr initialised at its
 *   declaration and never reassigned, `(u8)(lastAddr - data)` stored to the
 *   length, MI_CpuClear16/MI_CpuCopy16 inline wrappers reading the length
 *   back) is byte-identical to this one.  Every pair (cur/data, the else-arm
 *   u8 temp r1/r2, bsendBuff/sUnlockFunc r8/r7) is colour-reversed.
 *
 * symbols:
 *   sUnlockFunc    0x021F6EF4  data
 *   bsendBuff      0x021F6F20  data
 *   bsendBuff_pay  0x021F6F2E  data
 *   bsendBuff_cks  0x021F6F28  data
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy16   0x02082A60  arm
 *   MBi_calc_cksum  0x021F3CB8  arm  ov107
 *   WM_SetGameInfo  0x02090CD4  arm
 */
typedef struct {
    unsigned long ggid;
    unsigned char dataAttr : 2;
    unsigned char fileNo : 6;
    unsigned char seqNoFixed;
    unsigned char seqNoVolat;
    unsigned char beaconNo;
    unsigned short checksum;
    unsigned char pad0;
    unsigned char pad1;
    unsigned char length;
} MbBeacon;

typedef struct {
    char pad0[0x1C];
    unsigned char *cur;
    unsigned char *data;
    unsigned char state;
    unsigned char pad1;
    unsigned char seq;
    unsigned char n27;
    unsigned char n28;
    unsigned char beaconNo;
} MbSend;

extern MbSend sUnlockFunc;
extern MbBeacon bsendBuff;
extern unsigned char bsendBuff_pay[];   /* bsendBuff + 0xe */
extern unsigned char bsendBuff_cks[];   /* bsendBuff + 0x8 */

extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern unsigned short MBi_calc_cksum(unsigned char *buf, int length);
extern int WM_SetGameInfo(void *callback, void *userGameInfo, unsigned short size,
                          unsigned long ggid, unsigned short tgid, unsigned char attr);

static void MBi_SendFixedBeacon(unsigned long ggid, unsigned short tgid, unsigned char attribute)
{
    unsigned long lastAddr;

    lastAddr = (unsigned long)sUnlockFunc.cur + 0x358;
    if ((unsigned long)sUnlockFunc.data + 0x62 <= lastAddr) {
        bsendBuff.length = 0x62;
    } else {
        lastAddr = lastAddr - (unsigned long)sUnlockFunc.data;
        bsendBuff.length = (unsigned char)lastAddr;
        MIi_CpuClear16(0, bsendBuff_pay + (lastAddr & 0xFF), 0x62 - (lastAddr & 0xFF));
    }
    MIi_CpuCopy16(sUnlockFunc.data, bsendBuff_pay, bsendBuff.length);
    bsendBuff.pad0 = sUnlockFunc.n27;
    bsendBuff.pad1 = sUnlockFunc.n28;
    bsendBuff.dataAttr = sUnlockFunc.cur[0x4B2];
    bsendBuff.seqNoFixed = sUnlockFunc.cur[0x4B3];
    bsendBuff.seqNoVolat = sUnlockFunc.seq;
    bsendBuff.ggid = *(unsigned long *)(sUnlockFunc.cur + 0x4B8);
    bsendBuff.fileNo = sUnlockFunc.cur[0x4B5];
    bsendBuff.beaconNo = sUnlockFunc.beaconNo++;
    bsendBuff.checksum = 0;
    bsendBuff.checksum = MBi_calc_cksum(bsendBuff_cks, 0x68);
    sUnlockFunc.n27 = sUnlockFunc.n27 + 1;
    if (sUnlockFunc.n27 < sUnlockFunc.n28)
        sUnlockFunc.data += 0x62;
    else
        sUnlockFunc.state = 4;
    WM_SetGameInfo(0, &bsendBuff, 0x70, ggid, tgid, attribute | 3);
}
