/*
 * function: GPOWER_EVENT_FlashMain
 * address:  0x021F542C
 * packet:   pkt_ov083_021F542C
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned int u32;

typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int  FADE_IsActive(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int GPOWER_EVENT_FlashMain(int a0, int *p)
{
    switch (*p) {
    case 0:
        FADE_Start(4, 10, 16, 4);
        GFL_USE_PlaySeDefaultVolume(0x5E0);
        (*p)++;
        break;
    case 1:
        if (FADE_IsActive() != 0)
            break;
        FADE_Start(4, 16, 0, 8);
        (*p)++;
    case 2:
        if (FADE_IsActive() != 0)
            break;
    default:
        return 1;
    }
    return 0;
}
