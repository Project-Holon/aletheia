/*
 * file:     mb_parent_sys.c
 * unit:     yes
 * function: func_021F1B3C, MB_CommGetChildUser, MB_CommIsBootable, MB_CommResponseRequest, MBi_CommChangeParentState, func_021F1D58, MBi_CommParentCallback, MBi_CommParentRecvDataPerChild, MBi_CommParentRecvData, MBi_CommParentSendMsg, MBi_CommParentSendDLFileInfo, MBi_ReloadCache, func_021F2A44, MBi_CommParentSendData, MBi_calc_sendblock, func_021F2ED4, func_021F2EE8, func_021F2F04
 * address:  0x021F1B3C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   mbc   0x021F6FA0  data
 *   g_021F6FA0  0x021F6FA0  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 *   func_021F1D58  0x021F1D58  arm  ov107
 *   MI_CpuFill8  0x02082BCC  arm
 *   MBi_ClearParentPieceBuffer  0x021F6850  arm  ov107
 *   MB_UpdateGameInfoMember  0x021F3E9C  arm  ov107
 *   func_021F628C  0x021F628C  arm  ov107
 *   func_021F62A0  0x021F62A0  arm  ov107
 *   func_021F62B4  0x021F62B4  arm  ov107
 *   MB_SendGameInfoBeacon  0x021F3FC8  arm  ov107
 *   func_021F2F04  0x021F2F04  arm  ov107
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   g_021F6EEC                     0x021F6EEC  data
 *   MBi_SetRecvBufferFromChild     0x021F6908  arm
 *   MI_CpuCopy8                    0x02082D44  arm
 *   MBi_CommChangeParentState      0x021F1D0C  arm
 *   MBi_BlockHeaderEnd 0x021F3C80 arm ov107
 *   MBi_MakeParentSendBuffer 0x021F6890 arm ov107
 *   func_0208ED70  0x0208ED70  arm
 *   func_021F2200  0x021F2200  arm  ov107
 *   MBi_MakeParentSendBuffer   0x021F6890  arm
 *   func_021F3C80   0x021F3C80  arm
 *   g_021F6E48     0x021F6E48  data
 *   func_02077EB8 0x02077EB8 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_02075E04 0x02075E04 arm
 *   FS_InitFile 0x020788AC arm
 *   func_02078964 0x02078964 arm
 *   FS_ReadFile 0x02078B70 arm
 *   FS_CloseFile 0x02078A80 arm
 *   g_021F6E4C 0x021F6E4C data
 *   MBi_calc_sendblock           0x021F2E58  arm  ov107
 *   MBi_get_blockinfo            0x021F3A58  arm  ov107
 *   MBi_ReadFromCache            0x021F63E8  arm  ov107
 *   MBi_IsTaskBusy               0x021F6640  arm  ov107
 *   OS_Terminate                 0x02088234  arm
 *   MBi_SetTask                  0x021F6658  arm  ov107
 *   MIi_CpuClear16  0x02082A48  arm
 *   func_021F276C  0x021F276C  arm  ov107
 *   func_021F2A44  0x021F2A44  arm  ov107
 */
#include "mb_parent_sys.h"

struct WMMpRecvData;
struct WMMpRecvHeader;
struct FSArchive;
struct FSFile;
typedef void (*WMCallback_021F1B3C)(u32, void *);

typedef struct WMStartParentCallback {
    u16 apiid;                                       /* 0x00 */
    u16 errcode;                                     /* 0x02 */
    u16 wlCmdID;                                     /* 0x04 */
    u16 wlResult;                                    /* 0x06 */
    u16 state;                                       /* 0x08 */
    u8 macAddress[6];                                /* 0x0A */
    u16 aid;                                         /* 0x10 */
    u16 reason;                                      /* 0x12 */
    u8 ssid[24];                                     /* 0x14 */
    u16 parentSize;                                  /* 0x2C */
    u16 childSize;                                   /* 0x2E */
} WMStartParentCallback;

typedef struct WMCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
} WMCallback;

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
    char pad[0x1e0];
    u32 ntr_off;
    u32 ntr_len;
    u32 ltd_off;
    u32 ltd_len;
} RomHeader;

typedef struct {
    u32 child_address;
    u32 size;
    u32 offset;
    u8 segment_no;
    u8 pad[3];
} MB_BlockInfo;

