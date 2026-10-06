/*
 * function: func_02017FB0
 * address:  0x02017FB0
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02018438  0x02018438  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02017E64  0x02017E64  thumb
 *   func_02018094  0x02018094  thumb
 *   func_020180FC  0x020180FC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   gLearnBuf      0x02146330  data
 *
 * Reset a record's moves to its level-up set: clear the four move/PP/PP-up
 * slots, load the species/form learnset into the shared buffer at
 * 0x02146330, then teach every entry at or below the current level
 * (func_02018094; 0xFFFF = no free slot, so push it in with func_020180FC).
 * Block-lock sandwich (func_02017DBC / func_02017DE4).  Wave 11, 2026-09-23.
 *
 * Load-bearing: ONE loop variable `i` for both phases (the clearing loop
 * and the learnset walk, re-zeroed in between).  With two variables the
 * zero value argument and the walk index take separate registers and every
 * callee-saved register shifts (docs/idioms: reusing a loop variable
 * across phases); the permuter's hill (800, --types) found only volatile
 * hacks.  The frame's four entry copies and the pointer-taking terminator
 * inline follow func_02018328.c exactly (declaration order e, d, t, cur).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Learn { u16 move; u16 level; };

struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern u32  func_02018438(void *p);
extern void func_0201ADD0(u32 species, int form, void *dest);
extern void func_02017E64(void *p, u32 id, u32 v);
extern u32 func_02018094(void *p, u32 move);
extern void func_020180FC(void *p, u16 move);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern struct Learn gLearnBuf[];

static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}

u32 func_02017FB0(void *p)
{
    u32 flag;
    u16 species;
    u32 form;
    u8 level;
    int i;
    struct Learn e;
    struct Learn d;
    struct Learn t;
    struct Learn cur;

    flag = func_02017DBC(p);
    species = func_02017E88(p, 5, 0);
    form = func_02017E88(p, 0x6f, 0);
    level = func_02018438(p);
    func_0201ADD0(species, (u16)form, gLearnBuf);

    for (i = 0; i < 4; i++) {
        func_02017E64(p, 0x36 + i, 0);
        func_02017E64(p, 0x3a + i, 0);
        func_02017E64(p, 0x3e + i, 0);
    }
    i = 0;
    while (cur = gLearnBuf[i], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (e.level > level)
            break;
        d = cur;
        if (func_02018094(p, d.move) == 0xFFFF)
            func_020180FC(p, d.move);
        i++;
    }
    return func_02017DE4(p, flag);
}
