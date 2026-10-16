/*
 * function: BOX2_MAIN_CreateSummary
 * address:  0x021DEDD8
 * packet:   pkt_ov170_021DEDD8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetBoxNature 0x020185A0 thumb
 *   POKE_TOOL_GetBoxGender 0x02017F08 thumb
 *   POKE_TOOL_IsBoxShiny 0x02017EB4 thumb
 *   POKERUS_IsBoxInfected 0x0201B268 thumb
 *   POKERUS_IsBoxCured 0x0201B28C thumb
 *   d_021F1400 0x021F1400 data a1
 *
 * Allocates the 0x1C-byte summary of a Pokemon (species, form, PID,
 * markings, level, flags, four moves); NULL for an empty slot.
 */

typedef struct {
    void *mon;
    unsigned short species;
    unsigned short form;
    unsigned pid;
    unsigned char cC;
    unsigned char cD;
    unsigned char cE;
    unsigned char cF;
    unsigned short item;
    unsigned char level : 7;
    unsigned char egg : 1;
    unsigned char gender : 4;
    unsigned char showgender : 1;
    unsigned char shiny : 1;
    unsigned char mark : 2;
    unsigned short moves[4];
} Summary;

extern unsigned POKE_TOOL_GetBoxValue(void *p, unsigned id, unsigned v);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern unsigned char POKE_TOOL_GetBoxNature(void *mon);
extern unsigned char POKE_TOOL_GetBoxGender(void *mon);
extern u32 POKE_TOOL_IsBoxShiny(void *p);
extern u32 POKERUS_IsBoxInfected(void *mon);
extern u32 POKERUS_IsBoxCured(void *mon);
extern const char d_021F1400[];

Summary *BOX2_MAIN_CreateSummary(void *mon)
{
    Summary *s;
    unsigned i;

    if (POKE_TOOL_GetBoxValue(mon, 0xA9, 0) != 0) {
        s = func_02030734(0x4C, 0x1C, 0, d_021F1400, 0xCD2);
        s->mon = mon;
        s->species = POKE_TOOL_GetBoxValue(mon, 5, 0);
        s->form = POKE_TOOL_GetBoxValue(mon, 6, 0);
        s->pid = POKE_TOOL_GetBoxValue(mon, 0, 0);
        s->cC = POKE_TOOL_GetBoxValue(mon, 0xAE, 0);
        s->cD = POKE_TOOL_GetBoxValue(mon, 0xAF, 0);
        s->cE = POKE_TOOL_GetBoxValue(mon, 0xA, 0);
        s->cF = POKE_TOOL_GetBoxNature(mon);
        s->item = POKE_TOOL_GetBoxValue(mon, 0xB, 0);
        s->level = POKE_TOOL_GetBoxValue(mon, 0x9E, 0);
        s->egg = (unsigned char)POKE_TOOL_GetBoxValue(mon, 0x4C, 0);
        if (s->egg == 0)
            s->gender = POKE_TOOL_GetBoxGender(mon);
        else
            s->gender = 0;
        if (POKE_TOOL_IsBoxShiny(mon) == 1)
            s->shiny = 1;
        else
            s->shiny = 0;
        if (POKERUS_IsBoxInfected(mon) == 1)
            s->mark = 1;
        else if (POKERUS_IsBoxCured(mon) == 1)
            s->mark = 2;
        else
            s->mark = 0;
        if (s->species != 0x1D && s->species != 0x20 && s->egg == 0)
            s->showgender = 1;
        else
            s->showgender = 0;
        for (i = 0; i < 4; i++)
            s->moves[i] = POKE_TOOL_GetBoxValue(mon, 0x36 + i, 0);
    } else {
        s = 0;
    }
    return s;
}
