/*
 * function: func_02073484
 * address:  0x02073484
 * packet:   pkt_020733E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +001C PC24 func_02089398           -> unresolved: 02089398 (arm, from header) has no witness outside 02073484..020734AC
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   func_02089398    0x02089398  arm
 *
 * Pauses the sequence behind the object when the new value differs from the
 * cached one at +0x2E, then caches it.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02073484.c \
 *       --func func_02073484 --addr 0x02073484 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 unk00[0x2e];
    u8 unk2e;
    u8 unk2f[0x3c - 0x2f];
    u8 unk3c;
} Obj02073484;

extern void func_02089398(u32 player);

void func_02073484(Obj02073484 *p, u8 v)
{
    if (p != 0 && v != p->unk2e) {
        func_02089398(p->unk3c);
        p->unk2e = v;
    }
}
