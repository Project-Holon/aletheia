/*
 * unit:     no
 * function: func_0206615C
 * address:  0x0206615C
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_02147B98     0x02147B98  data  a4
 *   g_02147D18     0x02147D18  data  a4
 *   g_02148018     0x02148018  data  a4
 *   g_02147C18     0x02147C18  data  a4
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

struct Manager {
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

extern struct Manager g_02147B88;
extern fx32 g_02147B98[];
extern Mtx  g_02147D18[];
extern Mtx  g_02148018[];
extern struct SlotRec g_02147C18[];

static inline void CopySlot(int next)
{
    if (g_02147B88.unk_04 != 0) {
        int cur = ((volatile struct Manager *)&g_02147B88)->slot;
        g_02147D18[next].tx = g_02147D18[cur].tx;
        g_02147D18[next].ty = g_02147D18[cur].ty;
        g_02147B98[next] = g_02147B98[cur];
    } else {
        int cur = ((volatile struct Manager *)&g_02147B88)->slot;
        g_02147D18[next] = g_02147D18[cur];
        g_02148018[next] = g_02148018[cur];
        g_02147B98[next] = g_02147B98[cur];
    }
    g_02147B88.slot = next;
}

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
