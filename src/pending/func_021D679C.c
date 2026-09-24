/*
 * function: func_021D679C
 * address:  0x021D679C
 * packet:   pkt_021D679C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021E7710   0x021E7710  thumb
 *   func_021E8AA0   0x021E8AA0  thumb
 *   func_021E8A80   0x021E8A80  thumb
 *   func_021E8A90   0x021E8A90  thumb
 *   func_021E64C8   0x021E64C8  thumb
 *   func_021E8AA8   0x021E8AA8  thumb
 *
 * Reads back the +0x38 stream: asks 0x021E8A80 whether more data is
 *     pending and 0x021E8A90 whether the last read produced a byte, and
 *     returns the +0x3c word only in that case, else the 0xFFFF sentinel.
 */

typedef unsigned long u32;

extern void func_021E8A80(u32 h);
extern int func_021E8A90(u32 h);

u32 func_021D679C(char *obj)
{
    func_021E8A80(*(u32 *)(obj + 0x38));
    if (func_021E8A90(*(u32 *)(obj + 0x38)) != 0)
        return *(u32 *)(obj + 0x3c);
    return 0xFFFF;
}

/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * The second call, at +0x0C, targets 0x021E8A90.  That address carries no
 * func_/sub_ label in ANY listing -- ov093 has a bare `bx lr` there and
 * ov177 has plain .word data -- so no class can attest it: four call
 * sites image-wide (ov175 x2, ov176 x3) are not enough without a traced
 * entry point.  Bytes are exact; only the relocation is unwitnessed.
 */
