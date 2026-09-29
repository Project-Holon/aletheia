/*
 * function: func_021C4340
 * address:  0x021C4340
 * packet:   pkt_ov021_021C4340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Builds the day-care egg/offspring Pokemon from the 0x8C-byte work
 * record q (the struct func_021C38F4 fills on its stack). Every concrete
 * byte is right; the one wildcard is the bl to func_02018198 (no witness
 * outside this range).
 *
 * BLOCKER (arm9 leaf, Ilias's): 0x02018198 is an unlabelled Thumb
 * tail-call stub (00 4b 18 47, .word 0x020181A1) inside the extent of the
 * labelled arm9 func_020180FC (EXACT*). Verified EXACT at 0x02018198
 * (arm9, --thumb, no --region) with:
 *     extern void func_020181A0(void *mon);
 *     void func_02018198(void *mon) { func_020181A0(mon); }
 * Once it is filed with a shard, this file resolves as `matched`.
 *
 * Load-bearing: const S *q (the species/level loads rise above the zero
 * stack-argument stores), and heap u16 at both callees (func_02008510,
 * func_0202F190) so it is re-read from its stack slot per call.
 * symbols:
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02008510  0x02008510  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   func_02018198  0x02018198  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201B9F0  0x0201B9F0  thumb
 *   g_020A7370     0x020A7370  data
 *   d_021DA948     0x021DA948  data  ov021  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct { u32 v[6]; } T6;
typedef struct {
    u32 species;
    u32 form;
    u32 level;
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 iv[6];
    u32 f30;
    u32 f34;
    u32 f38;
    u32 mv[4];
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 a[6];
    u32 b[6];
    u32 n;
} S;

extern void func_02017588(void *mon, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern void func_02018A00(void *mon, u32 species, u32 form);
extern u32 func_02008510(void *my, u16 heap);
extern void func_02045808(u32 buf);
extern u32 func_02045EC0(void *bank, u32 index);
extern void func_0202F190(void *mon, u32 a1, void *a2, u32 a3, u16 heap);
extern void func_02018198(void *mon);
extern void func_020185C4(void *mon);
extern void func_0201B9F0(void *mon);
extern void *g_020A7370;
extern const T6 d_021DA948;

void func_021C4340(void *mon, const S *q, void *my, u32 y, u16 heap)
{
    T6 t = d_021DA948;
    int i;
    u32 s;

    func_02017588(mon, q->species, q->level, q->f30, -1, q->f34);
    func_02017E40(mon, 0x6f, q->form);
    func_02017E40(mon, 0x70, q->f0C);
    func_02017E40(mon, 9, q->f14);
    if (q->f4C == 2)
        func_02018A00(mon, q->species, q->form);
    else
        func_02017E40(mon, 0xb2, q->f10);
    for (i = 0; i < 6; i++) {
        if (q->a[i] != 0 || q->b[i] != 0)
            func_02017E40(mon, t.v[i], q->iv[i]);
    }
    func_02017E40(mon, 0x36, q->mv[0]);
    func_02017E40(mon, 0x37, q->mv[1]);
    func_02017E40(mon, 0x38, q->mv[2]);
    func_02017E40(mon, 0x39, q->mv[3]);
    s = func_02008510(my, heap);
    func_02017E40(mon, 0x8d, s);
    func_02045808(s);
    s = func_02045EC0(g_020A7370, 0x28a);
    func_02017E40(mon, 0x73, s);
    func_02045808(s);
    func_0202F190(mon, 5, my, y, heap);
    func_02017E40(mon, 0x4c, 1);
    func_02018198(mon);
    func_020185C4(mon);
    func_0201B9F0(mon);
}
