/*
 * function: MAILSYS_HandleInput
 * address:  0x021C479C
 * packet:   pkt_ov136_021C479C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAILSYS_HandleInput 0x021C479C thumb
 *   MAILSYS_UpdateInputMode 0x021C4538 thumb
 *   MAILSYS_HandleKeyInput 0x021C45C0 thumb
 *   MAILSYS_HandleTouchInput 0x021C4700 thumb
 */
typedef unsigned char u8;
extern int MAILSYS_UpdateInputMode(u8 *p);
extern int MAILSYS_HandleKeyInput(u8 *p);
extern int MAILSYS_HandleTouchInput(u8 *p);
int MAILSYS_HandleInput(u8 *p)
{
    if (MAILSYS_UpdateInputMode(p)) return 0;
    if (p[0xA] == 1) return MAILSYS_HandleKeyInput(p);
    return MAILSYS_HandleTouchInput(p);
}
