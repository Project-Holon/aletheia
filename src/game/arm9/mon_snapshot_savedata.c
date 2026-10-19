/*
 * file:     mon_snapshot_savedata.c
 * unit:     yes
 * function: MON_SNAPSHOT_GetSize, MON_SNAPSHOT_Clear, MON_SNAPSHOT_IsFilled, MON_SNAPSHOT_GetLevel, MON_SNAPSHOT_HasAbility, MON_SNAPSHOT_GetAbility, MON_SNAPSHOT_GetSpeciesForSlot, MON_SNAPSHOT_GetPersonalRnd, MON_SNAPSHOT_GetNickname, MON_SNAPSHOT_GetOtId, MON_SNAPSHOT_Fill
 * address:  0x0200E730
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata_2.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   MSGDATA_ReadUnits   0x02045F5C  arm
 *   WORDSET_CopyString   0x0201F41C  thumb
 *   gSpeciesNameBank      0x020A7370  data
 */
#include "misc_savedata_shared_types.h"

struct MsgData;

/* The byte at +0x1a of a BoxMonSlot: bit 0 is a set flag, bits 1..7 a level. */
struct LevelFlagBits {
    u8 flag : 1;
    u8 level : 7;
};

/* One 0x20-byte slot of the Pokemon list MON_SNAPSHOT_Fill fills. */
struct BoxMonSlot {
    u32 pid;                    /* +0x00 */
    u16 name[11];               /* +0x04 */
    struct LevelFlagBits bits;  /* +0x1a */
    u8  tag;                    /* +0x1b, 0xFF means unset */
    u32 experience;             /* +0x1c */
};

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);

extern u32  POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 buf);

extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);

extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

u32 MON_SNAPSHOT_GetSize(void);

void MON_SNAPSHOT_Clear(void *dest);

u32 MON_SNAPSHOT_IsFilled(const void *obj, u32 idx);

u32 MON_SNAPSHOT_GetLevel(const void *obj, u32 idx);

u32 MON_SNAPSHOT_HasAbility(const void *obj, u32 idx);

u8 MON_SNAPSHOT_GetAbility(const void *obj, u32 idx);

u32 MON_SNAPSHOT_GetSpeciesForSlot(const void *unused, u32 a, u32 b);

u32 MON_SNAPSHOT_GetPersonalRnd(const void *obj, u32 idx);

void *MON_SNAPSHOT_GetNickname(void *obj, u32 idx);

u32 MON_SNAPSHOT_GetOtId(const void *obj, u32 idx);

void MON_SNAPSHOT_Fill(struct BoxMonSlot *o, int idx, void *mon);

extern void *gSpeciesNameBank;

/*
 * A whole translation unit, matched as one byte range.
 *
 *           MON_SNAPSHOT_HasAbility, MON_SNAPSHOT_GetAbility, MON_SNAPSHOT_GetSpeciesForSlot, MON_SNAPSHOT_GetPersonalRnd,
 *           MON_SNAPSHOT_GetNickname, MON_SNAPSHOT_GetOtId
 *
 * alias: ten accessors on an array of 0x20-byte records, indexed by idx into
 * base + idx*0x20. MON_SNAPSHOT_GetSize/MON_SNAPSHOT_Clear are the constant-getter and
 * fill-user pair seen elsewhere in this packet: MON_SNAPSHOT_GetSize returns 0x40,
 * and MON_SNAPSHOT_Clear zero-fills that many bytes at the given pointer.
 *
 * The byte at record offset +0x1a packs two fields, read by the next pair:
 * bit 0 is a plain flag (MON_SNAPSHOT_IsFilled), and bits [7:1] are a level clamped
 * into [0x41, 0x64] (MON_SNAPSHOT_GetLevel, which adds 5 to the raw value once it is
 * at least 0x41 and clamps the low end up to 0x41 otherwise). The two
 * fields are declared as one bitfield struct so the compiler's lsls
 * #0x18 / lsrs #0x19 extraction for the 7-bit field is generated directly
 * instead of re-derived as a mask; see
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * MON_SNAPSHOT_HasAbility/MON_SNAPSHOT_GetAbility are a validity check and raw getter on the byte
 * at +0x1b (0xff means "unset"). MON_SNAPSHOT_GetSpeciesForSlot ignores its first argument
 * (r0) and looks at the second and third (r1, r2): it returns 0x23c when
 * r1 == 1, 0x222 when r2 == 0x15, and 0x224 otherwise, apparently a cost
 * table keyed by two flags. MON_SNAPSHOT_GetPersonalRnd/MON_SNAPSHOT_GetNickname/MON_SNAPSHOT_GetOtId are a
 * plain word getter at +0, a pointer-to-field getter at +4, and a plain
 * word getter at +0x1c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E730.c \
 *       --addr 0x0200E730 --thumb
 */
