/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007774
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BOX_SAVEDATA_CountFreeSlots, BOX_SAVEDATA_CountFreeSlotsInBox, BOX_SAVEDATA_SetCurrentBox, BOX_SAVEDATA_GetWallpaper,
 *           BOX_SAVEDATA_SetWallpaper
 *
 * symbols:
 *   sub_020077B8_File  0x020A7068  data
 *   BOX_SAVEDATA_GetHeader       0x020074CC  thumb
 *   BOX_SAVEDATA_GetBoxPokemon       0x02007AF4  thumb
 *   POKE_TOOL_GetBoxValue       0x02017E88  thumb
 *   func_02034714      0x02034714  arm
 *
 * Counting the occupied entries of every box and of one box, the box
 * cursor's setter, and the getter and setter for the per-box byte at
 * 0x3C4.  POKE_TOOL_GetBoxValue is the "is this entry empty" test, asked with the
 * field id 0xA9 throughout.
 *
 * BOX_SAVEDATA_CountFreeSlots spills its outer loop counter to the stack even though it is
 * an ordinary `int`: r4 through r7 are already carrying the inner counter,
 * the running total, the entry base and the constant 0x88, and the save
 * handle is on the stack too.  The spill is register pressure and not a
 * pointer in the source.
 *
 * The failure path of BOX_SAVEDATA_CountFreeSlotsInBox passes the same pointer as the first and
 * the third argument of func_02034714, which is the shape of an assertion
 * helper taking a file name twice.  The address is declared in the
 * `symbols:` block rather than written as `__FILE__`; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sub02007774Entry {
    u8 data[0x88];
};

struct Sub02007774Header {
    u32 unk00;
    u8  pad04[0x3C4 - 4];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern const char sub_020077B8_File[];

struct Sub02007454Header;
struct Sub02007AC8Entry;
extern struct Sub02007454Header *BOX_SAVEDATA_GetHeader(void **save);
extern struct Sub02007AC8Entry *BOX_SAVEDATA_GetBoxPokemon(void **save, u32 box);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void func_02034714(const char *expr, u32 line, const char *file);

int BOX_SAVEDATA_CountFreeSlots(void *save)
{
    int box;
    int slot;
    int n = 0;

    for (box = 0; box < 0x18; box++) {
        struct Sub02007774Entry *base = (struct Sub02007774Entry *)BOX_SAVEDATA_GetBoxPokemon(save, box);

        for (slot = 0; slot < 30; slot++) {
            if (POKE_TOOL_GetBoxValue(&base[slot], 0xA9, 0) == 0) {
                n++;
            }
        }
    }
    return n;
}

int BOX_SAVEDATA_CountFreeSlotsInBox(void *save, u32 box)
{
    struct Sub02007774Header *h = (struct Sub02007774Header *)BOX_SAVEDATA_GetHeader(save);
    struct Sub02007774Entry *base;
    int slot;
    int n;

    if (box == -1) {
        box = h->unk00;
    }
    if (box >= 0x18) {
        func_02034714(sub_020077B8_File, 0, sub_020077B8_File);
    }
    n = 0;
    base = (struct Sub02007774Entry *)BOX_SAVEDATA_GetBoxPokemon(save, box);
    for (slot = 0; slot < 30; slot++) {
        if (POKE_TOOL_GetBoxValue(&base[slot], 0xA9, 0) == 0) {
            n++;
        }
    }
    return n;
}

void BOX_SAVEDATA_SetCurrentBox(void *save, u32 box)
{
    struct Sub02007774Header *h = (struct Sub02007774Header *)BOX_SAVEDATA_GetHeader(save);

    if (box < 0x18) {
        h->unk00 = box;
    }
}

u8 BOX_SAVEDATA_GetWallpaper(void *save, u32 box)
{
    struct Sub02007774Header *h = (struct Sub02007774Header *)BOX_SAVEDATA_GetHeader(save);

    if (box < 0x18) {
        return h->unk3C4[box];
    }
    return 0;
}

void BOX_SAVEDATA_SetWallpaper(void *save, u32 box, u8 v)
{
    struct Sub02007774Header *h = (struct Sub02007774Header *)BOX_SAVEDATA_GetHeader(save);

    if (box == -1) {
        box = h->unk00;
    }
    if (box < 0x18) {
        h->unk3C4[box] = v;
    }
}
