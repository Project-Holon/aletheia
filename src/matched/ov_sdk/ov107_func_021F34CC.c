/*
 * function: MBi_ReadSegmentHeader
 * address:  0x021F34CC
 * packet:   pkt_ov107_021F34CC
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ReadSegmentHeader (libmb.TWL.HYB.a mb_fileinfo.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u32 target;
    u8 *src;
    u8 *dst;
    u32 size;
} SegmentHeaderInfo;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);

void MBi_ReadSegmentHeader(SegmentHeaderInfo *p, u32 top, u32 bottom, int clean)
{
    if (top < 0x4000)
        top = 0x4000;
    if (bottom > 0x8000)
        bottom = 0x8000;
    if (top < p->target)
        top = p->target;
    if (bottom > p->target + p->size)
        bottom = p->target + p->size;
    if (top >= bottom)
        return;
    if (clean) {
        MI_CpuFill8(p->dst + top, 0, bottom - top);
        return;
    }
    MI_CpuCopy8(p->src + top, p->dst + top, bottom - top);
}
