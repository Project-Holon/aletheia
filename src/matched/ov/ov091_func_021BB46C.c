/*
 * function: func_021BB46C
 * address: 0x021BB46C
 * packet: pkt_ov091_021BB46C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9A84 0x021B9A84 thumb ov091
 *   POKE_REGULATION_CheckPokemon 0x02019DA4 thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern int func_021B9A84(u32 p);
extern int POKE_REGULATION_CheckPokemon(void *a, void *b);
void func_021BB46C(u8 *p, u32 *q)
{
    if (func_021B9A84((u32)p) == 0) {
        q[7] = 8;
        return;
    }
    if (POKE_REGULATION_CheckPokemon(*(void **)(*(u8 **)(p + 0x280) + 0x14), (void *)q[0]) == 0) {
        q[7] = 6;
        return;
    }
    q[7] = 7;
}
