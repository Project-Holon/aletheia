/*
 * unit:     no
 * function: func_020663D0
 * address:  0x020663D0
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Matrix translate.  With the manager's mode word (+0x04) set, the current
 * slot's tx/ty are bumped in place; otherwise the translate matrix
 * (1, 0, 0, 1, x, y) is concatenated by func_02066754 into the slot of both
 * matrix tables, g_02147D18 and g_02148018.  z accumulates into the u32
 * per-slot table g_02147B98 either way.
 *
 * TWO READINGS closed this after four spellings in
 * docs/notes/pkt_02065D4C.c.txt stalled at 244 bytes:
 *   - 0x02147D28 and 0x02147D2C are NOT separate tables: they are
 *     &g_02147D18[0].tx and &g_02147D18[0].ty.  A field of table[i] with a
 *     run-time i puts the member offset in the relocation addend (register-
 *     offset ldr has no immediate), so the pool words are g_02147D18+0x10 and
 *     g_02147D18+0x14.  Written as .tx/.ty of the Mtx array the pool order
 *     and the load/add/store interleave come out as the image has them.
 *   - Compiler pin ../2.0/sp2 on the "kept constants" tell of
 *     docs/families/cluster_02064B68.h: the image reloads the g_02147B88
 *     pool word after each call and recomputes slot*0x18 for each argument
 *     (add r1 / add r2 from the same sum), with a four-register push.  Under
 *     dsi/1.1p1 the same C is 244 bytes, 134 out, push {r3-r7, lr}; under the
 *     pin it is EXACT on the first compile.
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_02147B98     0x02147B98  data  a4
 *   g_02147D18     0x02147D18  data  a4
 *   g_02148018     0x02148018  data  a4
 *   func_02066754  0x02066754  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           fx32;

typedef struct { fx32 m00, m01, m10, m11, tx, ty; } Mtx;

struct Manager {
    u8  pad_00[4];
    u32 unk_04;
    u8  pad_08[4];
    u32 slot;
};

extern struct Manager g_02147B88;
extern fx32 g_02147B98[];
extern Mtx  g_02147D18[];
extern Mtx  g_02148018[];

extern void func_02066754(const Mtx *a, const Mtx *b, Mtx *out);

void func_020663D0(fx32 x, fx32 y, fx32 z)
{
    Mtx m;

    if (g_02147B88.unk_04 != 0) {
        g_02147D18[g_02147B88.slot].tx += x;
        g_02147D18[g_02147B88.slot].ty += y;
        g_02147B98[g_02147B88.slot] += z;
        return;
    }

    m.m00 = 0x1000;
    m.m01 = 0;
    m.m10 = 0;
    m.m11 = 0x1000;
    m.tx = x;
    m.ty = y;
    func_02066754(&m, &g_02147D18[g_02147B88.slot], &g_02147D18[g_02147B88.slot]);
    func_02066754(&m, &g_02148018[g_02147B88.slot], &g_02148018[g_02147B88.slot]);
    g_02147B98[g_02147B88.slot] += z;
}
