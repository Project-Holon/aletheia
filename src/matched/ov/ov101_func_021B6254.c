/*
 * function: func_021B6254
 * address: 0x021B6254
 * packet: pkt_ov101_021B6254
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203D0DC 0x0203D0DC arm
 */
extern int func_0203D0DC(int);
int func_021B6254(int *p)
{
    if (p[30] != 0) return 1;
    switch(p[17]) {
    case 0:
        func_0203D0DC(0);
        p[17] = 1;
        p[33] = 1;
        p[20] = 0;
        p[19] = 0;
        break;
    case 1:
        if(p[20] != 0) {
            p[33] = 0;
            p[17] = 2;
        }
        break;
    case 2:
        p[17] = 0;
        return 1;
    }
    return 0;
}
