/*
 * function: FLD_FACEUP_VBlankUpload
 * address:  0x021F57D8
 * packet:   pkt_ov082_021F57D8
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020409E0  0x020409E0  arm
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    char fC[0xC];
    char f18[0xC];
} Sub;

extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);

void FLD_FACEUP_VBlankUpload(int a0, char *p)
{
    Sub *q = (Sub *)(p + 0x28);
    Sub *r;

    if (q->f4 != 0) {
        func_020409E0(3, q->fC, 0xC, 0x10D);
        func_020409E0(3, q->f18, 0xC, 0x12D);
        q->f4 = 0;
    }
    r = (Sub *)(p + 0x4C);
    if (r->f4 != 0) {
        func_020409E0(3, r->fC, 8, 0x16E);
        func_020409E0(3, r->f18, 8, 0x18E);
        r->f4 = 0;
    }
}
