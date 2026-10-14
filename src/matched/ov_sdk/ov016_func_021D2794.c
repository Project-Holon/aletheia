/*
 * function: DWCi_MOV_MBP_GetChildBmp
 * address:  0x021D2794
 * packet:   pkt_ov016_021D2794
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_GetChildBmp (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   gDwcMovMbpWork  0x021de65c  data
 *   sDwcMovMbpTable  0x021db9d4  data
 *   gMovMbpBuffers  0x021DB9D4  data
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

extern u16 *sDwcMovMbpTable[6];
extern u16 *gMovMbpBuffers[6];

u16 DWCi_MOV_MBP_GetChildBmp(int bmpType)
{
    sDwcMovMbpTable[0] = &gDwcMovMbpWork->mbpState.connectedBmp;
    sDwcMovMbpTable[1] = &gDwcMovMbpWork->mbpState.entryBmp;
    sDwcMovMbpTable[2] = &gDwcMovMbpWork->mbpState.requestBmp;
    sDwcMovMbpTable[3] = &gDwcMovMbpWork->mbpState.downloadBmp;
    sDwcMovMbpTable[4] = &gDwcMovMbpWork->mbpState.bootBmp;
    sDwcMovMbpTable[5] = &gDwcMovMbpWork->mbpState.endBmp;
    return *gMovMbpBuffers[bmpType];
}
