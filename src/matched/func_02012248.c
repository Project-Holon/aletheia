/*
 * function: func_02012248
 * address:  0x02012248
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012220  0x02012220  thumb
 *   func_02035138  0x02035138  arm
 *
 * Promoted from src/pending/func_02012248.c.  The C never changed; the ISA
 * on the second symbols line did.  The tail call goes through the pool word
 * 0x02035138, i.e. an ARM target with no Thumb bit - the parked copy
 * declared it `thumb`, so the word match.py looked for was 0x02035139 and
 * the second pool holding 0x02035138 (at 0x02012260, in the next function,
 * outside this range) could not be seen.  Declared `arm`, the `literal`
 * class resolves the site and the entry is EXACT.  A `bx r3` tail call
 * always has a pool word, and the pool word's low bit is the only place the
 * callee's ISA shows up - a wrong declaration hides the witness silently.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012248.c \
 *       --func func_02012248 --addr 0x02012248 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct IcaAnime;

extern void func_02012220(struct IcaAnime *p);
extern void func_02035138(void *fn, u32 arg);

void func_02012248(struct IcaAnime *p)
{
    func_02035138((void *)func_02012220, (u32)p);
}
