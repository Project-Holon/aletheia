/*
 * function: PLIST_MESSAGE_StreamCallback
 * address:  0x021BB910
 * packet:   pkt_ov091_021BB910
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int a, int b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern int GFL_USE_IsAnySeBusy(void);

int PLIST_MESSAGE_StreamCallback(int k)
{
    switch (k) {
    case 2:
        GFL_USE_SetBgmPaused((void *)1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56b);
        break;
    case 5:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPaused(0);
            return 0;
        }
        return 1;
    case 6:
        return GFL_USE_IsAnySeBusy();
    }
    return 0;
}
