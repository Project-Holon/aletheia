/*
 * function: func_021B9970
 * address:  0x021B9970
 * packet:   pkt_ov071_021B9970
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a list at l: entry 0 is (idx 0, kind 1), then one entry per slot
 * 0..0x2F whose func_0216FE2C kind is not 2, then a closing (0, 1) entry;
 * each entry gets a fresh func_02043678(0x17, 2, 0x20, 0x61) object, and
 * the count byte follows the three 50-entry arrays (0x24 + 3 * 0xC8 = 0x27C).
 * The slot counter is enum-typed: as an int, mwcc folds n = i + 1 to 1 and
 * drops the loop's entry guard (cmp r4,#0x30; bge), 6 bytes short; see
 * an-enum-type-keeps-values-out-of-constant-folding.md.
 * Byte-offset stores in the closing entry (b + n * 4 + 0x24) kept b + n * 4
 * live across the call instead of n * 4 (6 bytes differ); array indexing
 * gives the original.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_02043678  0x02043678  arm
 *   func_0216FE2C  0x0216FE2C  thumb  ov010
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef enum { IDX_FIRST } Idx;

typedef struct {
    u8 pad00[0x24];
    void *obj[50];
    int idx[50];
    int kind[50];
    u8 count;
} List;

extern void func_020120F4(void *a);
extern void *func_021B6F40(void *a);
extern void *func_02043678(u32 a, u32 b, u32 c, u32 d);
extern int func_0216FE2C(void *tbl, int idx, void *pos, u8 *flags);

void func_021B9970(char **a, List *l, char *c)
{
    Idx i = 0;
    int n;
    int r;
    void *pos;

    func_020120F4(**(char ***)a);
    pos = func_021B6F40(a);
    l->idx[0] = i;
    l->kind[0] = 1;
    l->obj[0] = func_02043678(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < 0x30; i++) {
        r = func_0216FE2C(*(void **)(c + 0x34), i, pos, (u8 *)(*a + 0x38));
        if (r != 2) {
            l->idx[n] = i;
            l->kind[n] = r;
            l->obj[n] = func_02043678(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    l->idx[n] = 0;
    l->kind[n] = 1;
    l->obj[n] = func_02043678(0x17, 2, 0x20, 0x61);
    l->count = n + 1;
}
