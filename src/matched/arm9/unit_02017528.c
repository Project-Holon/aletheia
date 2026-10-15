/*
 * unit:     yes
 * address:  0x02017528
 * packet:   pkt_02016FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_ClearPartyParam, POKE_TOOL_ClearBoxParam
 *
 * The two clears of the 0xDC byte record src/matched/unit_02017D30.c and
 * src/matched/unit_02018D10.c work on: POKE_TOOL_ClearPartyParam wipes the whole of it and
 * re-masks both areas, POKE_TOOL_ClearBoxParam wipes only the first 0x88 bytes and
 * re-masks the 0x80 byte one.  The masking calls are what say the record's
 * seed word and checksum halfword survive a clear in the caller's copy: the
 * value handed to POKE_CRYPTO_XorBlock is read back out of the object *after*
 * MIi_CpuClearFast has zeroed it, so both areas are masked with zero and the
 * call is the identity.
 *
 * The range stops at 0x0201756C.  That function and its twin at 0x02017600
 * are five argument entry points to eight argument workers, passing
 * 0xFFFFFFFF, 0 and 0xFFFFFFFF for the three arguments they do not take, and
 * neither reproduces: the original spends a third callee-saved register on
 * the incoming fifth argument and stores it into the outgoing frame last,
 * after all three constants, while every forwarding spelling tried loads it
 * first and reuses one register for it and for the zero.  Eighteen bytes, all
 * of them register numbers and store order.
 *
 * symbols:
 *   POKE_CRYPTO_XorBlock  0x02019A50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void POKE_CRYPTO_XorBlock(u16 *p, u32 size, u32 seed);

struct Sav {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u8  unk08[0x80];
    u8  unk88[0x54];
};

void POKE_TOOL_ClearPartyParam(struct Sav *p)
{
    MIi_CpuClearFast(0, p, sizeof(struct Sav));
    POKE_CRYPTO_XorBlock((u16 *)p->unk08, 0x80, p->unk06);
    POKE_CRYPTO_XorBlock((u16 *)p->unk88, 0x54, p->unk00);
}

void POKE_TOOL_ClearBoxParam(struct Sav *p)
{
    MIi_CpuClearFast(0, p, 0x88);
    POKE_CRYPTO_XorBlock((u16 *)p->unk08, 0x80, p->unk06);
}

