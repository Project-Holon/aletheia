/*
 * function: func_021F27A8
 * address:  0x021F27A8
 * packet:   pkt_ov107_021F27A8
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_CommParentSendDLFileInfo (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F6890  0x021F6890  arm  ov107
 *   func_02082D44  0x02082D44  arm
 *   func_021F3C80  0x021F3C80  arm  ov107
 *   g_021F6FA0     0x021F6FA0  data
 *   g_021F6E48     0x021F6E48  data
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct MBCommParentBlockHeader {
    u8 type;
    u8 pad1;
    u16 fid;
    u16 size;
} MBCommParentBlockHeader;


typedef struct MBiFileInfo {
    u8 dl_fileinfo[0xe4];
    u8 pad0e4[0x5ca - 0xe4];
    u8 active;
    u8 pad5cb[0x5d4 - 0x5cb];
} MBiFileInfo;

typedef struct MBiParam {
    u32 sendbuf[0x14e4 / 4];
    u32 p_comm_state[16];
    u8 pad1524;
    s8 req_fid[16];
    u8 pad1535[0x1788 - 0x1535];
    MBiFileInfo fileinfo[16];
} MBiParam;

extern MBiParam *g_021F6FA0;
extern u8 g_021F6E48;

extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern u8 *func_021F6890(MBCommParentBlockHeader *hdr, u8 *sendbuf);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_021F3C80(int body_len, u16 pollbmp, u32 *sendbuf);

int func_021F27A8(void)
{
    MBCommParentBlockHeader hd;
    u8 *databuf;
    u16 child;
    u8 i;
    u8 fid;
    s8 send_candidate_fid = -1;
    u8 file_req_num[16];
    u16 pollbmp = 0;

    func_02082BCC(file_req_num, 0, 16);
    for (child = 1; child <= 15; child++) {
        if (g_021F6FA0->p_comm_state[child] == 5)
            file_req_num[g_021F6FA0->req_fid[child]]++;
    }
    fid = g_021F6E48;
    for (i = 0; i < 16; i++) {
        fid = (fid + 1) % 16;
        if (g_021F6FA0->fileinfo[fid].active && file_req_num[fid] != 0) {
            send_candidate_fid = fid;
            break;
        }
    }
    if (send_candidate_fid == -1)
        return 0x15;
    g_021F6E48 = send_candidate_fid;
    for (child = 1; child <= 15; child++) {
        if (g_021F6FA0->p_comm_state[child] == 5 && g_021F6FA0->req_fid[child] == send_candidate_fid)
            pollbmp |= (u16)(1 << child);
    }
    hd.type = 3;
    hd.fid = send_candidate_fid;
    databuf = func_021F6890(&hd, (u8 *)g_021F6FA0->sendbuf);
    if (databuf)
        func_02082D44(g_021F6FA0->fileinfo[send_candidate_fid].dl_fileinfo, databuf, 0xe4);
    return func_021F3C80(0xea, pollbmp, g_021F6FA0->sendbuf);
}
