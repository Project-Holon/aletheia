/*
 * function: MOVE_POKEMON_FindEntryBySpecies
 * address:  0x0215E804
 * packet:   pkt_0215E804
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MOVE_POKEMON_SAVE_IsEntryActive  0x0200D488  thumb
 *   MOVE_POKEMON_SAVE_GetEntry  0x0200D4AC  thumb
 *   MOVE_POKEMON_SAVE_GetEntryField  0x0200D4B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Blk38;
struct GdsEnt;

extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct Blk38 *p, u32 i);
extern struct GdsEnt *MOVE_POKEMON_SAVE_GetEntry(struct Blk38 *p, u32 i);
extern u32 MOVE_POKEMON_SAVE_GetEntryField(const struct GdsEnt *e, u32 i);

struct GdsEnt *MOVE_POKEMON_FindEntryBySpecies(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    struct GdsEnt *t7;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
loc_0215E80C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = MOVE_POKEMON_SAVE_IsEntryActive((struct Blk38 *)a0, a1);
loc_0215E814:
    if (a0 == 0) goto loc_0215E830;
loc_0215E818:
a0 = t5 + 0;
a1 = t4 + 0;
    t7 = MOVE_POKEMON_SAVE_GetEntry((struct Blk38 *)a0, a1);
loc_0215E820:
a1 = 4;
    a0 = MOVE_POKEMON_SAVE_GetEntryField(t7, a1);
loc_0215E828:
    if (t6 != a0) goto loc_0215E830;
loc_0215E82C:
    return t7;
loc_0215E830:
a0 = t4 + 1;
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
    if ((unsigned)t4 < (unsigned)2) goto loc_0215E80C;
loc_0215E83A:
    return 0;}
