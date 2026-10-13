/*
 * function: MONOLITH_TOOL_LIST_BuildEntryList
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
 * 0..0x2F whose TOWN_MAP_SPOT_Classify kind is not 2, then a closing (0, 1) entry;
 * each entry gets a fresh BMP_Create(0x17, 2, 0x20, 0x61) object, and
 * the count byte follows the three 50-entry arrays (0x24 + 3 * 0xC8 = 0x27C).
 * The slot counter is enum-typed: as an int, mwcc folds n = i + 1 to 1 and
 * drops the loop's entry guard (cmp r4,#0x30; bge), 6 bytes short; see
 * an-enum-type-keeps-values-out-of-constant-folding.md.
 * Byte-offset stores in the closing entry (b + n * 4 + 0x24) kept b + n * 4
 * live across the call instead of n * 4 (6 bytes differ); array indexing
 * gives the original.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   MONOLITH_TOOL_GetSlotIconStates  0x021B6F40  thumb  ov071
 *   BMP_Create  0x02043678  arm
 *   TOWN_MAP_SPOT_Classify  0x0216FE2C  thumb  ov010
 */
#include "../include/Obj04340.h"
#include "../include/Obj20753.h"

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

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *MONOLITH_TOOL_GetSlotIconStates(u8 **p);
struct Bmp;
struct Pos;
struct Rec;
typedef unsigned short u16;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern int TOWN_MAP_SPOT_Classify(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);

void MONOLITH_TOOL_LIST_BuildEntryList(char **a, List *l, char *c)
{
    Idx i = 0;
    int n;
    int r;
    void *pos;

    GAMESYSTEM_GetGameData((const struct Ctx *)(**(char ** *)&((struct Obj04340 *)a)->f0));
    pos = MONOLITH_TOOL_GetSlotIconStates((u8 **)a);
    l->idx[0] = i;
    l->kind[0] = 1;
    l->obj[0] = BMP_Create(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < 0x30; i++) {
        r = TOWN_MAP_SPOT_Classify(((struct Obj20753 *)c)->f34, i, pos, (u8 *)(*a + 0x38));
        if (r != 2) {
            l->idx[n] = i;
            l->kind[n] = r;
            l->obj[n] = BMP_Create(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    l->idx[n] = 0;
    l->kind[n] = 1;
    l->obj[n] = BMP_Create(0x17, 2, 0x20, 0x61);
    l->count = n + 1;
}
