/*
 * function: func_02194A14
 * address:  0x02194A14
 * packet:   pkt_ov009_02194A14
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
 *   func_02194724 0x02194724  arm
 *   OS_SPrintf   0x02084F40  arm
 *   func_021947C0 0x021947C0  arm
 *   g_021A5914   0x021A5914  data
 */

extern int func_02194724(void *game, int pnum);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern double func_021947C0(void *game, char *name, void *func, double value, int index);
extern char g_021A5914[];

double func_02194A14(void *game, char *name, void *func, double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, g_021A5914, name, func_02194724(game, index));
    return func_021947C0(game, fullname, func, value, index);
}
