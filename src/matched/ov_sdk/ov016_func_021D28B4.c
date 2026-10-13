/*
 * function: DWCi_MOV_MBP_GetChildInfo
 * address:  0x021D28B4
 * packet:   pkt_ov016_021D28B4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_GetChildInfo (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   gDwcMovMbpWork  0x021de65c  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 user[0x16];
    u8 macAddress[6];
    u16 playerNo;
} DWCi_MOV_MBPChildInfo;

typedef struct {
    u16 state;
    u16 connectedBmp;
    u16 entryBmp;
    u16 requestBmp;
    u16 downloadBmp;
    u16 bootBmp;
    u16 endBmp;
} DWCi_MOV_MBPState;

typedef struct {
    DWCi_MOV_MBPState mbpState;
    DWCi_MOV_MBPChildInfo childInfo[1];
} DWCi_MOV_WPB_WORK;

extern DWCi_MOV_WPB_WORK *gDwcMovMbpWork;

DWCi_MOV_MBPChildInfo *DWCi_MOV_MBP_GetChildInfo(u16 child_aid)
{
    if (gDwcMovMbpWork->mbpState.connectedBmp & (1 << child_aid))
        return &gDwcMovMbpWork->childInfo[child_aid - 1];
    return 0;
}
