/*
 * function: DWCi_MOV_WH_StateOutStartScan
 * address:  0x02178788
 * packet:   pkt_ov014_02178788
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The WM_StartScanEx callback that DWCi_MOV_WH_StateInStartScan installs (the DWC copy of
 * the NitroSDK demo wh.c's scan callback).  arg is a WMStartScanExCallback:
 * errcode +2, state +8, bssDescCount +0xE, bssDesc[] +0x10, linkLevel[]
 * +0x50.  Each found BSS is copied to +0xF40 of the work block behind
 * g_021797A8 and offered to the hooks at +0x1E88 and +0x1E94.
 *
 * symbols:
 *   g_021797A8          0x021797A8  data   ov014  a4
 *   sWihAssertText          0x0217979C  data   a1
 *   func_0217814C       0x0217814C  thumb  ov014
 *   func_02178138       0x02178138  thumb  ov014
 *   func_02178964       0x02178964  thumb  ov014
 *   WIH_IsMatchingParent       0x0217873C  thumb  ov014
 *   WIH_DWC_RequestAlertLevel       0x02010864  thumb
 *   WIH_DWC_Dummy       0x02010884  thumb
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   GFL_NET_GetUserArg       0x0203D650  arm
 *   func_02034714       0x02034714  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A8;
extern char sWihAssertText[];

extern void func_0217814C(int err);
extern void func_02178138(int state);
extern int func_02178964(void);
extern int WIH_IsMatchingParent(u8 *p);
extern void WIH_DWC_RequestAlertLevel(u32 v);
extern void WIH_DWC_Dummy(void);
extern void DC_InvalidateRange(void *p, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 GFL_NET_GetUserArg(void);
extern void func_02034714(const char *expr, u32 line, const char *file);

typedef struct ScanExCb {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u16 reserved;
    u16 bssDescCount;
    void *bssDesc[16];
    u16 linkLevel[16];
} ScanExCb;

typedef void (*FoundFn)(void *desc, u32 a, u16 level);
typedef int (*FilterFn)(void *desc);

void DWCi_MOV_WH_StateOutStartScan(void *arg)
{
    ScanExCb *cb = arg;
    u16 state = cb->state;
    int found;
    int i;
    u8 *w;

    *(u16 *)(g_021797A8 + 0x1EBC) += 1;
    *(u16 *)(g_021797A8 + 0x1EBE) = 0;

    if (cb->errcode != 0) {
        func_0217814C(cb->errcode);
        func_02178138(9);
        return;
    }
    if (*(int *)(g_021797A8 + 0x1E70) != 2) {
        *(u16 *)(g_021797A8 + 0x1EB4) = 0;
        if (func_02178964() == 0)
            func_02178138(9);
        return;
    }
    *(u16 *)(g_021797A8 + 0x1EBE) = *(u16 *)(g_021797A8 + 0x1EC2);

    switch (state) {
    case 4:
        WIH_DWC_Dummy();
        return;
    case 5:
        if (cb->bssDescCount != 0)
            DC_InvalidateRange(g_021797A8 + 0x1000, 0x400);
        found = 0;
        for (i = 0; i < cb->bssDescCount; i++) {
            w = g_021797A8;
            MI_CpuCopy8(cb->bssDesc[i], w + 0xF40, 0xC0);
            WIH_DWC_RequestAlertLevel((u8)cb->linkLevel[i]);
            if (*(FoundFn *)(g_021797A8 + 0x1E88) != 0)
                (*(FoundFn *)(g_021797A8 + 0x1E88))(w + 0xF40, GFL_NET_GetUserArg(),
                                                    cb->linkLevel[i]);
            if (WIH_IsMatchingParent(w + 0xF40) != 0) {
                if (*(FilterFn *)(g_021797A8 + 0x1E94) == 0)
                    func_02034714(sWihAssertText, 0, sWihAssertText);
                if ((*(FilterFn *)(g_021797A8 + 0x1E94))(w + 0xF40) != 0)
                    found = 1;
            }
        }
        if (*(u16 *)(g_021797A8 + 0x1EB4) != 0 && found != 0) {
            *(u16 *)(g_021797A8 + 0x1EBE) = 0;
            if (func_02178964() == 0)
                func_02178138(9);
        }
        break;
    }
}
