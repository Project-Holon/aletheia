/*
 * function: BTLV_INPUT_ProcessKeyRepeat
 * address:  0x0220648C
 * packet:   pkt_ov094_0220648C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetRepeat  0x0203633C  arm
 *   BTLV_INPUT_PlayCursorSe  0x02206B58  thumb  ov094
 *   BTLV_INPUT_PlaySelectSe  0x02206B30  thumb  ov094
 */

typedef unsigned int u32;

extern unsigned int KEY_GetRepeat(void);
extern void BTLV_INPUT_PlayCursorSe(char *p);
extern void BTLV_INPUT_PlaySelectSe(char *p);

int BTLV_INPUT_ProcessKeyRepeat(char *p)
{
    u32 k = KEY_GetRepeat();

    if (k & 2) {
        BTLV_INPUT_PlayCursorSe(p);
        return 2;
    }
    if (k & 0x20) {
        BTLV_INPUT_PlaySelectSe(p);
        return 0;
    }
    if (k & 0x10) {
        BTLV_INPUT_PlaySelectSe(p);
        return 1;
    }
    return -1;
}
