/*
 * function: func_021F34CC
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u32 target;
    u8 *src;
    u8 *dst;
    u32 size;
} SegmentHeaderInfo;

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);

void func_021F34CC(SegmentHeaderInfo *p, u32 top, u32 bottom, int clean)
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
        func_02082BCC(p->dst + top, 0, bottom - top);
        return;
    }
    func_02082D44(p->src + top, p->dst + top, bottom - top);
}
