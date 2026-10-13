/*
 * function: FLDEFF_BUBBLE_Draw
 * address:  0x021D07D8
 * packet:   pkt_ov021_021D07D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDEFF_BUBBLE_DrawBubble  0x021D08D8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;

typedef struct S {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S;

struct Row;
extern void FLDEFF_BUBBLE_DrawBubble(struct Row *r, int a);

void FLDEFF_BUBBLE_Draw(void *a, S *s)
{
    int i;

    for (i = 0; i < 6; i++) {
        FLDEFF_BUBBLE_DrawBubble((struct Row *)s->rows[i], s->f0[7]);
    }
}
