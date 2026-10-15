/*
 * function: POKE_TOOL_SetupPartyParamEx
 * address:  0x02017588
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   POKE_TOOL_SetupBoxParamEx  0x0201761C  thumb
 *   POKE_CRYPTO_XorBlock  0x02019A50  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *
 * Build a full party record: clear it (POKE_TOOL_ClearPartyParam), initialise the block
 * area (POKE_TOOL_SetupBoxParamEx), mask the party area with seed 0 then with the PID,
 * write the level (id 0x9E) through the party-lock setter, attach a fresh
 * mail block (tag 0x8000, id 0xA7, then freed), and refresh the stats
 * (POKE_TOOL_RecalcParam).  Wave 11, 2026-09-23.  EXACT* only because the listing
 * extent includes the two alignment bytes at 0x020175FE.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

struct Mon {
    u32 unk00;
    u8  pad04[0x84];
    u8  unk88[0x54];
};

struct Sav;
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern void POKE_TOOL_SetupBoxParamEx(void *obj, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_CRYPTO_XorBlock(u16 *p, u32 size, u32 seed);
extern void  POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void *MAIL_Create(int a0);
extern u32 func_020307B0(void *p);
extern void  POKE_TOOL_RecalcParam(void *p);

void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *mail;

    POKE_TOOL_ClearPartyParam((struct Sav *)p);
    POKE_TOOL_SetupBoxParamEx(p, species, level, id, pow, rnd);
    POKE_CRYPTO_XorBlock((u16 *)p->unk88, 0x54, 0);
    POKE_CRYPTO_XorBlock((u16 *)p->unk88, 0x54, p->unk00);
    POKE_TOOL_SetPartyValue(p, 0x9e, level);
    mail = MAIL_Create(0x8000);
    POKE_TOOL_SetPartyValue(p, 0xa7, (u32)mail);
    func_020307B0(mail);
    POKE_TOOL_RecalcParam(p);
}
