/*
 * function: func_0205B2F8
 * address:  0x0205B2F8
 * packet:   pkt_0205B2F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * notes:    code bytes identical; the ABS32 literal SOCLiConfigPtr (0x021A1CD8) has no witness outside 0205B2F8..0205B33C (only an ov009 pool word refers to it)
 *
 * sdk:      CloseSocket (close.o)
 *
 * symbols:
 *   func_0215ED60 0x0215ED60 arm
 *   func_0215FA90 0x0215FA90 arm
 *   g_021A1CD8 0x021A1CD8 data
 */

extern int func_0215ED60(void);
extern int func_0215FA90(void);
extern void *g_021A1CD8;

int func_0205B2F8(void)
{
    int result;

    if (g_021A1CD8 == 0)
        return 1;
    if (func_0215ED60() != 0)
        return 0;
    result = func_0215FA90();
    if (result == 0 || result == -39)
        return 1;
    return 0;
}
