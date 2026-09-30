/*
 * function: func_021B87E8
 * address: 0x021B87E8
 * packet: pkt_ov105_021B87E8
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
int func_021B87E8(unsigned a, int *p)
{
    int limit, result;
    if (a == 100) { limit = 65535; result = 5; }
    else if (a >= 80) { limit = 100; result = 4; }
    else if (a >= 60) { limit = 80; result = 3; }
    else if (a >= 30) { limit = 60; result = 2; }
    else if (a > 0) { limit = 30; result = 1; }
    else if (a == 0) { limit = 0; result = 0; }
    else { limit = 100; result = 1; }
    if (p) *p = (int)(a + 3) > limit ? 1 : 0;
    return result;
}
