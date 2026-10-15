/*
 * function: LOCAL_TVT_SYS_ProcMain
 * address:  0x021B6C5C
 * packet:   pkt_021B6C5C
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   LOCAL_TVT_SYS_Main  0x021B622C  thumb  ov174
 */

typedef unsigned char  u8;
extern int LOCAL_TVT_SYS_Main(u8 *p);

int LOCAL_TVT_SYS_ProcMain(int a, int b, int c, int d)
{
    return LOCAL_TVT_SYS_Main((u8 *)d) == 1;
}
