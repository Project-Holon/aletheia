/*
 * function: MBi_CommParentRecvDataPerChild
 * address:  0x021F2200
 * packet:   pkt_ov107_021F2200
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  register allocation, not source shape. The vendor source is in
 *           tree at sdk/TwlSDK/build/libraries/mb/common/src/mb_parent.c
 *           (MBi_CommParentRecvDataPerChild, ~line 542), so the body is
 *           known. Two shape leads from it were applied and verified against
 *           the image:
 *           (1) the switch is on hd.type with the vendor enum arms
 *               FILEREQ=7, ACCEPT_FILEINFO=8, CONTINUE=9, STOPREQ=10,
 *               BOOTREQ_ACCEPTED=11 (empty); the 12-entry `cmp #0xb` table
 *               and its slot->body map now match byte for byte. The old
 *               switch(fileid) 0..15 spelling was a 16-entry table.
 *           (2) MBCommChildBlockHeader is 4-byte aligned in the object (hd
 *               slot at sp+0x20, not sp+0x1e); one u32 member fixes it.
 *           What remains is the allocator: the object keeps &g_021F6FA0 in
 *           sb (r9) and p_data in r5, child in r6, state in r4, fileid in r8;
 *           1.1p1 picks r5 for the base and r7 for p_data, child in r4, state
 *           in r8. Compiled 1192 vs 1216 (24 short) with ~1006 concrete bytes
 *           differing, all codegen. Every body reconstructs; the vendor
 *           pointer-field spelling (pPwork->field) rather than the raw-offset
 *           casts in this file is the likely route to the object's colouring.
 *           Same wall as ParentStateCallback (0x021D2450).
 *           Wave-8 attempt: reproduced the vendor's declaration scoping
 *           (req_data inside the state==CONNECTED block, its locals inside
 *           the state==REQUESTED block) -- compiled output byte-identical to
 *           before, so scoping is not the lever. Also tried the vendor's
 *           declaration order (state before p_data): byte-identical, 1192 vs
 *           1216 (24 short), 1006 concrete bytes differ. The gap is the
 *           global register rotation, not any single statement: the object
 *           keeps &pPwork in sb and the fileinfo stride 0x5D4 in r7 for the
 *           whole function (child r6, state r4, p_data r5, type r8), while
 *           1.1p1 puts &pPwork in r5, child r4, state r8, p_data r7 and
 *           rematerialises 0x5D4 from the pool at each use. Same wall as
 *           ParentStateCallback (0x021D2450). Related idiom read and not
 *           applicable: address-of-a-global-reread-across-an-extern-call-
 *           cannot-be-cached (the reload is present in both; the register
 *           chosen for the global's address is the difference).
 *
 * sdk:      MBi_CommParentRecvDataPerChild (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6FA0                     0x021F6FA0  data
 *   g_021F6EEC                     0x021F6EEC  data
 *   MBi_SetRecvBufferFromChild     0x021F6908  arm
 *   MI_CpuCopy8                    0x02082D44  arm
 *   MBi_CommChangeParentState      0x021F1D0C  arm
 *   MBi_calc_nextsendblock         0x021F2ED4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 fileid;
    u8 unk1;
    u16 f2;
    u32 unk4;
    u8 pad[0x0c];
} MBCommChildBlockHeader;

typedef struct {
    u8 data[0x1d];
} MBCommRequestData;

extern unsigned char *g_021F6FA0;
extern int g_021F6EEC;
extern u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, MBCommChildBlockHeader *hdr,
                                      u16 child_id);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern void MBi_CommChangeParentState(u16 child, int state, void *arg);
extern u16 MBi_calc_nextsendblock(u32 next_block, u32 next_block_req);

static void MBi_CommParentRecvDataPerChild(void *arg, u16 child)
{
    MBCommChildBlockHeader hd;
    u8 *p_data;
    int state;
    u8 fileid;

    if (child == 0)
        return;
    if (child > 0xf)
        return;
    p_data = MBi_SetRecvBufferFromChild((u8 *)arg + 0xa, &hd, child);
    fileid = hd.fileid;
    state = ((int *)(g_021F6FA0 + 0x14E8))[child - 1];
    switch (fileid) {
    case 7: {
        if (p_data == 0)
            return;
        if (state == 2) {
            MBCommRequestData req_data;

            MI_CpuCopy8(p_data, &req_data, 0x1d);
            ((int *)(g_021F6FA0 + 0x14A8))[child - 1] = *(int *)&req_data;
            *(u16 *)(g_021F6FA0 + 0x148A + (child - 1) * 2) =
                *(u16 *)((u8 *)&req_data + 0x1a);
            MI_CpuCopy8((u8 *)&req_data + 4,
                        g_021F6FA0 + 0x1340 + (child - 1) * 0x16, 0x16);
            g_021F6FA0[0x1340 + (child - 1) * 0x16] =
                (g_021F6FA0[0x1340 + (child - 1) * 0x16] & 0x0f) |
                (u8)(child << 4);
            MBi_CommChangeParentState(child, 0xa, (u8 *)&req_data + 4);
        }
        if (state != 0xa)
            return;
        {
        u8 fid = p_data[0x1c];
        u8 entry_num = 0;
        u8 i;
        if (fid < 0x10) {
            if (g_021F6FA0[fid * 0x5D4 + 0x1D52] != 0) {
                void *ptr = *(void **)(g_021F6FA0 + fid * 0x5D4 + 0x1D40);
                if (((int *)(g_021F6FA0 + 0x14E8))[child - 1] ==
                    *(int *)((u8 *)ptr + 0x14)) {
                    for (i = 0; i < 0x10; i++)
                        if (*(u16 *)(g_021F6FA0 + fid * 0x5D4 + 0x1D4E + i * 2) &
                            (1 << i))
                            entry_num++;
                    if (entry_num >= *((u8 *)ptr + 0x18)) {
                        *(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) = 0;
                        MBi_CommChangeParentState(child, 0xb, 0);
                        return;
                    }
                } else {
                    *(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) = 4;
                }
            } else {
                *(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) = 4;
            }
        } else {
            *(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) = 4;
        }
        {
            u8 *w = g_021F6FA0;
            u16 x = *(u16 *)(w + 0x1754 + (child - 1) * 2);

            if (x == 3) {
                u8 f2;

                if (*(u16 *)(w + 0x1536) & (1 << child))
                    return;
                f2 = w[0x1526 + (child - 1)];
                w[0x1535]++;
                *(u16 *)(w + 0x1536) |= 1 << child;
                w[0x1526 + (child - 1)] = f2;
                *(u16 *)(w + 0x1D4E + f2 * 0x5D4) |= 1 << child;
                *(u16 *)(w + 0x1D50 + f2 * 0x5D4) |= 1 << child;
                *(u16 *)(w + 0x1754 + (child - 1) * 2) = 0;
                MBi_CommChangeParentState(child, 5, 0);
                return;
            }
            if (x == 4) {
                *(u16 *)(w + 0x1754 + (child - 1) * 2) = 0;
                MBi_CommChangeParentState(child, 4, 0);
                return;
            }
        }
        return;
        }
    }
    case 8: {
        u8 fid;

        if (state == 5) {
            MBi_CommChangeParentState(child, 0xe, 0);
            return;
        }
        if (state != 0xe)
            return;
        if (*(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) != 2)
            return;
        fid = g_021F6FA0[0x1526 + (child - 1)];
        *(u16 *)(g_021F6FA0 + 0x1D4C + fid * 0x5D4) |= 1 << child;
        *(u16 *)(g_021F6FA0 + 0x1D48 + fid * 0x5D4) = 0;
        *(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) = 0;
        MBi_CommChangeParentState(child, 6, 0);
        return;
    }
    case 9: {
        u8 fid;

        if (state != 6)
            return;
        fid = g_021F6FA0[0x1526 + (child - 1)];
        if (fid == 0xff)
            return;
        *(u16 *)(g_021F6FA0 + 0x1D4A + fid * 0x5D4) =
            MBi_calc_nextsendblock(*(u16 *)(g_021F6FA0 + 0x1D4A + fid * 0x5D4),
                                   hd.f2);
        g_021F6EEC |= 1 << fid;
        return;
    }
    case 10: {
        u8 fid;

        if (state == 6) {
            fid = g_021F6FA0[0x1526 + (child - 1)];
            if (fid == 0xff)
                return;
            *(u16 *)(g_021F6FA0 + 0x1D4C + fid * 0x5D4) &= ~(1 << child);
            MBi_CommChangeParentState(child, 7, 0);
            return;
        }
        if (state != 7)
            return;
        if (*(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) != 5)
            return;
        *(u16 *)(g_021F6FA0 + 0x1754 + (child - 1) * 2) = 0;
        MBi_CommChangeParentState(child, 8, 0);
        return;
    }
    case 11:
    default:
        return;
    }
}
