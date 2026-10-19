/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E730
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MON_SNAPSHOT_GetSize, MON_SNAPSHOT_Clear, MON_SNAPSHOT_IsFilled, MON_SNAPSHOT_GetLevel,
 *           MON_SNAPSHOT_HasAbility, MON_SNAPSHOT_GetAbility, MON_SNAPSHOT_GetSpeciesForSlot, MON_SNAPSHOT_GetPersonalRnd,
 *           MON_SNAPSHOT_GetNickname, MON_SNAPSHOT_GetOtId
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
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

typedef unsigned char u8;
typedef unsigned int u32;

u32 MON_SNAPSHOT_GetSize(void)
{
    return 0x40;
}

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void MON_SNAPSHOT_Clear(void *dest)
{
    MI_CpuFill8(dest, 0, 0x40);
}

typedef struct {
    u8 flag : 1;
    u8 level : 7;
} Flags;

u32 MON_SNAPSHOT_IsFilled(const void *obj, u32 idx)
{
    return ((const Flags *)((const u8 *)obj + idx * 0x20 + 0x1a))->flag;
}

u32 MON_SNAPSHOT_GetLevel(const void *obj, u32 idx)
{
    u32 level = ((const Flags *)((const u8 *)obj + idx * 0x20 + 0x1a))->level;
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

u32 MON_SNAPSHOT_HasAbility(const void *obj, u32 idx)
{
    return *((const u8 *)obj + idx * 0x20 + 0x1b) != 0xff;
}

u8 MON_SNAPSHOT_GetAbility(const void *obj, u32 idx)
{
    return *((const u8 *)obj + idx * 0x20 + 0x1b);
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

u32 MON_SNAPSHOT_GetPersonalRnd(const void *obj, u32 idx)
{
    return *(const u32 *)((const u8 *)obj + idx * 0x20);
}

void *MON_SNAPSHOT_GetNickname(void *obj, u32 idx)
{
    return (u8 *)obj + idx * 0x20 + 4;
}

u32 MON_SNAPSHOT_GetOtId(const void *obj, u32 idx)
{
    return *(const u32 *)((const u8 *)obj + idx * 0x20 + 0x1c);
}
