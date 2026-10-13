/*
 * function: SCRCMD_PROC_FLD_PrintListText
 * address:  0x021B44CC
 * packet:   pkt_ov021_021B44CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void SCRCMD_PROC_FLD_PrintListText(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g)
{
    if (d <= 8) {
        PRINTSYS_PrintColor((void *)b, c, d, (void *)e, (void *)f, g);
    } else {
        PRINTSYS_PrintQueColor(a, b, (s16)c, (s16)d, e, f, (u32)g);
    }
}
