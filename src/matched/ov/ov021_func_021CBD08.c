/*
 * function: BSUBWAY_SCR_CreateBtlSetup
 * address:  0x021CBD08
 * packet:   pkt_ov021_021CBD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a party list from the selected slots and runs the ov010 summary on it.
 *
 * symbols:
 *   POKEPARTY_Create  0x0201A920  thumb
 *   BSUBWAY_SCR_GetParty  0x021CA210  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   FLD_BTL_INST_TOOL_CreateBtlSetup  0x021681C8  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

typedef signed int     s32;
struct Party;
struct PartyMon;
extern struct Party *POKEPARTY_Create(u32 heap);
extern void *BSUBWAY_SCR_GetParty(u8 *p);
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
struct Bs;
struct Rec;
extern struct Bs *FLD_BTL_INST_TOOL_CreateBtlSetup(void *sys, void *partyA, u32 mode0, struct Rec *recA, struct Rec *recB, int n);
extern u32 func_020307B0(void *p);

u32 BSUBWAY_SCR_CreateBtlSetup(u8 *p, int a)
{
    void *list = POKEPARTY_Create(0x8004);
    void *h = BSUBWAY_SCR_GetParty(p);
    int i;
    u32 r;

    POKEPARTY_InitEx(list, p[8]);
    for (i = 0; i < p[8]; i++)
        POKEPARTY_Add(list, POKEPARTY_GetMember(h, p[0x1e + i]));
    r = (u32)FLD_BTL_INST_TOOL_CreateBtlSetup((void *)a, list, p[9], (struct Rec *)(p + 0x88), (struct Rec *)(p + 0x2c8 + ((Sel *)p)->sel * 0x120), p[8]);
    func_020307B0(list);
    return r;
}
