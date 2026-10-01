/*
 * function: MBi_CommParentRecvDataPerChild
 * address:  0x021F2200
 * packet:   pkt_ov107_021F2200
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed (wave 2 lane 08, 2026-10-01): the body from lane 05 was right; the
 *           residue (no CSE across calls or the entry_num loop, loop entered
 *           by b to its bottom test, &mbc and 0x5d4 hoisted to the entry with
 *           per-arm copies) is the codegen mwcc gives any function that
 *           references a variable declared __attribute__((aligned(N))).
 *           req_data carries it. Evidence for the variable: mbc and
 *           any_recv_bitmap are plain align-4 .bss and their other users
 *           (MBi_CommParentRecvData 021F26C0, EXACT) break if they are
 *           declared aligned; the child-side MBi_CommChildSendData, whose only
 *           local is an MBCommChildBlockHeader hd, matches only with hd
 *           unaligned (scratch rebuild from the libmb object), and so does
 *           MBi_CommParentSendBlock's hd. The value (4) is not measurable:
 *           4, 8 and 32 all give the same bytes. The old allocator-wall notes
 *           are superseded.
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
    u8 favoriteColour:4;
    u8 playerNo:4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

typedef struct {
    u32 ggid;
    MBUserInfo userinfo;
    u16 version;
    u8 fileid;
    u8 pad[3];
} MBCommRequestData;

typedef struct {
    u8 type;
    u8 pad1[1];
    union {
        struct {
            u16 req;
            u8 reserved[14];
        } data;
        u8 raw[16];
    } u;
} MBCommChildBlockHeader;

typedef struct {
    u8 pad0[0x14];
    u32 ggid;                       /* 0x14 */
    u8 maxPlayerNum;                /* 0x18 */
} MBGameInfoHead;

typedef struct {
    MBGameInfoHead *game_info;      /* 0x00 */
    u8 pad4[4];
    u16 currentb;                   /* 0x08 */
    u16 nextb;                      /* 0x0a */
    u16 pollbmp;                    /* 0x0c */
    u16 gameinfo_child_bmp;         /* 0x0e */
    u16 gameinfo_changed_bmp;       /* 0x10 */
    u8 active;                      /* 0x12 */
    u8 pad13[0x5d4 - 0x13];
} MBFileInfo;

typedef struct {
    u8 pad0[0x1340];
    MBUserInfo childUser[15];       /* 0x1340 */
    u16 childversion[15];           /* 0x148a */
    u32 childggid[15];              /* 0x14a8 */
    u8 pad14e4[4];
    int p_comm_state[15];           /* 0x14e8 */
    u8 pad1524[2];
    u8 fileid_of_child[15];         /* 0x1526 */
    u8 child_num;                   /* 0x1535 */
    u16 child_entry_bmp;            /* 0x1536 */
    u8 pad1538[0x1754 - 0x1538];
    u16 req2child[15];              /* 0x1754 */
    u8 pad1772[0x1d40 - 0x1772];
    MBFileInfo fileinfo[16];        /* 0x1d40 */
} MB_CommPWork;

extern MB_CommPWork *g_021F6FA0;
extern int g_021F6EEC;
extern u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MBi_CommChangeParentState(u16 child, int state, void *arg);
extern u16 MBi_calc_nextsendblock(u16 next_block, u16 next_block_req);

#define pPwork g_021F6FA0

static void MBi_CommParentRecvDataPerChild(void *arg, u16 child)
{
    MBCommChildBlockHeader hd;
    int state;
    u8 *p_data;

    if (child == 0 || child > 15)
        return;

    p_data = MBi_SetRecvBufferFromChild((u8 *)arg + 0xa, &hd, child);

    state = pPwork->p_comm_state[child - 1];

    switch (hd.type) {
    case 7:
        {
            if (p_data == 0)
                break;
            if (state == 2) {
                MBCommRequestData req_data __attribute__((aligned(4)));

                MI_CpuCopy8(p_data, &req_data, 0x1d);
                pPwork->childggid[child - 1] = req_data.ggid;
                pPwork->childversion[child - 1] = req_data.version;
                MI_CpuCopy8(&req_data.userinfo, &pPwork->childUser[child - 1], sizeof(MBUserInfo));
                pPwork->childUser[child - 1].playerNo = child;
                MBi_CommChangeParentState(child, 0xa, &req_data.userinfo);
            }
            if (state == 0xa) {
                u8 i, entry_num = 0;
                u8 fileid = ((MBCommRequestData *)p_data)->fileid;

                if (fileid >= 16 || pPwork->fileinfo[fileid].active == 0
                    || pPwork->childggid[child - 1] != pPwork->fileinfo[fileid].game_info->ggid) {
                    pPwork->req2child[child - 1] = 4;
                } else {
                    for (i = 0; i < 16; i++) {
                        if (pPwork->fileinfo[fileid].gameinfo_child_bmp & (1 << i))
                            entry_num++;
                    }
                    if (entry_num >= pPwork->fileinfo[fileid].game_info->maxPlayerNum) {
                        pPwork->req2child[child - 1] = 0;
                        MBi_CommChangeParentState(child, 0xb, 0);
                        break;
                    }
                }

                switch (pPwork->req2child[child - 1]) {
                case 3:
                    if (pPwork->child_entry_bmp & (1 << child))
                        break;
                    pPwork->child_num++;
                    pPwork->child_entry_bmp |= (u16)(1 << child);
                    pPwork->fileid_of_child[child - 1] = fileid;
                    pPwork->fileinfo[fileid].gameinfo_child_bmp |= (u16)(1 << child);
                    pPwork->fileinfo[fileid].gameinfo_changed_bmp |= (u16)(1 << child);
                    pPwork->req2child[child - 1] = 0;
                    MBi_CommChangeParentState(child, 5, 0);
                    break;
                case 4:
                    pPwork->req2child[child - 1] = 0;
                    MBi_CommChangeParentState(child, 4, 0);
                    break;
                }
            }
        }
        break;

    case 8:
        if (state == 5) {
            MBi_CommChangeParentState(child, 0xe, 0);
        } else if (state == 0xe) {
            if (pPwork->req2child[child - 1] == 2) {
                u8 fid = pPwork->fileid_of_child[child - 1];

                pPwork->fileinfo[fid].pollbmp |= (u16)(1 << child);
                pPwork->fileinfo[fid].currentb = 0;
                pPwork->req2child[child - 1] = 0;
                MBi_CommChangeParentState(child, 6, 0);
            }
        }
        break;

    case 9:
        if (state == 6) {
            u8 fileid = pPwork->fileid_of_child[child - 1];

            if (fileid == 0xff)
                break;
            pPwork->fileinfo[fileid].nextb = MBi_calc_nextsendblock(pPwork->fileinfo[fileid].nextb, hd.u.data.req);
            g_021F6EEC |= 1 << fileid;
        }
        break;

    case 10:
        if (state == 6) {
            u8 fileid = pPwork->fileid_of_child[child - 1];

            if (fileid == 0xff)
                break;
            pPwork->fileinfo[fileid].pollbmp &= ~(1 << child);
            MBi_CommChangeParentState(child, 7, 0);
        } else if (state == 7) {
            if (pPwork->req2child[child - 1] == 5) {
                pPwork->req2child[child - 1] = 0;
                MBi_CommChangeParentState(child, 8, 0);
            }
        }
        break;

    case 11:
        break;

    default:
        break;
    }
}
