/*
 * file:     unit_02064D70_p13.c
 * unit:     yes
 * function: func_0206615C, func_02066380, func_020663D0
 * address:  0x0206615C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_02147B98     0x02147B98  data  a4
 *   g_02147D18     0x02147D18  data  a4
 *   g_02148018     0x02148018  data  a4
 *   g_02147C18     0x02147C18  data  a4
 *   g_020A81F8  0x020A81F8  data  a2
 *   - 0x02147D28 / 0x02147D2C are &g_02147D18[0].tx / .ty (member offset in
 *   func_02066754  0x02066754  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            fx32;

typedef struct { fx32 m00, m01, m10, m11, tx, ty; } Mtx;

struct Actor {
    u8  pad_00[0x7c];
    u32 flags;
};

struct Manager_0206615C {
    u16 slotCount;
    u16 slotLimit;
    u32 unk_04;
    struct Actor *obj;
    int slot;
};

struct SlotRec {
    u16 unk_00;
    u16 unk_02;
    u16 state;
    u16 unk_06;
};

typedef struct
{
    u16 count;
    u16 limit;
    int unk_04;
    void *obj;
    int slot;
} Manager_0206615C;

struct Manager_020663D0 {
    u8  pad_00[4];
    u32 unk_04;
    u8  pad_08[4];
    u32 slot;
};

extern void func_02066754(const Mtx *a, const Mtx *b, Mtx *out);
void func_0206615C(void);
void func_02066380(int n);
void func_020663D0(fx32 x, fx32 y, fx32 z);
extern struct Manager_0206615C g_02147B88;
extern fx32 g_02147B98[];
extern Mtx  g_02147D18[];
extern Mtx  g_02148018[];
extern struct SlotRec g_02147C18[];
extern u16 g_020A81F8;



static inline void CopySlot(int next)
{
    if (g_02147B88.unk_04 != 0) {
        int cur = ((volatile struct Manager_0206615C *)&g_02147B88)->slot;
        g_02147D18[next].tx = g_02147D18[cur].tx;
        g_02147D18[next].ty = g_02147D18[cur].ty;
        g_02147B98[next] = g_02147B98[cur];
    } else {
        int cur = ((volatile struct Manager_0206615C *)&g_02147B88)->slot;
        g_02147D18[next] = g_02147D18[cur];
        g_02148018[next] = g_02148018[cur];
        g_02147B98[next] = g_02147B98[cur];
    }
    g_02147B88.slot = next;
}



/*
 * The matrix-slot PUSH, the counterpart of src/matched/func_02066380.c.
 * The slot index g_02147B88.slot (+0x0c) is advanced if it stays below 0x20,
 * copying the current slot of every per-slot table into the next one: in
 * the translate-only mode (g_02147B88.unk_04 != 0) just tx/ty of g_02147D18
 * plus the u32 in g_02147B98; otherwise the whole 0x18-byte matrix of
 * g_02147D18 and g_02148018 plus g_02147B98.  Unless the live actor's +0x7c
 * bit 0 is set, the 8-byte slot record g_02147C18[(u16)slot] is then
 * copied from the old slot to the (possibly unchanged) current one with its
 * state promoted 1 -> 2.  r0 is never read (every caller passes the flag
 * word it tested), so the parameter is kept, unused.
 *
 * Levers, all needed:
 *   - Compiler pin ../2.0/sp2 ("kept constants": the image reloads the
 *     g_02147B88 pool word in each arm and after the store); 1.1p1 is 524
 *     bytes against 548, 381 out.
 *   - 0x02147D28 / 0x02147D2C are &g_02147D18[0].tx / .ty (member offset in
 *     the relocation addend), and 0x02147C1C is &g_02147C18[0].state, the
 *     same reading for the state reload of the promote step.
 *   - The flag test is written `(flags & 1) == 0` first: the image falls
 *     through into the long arm.
 *   - The copy helper re-reads the slot through a volatile cast in each
 *     arm (the image reloads it after the unk_04 test; plain, 394 out).
 *   - Copy order is tx, ty, g_02147B98 in the translate arm and g_02147D18,
 *     g_02148018, g_02147B98 in the full arm; the other eight orders of the
 *     two arms measured 30..118 out.
 *   - The promote is an if/else that stores in both arms (strheq/strhne);
 *     the ternary costs a second pool word.
 */
void func_0206615C(void)
{
    if ((g_02147B88.obj->flags & 1) == 0) {
        int cur = g_02147B88.slot;
        u16 old = cur;
        int next = cur + 1;
        int r = !(next >= 0x20);
        u16 nw;

        if (r != 0)
            CopySlot(next);

        nw = g_02147B88.slot;
        g_02147C18[nw] = g_02147C18[old];
        if (g_02147C18[old].state == 1)
            g_02147C18[nw].state = 2;
        else
            g_02147C18[nw].state = g_02147C18[old].state;
    } else {
        int next = g_02147B88.slot + 1;
        int r = !(next >= 0x20);
        if (r == 0)
            return;
        CopySlot(next);
    }
}



/*
 * The matrix-slot POP, the counterpart of func_0206615C.  Returns at once
 * when the slot index g_02147B88.slot (+0x0c) is already 0; otherwise
 * decrements it and, if the "first modified slot" halfword g_020A81F8 now
 * lies above the new index, resets it to the 0xFFFE sentinel.  Every
 * caller passes 1 in r0 (func_020659D4, func_02065878, func_02066080) and
 * the body never reads it, so the parameter is kept, unused.
 *
 * TWO LEVERS, both needed (EXACT under dsi/1.1p1 and equally under
 * ../2.0/sp2; the default is kept):
 *   1. The guard's MATERIALISED boolean (`movle r0, #1` / `movgt r0, #0` /
 *      `cmp r0, #0` / `bxne lr`) is `int r = !(g_02147B88.slot > 0);`.
 *      Every spelling of `slot <= 0` (plain, named local, inline helper,
 *      if/else, ternary) folds to a predicated body 24 bytes short, which is
 *      why the earlier drafts in docs/notes/pkt_02065D4C.c.txt and
 *      docs/notes/pkt_02065020.c.txt needed a fake `u16 *` return.  Same
 *      lever as src/matched/func_02065878.c's `!(x == -1)`.
 *   2. The image loads g_020A81F8 BETWEEN the slot load and the subtract
 *      (`ldr r3, [r1, #0xc]` / `ldrh r2, [r0]` / `sub` / `str` / `cmp r2,
 *      r3`).  Without volatile both compilers sink the ldrh below the store
 *      (14 bytes out, immovable by permuter hill 80 and anneal 1200).  The
 *      read-modify-write through `(volatile Manager *)` with the halfword
 *      read through `*(volatile u16 *)` between them pins the order.
 */
void func_02066380(int n)
{
    int r = !(g_02147B88.slot > 0);
    if (r != 0)
        return;
    {
    int s = ((volatile Manager_0206615C *)&g_02147B88)->slot - 1;
    u16 c = (*(volatile u16 *)&g_020A81F8);
    ((volatile Manager_0206615C *)&g_02147B88)->slot = s;
    if (c > s)
        g_020A81F8 = 0xFFFE;
    }
}


/*
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
 */
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
