/*
 * function: func_021DEF98
 * address: 0x021DEF98
 * packet: pkt_ov170_021DEF98
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   func_021DEDD8 0x021DEDD8 thumb ov170
 *   func_021DEF60 0x021DEF60 thumb ov170
 *   func_021DEF58 0x021DEF58 thumb ov170
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   func_021DF040 0x021DF040 thumb ov170
 */
extern int func_021DD2D0(void ***p, int a, unsigned b);
typedef unsigned int   u32;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern void *func_021DEDD8(void *p);
extern void func_021DEF60(char *p, int a);
extern void func_021DEF58(void *s);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void func_021DF040(char *p);
int func_021DEF98(char *p, int a, unsigned b)
{
    void *mon;
    int state;
    void *s;
    mon = (void *)func_021DD2D0((void ***)p, a, b);
    if (mon) {
        state = POKE_TOOL_DecodeBoxParam(mon);
        s = func_021DEDD8(mon);
        if (s) {
            func_021DEF60(p, (int)s);
            func_021DEF58(s);
            POKE_TOOL_EncodeBoxParam(mon, state);
        } else {
            func_021DF040(p);
            POKE_TOOL_EncodeBoxParam(mon, state);
            return 0;
        }
    } else {
        func_021DF040(p);
        return 0;
    }
    return 1;
}