struct bitmap {
    u16 connected;
    u16 req;
    u16 kick;
    u16 boot;
    u16 mem_full;
};

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enabled);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int func_021F2EE8(unsigned short child_aid);
extern void func_021F1D58(unsigned short child, int state, void *arg);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MBi_ClearParentPieceBuffer(u16 child_aid);
extern void MB_UpdateGameInfoMember(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag);
extern u32 func_021F628C(void);
extern u16 func_021F62A0(void);
extern u8 func_021F62B4(void);
extern void MB_SendGameInfoBeacon(u32 ggid, u16 tgid, u8 attribute);
extern void func_021F2F04(u16 aid, u16 errcode);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id);
extern void MBi_CommChangeParentState(u16 child, int state, void *arg);
extern struct WMMpRecvData *func_0208ED70(const struct WMMpRecvHeader *header, u16 aid);
extern void func_021F2200(void *arg, unsigned short child);
extern u8 *MBi_MakeParentSendBuffer(MBCommParentBlockHeader *hdr, u8 *sendbuf);
extern int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf);
extern struct FSArchive *func_02077EB8(const char *name, int name_len);
extern int OS_IsRunOnTwl(void);
extern RomHeader *func_02075E04(void);
extern void FS_InitFile(void *file);
extern int func_02078964(void *file, void *arc, u32 top, u32 bottom, u32 id);
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);
extern int FS_CloseFile(void *file);
extern void MBi_calc_sendblock(u8 file_id);
extern int MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table,
                             u32 block, MbDownloadFileInfoHeader *mdfi);
extern int MBi_ReadFromCache(MBiCacheList *pl, u32 src, void *dst, u32 len);
extern int MBi_IsTaskBusy(MBiTaskInfo *pt);
extern void OS_Terminate(void);
extern void MBi_SetTask(MBiTaskInfo *pt, void (*task)(MBiTaskInfo *),
                        void (*callback)(MBiTaskInfo *), u32 priority);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int func_021F276C(u8 type, u16 pollbmp);
extern int func_021F2A44(void);
void MB_CommSetParentStateCallback(WMCallback_021F1B3C callback);
void *MB_CommGetChildUser(unsigned short child_aid);
int MB_CommIsBootable(unsigned short child_aid);
int MB_CommResponseRequest(unsigned short child_aid, int ack);
void MBi_CommChangeParentStateCallbackOnly(u16 child, int state, void *arg);
void MBi_CommParentCallback(u16 type, void *arg);
void MBi_CommParentRecvData(void *arg);
void MBi_CommParentSendMsg(u8 type, u16 pollbmp);
int MBi_CommParentSendDLFileInfo(void);
void MBi_ReloadCache(MBiTaskInfo *p_task);
int MBi_CommParentSendBlock(void);
u16 MBi_calc_nextsendblock(unsigned long next_block, unsigned long next_block_req);
BOOL IsChildAidValid(u16 child_aid);
void MBi_CommCallParentError(u16 aid, u16 errcode);
extern int g_021F6EEC;
extern u8 g_021F6E48;
extern char g_021F6E4C[];







void MB_CommSetParentStateCallback(WMCallback_021F1B3C callback)
{
    u32 enabled;

    enabled = OS_DisableInterrupts();
    *(WMCallback_021F1B3C *)&pPwork->parent_callback = callback;
    OS_RestoreInterrupts(enabled);
}







/*
 * sdk:      MB_CommGetChildUser (libmb.TWL.HYB.a(mb_parent.o))
 */
