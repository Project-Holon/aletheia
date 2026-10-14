/*
 * function: ZUKAN_DETAIL_HEADBAR_SetIconKind
 * address:  0x021BE82C
 * packet:   pkt_ov208_021BE82C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_HEADBAR_ClearIcon        0x021BE9C8  thumb
 *   ZUKAN_DETAIL_HEADBAR_DrawIcon  0x021BE920  thumb
 */

typedef unsigned int u32;

struct Ov208Icon {
    u32 pad0[3];
    int fc;
};

extern void ZUKAN_DETAIL_HEADBAR_ClearIcon(void);
extern void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon *p, int kind)
{
    p->fc = kind;
    ZUKAN_DETAIL_HEADBAR_ClearIcon();
    ZUKAN_DETAIL_HEADBAR_DrawIcon(p);
}
