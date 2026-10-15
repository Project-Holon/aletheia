/*
 * function: SHINKA_DEMO_PrintStreamCallback
 * address:  0x02205360
 * packet:   pkt_02205360
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 */

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_IsAnySeBusy(void);

int SHINKA_DEMO_PrintStreamCallback(int a)
{
    switch (a) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56b);
        break;
    case 5:
        return GFL_USE_IsAnySeBusy();
    }
    return 0;
}
