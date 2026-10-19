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
 *   BG_SYS_ChangeScroll  0x02041EE4  arm
 */

typedef struct {
    char pad[0xfc];
    short hfc;
    short pad2;
    int f100;
} S;

typedef unsigned int   u32;
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);

void FIELD_MENU_ApplyBgScroll(S *s)
{
    if (s->f100 == 1) {
        BG_SYS_ChangeScroll(5, 3, -s->hfc);
        BG_SYS_ChangeScroll(6, 3, -5 - s->hfc);
        s->f100 = 0;
    }
}
