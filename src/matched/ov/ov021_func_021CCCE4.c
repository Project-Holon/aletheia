/*
 * function: func_021CCCE4
 * address:  0x021CCCE4
 * packet:   pkt_ov021_021CCCE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the party icon sprites for both sides: one per non-empty slot, at x = 0x20 + 0x28 * slot, flagged for the alternate form, into the +0x4C and +0x64 handle arrays.
 *
 * The alternate-form flag is an if/else storing 1 or 0 into pos.alt, not a
 * ternary: the ternary version (114 bytes out) left the second party count in
 * a register and rematerialised &pos; the if/else spills both counts and
 * keeps &pos hoisted in each loop, as the original does.
 *
 * symbols:
 *   d_021DB40C  0x021DB40C  data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
    u16 alt;
    u16 h6;
} IconPos;

typedef struct {
    u8 pad0[4];
    void *party[2];     /* 0x04 */
    u16 hC;             /* 0x0C */
    u8 padE[0x18 - 0xe];
    void *sys;          /* 0x18 */
    u8 pad1C[0x4c - 0x1c];
    void *icon[2][6];   /* 0x4C */
    u8 pad7C[0x98 - 0x7c];
    u16 h98;
    u16 h9A;
    u16 h9C;
} Work;

extern const IconPos d_021DB40C;
struct Obj;
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern u32 func_0202136C(u16 v);
extern void *func_0204B294(void *sys, u16 a, u16 b, u16 c, IconPos *pos, u32 d, u16 heap);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021CCCE4(Work *w)
{
    IconPos pos = d_021DB40C;
    int n0;
    int n1;
    int i;
    u32 species;

    n0 = func_0201AA18(w->party[0]);
    for (i = 0; i < n0; i++) {
        species = func_02017E1C(func_0201AB28(w->party[0], i), 6, 0);
        if (species != 0) {
            if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
            pos.x = i * 0x28 + 0x20;
            w->icon[0][i] = func_0204B294(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
            func_0204B3DC(w->icon[0][i], 0);
        }
    }
    if (w->party[1] != 0) {
        n1 = func_0201AA18(w->party[1]);
        for (i = 0; i < n1; i++) {
            species = func_02017E1C(func_0201AB28(w->party[1], i), 6, 0);
            if (species != 0) {
                if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
                pos.x = i * 0x28 + 0x20;
                w->icon[1][i] = func_0204B294(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
                func_0204B3DC(w->icon[1][i], 0);
            }
        }
    }
}
