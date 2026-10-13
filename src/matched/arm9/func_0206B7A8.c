/*
 * function: G3D_SBC_RunCallbackSetDone
 * address:  0x0206B7A8
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Same shape as G3D_SBC_RunCountedCallback one slot over: the callback at +0x10 is handed
 * the object itself, then bit 5 of the status word at +0x08 is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SBC_RunCallbackSetDone.c \
 *       --func G3D_SBC_RunCallbackSetDone --addr 0x0206B7A8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct Obj0206B7A8 Obj0206B7A8;
struct Obj0206B7A8 {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    u32   unk0c;
    void (*unk10)(void *);
};

void G3D_SBC_RunCallbackSetDone(Obj0206B7A8 *p)
{
    if (p->unk10 != 0) {
        p->unk10(p);
    }
    p->unk08 |= 0x20;
}
