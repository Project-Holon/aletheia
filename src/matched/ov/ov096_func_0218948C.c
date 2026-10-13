/*
 * unit:     yes
 * function: TR_AI_CmdLoadPokeValueByte, TR_AI_CmdLoadRule, TR_AI_CmdLoadCompetitor
 * address:  0x0218948C
 * packet:   pkt_ov096_0218948C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TR_AI_CmdLoadRule and TR_AI_CmdLoadCompetitor are the unlabelled store-and-return stubs
 * after the lead function (function_starts seeds).
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x38];
    int f38;
    u8 pad3C[0x98 - 0x3c];
    int f98;
    int f9c;
    u8 padA0[0xc4 - 0xa0];
    int fc4;
} Conn;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);

int TR_AI_CmdLoadPokeValueByte(struct Cursor *a, Conn *b)
{
    b->f38 = BTL_POKEPARAM_GetCounter(TR_AI_GetPoke((u8 *)b, TR_AI_GetPosition((u8 *)b, VM_GetU32(a))), 0);
    return b->fc4;
}

int TR_AI_CmdLoadRule(int a, Conn *b)
{
    b->f38 = b->f98;
    return b->fc4;
}

int TR_AI_CmdLoadCompetitor(int a, Conn *b)
{
    b->f38 = b->f9c;
    return b->fc4;
}
