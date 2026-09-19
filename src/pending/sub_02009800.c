/*
 * function: sub_02009800
 * address:  0x02009800
 * packet:   pkt_02009800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocking: unresolved: 02157138 (thumb, from header) has no witness outside 02009800..02009; unresolved: 0000000D (data, from header) has no witness outside 02009800..020098; unresolved: 00000009 (data, from header) has no witness outside 02009800..020098
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02157138  0x02157138  thumb ov009
 *   ov_id_09       0x00000009  data
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_0D       0x0000000D  data
 *
 * The wifilist constructor.  Already diagnosed in the header of
 * src/matched/unit_02009860.c under "NEAR MISS, 0x02009800": the only branch
 * to func_02157138 (ov009) anywhere in the image is the call in this
 * function, so the overlay-label witness is inside the compared range and the
 * site stays wildcarded whatever the C says; no cut can help.
 *
 * blocking class: label / overlay (0x02157138 has no witness outside
 * 0x02009800..0x02009848).
 *
 * The four ids arrive from literal pool words holding 0x09, 0x0A, 0x0B and
 * 0x0D rather than as `movs`, so they are relocations against absolute
 * symbols, not integer literals: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  With
 * the four declared as extern data symbols all four sites resolve and every
 * concrete byte reproduces; only the ov009 call is left.
 */

extern void func_02082BCC(void *dst, int val, unsigned n);
extern void func_02034A5C(void *id);
extern void func_02034AC4(void *id);
extern void func_02157138(void *p);

extern unsigned char ov_id_09[];
extern unsigned char ov_id_0A[];
extern unsigned char ov_id_0B[];
extern unsigned char ov_id_0D[];

void sub_02009800(void *p)
{
    func_02082BCC(p, 0, 0x7c4);
    func_02034A5C(ov_id_0A);
    func_02034A5C(ov_id_0B);
    func_02034AC4(ov_id_0D);
    func_02034AC4(ov_id_09);
    func_02157138(p);
    func_02034A5C(ov_id_09);
    func_02034A5C(ov_id_0D);
    func_02034AC4(ov_id_0A);
    func_02034AC4(ov_id_0B);
}
