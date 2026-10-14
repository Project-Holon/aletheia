/*
 * function: CTVT_CAMVIEW_GetSlotBufferStep
 * address:  0x021B785C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Table lookup at gCtvtSlotStepTable, value shifted in the second arm.
 *
 * symbols:
 *   COMM_TVT_SYS_GetLayoutMode  0x021BE05C  thumb  ov172
 *   COMM_TVT_SYS_GetHalfRes  0x021BE078  thumb  ov172
 *   gCtvtSlotStepTable    0x021C6EB4  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int COMM_TVT_SYS_GetLayoutMode(void *p);
extern u32 COMM_TVT_SYS_GetHalfRes(void *p);
extern u32 gCtvtSlotStepTable[];

u32 CTVT_CAMVIEW_GetSlotBufferStep(void *p)
{
    u32 i = COMM_TVT_SYS_GetLayoutMode(p);
    if (COMM_TVT_SYS_GetHalfRes(p) == 0) {
        return gCtvtSlotStepTable[i];
    }
    return gCtvtSlotStepTable[i] >> 2;
}
