/*
 * function: FIELD_MENU_ShowItemWindow
 * address:  0x021A9294
 * packet:   pkt_ov021_021A9294
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef struct {
    int f0;
    int f4;
} S;

struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *a);

void FIELD_MENU_ShowItemWindow(int a, S *s)
{
    if (s->f0 == 1) {
        BMP_WIN_TransferChars((struct Descriptor *)s->f4);
    }
}
