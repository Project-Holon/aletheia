/*
 * function: BTL_SERVER_FLOW_AddDefeatEffortValues
 * address:  0x021CB5F0
 * packet:   pkt_021CB5F0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the six per-party "battle handicap" bytes and writes them to the
 * output record.  Reads the record's u16 fields 0xc and 0x13, asks the
 * battle dispatcher POKE_TOOL_GetPersonalParam for a base value per entry of the six
 * entry table at 0x021EFDC0 (6-byte records: u8 at +0, u16 at +2, u16 at
 * +4), doubles them when the mode field 0x12 is 0xd7, then walks the table
 * again to add BTL_CALC_GetMonParamWithHeap's value for the entry whose +4 field matches
 * and to fold each result into the savedata record 0x97 through the
 * POKE_TOOL_GetPartyValue/POKE_TOOL_SetPartyValue read/write pair, clamped at 0xff.  The final
 * switch on the loop index is the image's, not a source choice: the table
 * at 0x021CB6F4 is six four-byte arms, case i storing the byte at
 * a2[5 + i].  Ends by releasing the savedata record.
 *
 * symbols:
 *   gEffortValueStatTable      0x021EFDC0  data  ov093
 *   BTL_POKEPARAM_GetSpecies   0x021D5444  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_POKEPARAM_GetItem   0x021D5B40  thumb ov093
 *   BTL_POKEPARAM_GetMon   0x021D5844  thumb ov093
 *   BTL_CALC_GetMonParamWithHeap   0x021D805C  thumb ov093
 *   POKE_TOOL_GetPersonalParam   0x02019C90  thumb arm9
 *   POKE_TOOL_DecodePartyParam   0x02017D30  thumb arm9
 *   POKE_TOOL_EncodePartyParam   0x02017D70  thumb arm9
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb arm9
 *   POKE_TOOL_SetPartyValue   0x02017E40  thumb arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };
extern struct T6 gEffortValueStatTable[];

struct QF;
struct QI;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);

extern u32 POKE_TOOL_GetPersonalParam(void *p, u32 a, u32 b);
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);

void BTL_SERVER_FLOW_AddDefeatEffortValues(u32 *a0, u8 *a1, u8 *a2)
{
    u8 buf[6];
    u8 i;
    u16 v6;
    u32 m;
    u32 t;
    void *rec;
    u32 sv;

    m = BTL_POKEPARAM_GetSpecies((struct QF *)a1);
    v6 = (u16)func_021D59B4(a1, 0x13);
    for (i = 0; i < 6; i++) {
        buf[i] = (u8)POKE_TOOL_GetPersonalParam((void *)m, v6, gEffortValueStatTable[i].f0);
    }
    if (BTL_POKEPARAM_GetItem((struct QI *)a0) == 0xd7) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        t = gEffortValueStatTable[i].f4;
        if (t == BTL_POKEPARAM_GetItem((struct QI *)a0)) {
            buf[i] = (u8)(buf[i] + (u8)BTL_CALC_GetMonParamWithHeap((void *)t, 2));
        }
    }
    rec = BTL_POKEPARAM_GetMon(a0);
    sv = POKE_TOOL_DecodePartyParam(rec);
    if (POKE_TOOL_GetPartyValue(rec, 0x97, 0) != 0) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        u8 v;
        u32 w;

        v = buf[i];
        if (v == 0) {
            continue;
        }
        t = gEffortValueStatTable[i].f2;
        w = POKE_TOOL_GetPartyValue(rec, t, 0) + v;
        if (w > 0xff) {
            w = 0xff;
        }
        POKE_TOOL_SetPartyValue(rec, t, w);
        switch (i) {
        case 0: a2[5] = v; break;
        case 1: a2[6] = v; break;
        case 2: a2[7] = v; break;
        case 3: a2[8] = v; break;
        case 4: a2[9] = v; break;
        case 5: a2[0xa] = v; break;
        }
    }
    POKE_TOOL_EncodePartyParam(rec, sv);
}
