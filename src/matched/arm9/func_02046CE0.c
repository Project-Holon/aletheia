/*
 * function: func_02046CE0
 * address:  0x02046CE0
 * packet:   pkt_02046CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Classify a 4-byte archive/container tag and record the result.
 *
 * `out` is a three-field record: a u16 at +00 (constant 0x48BF), a u16
 * result code at +02, and the tag pointer itself at +04.  The tag is one
 * of the little-endian ASCII magics; the five audio-ish containers
 * (BVA0/BMA0/BCA0/BTA0/BTP0) all report 4, BMD0 reports 1 or 2 depending
 * on func_0206E964, BTX0 reports 3, anything else 0.
 *
 * Shape notes:
 *  - The case bodies are laid out in *source* order, not value order.  The
 *    comparison tree is value-ordered either way, but writing BMD0 first,
 *    BTX0 second, then the five 4-reporting cases puts the BMD0 arm at
 *    +0x80 and the shared `result = 4` arm at +0xA8, which is what the
 *    original does; the natural ascending order puts the 4-arm right after
 *    the tree and moves all four branch targets.
 *  - The five 4-reporting cases share one store because the arms are
 *    identical; only the value in r0 differs.
 *  - BMD0's two stores are the if/else written out (`= 2` in one arm,
 *    `= 1` in the other), which mwcc predicates rather than folds into a
 *    select.
 *
 * symbols:
 *   func_0206E964      0x0206E964  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046CE0.c \
 *       --func func_02046CE0 --addr 0x02046CE0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct S02046CE0 {
    u16 unk00;
    u16 result;
    u32 *tag;
};

extern unsigned char *func_0206E964(unsigned char *p);

void func_02046CE0(struct S02046CE0 *out, u32 *tag)
{
    switch (*tag) {
    case 0x30444D42:
        if (func_0206E964((unsigned char *)tag) == 0) {
            out->result = 2;
        } else {
            out->result = 1;
        }
        break;
    case 0x30585442:
        out->result = 3;
        break;
    case 0x30415642:
    case 0x30414D42:
    case 0x30414342:
    case 0x30415442:
    case 0x30505442:
        out->result = 4;
        break;
    default:
        out->result = 0;
        break;
    }
    out->tag = tag;
    out->unk00 = 0x48BF;
}
