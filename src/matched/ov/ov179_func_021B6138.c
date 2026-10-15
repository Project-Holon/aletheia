/*
 * function: CDEMO_MAIN_Update
 * address:  0x021B6138
 * packet:   pkt_021B6138
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CDEMO_WIPE_RunScript  0x021B6380  thumb  ov179
 */

extern int CDEMO_WIPE_RunScript(char *p);

int CDEMO_MAIN_Update(int a, int b, int c, int d)
{
    if (CDEMO_WIPE_RunScript((char *)d))
        return 0;
    return 1;
}
