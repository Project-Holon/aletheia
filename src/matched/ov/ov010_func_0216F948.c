/*
 * function: func_0216F948
 * address:  0x0216F948
 * packet:   pkt_ov010_0216F948
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the list of level-up moves a mon could still learn: reads
 * species/form/level and its 4 current moves, loads the learnset (26
 * {move, level} pairs, 0xFFFF/0xFFFF terminated) with func_0201ADD0, and
 * collects moves at or below its level that it neither knows nor already
 * collected. Returns the 0x34-byte list (caller frees); frees the learnset.
 *
 * pass 2 2026-10-06 P2L52: EXACT (also EXACT with --lang c). Load-bearing:
 *   - Every entry access is a by-value inline helper called on `tbl[j]`
 *     itself (no named entry local). The argument is not a plain local, so
 *     each call keeps its own parameter copy (the 8 stack Ent slots of the
 *     image): CSE makes the shared tbl[j] temp at sp+0x18, loop invariants
 *     make the copies before the k and m loops, and the parameter copies in
 *     the loops keep their stores inside the loop. Named Ent locals or
 *     helpers called on a plain local are copy-propagated or substituted.
 *   - `for` loops everywhere with `n = 0, j = 0` in the j loop (propagation
 *     on: the hoisted zero argument is the copy of i, the m guard is
 *     `cmp n,#0; bls`). A do-while k or m loop hoists the in-loop copy.
 *   - `Ent *tbl` declared first: spill slots species 0x10, form 0xc, tbl 0x14.
 *   - The file name pool word is d_02172B74 (the old header said 02173B74).
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02172B74     0x02172B74  data  ov010 a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 move;
    u16 level;
} Ent;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_02030734(u32 heap, u32 size, u32 flag, const char *file, u32 line);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern void func_020307B0(void *p);
extern char d_02172B74[];

static inline int Ent_IsEnd(Ent x)
{
    return x.move == 0xFFFF && x.level == 0xFFFF;
}

static inline u16 Ent_Level(Ent x)
{
    return x.level;
}

static inline u16 Ent_Move(Ent x)
{
    return x.move;
}

u16 *func_0216F948(void *mon, u32 heap)
{
    Ent *tbl;
    u16 cur[4];
    u16 species;
    u8 form;
    u8 level;
    u8 i;
    u8 n;
    u8 j;
    u8 k;
    u8 m;
    u16 *out;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    level = func_02017E1C(mon, 0x9E, 0);
    for (i = 0; i < 4; i++)
        cur[i] = func_02017E1C(mon, 0x36 + i, 0);
    tbl = (Ent *)func_02030734(heap, 0x68, 0, d_02172B74, 0x55);
    out = (u16 *)func_02030734(heap, 0x34, 0, d_02172B74, 0x56);
    func_0201ADD0(species, form, tbl);
    for (n = 0, j = 0; j < 26; j++) {
        if (Ent_IsEnd(tbl[j])) {
            out[n] = 0xFFFF;
            break;
        }
        if (Ent_Level(tbl[j]) > level)
            continue;
        for (k = 0; k < 4; k++) {
            if (cur[k] == Ent_Move(tbl[j]))
                break;
        }
        if (k != 4)
            continue;
        for (m = 0; m < n; m++) {
            if (out[m] == Ent_Move(tbl[j]))
                break;
        }
        if (m != n)
            continue;
        out[n] = Ent_Move(tbl[j]);
        n++;
    }
    func_020307B0(tbl);
    return out;
}
