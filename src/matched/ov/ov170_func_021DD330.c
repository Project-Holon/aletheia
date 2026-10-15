/*
 * function: BOX2_MAIN_MoveMonToParty
 * address: 0x021DD330
 * packet: pkt_ov170_021DD330
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   POKE_TOOL_CreateFromBoxParam 0x0201747C thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_020075B0 0x020075B0 thumb
 *   POKEPARTY_SetMember 0x0201AB48 thumb
 *   func_020307B0 0x020307B0 arm
 */
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_UI_DrawSlot(char *p, int i);
typedef unsigned int   u32;
struct Mon;
struct Party;
struct PartyMon;
struct Sub020075B0Entry;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void *POKEPARTY_GetMember(void *,unsigned);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
void BOX2_MAIN_MoveMonToParty(unsigned char *p,unsigned short *q,unsigned short *t)
{
    unsigned box;
    unsigned short slot;
    void *m;
    if (q[0] == 0x24) box=p[0x17]; else box=p[0x14];
    m=POKE_TOOL_CreateFromBoxParam((struct Mon *)BOX2_MAIN_GetMonAt((void ***)p,box,q[2]),0x804c);
    slot=t[2]-30;
    func_020075B0((*(void ***)p)[1],box,q[2],POKE_TOOL_GetBoxParam(POKEPARTY_GetMember((*(void ***)p)[2],slot)));
    POKEPARTY_SetMember((*(void ***)p)[2],slot,m);
    func_020307B0(m);
    BOX2_UI_DrawSlot((char *)p,box);
}
