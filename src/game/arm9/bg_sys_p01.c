/*
 * file:     bg_sys_p01.c
 * unit:     yes
 * function: func_0203EF5C, func_0203EFC8, func_0203F004, func_0203F028, func_0203F034
 * address:  0x0203EF5C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469F8     0x021469F8  data
 *   g_020A7E4C     0x020A7E4C  data
 *   sub_02030734   0x02030734  arm
 *   func_020819B8  0x020819B8  arm
 */
struct MATHCRC16Table;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Mt {
    u32 mt[624];
    s32 index;
    u32 unk_9c4;
    u32 unk_9c8;
    u8  unk_9cc[0x200];
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void func_020819B8(struct MATHCRC16Table *table, u16 poly);
void func_0203EF5C(u32 heapId);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
u32 func_0203F004(const u8 *s);
extern struct Mt *g_021469F8;
extern char g_020A7E4C[];
extern int STD_CompareString(const char *s1, const char *s2);
int func_0203F028(const char *s1, const char *s2);
void func_0203F034(u32 seed);


/*
 * TU: gf_standard.c.  The allocation site string at 0x020A7E4C reads
 * "gf_standard.c" and this is its only reference in the image, so the
 * Mersenne Twister block (0x0203EF5C onwards) is that translation unit;
 * bg_sys.c starts further down at 0x0203F8F4, whose site string is the
 * "bg_sys.c" at 0x020A7E5C.
 *
 * Constructor for the random-number state: 0xbcc bytes holding mt[624], the
 * generator index (set to 625, "exhausted"), a spare word and the constant
 * 0x9908b0df, then a 0x200-byte buffer at +0x9cc that func_020819B8
 * initialises.  The allocation tag 49 stays live in r5 afterwards and both
 * later constants are derived from it with a single `add`, which is why
 * neither 625 nor 4129 costs a pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203EF5C.c \
 *       --func func_0203EF5C --addr 0x0203EF5C --cc 1.1p1 --arm
 */
void func_0203EF5C(u32 heapId)
{
    g_021469F8 = sub_02030734(heapId, 0xbcc, 0, g_020A7E4C, 49);
    g_021469F8->index = 625;
    g_021469F8->unk_9c4 = 0;
    g_021469F8->unk_9c8 = 0x9908b0df;
    func_020819B8((struct MATHCRC16Table *)g_021469F8->unk_9cc, 4129);
}


/*
 * memcmp over unsigned bytes.  The count is tested and decremented in one
 * expression (`n-- != 0`), which is what puts the `sub r2, r2, #1` between
 * the `cmp` and the branch at the head and again in the loop's tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203EFC8.c \
 *       --func func_0203EFC8 --addr 0x0203EFC8 --cc 1.1p1 --arm
 */
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n)
{
    while (n-- != 0) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return 0;
}


/*
 * Byte-counting strlen over an unsigned char string.  The loop is written
 * as an unconditional one with the test and the return inside it, which is
 * why the original has a plain `b` back to the head and a dead `bx lr`
 * after it for the path that falls off the end.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203F034 because the
 * follower at 0x0203F028 has no label.  It is a twelve-byte ARM long-branch
 * veneer (ldr ip, [pc]; bx ip; .word 0x0208CD94), not a byte difference,
 * and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F004.c \
 *       --func func_0203F004 --addr 0x0203F004 --cc 1.1p1 --arm
 */
u32 func_0203F004(const u8 *s)
{
    u32 n = 0;

    while (1) {
        if (*s == 0) {
            return n;
        }
        s++;
        n++;
    }
}


int func_0203F028(const char *s1, const char *s2)
{
    return STD_CompareString(s1, s2);
}


/*
 * Mersenne Twister (MT19937) seeding: 624 words at offset 0 of the block
 * behind 0x021469F8, with the generator index at +0x9c0.  Every step
 * re-reads both the global pointer and the index out of memory, so the
 * index is a real field and not a local; the multiply-accumulate is one
 * `mla` because the index is the addend.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F034.c \
 *       --func func_0203F034 --addr 0x0203F034 --cc 1.1p1 --arm
 */
void func_0203F034(u32 seed)
{
    g_021469F8->mt[0] = seed;
    for (g_021469F8->index = 1; g_021469F8->index < 624;
         g_021469F8->index++) {
        u32 prev = g_021469F8->mt[g_021469F8->index - 1];

        g_021469F8->mt[g_021469F8->index] =
            (prev ^ (prev >> 30)) * 0x6c078965 + g_021469F8->index;
    }
}
