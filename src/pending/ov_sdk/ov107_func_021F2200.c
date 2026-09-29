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
 * blocker:  size-exact (1216) but 1018 concrete bytes differ, all codegen.
 *           (1) the object keeps `&g_021F6FA0` in sb (r9) for the whole run
 *           and re-loads the pointee from [sb]; 1.1p1 loads the pool address
 *           into r5 instead, shifting every other value. (2) the object draws
 *           the switch on fileid as a 12-entry table (cmp #0xb); a plain
 *           {8,9,10,11}/default switch narrows to `sub #8; cmp #3` with a
 *           4-entry table, and spelling out the 0..7 empty cases makes 1.1p1
 *           emit a fresh early return block instead of routing them to the
 *           function's single 0x26AC epilogue the object uses. Same register-
 *           allocation wall as ParentStateCallback (0x021D2450): every body
 *           reconstructs cleanly, the allocator will not pick the object's
 *           registers. mb_parent.o is .comment 4.0.0.1024 (= 1.1p1) so this is
 *           source shape, not build, but the object's avoidance of r8/sb and
 *           its table reach were not reproduced in the spellings tried.
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
    u8 pad[0x10];
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
    MBCommRequestData req_data;
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
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 12:
    case 13:
    case 14:
    case 15:
        return;
    case 8: {
        u8 fid;
        u8 entry_num;
        u8 i;

        if (p_data == 0)
            return;
        if (state == 2) {
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
        fid = p_data[0x1c];
        entry_num = 0;
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
    case 9: {
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
    case 10: {
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
    case 11: {
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
    default:
        return;
    }
}
