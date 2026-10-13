/*
 * function: FISHING_StepCounter
 * address:  0x021C5FA8
 * packet:   pkt_ov021_021C5FA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (saves no lr) after FISHING_EventMain's pool; its only caller
 * is FISHING_EventMain.  Frame counter at +0x60: true once it passes n, then
 * rewinds.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x60];
    u32 f60;
} Work;

int FISHING_StepCounter(Work *w, u32 n)
{
    if (w->f60++ < n)
        return 0;
    w->f60 = 0;
    return 1;
}
