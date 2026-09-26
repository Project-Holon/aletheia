/*
 * function: func_0219F068
 * address:  0x0219F068
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Tail call on the object 0x60 bytes in.
 *
 * Blocker: 0x0219F7B4 is an unlabelled ARM target in the ov009/ov021 window
 *   (ov009's listing emits it as a .word run, ov021's as Thumb code), so
 *   neither `label` nor `sole-ref/code` can attest the ABS32 site.  Witness
 *   class: label / sole-ref/code.
 *
 * symbols:
 *   func_0219F7B4  0x0219F7B4  arm
 */

extern void func_0219F7B4(char *p);

void func_0219F068(char *p)
{
    func_0219F7B4(p + 0x60);
}

