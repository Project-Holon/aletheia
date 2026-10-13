/*
 * function: FLD_BTL_INST_TOOL_AddBattleTally
 * address:  0x02168D30
 * packet:   pkt_ov010_02168D30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Add one battle's tallies into the running record and credit the
 * score share against the party's summed stat 0xA1. First draft.
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Result {
    u8 pad00[0x24];
    void *party;        /* 0x24 */
    u8 pad28[0xB4 - 0x28];
    u16 fb4;            /* 0xB4 */
    u8 fb6[11];         /* 0xB6 */
} Result;

typedef struct Record {
    u8 pad000[0x134];
    u16 f134[10];       /* 0x134 */
    u16 f148;           /* 0x148 */
    u16 f14a;           /* 0x14A */
} Record;

extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

void FLD_BTL_INST_TOOL_AddBattleTally(Record *r, Result *s)
{
    void *party;
    int n;
    int i;
    int sum;

    r->f134[0] += (u16)(s->fb6[0] + 1);
    r->f134[1] += s->fb6[1];
    r->f134[2] += s->fb6[2];
    r->f134[3] += s->fb6[3];
    r->f134[4] += s->fb6[4];
    r->f134[5] += s->fb6[5];
    r->f134[6] += s->fb6[6];
    r->f134[7] += s->fb6[7];
    r->f134[8] += s->fb6[8];
    r->f134[9] += s->fb6[9];
    r->f14a += s->fb6[10];
    party = s->party;
    n = POKEPARTY_GetCount(party);
    sum = 0;
    for (i = 0; i < n; i++)
        sum += POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 0xA1, 0);
    r->f148 += (u16)(s->fb4 * 100 / sum);
}
