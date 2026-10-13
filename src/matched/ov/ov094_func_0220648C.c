/*
 * function: func_0220648C
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
 *   func_02206B58  0x02206B58  thumb  ov094
 *   func_02206B30  0x02206B30  thumb  ov094
 */

typedef unsigned int u32;

extern unsigned int KEY_GetRepeat(void);
extern void func_02206B58(char *p);
extern void func_02206B30(char *p);

int func_0220648C(char *p)
{
    u32 k = KEY_GetRepeat();

    if (k & 2) {
        func_02206B58(p);
        return 2;
    }
    if (k & 0x20) {
        func_02206B30(p);
        return 0;
    }
    if (k & 0x10) {
        func_02206B30(p);
        return 1;
    }
    return -1;
}
