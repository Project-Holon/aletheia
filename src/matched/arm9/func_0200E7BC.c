/*
 * function: MISC_SAVEDATA_FillMonEntry
 * address:  0x0200E7BC
 * packet:   pkt_0200E7BC
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   MSGDATA_ReadUnits   0x02045F5C  arm
 *   WORDSET_CopyString   0x0201F41C  thumb
 *   gSpeciesNameBank      0x020A7370  data
 *
 * Fill slot idx of the 0x20-byte-stride record array that unit_0200E730's
 * ten accessors read (level in bits 1..7 of +0x1a, a "set" flag in bit 0,
 * the +0x1b byte or 0xff, words at +0 and +0x1c, an 11-u16 name at +4)
 * from a Pokemon via POKE_TOOL_GetPartyValue: fields 0x9e, 0x71/0xa, 0, 7, then the
 * nickname (0x74) when field 0x75 says there is one, else the species name
 * (field 5) read out of the message bank at gSpeciesNameBank into a stack buffer
 * and copied in.
 *
 * Two facts closed the 133-135-byte "pointer permutation" of the earlier
 * notes: the notes' struct had a stray pad byte before +0x1a (every field
 * from the bitfield on was one byte off), and every field is written as
 * o[idx].field rather than through a hoisted record pointer.  Written that
 * way mwcc keeps o and idx*32 in r5/r7 across all nine calls and CSEs
 * o + idx*32 into r4 for most, but not all, of the uses -- the image's
 * `adds r1, r5, r7` before the +0x1c store is exactly that.
 *
 * EXACT* because the listing extent runs over the unlabelled followers at
 * 0x0200E874/0x0200E878 (unit_0200E874.c); compiled bytes match exactly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bits0200E7BC {
    u8 flag : 1;
    u8 level : 7;
};

struct Rec0200E7BC {
    u32 f00;
    u16 name[11];
    struct Bits0200E7BC bits;
    u8  f1b;
    u32 f1c;
};

extern u32  POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 buf);
struct MsgData;
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);
extern void *gSpeciesNameBank;

void MISC_SAVEDATA_FillMonEntry(struct Rec0200E7BC *o, int idx, void *mon)
{
    o[idx].bits.level = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
    if (POKE_TOOL_GetPartyValue(mon, 0x71, 0) != 0)
        o[idx].f1b = POKE_TOOL_GetPartyValue(mon, 0xa, 0);
    else
        o[idx].f1b = 0xff;
    o[idx].f00 = POKE_TOOL_GetPartyValue(mon, 0, 0);
    o[idx].f1c = POKE_TOOL_GetPartyValue(mon, 7, 0);
    if (POKE_TOOL_GetPartyValue(mon, 0x75, 0) != 0) {
        POKE_TOOL_GetPartyValue(mon, 0x74, (u32)o[idx].name);
    } else {
        u16 buf[12];

        MSGDATA_ReadUnits(gSpeciesNameBank, POKE_TOOL_GetPartyValue(mon, 5, 0), buf, 0xb);
        WORDSET_CopyString(buf, o[idx].name, 0xb);
    }
    o[idx].bits.flag = 1;
}
