/*
 * function: JudgeConnectableChild
 * address:  0x021D45A4
 * packet:   pkt_ov016_021D45A4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      JudgeConnectableChild (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   DWCi_MOV_MBP_GetPlayerNo         0x021D28E4  arm  ov016
 *   DWCi_MOV_MBP_GetChildInfo        0x021D28B4  arm  ov016
 *   gDwcMoveidWork                       0x021DE668  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern void *DWCi_MOV_MBP_GetChildInfo(u16 child_aid);
extern u16 DWCi_MOV_MBP_GetPlayerNo(u8 *macAddress);

typedef struct {
    u8 pad0[0xaa0];
    void *sChildInfo[1];
} Wk;

extern Wk *gDwcMoveidWork;

typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
} WMStartParentCallback;

int JudgeConnectableChild(WMStartParentCallback *cb)
{
    u16 playerNo = DWCi_MOV_MBP_GetPlayerNo(cb->macAddress);
    if (playerNo == 0)
        return 0;
    gDwcMoveidWork->sChildInfo[playerNo - 1] = DWCi_MOV_MBP_GetChildInfo(playerNo);
    return 1;
}
