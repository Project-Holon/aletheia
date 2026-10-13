/*
 * function: func_021F11CC
 * address:  0x021F11CC
 * packet:   pkt_ov107_021F11CC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetBoxParamSize  0x020173E8  thumb
 */

typedef struct {
    unsigned char pad00[0x10];
    unsigned char *f10;
} Ov107Ctx;

typedef unsigned int   u32;
u32 POKE_TOOL_GetBoxParamSize(void);

void *func_021F11CC(Ov107Ctx *p, int i)
{
    return p->f10 + i * POKE_TOOL_GetBoxParamSize() + 4;
}
