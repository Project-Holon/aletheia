/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02028F18
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: sub_02028F18, sub_02028F30, sub_02028F48, sub_02028F60,
 *           sub_02028F7C, sub_02028F9C, sub_02028FB8, sub_02028FD0
 *
 * Eight setters over a small event/descriptor object plus the shared
 * type-check helper they all call. Each setter validates a numeric "kind"
 * argument (1..7) against a per-object-kind permission byte, obtained from
 * `sub_02028FD0(obj, type)`: a table of 8-byte rows indexed by the field 4
 * bytes into the object (its own "kind"), one row byte per type. Only on a
 * nonzero result does the setter tag the object with the type constant at
 * +0x1c and write its arguments into a handful of fields at +0xc, +0x18 and
 * +0x1a: sub_02028F18/30/48 take one halfword argument, sub_02028F60 two,
 * sub_02028F7C four (a word and two halfwords), sub_02028F9C a word and a
 * halfword, sub_02028FB8 one word. Field 0x18 gets the second-declared
 * halfword argument and 0x1a the first for sub_02028F60 specifically
 * (source order there is (obj, a, b) but the store order is b then a; the
 * original's register shuffle names it, not the calling convention).
 *
 * Every concrete byte reproduces the original, including the internal
 * `bl sub_02028FD0` sites, which are local to the unit. The single ABS32
 * relocation inside sub_02028FD0, the pool word naming its lookup table,
 * has no witness outside this range: the only two places in the whole
 * arm9 image that hold 0x0209FE1C are this function's own pool word (seen
 * twice, once per generated listing split of the same region), so it stays
 * an unresolved wildcard under the honesty rule and the unit caps at
 * MATCH. It stays open until the table address gets an outside reference,
 * because the table itself is bss (no label is possible) and nothing else
 * in the ARM9 static module loads it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02028F18.c \
 *       --addr 0x02028F18 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const u8 g_EventTypeTable[][8];

static u32 sub_02028FD0(void *obj, u32 type);

void sub_02028F18(void *obj, u16 value)
{
    if (sub_02028FD0(obj, 1)) {
        *(u32 *)((u8 *)obj + 0x1c) = 1;
        *(u16 *)((u8 *)obj + 0x18) = value;
    }
}

void sub_02028F30(void *obj, u16 value)
{
    if (sub_02028FD0(obj, 2)) {
        *(u32 *)((u8 *)obj + 0x1c) = 2;
        *(u16 *)((u8 *)obj + 0x1a) = value;
    }
}

void sub_02028F48(void *obj, u16 value)
{
    if (sub_02028FD0(obj, 3)) {
        *(u32 *)((u8 *)obj + 0x1c) = 3;
        *(u16 *)((u8 *)obj + 0x1a) = value;
    }
}

void sub_02028F60(void *obj, u16 a, u16 b)
{
    if (sub_02028FD0(obj, 4)) {
        *(u32 *)((u8 *)obj + 0x1c) = 4;
        *(u16 *)((u8 *)obj + 0x18) = b;
        *(u16 *)((u8 *)obj + 0x1a) = a;
    }
}

void sub_02028F7C(void *obj, u32 a, u16 b, u16 c)
{
    if (sub_02028FD0(obj, 5)) {
        *(u32 *)((u8 *)obj + 0x1c) = 5;
        *(u32 *)((u8 *)obj + 0xc) = a;
        *(u16 *)((u8 *)obj + 0x18) = c;
        *(u16 *)((u8 *)obj + 0x1a) = b;
    }
}

void sub_02028F9C(void *obj, u32 a, u16 b)
{
    if (sub_02028FD0(obj, 6)) {
        *(u32 *)((u8 *)obj + 0x1c) = 6;
        *(u32 *)((u8 *)obj + 0xc) = a;
        *(u16 *)((u8 *)obj + 0x1a) = b;
    }
}

void sub_02028FB8(void *obj, u32 a)
{
    if (sub_02028FD0(obj, 7)) {
        *(u32 *)((u8 *)obj + 0x1c) = 7;
        *(u32 *)((u8 *)obj + 0xc) = a;
    }
}

static u32 sub_02028FD0(void *obj, u32 type)
{
    u32 kind = *(u32 *)((u8 *)obj + 4);
    return g_EventTypeTable[kind][type];
}
