/*
 * function: MBi_calc_sendblock
 * address:  0x021F2E58
 * packet:   pkt_ov107_021F2E58
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_calc_sendblock (mb_parent.o), TwlSDK/libmb.TWL.HYB.a
 *
 * Advance one multi-boot parent's send block by one when it is already
 * within two of the peer's `b`, otherwise snap `a` to `b`.  124/124 bytes.
 *
 * The whole `e` local of the parked source was the residue: with the
 * element pointer held in a named local, mwcc keeps the element base in
 * r3 and reuses the derived `e+0x1d00` for the else-arm store.  The image
 * keeps the base in ip, derives +0x1d00 into r0 for the guard/if body, and
 * RE-DERIVES `ip + 0x1d00` in the else arm; its else arm is also reached
 * by fall-through from the inner test, so the a/b update is one if/else:
 *
 *     if (y <= x && x <= y + 2) e->a = x + 1; else e->a = y;
 *
 * Spelling the element pointer inline at every use (no local) gives all
 * three at once: `mla ip, r0, r1, r2`, the +0x1d00 re-derivation, and the
 * predicated `strhle` + `bxle lr` whose fall-through lands in the else arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov107_func_021F2E58.c \
 *       --func MBi_calc_sendblock --addr 0x021F2E58 --region ov107 \
 *       --cc dsi/1.1p1 --flags=-O4,p --arm --lang c99 --diff
 *
 * symbols:
 *   g_021F6EEC  0x021F6EEC  data
 *   g_021F6FA0  0x021F6FA0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x1d48];
    u16 a;
    u16 b;
    u16 c;
    u8 pad1[0x1d52 - 0x1d4e];
    u8 flag;
} Ent;

extern int g_021F6EEC;
extern u8 *g_021F6FA0;

void MBi_calc_sendblock(u8 file_id)
{
    if (!(g_021F6EEC & (1 << file_id)))
        return;
    if (((Ent *)(g_021F6FA0 + file_id * 0x5d4))->flag != 0
        && ((Ent *)(g_021F6FA0 + file_id * 0x5d4))->c != 0) {
        u16 x = ((Ent *)(g_021F6FA0 + file_id * 0x5d4))->a;
        u16 y = ((Ent *)(g_021F6FA0 + file_id * 0x5d4))->b;
        if (y <= x && x <= y + 2)
            ((Ent *)(g_021F6FA0 + file_id * 0x5d4))->a = x + 1;
        else
            ((Ent *)(g_021F6FA0 + file_id * 0x5d4))->a = y;
        return;
    }
}