u32 MON_SNAPSHOT_GetSize(void)
{
    return 0x40;
}

void MON_SNAPSHOT_Clear(void *dest)
{
    MI_CpuFill8(dest, 0, 0x40);
}

u32 MON_SNAPSHOT_IsFilled(const void *slots, u32 index)
{
    return ((const struct LevelFlagBits *)((const u8 *)slots + index * 0x20 + 0x1a))->flag;
}

u32 MON_SNAPSHOT_GetLevel(const void *slots, u32 index)
{
    u32 level = ((const struct LevelFlagBits *)((const u8 *)slots + index * 0x20 + 0x1a))->level;
    if (level < 0x41) {
        level = 0x41;
    } else {
        level = (u8)(level + 5);
    }
    if (level > 0x64) {
        level = 0x64;
    }
    return level;
}

u32 MON_SNAPSHOT_HasAbility(const void *slots, u32 index)
{
    return *((const u8 *)slots + index * 0x20 + 0x1b) != 0xff;
}

u8 MON_SNAPSHOT_GetAbility(const void *slots, u32 index)
{
    return *((const u8 *)slots + index * 0x20 + 0x1b);
}

u32 MON_SNAPSHOT_GetSpeciesForSlot(const void *unused, u32 a, u32 b)
{
    if (a == 1) {
        return 0x23c;
    }
    if (b == 0x15) {
        return 0x222;
    }
    return 0x224;
}

u32 MON_SNAPSHOT_GetPersonalRnd(const void *slots, u32 index)
{
    return *(const u32 *)((const u8 *)slots + index * 0x20);
}

void *MON_SNAPSHOT_GetNickname(void *slots, u32 index)
{
    return (u8 *)slots + index * 0x20 + 4;
}

u32 MON_SNAPSHOT_GetOtId(const void *slots, u32 index)
{
    return *(const u32 *)((const u8 *)slots + index * 0x20 + 0x1c);
}

/*
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
void MON_SNAPSHOT_Fill(struct BoxMonSlot *slots, int index, void *mon)
{
    slots[index].bits.level = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
    if (POKE_TOOL_GetPartyValue(mon, 0x71, 0) != 0)
        slots[index].tag = POKE_TOOL_GetPartyValue(mon, 0xa, 0);
    else
        slots[index].tag = 0xff;
    slots[index].pid = POKE_TOOL_GetPartyValue(mon, 0, 0);
    slots[index].experience = POKE_TOOL_GetPartyValue(mon, 7, 0);
    if (POKE_TOOL_GetPartyValue(mon, 0x75, 0) != 0) {
        POKE_TOOL_GetPartyValue(mon, 0x74, (u32)slots[index].name);
    } else {
        u16 buf[12];

        MSGDATA_ReadUnits(gSpeciesNameBank, POKE_TOOL_GetPartyValue(mon, 5, 0), buf, 0xb);
        WORDSET_CopyString(buf, slots[index].name, 0xb);
    }
    slots[index].bits.flag = 1;
}
