/*
 * function: VIEWER_MAIN_UpdateInput
 * address:  0x021C56E8
 * packet:   pkt_ov111_021C56E8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_CheckInputHeld  0x021C5008  thumb  ov111
 *   VIEWER_MAIN_HandlePageTouch  0x021C555C  thumb  ov111
 *   VIEWER_MAIN_CheckTouch  0x021C5B80  thumb  ov111
 *   VIEWER_MAIN_HandleInput  0x021C567C  thumb  ov111
 *   VIEWER_MAIN_HandleKey  0x021C5054  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work;

extern int VIEWER_MAIN_CheckInputHeld(Work *p);
extern void VIEWER_MAIN_HandlePageTouch(Work *p);
extern void VIEWER_MAIN_CheckTouch(Work *p);
extern int VIEWER_MAIN_HandleInput(Work *p);
extern int VIEWER_MAIN_HandleKey(Work *p);

int VIEWER_MAIN_UpdateInput(Work *p)
{
    VIEWER_MAIN_CheckInputHeld(p);
    VIEWER_MAIN_HandlePageTouch(p);
    VIEWER_MAIN_CheckTouch(p);
    if (p->mode == 1) {
        return VIEWER_MAIN_HandleInput(p);
    }
    return VIEWER_MAIN_HandleKey(p);
}
