/*
 * function: SetBottomScreenLineCentered
 * address:  0x021EF91C
 * packet:   pkt_ov093_021EF91C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SetBottomScreenLineCentered (libdwcgscommon/screen.o): forwards the global
 * bottom-screen descriptor and all three parameters to SetScreenLineCentered;
 * the fourth argument rides in r3 across the BL.
 *
 * symbols:
 *   func_021EFC1C  0x021EFC1C  thumb  ov093
 *   gBottomScreen  0x021F63F4  data   ov093  a4
 */

extern char gBottomScreen;
extern void func_021EFC1C(void *screen, int line, int color, char *text);

void SetBottomScreenLineCentered(int line, int color, char *text)
{
    func_021EFC1C(&gBottomScreen, line, color, text);
}
