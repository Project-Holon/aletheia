/*
 * function: FIELD_MENU_ApplyBgScroll
 * address:  0x021A8840
 * packet:   pkt_ov021_021A8840
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02041EE4  0x02041EE4  arm
 */

typedef struct {
    char pad[0xfc];
    short hfc;
    short pad2;
    int f100;
} S;

typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);

void FIELD_MENU_ApplyBgScroll(S *s)
{
    if (s->f100 == 1) {
        func_02041EE4(5, 3, -s->hfc);
        func_02041EE4(6, 3, -5 - s->hfc);
        s->f100 = 0;
    }
}
