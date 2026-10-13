/*
 * function: INTRUDE_COMM_RecvProfile
 * address:  0x021745B0
 * packet:   pkt_ov011_021745B0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef struct F {
    unsigned char f0 : 1;
    unsigned char f1 : 7;
} F;

typedef unsigned int   u32;
u32 GAME_COMM_GetGameData(void *obj);
void func_02082D44(void *d, void *s, int n);

void INTRUDE_COMM_RecvProfile(int a, int b, void *c, char *d)
{
    GAME_COMM_GetGameData((void *)(((int *)d)[1]));
    if (((unsigned char)d[0x8fb] & (1 << a)) && ((F *)(d + 0x8f8))->f0 == 0) {
        func_02082D44(c, d + 0x8e4, 0x14);
        ((F *)(d + 0x8f8))->f0 = 1;
    }
}
