/*
 * unit:     yes
 * function: func_02026124
 * address:  0x02026124
 * packet:   pkt_02026124
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c leaves after src/matched/sub_020260F4.c, on the
 * same object as src/matched/unit_020260E0.c: clear a bit in the flag
 * words at +0x10, set it, and address an entry of the 12-byte table.
 * The clear spells ~m as m ^ 0xFFFFFFFF (the compiler derives -1 from the
 * live 0x1f with subs #0x20); the set is an xor guarded by the test.
 * Seeded from ov170 (0x021DF6AE, 0x021EA0FE, 0x021EA892) and ov069/ov136.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Entry {
    u32 a;
    u32 b;
    u32 c;
};

struct Vtbl;

struct Sound {
    struct Entry *entries;
    u32 field_4;
    u32 field_8;
    u8  field_C;
    u8  field_D;
    u8  field_E;
    u8  field_F;
    u32 bits[2];
    struct Vtbl *vt;
    void *ctx;
};

void func_02026124(struct Sound *obj, u32 idx)
{
    u32 w = idx / 32;
    u32 b = idx % 32;
    if (obj->bits[w] & (1 << b)) {
        obj->bits[w] &= (1 << b) ^ 0xFFFFFFFF;
    }
}

void func_0202614C(struct Sound *obj, u32 idx)
{
    u32 w = idx / 32;
    u32 b = idx % 32;
    if ((obj->bits[w] & (1 << b)) == 0) {
        obj->bits[w] ^= (1 << b);
    }
}

struct Entry *func_0202616C(struct Sound *obj, u32 idx)
{
    return &obj->entries[idx];
}
