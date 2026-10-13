/*
 * unit:     yes
 * address:  0x02019ABC
 * packet:   pkt_02019ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02019ABC
 *
 * "Is the name in substruct C still the species' default name": it renders the
 * species name for substruct A's species id into the shared 0x20 halfword
 * buffer at 0x021462F0 and compares it with substruct C's own name, returning
 * 1 when they are equal.  POKE_TOOL_SetBoxValueRaw (src/matched/POKE_TOOL_SetBoxValueRaw.c) calls it
 * from ids 0x73 and 0x74 and stores the result in substruct B +0x10 bit 31,
 * which is the bit POKE_TOOL_GetBoxValueRaw reads back as id 0x75.  Those two calls are
 * the only references to this address in the image.
 *
 * The result local is declared before the two substruct fetches, which is what
 * puts `movs r5, #0` in front of the first call rather than after the second.
 *
 * The message bank at 0x020A7370 is a global pointer, so its address is a
 * build property and has to be re-derived for a White build rather than
 * copied; the 0x20 is a halfword count and the species id is data, so nothing
 * else here is version specific.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019ABC.c \
 *       --addr 0x02019ABC --thumb
 *
 * symbols:
 *   gSpeciesNameBank   0x020A7370  data
 *   gNameBuf   0x021462F0  data
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Mon {
    u32 unk00;
};

struct BlockA {
    u16 species;
};

extern void *func_02019C38(struct Mon *p, u32 pid, u32 n);
struct MsgData;
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_0201F448(const u16 *a, const u16 *b);

extern void *gSpeciesNameBank;
extern u16   gNameBuf[];

u32 func_02019ABC(struct Mon *p)
{
    u32 r = 0;
    struct BlockA *a = (struct BlockA *)func_02019C38(p, p->unk00, 0);
    void *c = func_02019C38(p, p->unk00, 2);

    MSGDATA_ReadUnits(gSpeciesNameBank, a->species, gNameBuf, 0x20);
    if (func_0201F448(gNameBuf, c) == 0) {
        r = 1;
    }
    return r;
}
