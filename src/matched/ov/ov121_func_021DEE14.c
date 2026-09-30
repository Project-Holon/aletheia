/*
 * function: func_021DEE14
 * address: 0x021DEE14
 * packet: pkt_ov121_021DEE14
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DFC00 0x021DFC00 data a4
 */
extern int d_021DFC00[];
void func_021DEE14(char *p, int *state, int value)
{
    d_021DFC00[1] = 0;
    d_021DFC00[3] = 0;
    *(int *)(p + 0x708) = value;
    *(int *)(p + 0x72c) = 0;
    *state = 100;
}
