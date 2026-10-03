/*
 * function: func_021948F0
 * address:  0x021948F0
 * packet:   pkt_ov009_021948F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TeamOpFloat (gstats.o)
 *
 * symbols:
 *   func_021946F4 0x021946F4  arm
 *   OS_SPrintf   0x02084F40  arm
 *   func_021947C0 0x021947C0  arm
 *   g_021A590C   0x021A590C  data
 */

extern int func_021946F4(int *game, int tnum);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern double func_021947C0(void *game, char *name, void *func, double value, int index);
extern char g_021A590C[];

double func_021948F0(void *game, char *name, void *func, double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, g_021A590C, name, func_021946F4(game, index));
    return func_021947C0(game, fullname, func, value, index);
}
