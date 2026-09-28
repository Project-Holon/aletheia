/*
 * function: func_0216F948
 * address:  0x0216F948
 * packet:   pkt_ov010_0216F948
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * waza_oshie.c: the relearnable move list of a Pokemon. Loads its
 * species/form learnset and returns a 0xFFFF-terminated heap list of
 * the moves learned at or below its level that it neither knows nor
 * already has in the list.
 *
 * DIFF, 144 bytes out, frame 0x38 against 0x40 (2026-09-28 tree_ov010_4).
 * The image keeps eight 4-byte copies of the learnset entry in the frame
 * (0x18 cur, 0x1C/0x2C the known-move pair, 0x20/0x28 the list pair,
 * 0x24 the stored move, 0x30 the level test, 0x34 the terminator test);
 * in each pair the first copy is made once before its loop and the second
 * is re-stored every iteration from registers loaded from the first. 1.1p1
 * folds every `b = a` chain (explicit locals or by-value inlines) into one
 * copy; the pairs are written here as an explicit
 * first copy plus a struct-returning identity inline. Notes: docs/notes/pkt_ov010_0216F948.c.txt.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02172B74     0x02172B74  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Learn { u16 move; u16 level; };

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern void func_0201ADD0(u16 species, u16 form, void *dest);
extern void func_020307B0(void *m);
extern const char d_02172B74[];

static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}

static inline struct Learn Learn_Copy(struct Learn l)
{
    return l;
}

u16 *func_0216F948(void *mon, u32 heap)
{
    u16 moves[4];
    struct Learn t;
    struct Learn e;
    struct Learn f;
    struct Learn c;
    struct Learn a;
    struct Learn cur;
    struct Learn *tbl;
    u16 species;
    u8 form;
    u8 level;
    u16 *out;
    u8 n;
    u8 i;
    u8 j;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    level = func_02017E1C(mon, 0x9E, 0);
    for (j = 0; j < 4; j++)
        moves[j] = func_02017E1C(mon, 0x36 + j, 0);
    n = 0;
    tbl = func_02030734(heap, 0x68, 0, d_02172B74, 0x55);
    out = func_02030734(heap, 0x34, 0, d_02172B74, 0x56);
    func_0201ADD0(species, form, tbl);

    for (i = 0; i < 26; i++) {
        cur = tbl[i];
        t = cur;
        if (Learn_IsEnd(&t)) {
            out[n] = 0xFFFF;
            break;
        }
        e = cur;
        if (e.level > level)
            continue;
        a = cur;
        for (j = 0; j < 4; j++) {
            if (moves[j] == Learn_Copy(a).move)
                break;
        }
        if (j != 4)
            continue;
        c = cur;
        for (j = 0; j < n; j++) {
            if (out[j] == Learn_Copy(c).move)
                break;
        }
        if (j != n)
            continue;
        f = cur;
        out[n] = f.move;
        n++;
    }
    func_020307B0(tbl);
    return out;
}
