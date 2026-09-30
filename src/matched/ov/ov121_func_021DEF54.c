/*
 * function: func_021DEF54
 * address: 0x021DEF54
 * packet: pkt_ov121_021DEF54
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Ends at labelled function 021DEF6C.
 */
int func_021DEF54(char *p, int unused, int type)
{
    switch (type) {
    case 3:
    case 5:
    case 6:
        return *(int *)(p + 0x730);
    }
    return 0;
}