void *MB_CommGetChildUser(unsigned short child_aid)
{
    unsigned long enabled = OS_DisableInterrupts();

    if (mbc && func_021F2EE8(child_aid)) {
        MI_CpuCopy8(&pPwork->childUser[child_aid - 1], &pPwork->childUserCopy, 0x16);
        OS_RestoreInterrupts(enabled);
        return &pPwork->childUserCopy;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}







/*
 * sdk:      MB_CommIsBootable (libmb.TWL.HYB.a(mb_parent.o))
 */
int MB_CommIsBootable(unsigned short child_aid)
{
    if (mbc && func_021F2EE8(child_aid)) {
        if (pPwork->p_comm_state[child_aid - 1] == 7)
            return 1;
    }
    return 0;
}







/*
 * sdk:      MB_CommResponseRequest (libmb.TWL.HYB.a(mb_parent.o))
 */
int MB_CommResponseRequest(unsigned short child_aid, int ack)
{
    unsigned short req;
    int state;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();

    switch (ack) {
    case 0:
        state = 10;
        req = 4;
        break;
    case 1:
        state = 10;
        req = 3;
        break;
    case 2:
        state = 14;
        req = 2;
        break;
    case 3:
        state = 7;
        req = 5;
        break;
    default:
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (mbc && func_021F2EE8(child_aid)) {
        if (state == pPwork->p_comm_state[child_aid - 1]) {
            pPwork->req2child[child_aid - 1] = req;
            OS_RestoreInterrupts(enabled);
            return 1;
        }
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}







/*
 * sdk:      MBi_CommChangeParentState (libmb.TWL.HYB.a(mb_parent.o))
 */
void MBi_CommChangeParentState(unsigned short child, int state, void *arg)
{
    if (func_021F2EE8(child))
        pPwork->p_comm_state[child - 1] = state;
    func_021F1D58(child, state, arg);
}







void MBi_CommChangeParentStateCallbackOnly(u16 child, int state, void *arg)
{
    MBCommPStateCallback callback = pPwork->parent_callback;

    if (callback)
        callback(child, state, arg);
}





/* FIELD: u16 members of fileinfo[id] (gameinfo_child_bmp, gameinfo_changed_bmp, pollbmp) */
#define FIELD(id, off) (*(u16 *)((u8 *)mbc + (id) * 0x5D4 + (off)))




/*
 * sdk:      MBi_CommParentCallback (libmb.TWL.HYB.a mb_parent.o)
 *
 * notes:    the fileinfo fields are addressed as g + fileID * 0x5D4 + constant (the
 *           FIELD macro), which puts the scaled index into the base and folds only the
 *           large constant, as the image does; the API_ERROR switch is on an unsigned
 *           value (cmp; addls pc) and lists every value of its table 0..29 explicitly
 *           so the compiler emits the full table; the child-disconnect block works on a
 *           u16 copy of the aid that the vendor's debug info does not list.
 */
void MBi_CommParentCallback(u16 type, void *arg)
{
    switch (type) {
    case 0x15:
        MBi_CommChangeParentState(0, 1, arg);
        break;

    case 0x11:
        break;

    case 0:
        if (((WMStartParentCallback *)arg)->aid == 0)
            break;
        if (((WMStartParentCallback *)arg)->aid >= 16)
            break;
        MBi_CommChangeParentState(((WMStartParentCallback *)arg)->aid, 2, arg);
        break;

    case 1:
        {
            WMStartParentCallback *sparg = (WMStartParentCallback *)arg;

            if (sparg->aid == 0)
                break;
            if (sparg->aid >= 16)
                break;

            pPwork->childversion[sparg->aid - 1] = 0;
            MI_CpuFill8(&pPwork->childggid[sparg->aid - 1], 0, sizeof(u32));
            MI_CpuFill8(&pPwork->childUser[sparg->aid - 1], 0, sizeof(MBUserInfo));
            MBi_ClearParentPieceBuffer(sparg->aid);
            pPwork->req2child[sparg->aid - 1] = 0;

            {
                u16 child = sparg->aid;

                if (pPwork->fileid_of_child[child - 1] != -1) {
                    u8 fileID = (u8)pPwork->fileid_of_child[child - 1];
                    FIELD(fileID, 0x1D4E) &= (u16)~(1 << child);
                    FIELD(fileID, 0x1D50) |= (u16)(1 << child);
                    pPwork->fileid_of_child[child - 1] = -1;
                    FIELD(fileID, 0x1D4C) &= (u16)~(1 << child);
                }
            }

            if (pPwork->child_entry_bmp & (1 << sparg->aid)) {
                pPwork->child_num--;
                pPwork->child_entry_bmp &= ~(1 << sparg->aid);
            }

            if (pPwork->p_comm_state[sparg->aid - 1] == 8)
                MBi_CommChangeParentState(sparg->aid, 9, 0);

            MBi_CommChangeParentState(sparg->aid, 3, arg);
            pPwork->p_comm_state[sparg->aid - 1] = 0;
        }
        break;

    case 3:
        MBi_CommParentRecvData(arg);
        break;

    case 0x19:
        (void)MBi_CommParentSendData();
        break;

    case 0x1C:
        {
            u8 i;
            for (i = 0; i < 16; i++) {
                if (pPwork->fileinfo[i].active && pPwork->fileinfo[i].gameinfo_changed_bmp) {
                    MB_UpdateGameInfoMember((unsigned char *)(&pPwork->fileinfo[i].game_info), &pPwork->childUser[0],
                                  pPwork->fileinfo[i].gameinfo_child_bmp,
                                  pPwork->fileinfo[i].gameinfo_changed_bmp);
                    pPwork->fileinfo[i].gameinfo_changed_bmp = 0;
                }
            }
        }
        MB_SendGameInfoBeacon(func_021F628C(), func_021F62A0(), func_021F62B4());
        break;

    case 0xFF:
        switch (((u16 *)arg)[1]) {
        case 1:
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
            func_021F2F04(0, 9);
            break;
        case 15:
        default:
            func_021F2F04(0, 8);
            break;
        }
        break;

    case 0x100:
        switch ((unsigned int)((WMCallback *)arg)->apiid) {
        case 0:
        case 7:
        case 8:
        case 13:
        case 14:
        case 15:
        case 17:
        case 18:
        case 21:
        case 25:
        case 29:
            func_021F2F04(0, 9);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
        case 10:
        case 11:
        case 12:
        case 16:
        case 19:
        case 20:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
        case 28:
        default:
            func_021F2F04(0, 8);
            break;
        }
        break;

    default:
        break;
    }

    if (type == 0x11) {
        MBCommPStateCallback tmpCb = pPwork->parent_callback;
        MIi_CpuClearFast(0, mbc, 0x7D00);
        mbc = 0;
        if (tmpCb)
            tmpCb(0, 12, 0);
    }
}





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
                    || pPwork->childggid[child - 1] != pPwork->fileinfo[fileid].game_info_ptr->ggid) {
                    pPwork->req2child[child - 1] = 4;
                } else {
                    for (i = 0; i < 16; i++) {
                        if (pPwork->fileinfo[fileid].gameinfo_child_bmp & (1 << i))
                            entry_num++;
                    }
                    if (entry_num >= pPwork->fileinfo[fileid].game_info_ptr->maxPlayerNum) {
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




/*
 * sdk:      MBi_CommParentRecvData (libmb.TWL.HYB.a(mb_parent.o))
 */
void MBi_CommParentRecvData(void *arg)
{
    unsigned short i;
    unsigned short *datap;

    for (i = 0; i < 16; i++) {
        if (pPwork->fileinfo[i].active != 0)
            pPwork->fileinfo[i].nextb = 0;
    }
    g_021F6EEC = 0;
    for (i = 1; i <= 15; i++) {
        datap = (short unsigned int *)func_0208ED70(arg, i);
        if (datap != 0 && datap[0] != 0xFFFF && datap[0] != 0)
            func_021F2200(datap, i);
    }
}




void MBi_CommParentSendMsg(u8 type, u16 pollbmp)
{
    MBCommParentBlockHeader hd;

    hd.type = type;
    MBi_MakeParentSendBuffer(&hd, (u8 *)pPwork->common.sendbuf);
    MBi_BlockHeaderEnd(6, pollbmp, pPwork->common.sendbuf);
}





/*
 * sdk:      MBi_CommParentSendDLFileInfo (libmb.TWL.HYB.a(mb_parent.o))
 */
int MBi_CommParentSendDLFileInfo(void)
{
    MBCommParentBlockHeader hd;
    u8 *databuf;
    u16 child;
    u8 i;
    u8 fid;
    s8 send_candidate_fid = -1;
    u8 file_req_num[16];
    u16 pollbmp = 0;

    MI_CpuFill8(file_req_num, 0, 16);
    for (child = 1; child <= 15; child++) {
        if (pPwork->p_comm_state[child - 1] == 5)
            file_req_num[pPwork->fileid_of_child[child - 1]]++;
    }
    fid = g_021F6E48;
    for (i = 0; i < 16; i++) {
        fid = (fid + 1) % 16;
        if (pPwork->fileinfo[fid].active && file_req_num[fid] != 0) {
            send_candidate_fid = fid;
            break;
        }
    }
    if (send_candidate_fid == -1)
        return 0x15;
    g_021F6E48 = send_candidate_fid;
    for (child = 1; child <= 15; child++) {
        if (pPwork->p_comm_state[child - 1] == 5 && pPwork->fileid_of_child[child - 1] == send_candidate_fid)
            pollbmp |= (u16)(1 << child);
    }
    hd.type = 3;
    hd.fid = send_candidate_fid;
    databuf = MBi_MakeParentSendBuffer(&hd, (u8 *)pPwork->common.sendbuf);
    if (databuf)
        MI_CpuCopy8(pPwork->fileinfo[send_candidate_fid].dl_fileinfo, databuf, 0xe4);
    return MBi_BlockHeaderEnd(0xea, pollbmp, pPwork->common.sendbuf);
}






/*
 * sdk:      MBi_ReloadCache (libmb.TWL.HYB.a(mb_parent.o))
 */
void MBi_ReloadCache(MBiTaskInfo *p_task)
{
    MBiCacheInfo *p_info;
    MBiCacheList *p_list;
    u32 file[18];
    void *arc;
    u32 length;
    RomHeader *header;
    u32 boundary_ntr;
    u32 boundary_ltd;

    p_list = (MBiCacheList *)p_task->param[1];
    p_info = (MBiCacheInfo *)p_task->param[0];
    length = p_info->len;
    arc = func_02077EB8(p_list->arc_name, p_list->arc_name_len);
    if (arc == 0) {
        arc = p_list->arc_pointer;
    }
    if (OS_IsRunOnTwl() && arc == func_02077EB8(g_021F6E4C, 3)) {
        header = func_02075E04();
        boundary_ntr = header->ntr_off + header->ntr_len;
        boundary_ltd = header->ltd_off + header->ltd_len;
        if (p_info->src < boundary_ntr && p_info->src + length > boundary_ntr) {
            length = boundary_ntr - p_info->src;
        } else if (p_info->src < boundary_ltd && p_info->src + length > boundary_ltd) {
            length = boundary_ltd - p_info->src;
        }
    }
    FS_InitFile(file);
    if (func_02078964(file, arc, p_info->src, p_info->src + length, 0xffffffff)) {
        if (length == FS_ReadFile((struct FSFile *)file, p_info->ptr, length)) {
            p_info->state = 2;
        }
        FS_CloseFile(file);
    }
    if (p_info->state != 2) {
        p_info->src = 0;
        p_info->state = 2;
    }
}






int MBi_CommParentSendBlock(void)
{
	MBCommParentBlockHeader hd;
	u8 *databuf;
	u8 i;
	MB_BlockInfo bi;

	if (pPwork->file_num == 0)
		return 0x15;

	for (i = 0; i < 16; i++) {
		pPwork->cur_fileid = (u8)((pPwork->cur_fileid + 1) % 16);
		if (pPwork->fileinfo[pPwork->cur_fileid].active
		    && pPwork->fileinfo[pPwork->cur_fileid].pollbmp)
			break;
	}
	if (i == 16)
		return 0x15;

	MBi_calc_sendblock(pPwork->cur_fileid);

	if (!MBi_get_blockinfo(&bi, &pPwork->fileinfo[pPwork->cur_fileid].blockinfo_table,
	                       pPwork->fileinfo[pPwork->cur_fileid].currentb,
	                       &pPwork->fileinfo[pPwork->cur_fileid].header))
		return 0x15;

	hd.type = 4;
	hd.fid = pPwork->cur_fileid;
	hd.seqno = pPwork->fileinfo[pPwork->cur_fileid].currentb;
	databuf = MBi_MakeParentSendBuffer(&hd, (u8 *)pPwork->common.sendbuf);

	{
		u32 card_addr = (u32)(bi.offset -
		                      pPwork->fileinfo[pPwork->cur_fileid].blockinfo_table.seg_src_offset[bi.segment_no] +
		                      pPwork->fileinfo[pPwork->cur_fileid].card_mapping[bi.segment_no]);
		MBiCacheList *const pl = pPwork->fileinfo[pPwork->cur_fileid].cache_list;
		if (!MBi_ReadFromCache(pl, card_addr, databuf, bi.size)) {
			MBiTaskInfo *const p_task = &pPwork->cur_task;
			if (!MBi_IsTaskBusy(p_task)) {
				if (pl->lifetime) {
					--pl->lifetime;
				} else {
					MBiCacheInfo *pi = pl->list;
					MBiCacheInfo *trg = 0;
					int i;
					for (i = 0; i < 4; ++i) {
						if (pi[i].state == 2) {
							if (!trg || (trg->src > pi[i].src))
								trg = &pi[i];
						}
					}
					if (!trg)
						OS_Terminate();
					pl->lifetime = 2;
					trg->state = 1;
					trg->src = (card_addr & ~31);
					p_task->param[0] = (u32)trg;
					p_task->param[1] = (u32)pl;
					MBi_SetTask(p_task, MBi_ReloadCache, 0, 4);
				}
			}
			return 0x15;
		}
	}
	return MBi_BlockHeaderEnd((int)(bi.size + sizeof(MBCommParentBlockHeader)),
	                          pPwork->fileinfo[pPwork->cur_fileid].pollbmp,
	                          pPwork->common.sendbuf);
}




/*
 * sdk:      MBi_CommParentSendData (libmb.TWL.HYB.a(mb_parent.o))
 */
static int MBi_CommParentSendData(void)
{
    int errcode;
    u16 child;
    struct bitmap bmp;

    MIi_CpuClear16(0, &bmp, sizeof(bmp));

    for (child = 1; child <= 15; child++) {
        switch (pPwork->p_comm_state[child - 1]) {
        case 2:
            bmp.connected |= 1 << child;
            break;
        case 5:
            bmp.req |= 1 << child;
            break;
        case 4:
            bmp.kick |= 1 << child;
            break;
        case 8:
            bmp.boot |= 1 << child;
            break;
        case 11:
            bmp.mem_full |= 1 << child;
            break;
        }
    }

    if (bmp.boot)
        errcode = func_021F276C(5, bmp.boot);
    else if (bmp.connected)
        errcode = func_021F276C(1, bmp.connected);
    else if (bmp.mem_full)
        errcode = func_021F276C(6, bmp.mem_full);
    else if (bmp.kick)
        errcode = func_021F276C(2, bmp.kick);
    else if (bmp.req)
        errcode = MBi_CommParentSendDLFileInfo();
    else
        errcode = func_021F2A44();

    if (errcode != 0x15)
        return errcode;
    return func_021F276C(0, 0xffff);
}




/*
 * sdk:      MBi_calc_sendblock (mb_parent.o), TwlSDK/libmb.TWL.HYB.a
 *
 * Advance one multi-boot parent's send block by one when it is already
 * within two of the peer's `b`, otherwise snap `a` to `b`.  124/124 bytes.
 *
 * The whole `e` local of the parked source was the residue: with the
 * element pointer held in a named local, mwcc keeps the element base in
 * r3 and reuses the derived `e+0x1d00` for the else-arm store.  The image
 * keeps the base in ip, derives +0x1d00 into r0 for the guard/if body, and
 * RE-DERIVES `ip + 0x1d00` in the else arm; its else arm is also reached
 * by fall-through from the inner test, so the a/b update is one if/else:
 *
 *     if (y <= x && x <= y + 2) e->a = x + 1; else e->a = y;
 *
 * Spelling the element pointer inline at every use (no local) gives all
 * three at once: `mla ip, r0, r1, r2`, the +0x1d00 re-derivation, and the
 * predicated `strhle` + `bxle lr` whose fall-through lands in the else arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov107_func_021F2E58.c \
 *       --func MBi_calc_sendblock --addr 0x021F2E58 --region ov107 \
 *       --cc dsi/1.1p1 --flags=-O4,p --arm --lang c99 --diff
 */
void MBi_calc_sendblock(u8 file_id)
{
    if (!(g_021F6EEC & (1 << file_id)))
        return;
    if (pPwork->fileinfo[file_id].active != 0
        && pPwork->fileinfo[file_id].pollbmp != 0) {
        u16 x = pPwork->fileinfo[file_id].currentb;
        u16 y = pPwork->fileinfo[file_id].nextb;
        if (y <= x && x <= y + 2)
            pPwork->fileinfo[file_id].currentb = x + 1;
        else
            pPwork->fileinfo[file_id].currentb = y;
        return;
    }
}





u16 MBi_calc_nextsendblock(unsigned long next_block, unsigned long next_block_req)
{
    if (next_block_req <= next_block)
        next_block_req = next_block;
    return next_block_req;
}





BOOL IsChildAidValid(u16 child_aid)
{
    if (child_aid >= 1 && child_aid <= 15)
        return 1;
    return 0;
}





void MBi_CommCallParentError(u16 aid, u16 errcode)
{
    u16 e_stat;

    e_stat = errcode;
    MBi_CommChangeParentStateCallbackOnly(aid, 0xD, &e_stat);
}
