/*
 * function: func_021F1D80
 * address:  0x021F1D80
 * packet:   pkt_ov107_021F1D80
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_CommParentCallback (libmb.TWL.HYB.a mb_parent.o)
 *
 * symbols:
 *   func_021F1D0C  0x021F1D0C  arm  ov107
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021F6850  0x021F6850  arm  ov107
 *   func_021F26C0  0x021F26C0  arm  ov107
 *   func_021F2CBC  0x021F2CBC  arm  ov107
 *   func_021F3E9C  0x021F3E9C  arm  ov107
 *   func_021F628C  0x021F628C  arm  ov107
 *   func_021F62A0  0x021F62A0  arm  ov107
 *   func_021F62B4  0x021F62B4  arm  ov107
 *   func_021F3FC8  0x021F3FC8  arm  ov107
 *   func_021F2F04  0x021F2F04  arm  ov107
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   g_021F6FA0     0x021F6FA0  data
 *
 * notes:    the fileinfo fields are addressed as g + fileID * 0x5D4 + constant (the
 *           FIELD macro), which puts the scaled index into the base and folds only the
 *           large constant, as the image does; the API_ERROR switch is on an unsigned
 *           value (cmp; addls pc) and lists every value of its table 0..29 explicitly
 *           so the compiler emits the full table; the child-disconnect block works on a
 *           u16 copy of the aid that the vendor's debug info does not list.
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

typedef struct MBUserInfo {
    u8 data[0x16];
} MBUserInfo;

typedef struct MBGameInfo {
    u8 data[0x4E0];
} MBGameInfo;

typedef void (*MBCommPStateCallback)(u16 child_aid, u32 status, void *arg);

typedef struct MBiParentFileInfo {
    MBGameInfo game_info;                            /* 0x000 */
    u16 pollbmp;                                     /* 0x4E0 */
    u16 gameinfo_child_bmp;                          /* 0x4E2 */
    u16 gameinfo_changed_bmp;                        /* 0x4E4 */
    u8 active;                                       /* 0x4E6 */
    u8 pad[0x5D4 - 0x4E7];
} MBiParentFileInfo;

typedef struct MBCommPWork {
    u8 pad0[0x1340];
    MBUserInfo childUser[15];                        /* 0x1340 */
    u16 childversion[15];                            /* 0x148A */
    u32 childggid[15];                               /* 0x14A8 */
    MBCommPStateCallback parent_callback;            /* 0x14E4 */
    int p_comm_state[15];                            /* 0x14E8 */
    u16 pad1524;                                     /* 0x1524 */
    s8 fileid_of_child[15];                          /* 0x1526 */
    u8 child_num;                                    /* 0x1535 */
    u16 child_entry_bmp;                             /* 0x1536 */
    u8 pad1538[0x1754 - 0x1538];
    u16 req2child[15];                               /* 0x1754 */
    u8 pad1772[0x186C - 0x1772];
    MBiParentFileInfo fileinfo[16];                  /* 0x186C */
} MBCommPWork;

extern MBCommPWork *g_021F6FA0;

extern void func_021F1D0C(u16 child, int state, void *arg);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_021F6850(u16 child_aid);
extern void func_021F26C0(void *arg);
extern int func_021F2CBC(void);
extern void func_021F3E9C(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag);
extern u32 func_021F628C(void);
extern u16 func_021F62A0(void);
extern u8 func_021F62B4(void);
extern void func_021F3FC8(u32 ggid, u16 tgid, u8 attribute);
extern void func_021F2F04(u16 aid, u16 errcode);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);

#define FIELD(id, off) (*(u16 *)((u8 *)g_021F6FA0 + (id) * 0x5D4 + (off)))
void func_021F1D80(u16 type, void *arg)
{
    switch (type) {
    case 0x15:
        func_021F1D0C(0, 1, arg);
        break;

    case 0x11:
        break;

    case 0:
        if (((WMStartParentCallback *)arg)->aid == 0)
            break;
        if (((WMStartParentCallback *)arg)->aid >= 16)
            break;
        func_021F1D0C(((WMStartParentCallback *)arg)->aid, 2, arg);
        break;

    case 1:
        {
            WMStartParentCallback *sparg = (WMStartParentCallback *)arg;

            if (sparg->aid == 0)
                break;
            if (sparg->aid >= 16)
                break;

            g_021F6FA0->childversion[sparg->aid - 1] = 0;
            MI_CpuFill8(&g_021F6FA0->childggid[sparg->aid - 1], 0, sizeof(u32));
            MI_CpuFill8(&g_021F6FA0->childUser[sparg->aid - 1], 0, sizeof(MBUserInfo));
            func_021F6850(sparg->aid);
            g_021F6FA0->req2child[sparg->aid - 1] = 0;

            {
                u16 child = sparg->aid;

                if (g_021F6FA0->fileid_of_child[child - 1] != -1) {
                    u8 fileID = (u8)g_021F6FA0->fileid_of_child[child - 1];
                    FIELD(fileID, 0x1D4E) &= (u16)~(1 << child);
                    FIELD(fileID, 0x1D50) |= (u16)(1 << child);
                    g_021F6FA0->fileid_of_child[child - 1] = -1;
                    FIELD(fileID, 0x1D4C) &= (u16)~(1 << child);
                }
            }

            if (g_021F6FA0->child_entry_bmp & (1 << sparg->aid)) {
                g_021F6FA0->child_num--;
                g_021F6FA0->child_entry_bmp &= ~(1 << sparg->aid);
            }

            if (g_021F6FA0->p_comm_state[sparg->aid - 1] == 8)
                func_021F1D0C(sparg->aid, 9, 0);

            func_021F1D0C(sparg->aid, 3, arg);
            g_021F6FA0->p_comm_state[sparg->aid - 1] = 0;
        }
        break;

    case 3:
        func_021F26C0(arg);
        break;

    case 0x19:
        (void)func_021F2CBC();
        break;

    case 0x1C:
        {
            u8 i;
            for (i = 0; i < 16; i++) {
                if (g_021F6FA0->fileinfo[i].active && g_021F6FA0->fileinfo[i].gameinfo_changed_bmp) {
                    func_021F3E9C((unsigned char *)(&g_021F6FA0->fileinfo[i].game_info), &g_021F6FA0->childUser[0],
                                  g_021F6FA0->fileinfo[i].gameinfo_child_bmp,
                                  g_021F6FA0->fileinfo[i].gameinfo_changed_bmp);
                    g_021F6FA0->fileinfo[i].gameinfo_changed_bmp = 0;
                }
            }
        }
        func_021F3FC8(func_021F628C(), func_021F62A0(), func_021F62B4());
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
        MBCommPStateCallback tmpCb = g_021F6FA0->parent_callback;
        MIi_CpuClearFast(0, g_021F6FA0, 0x7D00);
        g_021F6FA0 = 0;
        if (tmpCb)
            tmpCb(0, 12, 0);
    }
}
