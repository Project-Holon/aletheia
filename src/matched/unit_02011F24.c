/*
 * unit:     yes
 * address:  0x02011F24
 * packet:   pkt_02011EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02011F24
 *
 * Four bytes, `movs r0, #0x34; bx lr`: the sizeof getter of the context record
 * whose accessors are src/matched/unit_020120F0.c and
 * src/matched/unit_02012204.c.  It is what pins that struct's size, and the
 * declaration here is the same one those two files carry, so the three check
 * each other.  It is a file of its own because the functions on either side of
 * it are not matched yet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011F24.c  *       --addr 0x02011F24 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx {
    u8    unk00[0xC];
    u32   unk0C;
    u8    unk10[8];
    u32   unk18;
    void *unk1C;
    u32   unk20;
    u32   unk24;
    u32   unk28;
    u32   unk2C;
    u8    unk30;
    u8    unk31;
    u8    unk32;
    u8    unk33_0 : 1;
    u8    unk33_1 : 7;
};

u32 func_02011F24(void)
{
    return sizeof(struct Ctx);
}
