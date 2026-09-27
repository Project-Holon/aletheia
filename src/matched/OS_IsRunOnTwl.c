/*
 * function: OS_IsRunOnTwl
 * address:  0x02085D3C
 * packet:   pkt_02085D3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The two
 * function-scope statics live in the object's .bss, which the member
 * addresses through one section-relative pool word (0x02151244, the .bss
 * base, where OSi_IsNitroModeOnTwl's own static sits at +0); the struct below
 * is that section's layout as this function sees it.  0x04004000 is the
 * SCFG A9ROM register.
 *
 * symbols:
 *   g_02151244  0x02151244  data
 */

typedef struct OsSystemBss {
    int nitroModeOnTwl;
    int isTwl;
    int pad[5];
    int isChecked;
} OsSystemBss;

extern OsSystemBss g_02151244;

int OS_IsRunOnTwl(void)
{
    if (!g_02151244.isChecked) {
        unsigned char rom9 = *(volatile unsigned char *)0x04004000;
        g_02151244.isTwl = ((rom9 & 3) == 1) ? 1 : 0;
        g_02151244.isChecked = 1;
    }
    return g_02151244.isTwl;
}
