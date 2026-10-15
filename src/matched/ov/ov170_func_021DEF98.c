/*
 * function: BOX2_MAIN_ChangeBoxForm
 * address: 0x021DEF98
 * packet: pkt_ov170_021DEF98
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   BOX2_MAIN_CreateSummary 0x021DEDD8 thumb ov170
 *   BOX2_MAIN_SetupSummary 0x021DEF60 thumb ov170
 *   BOX2_MAIN_DeleteHandle 0x021DEF58 thumb ov170
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb ov170
 */
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
typedef unsigned int   u32;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern void *BOX2_MAIN_CreateSummary(void *p);
extern void BOX2_MAIN_SetupSummary(char *p, int a);
extern void BOX2_MAIN_DeleteHandle(void *s);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void BOX2_MAIN_ResetBoxView(char *p);
int BOX2_MAIN_ChangeBoxForm(char *p, int a, unsigned b)
{
    void *mon;
    int state;
    void *s;
    mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, a, b);
    if (mon) {
        state = POKE_TOOL_DecodeBoxParam(mon);
        s = BOX2_MAIN_CreateSummary(mon);
        if (s) {
            BOX2_MAIN_SetupSummary(p, (int)s);
            BOX2_MAIN_DeleteHandle(s);
            POKE_TOOL_EncodeBoxParam(mon, state);
        } else {
            BOX2_MAIN_ResetBoxView(p);
            POKE_TOOL_EncodeBoxParam(mon, state);
            return 0;
        }
    } else {
        BOX2_MAIN_ResetBoxView(p);
        return 0;
    }
    return 1;
}
