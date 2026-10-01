/*
 * function: func_02185D08
 * address: 0x02185D08
 * packet: pkt_ov219_02185D08
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
static inline int absolute(int a)
{
    return a<0?-a:a;
}
void func_02185D08(int *p)
{
    if(p[0]>=0) p[0]%=65535;
    else p[0]+=(absolute(p[0])/65535+1)*65535;
    if(p[1]>=0) p[1]%=65535;
    else p[1]+=(absolute(p[1])/65535+1)*65535;
}
