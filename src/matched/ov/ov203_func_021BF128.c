/*
 * function: func_021BF128
 * address: 0x021BF128
 * packet: pkt_ov203_021BF128
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   func_021BF168 0x021BF168 thumb ov203
 */
extern int func_021BF7AC(char *,int);
extern void func_021BF168(char *,unsigned char,signed char,signed char,signed char,int,int);
void func_021BF128(char *p,int unused,int *s)
{
    int a,b;
    a=func_021BF7AC(p,s[4]);b=func_021BF7AC(p,s[5]);
    func_021BF168(p,s[0],s[1],s[2],s[3],a,b);
}
