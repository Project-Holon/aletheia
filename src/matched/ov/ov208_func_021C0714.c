/*
 * function: ZUKAN_DETAIL_AREA_UpdatePrintQueues
 * address:  0x021C0714
 * packet:   pkt_ov208_021C0714
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   ZUKAN_DETAIL_AREA_FlushPrintWindow  0x021C0740  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void ZUKAN_DETAIL_AREA_FlushPrintWindow(u16 *heap, u8 *p, int key, u8 i);

void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        PRINTSYS_QUE_Main((struct PrintSys *)(((u32 *)(p + 0x34))[i]));
        ZUKAN_DETAIL_AREA_FlushPrintWindow(heap, p, key, i);
    }
}
