/*
 * function: func_0216070C
 * address:  0x0216070C
 * packet:   pkt_ov010_0216070C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * TRUE when some party member has field 0xA9 set and passes POKE_TOOL_HasRibbonData.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   POKE_TOOL_HasRibbonData  0x0201897C  thumb
 */

typedef unsigned int u32;

typedef struct Work {
    void *f00;
    void *f04;
} Work;

struct BigObj;
struct Ctx;
struct Hdr;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *pp, u32 id, u32 v);
extern u32 POKE_TOOL_HasRibbonData(struct Hdr *p);

int func_0216070C(Work *w)
{
    void *party;
    void *pp;
    int i;

    party = func_02012934(func_020120F4(w->f04));
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        pp = func_0201AB28(party, i);
        if (func_02017E1C(pp, 0xA9, 0) != 0 && POKE_TOOL_HasRibbonData(pp) != 0)
            return 1;
    }
    return 0;
}
