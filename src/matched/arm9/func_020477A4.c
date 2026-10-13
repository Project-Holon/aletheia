/*
 * unit:     no
 * function: G3D_SYSTEM_EnableObjectAnime
 * address:  0x020477A4
 * packet:   pkt_02047260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02069E88  0x02069E88  arm
 *
 * Dispatch one slot of the G3D system's object table, reporting whether the
 * slot was occupied.  The empty case is the conditional early return
 * `moveq r0, #0 / popeq {r3, pc}`, so the two exits carry different constants
 * and neither arm is shared.
 *
 * The three `ldr ..., #4` loads interleave two independent chains, the
 * system's own +0x04 -> +0x04 pointer walk and the slot's +0x04 payload;
 * scheduling them together is what puts the slot's load in the middle.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_EnableObjectAnime.c \
 *       --func G3D_SYSTEM_EnableObjectAnime --addr 0x020477A4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct G3dSlot {
    u32   unk_00;
    void *unk_04;
};

struct G3dInner {
    u32   unk_00;
    void *unk_04;
};

struct G3dSys {
    u32               unk_00;
    struct G3dInner  *unk_04;
    struct G3dSlot  **slots;
};

extern void func_02069E88(void *a, void *b);

u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx)
{
    struct G3dSlot *slot = sys->slots[idx];

    if (slot == 0) {
        return 0;
    }

    func_02069E88(sys->unk_04->unk_04, slot->unk_04);
    return 1;
}
