/*
 * function: func_02017588
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
 *   func_02019A50  0x02019A50  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020185C4  0x020185C4  thumb
 *
 * Build a full party record: clear it (POKE_TOOL_ClearPartyParam), initialise the block
 * area (POKE_TOOL_SetupBoxParamEx), mask the party area with seed 0 then with the PID,
 * write the level (id 0x9E) through the party-lock setter, attach a fresh
 * mail block (tag 0x8000, id 0xA7, then freed), and refresh the stats
 * (func_020185C4).  Wave 11, 2026-09-23.  EXACT* only because the listing
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
extern void func_02019A50(u16 *p, u32 size, u32 seed);
extern void  func_02017E40(void *p, u32 id, u32 v);
extern void *func_02008F08(int a0);
extern u32 func_020307B0(void *p);
extern void  func_020185C4(void *p);

void func_02017588(struct Mon *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *mail;

    POKE_TOOL_ClearPartyParam((struct Sav *)p);
    POKE_TOOL_SetupBoxParamEx(p, species, level, id, pow, rnd);
    func_02019A50((u16 *)p->unk88, 0x54, 0);
    func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
    func_02017E40(p, 0x9e, level);
    mail = func_02008F08(0x8000);
    func_02017E40(p, 0xa7, (u32)mail);
    func_020307B0(mail);
    func_020185C4(p);
}
