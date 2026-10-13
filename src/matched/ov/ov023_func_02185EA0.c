/*
 * function: OEKAKI_UpdateRemoteCursors
 * address:  0x02185EA0
 * packet:   pkt_ov023_02185EA0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   UNION_APP_GetMemberEntry  0x02184180  thumb  ov022
 *   OEKAKI_SetCursorPosition  0x0218506C  thumb  ov023
 *
 * The 6-byte records at +0x4212 are reached through a byte cast of a struct
 * pointer at every use (E below): the base is hoisted into r6 and the
 * element address is recomputed (muls) at each use. A local `e`, or a
 * `char *` parameter with the same cast, CSEs the element pointer instead.
 */

struct e6 {
    unsigned char b[4];
    unsigned char c : 3;
    unsigned char n : 3;
    unsigned char d : 2;
    unsigned char pad;
};

struct P {
    char pad0[4];
    int *unk4;
    char pad1[0x60 - 8];
    int unk60[5];
};

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void OEKAKI_SetCursorPosition(void *actor, int x, int y);

#define E(p) ((struct e6 *)((char *)(p) + 0x4212))

void OEKAKI_UpdateRemoteCursors(struct P *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (i == GFL_NET_SYSTEM_GetCurrentAid())
            continue;
        if (E(p)[i].n != 0 && UNION_APP_GetMemberEntry((unsigned char *)(*p->unk4), (unsigned char)i) != 0) {
            func_0204B3DC((struct Obj *)p->unk60[i], 1);
            OEKAKI_SetCursorPosition((void *)p->unk60[i], E(p)[i].b[E(p)[i].n - 1], E(p)[i].b[E(p)[i].n + 1]);
        } else {
            func_0204B3DC((struct Obj *)p->unk60[i], 0);
        }
    }
}
