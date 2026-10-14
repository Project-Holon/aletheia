/*
 * function: func_021BAB0C
 * address:  0x021BAB0C
 * packet:   pkt_ov217_021BAB0C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   d_021C2FF8  0x021C2FF8  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ent { u32 a; u32 b; u8 c; u8 pad[11]; };

extern void PALETTE_ANIME_Bind(void *p, u32 b, u32 c, u32 d);
extern struct Ent d_021C2FF8[];

void func_021BAB0C(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Bind((void *)(*(int *)(self + i * 4 + 0x38)), d_021C2FF8[i].a, d_021C2FF8[i].b, d_021C2FF8[i].c);
    }
}
