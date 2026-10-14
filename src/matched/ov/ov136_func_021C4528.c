/*
 * function: MAILSYS_OnTouchMode
 * address:  0x021C4528
 * packet:   pkt_ov136_021C4528
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAILSYS_OnTouchMode 0x021C4528 thumb
 *   MAILSYS_ResetCursorBlend 0x021C44FC thumb
 */
typedef unsigned char  u8;
extern void MAILSYS_ResetCursorBlend(u8 *p);
int MAILSYS_OnTouchMode(void *a)
{
    MAILSYS_ResetCursorBlend(a);
    return 0;
}
