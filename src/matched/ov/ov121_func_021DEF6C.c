/*
 * function: func_021DEF6C
 * address: 0x021DEF6C
 * packet: pkt_ov121_021DEF6C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes at 021DEFAA before labelled 021DEFAC.
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_021DEFAC 0x021DEFAC thumb ov121
 */
extern unsigned short func_02045A98(void);
extern int func_021DEFAC(void *, void *, unsigned short);
int func_021DEF6C(char *p, void *a, unsigned short b)
{
    int count = 0;
    int found = 1;
    int i;
    for (i = 0; i < 253; i++) {
        if (*(unsigned short *)(p + i * 2 + 0xd0) == func_02045A98()) found = 0;
    }
    if (found) count++;
    return count + func_021DEFAC(p, a, b);
}
