/*
 * function: func_02213894
 * address: 0x02213894
 * packet: pkt_ov199_02213894
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov213_id 0x000000D5 data
 *   ov093_id 0x0000005D data
 *   data_021BB0B0 0x021BB0B0 data ov213
 *   data_021F03C4 0x021F03C4 data ov093
 *   data_021EFDAC 0x021EFDAC data ov093
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   PROCSYS_Main  0x02031330  arm  arm9
 *   PROCSYS_Push  0x02031348  arm  arm9
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb  arm9
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm  arm9
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm  arm9
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm  arm9
 *   GFL_NET_GetRunState  0x0203CD98  arm  arm9
 *   GFL_NET_GetInitParam  0x0203D798  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Link;
struct MyWk {
    void *f0;
    u32 f4;
    u32 f8;
    u32 fC;
};
struct Row { u8 pad[10]; u8 name[6]; };
struct PWk {
    u32 f0;
    u8 *f4;
    u8 *f8;
    u32 fC;
};

extern u8 ov213_id[];
extern u8 ov093_id[];
extern u8 data_021BB0B0[];
extern u8 data_021F03C4[];
extern u8 data_021EFDAC[];
extern u32 PROCSYS_Main(void *);
extern void PROCSYS_Push(void *, int, void *, void *);
extern void GFL_USE_CancelChangeAndPlayBgm(u16, u32);
typedef signed int     s32;
struct Entry;
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(int);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_02039C68(struct Link *, u32, u32);
extern u32 func_02039CB4(struct Link *, u32, u32);
extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int DWC_RAPCOMMON_HandleNetError(int, int);

int func_02213894(void *proc, int *seq, struct PWk *pw, struct MyWk *wk)
{
    u32 st = PROCSYS_Main(wk->f0);

    switch (*seq) {
    case 0:
        GFL_USE_CancelChangeAndPlayBgm(*(u16 *)(pw->f4 + 0x18), 0xffff);
        *(u32 *)(pw->f8 + 0x44) = 1;
        PROCSYS_Push(wk->f0, (int)ov213_id, data_021BB0B0, pw->f8);
        st = 2;
        *seq = 1;
        break;
    case 1:
        if (st != 1) *seq = 2;
        break;
    case 2:
        func_02034AC4((int)ov093_id);
        wk->f8 = 1;
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)data_021F03C4, 9, 0);
        wk->fC = 1;
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8, 0x24);
        *seq = 3;
        break;
    case 3:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8, 0x24)) *seq = 4;
        break;
    case 4:
        PROCSYS_Push(wk->f0, -1, data_021EFDAC, pw->f4);
        st = 2;
        *seq = 5;
        break;
    case 5:
        if (st != 1) *seq = 6;
        break;
    case 6:
        *seq = 7;
        break;
    case 7:
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd2, 0x24);
        wk->f4 = 0;
        *seq = 8;
        break;
    case 8:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd2, 0x24)) {
            GFL_NET_COMMAND_DeleteCommandTable(0x100);
            wk->fC = 0;
            func_02034A5C((int)ov093_id);
            wk->f8 = 0;
            *seq = 9;
        }
        if (GFL_NET_GetRunState() && *(u8 *)((u8 *)GFL_NET_GetInitParam() + 0x65) == 3) {
            if (wk->f4++ > 600) {
                GFL_NET_COMMAND_DeleteCommandTable(0x100);
                wk->fC = 0;
                func_02034A5C((int)ov093_id);
                wk->f8 = 0;
                *seq = 9;
                wk->f4 = 0;
            }
        }
        break;
    case 9:
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd3, 0x24);
        *seq = 10;
        wk->f4 = 0;
        break;
    case 10:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xd3, 0x24)) *seq = 11;
        if (GFL_NET_GetRunState() && *(u8 *)((u8 *)GFL_NET_GetInitParam() + 0x65) == 3) {
            if (wk->f4++ > 600) {
                *seq = 11;
                wk->f4 = 0;
            }
        }
        break;
    case 11: {
        int flag = 1;
        int n, a, b, i, j, k, v;
        u8 *q;
        u8 side;
        if (pw->f4[0x22] == 0) *(u32 *)(pw->f8 + 0x44) = 2;
        else *(u32 *)(pw->f8 + 0x44) = 4;
        switch (*(u32 *)(pw->f4 + 0x8c)) {
        case 1:
        case 4:
            *(u32 *)(pw->f8 + 0x40) = 0;
            break;
        case 0:
        case 3:
            *(u32 *)(pw->f8 + 0x40) = 1;
            break;
        case 2:
            *(u32 *)(pw->f8 + 0x40) = 2;
            break;
        case 6:
            wk->f4 = 0;
            flag = 0;
            *seq = 15;
            break;
        default:
            *(u32 *)(pw->f8 + 0x40) = 2;
            break;
        }
        q = pw->f4;
        if (q[0x22] == 0) {
            n = 1;
            a = 0;
            b = 1;
        } else {
            n = 3;
            a = 0;
            b = 2;
        }
        side = q[0x21];
        for (i = 0; i <= n; i++) {
            if ((i & 1) == (side & 1)) {
                k = (side & 1) ? (i & 2) + 1 : (i & 2);
                for (j = 0; j < 6; j++)
                    ((struct Row *)pw->f8)[a + (i >> 1)].name[j] = pw->f4[k * 6 + j + 0xc8];
            } else {
                k = (side & 1) ? (i & 2) : (i & 2) + 1;
                for (j = 0; j < 6; j++)
                    ((struct Row *)pw->f8)[b + (i >> 1)].name[j] = pw->f4[k * 6 + j + 0xc8];
            }
        }
        if (flag) {
            PROCSYS_Push(wk->f0, (int)ov213_id, data_021BB0B0, pw->f8);
            st = 2;
            *seq = 12;
        }
        break;
    }
    case 12:
        if (st != 1) *seq = 14;
        break;
    case 13:
        break;
    case 14:
        return 1;
    case 15:
        if (wk->f4++ > 0x708) {
            GFL_NET_ERR_RequestScreen();
            pw->fC = 2;
            return 1;
        }
        break;
    }

    if (GFL_NET_GetRunState() && st != 1) {
        if (*(u8 *)((u8 *)GFL_NET_GetInitParam() + 0x65) == 3) {
            if (func_0200FB24()) {
                GFL_NET_ERR_RequestScreen();
                pw->fC = 1;
                return 1;
            }
        } else {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0:
                break;
            case 1:
            case 2:
            case 3:
            default:
                pw->fC = 2;
                return 1;
            case 4:
                pw->fC = 3;
                return 1;
            }
        }
    }
    return 0;
}
