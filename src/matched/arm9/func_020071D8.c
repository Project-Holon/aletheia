/*
 * function: func_020071D8
 * address:  0x020071D8
 * packet:   pkt_020071D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk: func_02031994(ctrl->unk10); sibling of sub_020071CC.
 *
 * symbols:
 *   func_02031994  0x02031994  arm
 */

struct Ctrl020071D8 {
    unsigned char pad[16];
    void *unk10;
};

extern void *func_02031994(void *p, void *out);

void *func_020071D8(struct Ctrl020071D8 *ctrl, void *out)
{
    return func_02031994(ctrl->unk10, out);
}
