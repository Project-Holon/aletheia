/*
 * function: func_021C9F58
 * address:  0x021C9F58
 * packet:   pkt_021C9F58
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_021C9F58   0x021C9F58  arm
 *   func_021BD41C   0x021BD41C  arm  ov016
 *   dat_021DA6C8   0x021DA6C8  data
 *   dat_021DA694   0x021DA694  data
 *   dat_021DA696   0x021DA696  data
 *   dat_021DA698   0x021DA698  data
 *   dat_021DE5EC   0x021DE5EC  data
 *
 * PARKED: 93 bytes differ; the structure is solved, the residue is the
 * else-branch base and register naming.  Right: the 0x18 frame with the 0xe
 * byte table copied to sp+8 by the byte-pair loop, `int v` (which is what buys
 * the signed `blt` of the image -- an `unsigned char v` compiles to `blo`),
 * and the three-or-more branch, which loads its three 0x021DA694/696/698 pool
 * words and indexes them with a single `lsl #3` exactly as the image does.
 * Wrong: MWCC materialises the 0x021DA694 base once per access in the
 * else-branch (four pool words instead of the image's one, then
 * `add ip, r2, lr, lsl #3` plus immediate offsets 0/2/4/6), and it uses r2/r4
 * where the image uses lr/ip, so the whole body shifts.  The keys that got it
 * this far are worth reusing: the two stack objects must be members of ONE
 * address-taken local struct (`struct { u16 tmp[4]; T14 buf; }`) or MWCC
 * scalarises tmp into registers and the strh/ldrh pair never appears; the
 * halfword tables must be `struct { u16 h[4]; }` arrays so the index scales by
 * 8 in one shift; and a local `Q *q` for the base is WORSE (it lives across
 * the call, goes in r4 and rewrites the prologue: 212 bytes, 120 diffs).
 *
 * Copy a 0xe-byte byte table into a stack buffer, index it with the byte at
 * 0x021DE5EC+0 and dispatch: three or more selects three halfwords out of
 * the 0x021DA694 halfword table through func_021BD41C(3, ...), otherwise it
 * builds the same four halfwords locally (the second one shifted by
 * 0x1d * 0x021DE5EC[2]) and passes them through func_021BD41C(1, ...).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C9F58.c \
 *       --func func_021C9F58 --addr 0x021C9F58 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u16 h[4]; } Q;
typedef struct { u8 b[0xe]; } T14;
typedef struct { u16 tmp[4]; T14 buf; } Frame;

extern void func_021BD41C(int, int, int, int);
extern T14 dat_021DA6C8;
extern Q dat_021DA694[];
extern Q dat_021DA696[];
extern Q dat_021DA698[];
extern u8 dat_021DE5EC[];

void func_021C9F58(void)
{
    Frame fr;
    int v;

    fr.buf = dat_021DA6C8;
    v = ((u8 *)&fr.buf)[dat_021DE5EC[0]];
    if (v >= 3) {
        func_021BD41C(3, dat_021DA694[v].h[0], dat_021DA698[v].h[0], dat_021DA696[v].h[0]);
    } else {
        fr.tmp[0] = dat_021DA694[v].h[0];
        fr.tmp[1] = dat_021DA694[v].h[1] + (u16)(0x1d * dat_021DE5EC[2]);
        fr.tmp[2] = dat_021DA694[v].h[2];
        fr.tmp[3] = dat_021DA694[v].h[3];
        func_021BD41C(1, fr.tmp[0], fr.tmp[2], fr.tmp[1]);
    }
}
