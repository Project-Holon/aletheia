/*
 * function: MSL_C_LIB_SetPrecision
 * address:  0x02096670
 * packet:   pkt_02096670
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * closed:   blocker func_020965B4 is now a manifest entry (matched class)
 *
 * blocker:  +0020 PC24 func_020965B4           -> unresolved: 020965B4 (arm, from header) has no witness outside 02096670..020966B0
 *
 * symbols:
 *   func_020965B4    0x020965B4  arm
 *   MSL_C_LIB_IncrementDigits    0x02096620  arm
 *
 * Clamps the new value against the count byte at +4, records it and, when the
 * worker returns non-negative, propagates it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_SetPrecision.c \
 *       --func MSL_C_LIB_SetPrecision --addr 0x02096670 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 unk00[4];
    u8 unk04;
} Obj02096670;

extern int func_020965B4(u8 *p, int i);
extern void MSL_C_LIB_IncrementDigits(u8 *p, int idx);

void MSL_C_LIB_SetPrecision(Obj02096670 *p, int v)
{
    int r;

    if (v <= 0) {
        return;
    }
    if (v >= p->unk04) {
        return;
    }
    r = func_020965B4((u8 *)p, v);
    p->unk04 = v;
    if (r < 0) {
        return;
    }
    MSL_C_LIB_IncrementDigits((u8 *)p, v);
}
