/*
 * function: func_02194834
 * address:  0x02194834
 * packet:   pkt_ov009_02194834
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerOpString (gstats.o)
 *
 * symbols:
 *   func_021937D0 0x021937D0  arm
 *   g_021ADFE0   0x021ADFE0  data
 */

extern void *func_021937D0(void *set, char *name, int type, void *initialvalue);
extern int g_021ADFE0[];

void *func_02194834(int *game, char *name, void *(*func)(void *, char *, void *), void *value)
{
    void *ret;

    if (game == 0)
        game = (int *)g_021ADFE0[3];
    if (game == 0)
        return value;
    ret = func((void *)game[3], name, value);
    if (ret != 0)
        return ret;
    return func_021937D0((void *)game[3], name, 2, value);
}
