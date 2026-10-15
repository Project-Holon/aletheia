/*
 * function: BOX2_MAIN_AddMonToParty
 * address: 0x021DD39C
 * packet: pkt_ov170_021DD39C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   BOX2_MAIN_ClearSlot 0x021DD314 thumb ov170
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   POKE_TOOL_CreateFromBoxParam 0x0201747C thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 */
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);
extern void BOX2_UI_DrawSlot(char *p, int i);
typedef unsigned int   u32;
struct Mon;
struct Party;
struct PartyMon;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
void BOX2_MAIN_AddMonToParty(unsigned char *p, unsigned short *q)
{
    void *m;
    m = POKE_TOOL_CreateFromBoxParam((struct Mon *)BOX2_MAIN_GetMonAt((void ***)p,p[0x17],q[2]),0x804c);
    POKEPARTY_Add((*(void ***)p)[2],m);
    BOX2_MAIN_ClearSlot((char **)p,p[0x17],q[2]);
    func_020307B0(m);
    BOX2_UI_DrawSlot((char *)p,p[0x17]);
}
