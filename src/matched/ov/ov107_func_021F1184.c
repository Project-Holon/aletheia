/*
 * function: MB_COMM_SYS_ClearMonBuffer
 * address:  0x021F1184
 * packet:   pkt_ov107_021F1184
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetBoxParamSize  0x020173E8  thumb
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 */

typedef struct {
    unsigned char f00;
    unsigned char pad01;
    unsigned short f02;
} Ov107List;

typedef struct {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short rest : 13;
} Ov107Flags;

typedef struct {
    unsigned char pad00[0x10];
    Ov107List *f10;
    unsigned char pad14[4];
    Ov107Flags f18;
} Ov107Ctx;

typedef unsigned int   u32;
u32 POKE_TOOL_GetBoxParamSize(void);
struct Sav;
void POKE_TOOL_ClearBoxParam(struct Sav *);

void MB_COMM_SYS_ClearMonBuffer(Ov107Ctx *p)
{
    Ov107List *list;
    unsigned char i;

    list = p->f10;
    list->f00 = 0;
    list->f02 = 0;
    for (i = 0; i < 6; i++) {
        POKE_TOOL_ClearBoxParam((struct Sav *)((unsigned char *)p->f10 + i * POKE_TOOL_GetBoxParamSize() + 4));
    }
    p->f18.b1 = 0;
    p->f18.b2 = 0;
}
