/*
 * function: func_0200BE84
 * address:  0x0200BE84
 * packet:   pkt_0200BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GX_GetBankForLCDC  0x02045A98  arm
 *
 * A 20-entry table of 20-byte records at p+0x10 (not at p: p+0x10..p+0x1A0
 * is exactly 20 * 0x14, and p+0x1A0 is the byte func_0200BF08 of
 * src/matched/unit_0200BF08.c sets).  Insert a copy of *q into the first
 * record whose `f00[8] == 0`, else drop the oldest record and append.
 *
 * The record is `u16 f00[9]; u8 f12;` -- 19 bytes rounded to 20 by its
 * two-byte alignment, which is why `*s = *q;` is a 10-iteration ldrh/strh
 * loop and not a five-word ldm/stm pair: an align-2 aggregate has no
 * four-byte move to use.  `f00[8]` is the free-slot marker and it is what
 * the scan loop tests at [slot+0x10].
 *
 * Declaration order decides the register plan here, and it is not the
 * order the statements run in: with `u16 stamp;` declared before
 * `Slot *s = p->slot;` the same body compiles to the same 130 bytes with a
 * different allocation (p in r5, q in r4, the cursor demoted to the
 * scratch r2, 47 bytes out).  Declaring `s` first makes the cursor's live
 * range start before the GX_GetBankForLCDC call, so it earns a
 * callee-saved register (p -> r6, q -> r5, cursor -> r4) and the whole
 * prologue lines up.  See docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 * GX_GetBankForLCDC takes no arguments and returns the u16 bank mask
 * (src/calib/gx_getbankforlcdc.c); the `blx` is a Thumb -> ARM call, so
 * the symbol is declared `arm`.
 *
 * EXACT*: the listing's extent for 0x0200BE84 runs to 0x0200BFA4 because
 * the seven functions at 0x0200BF08..0x0200BFA4 save no lr and carry no
 * label; the compared range is the 130 bytes of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200BE84.c \
 *       --func func_0200BE84 --addr 0x0200BE84 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 f00[9];
    u8  f12;
} Slot;

typedef struct {
    u8   unk000[0x10];
    Slot slot[20];
} Rec;

extern u16 GX_GetBankForLCDC(void);

void func_0200BE84(Rec *p, Slot *q)
{
    Slot *s = p->slot;
    u16 stamp;
    int i;

    stamp = GX_GetBankForLCDC();

    for (i = 0; i < 8; i++) {
        if (stamp == q->f00[i]) {
            break;
        }
    }
    if (i == 8) {
        return;
    }
    if (q->f12 >= 0x12) {
        return;
    }
    for (i = 0; i < 20; i++, s++) {
        if (s->f00[8] == 0) {
            *s = *q;
            return;
        }
    }
    for (i = 1; i < 20; i++) {
        p->slot[i - 1] = p->slot[i];
    }
    p->slot[19] = *q;
}
