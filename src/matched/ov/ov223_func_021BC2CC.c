/*
 * function: func_021BC2CC
 * address: 0x021BC2CC
 * packet: pkt_ov223_021BC2CC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display blend register stores at 021BC2D2/021BC2D8.
 * symbols:
 *   func_021BB954 0x021BB954 thumb ov223
 *   func_021BADFC 0x021BADFC thumb ov223
 *   func_021BAD68 0x021BAD68 thumb ov223
 *   func_021BAA30 0x021BAA30 thumb ov223
 *   func_021BA050 0x021BA050 thumb ov223
 *   func_021B9A6C 0x021B9A6C thumb ov223
 * Original caller passes p in r0 to BAD68 despite its matched void prototype;
 * retain that visibly supplied input without editing the callee.
 */
extern void func_021BB954(char *);
extern void func_021BADFC(char *);
extern void func_021BAD68(char *);
extern void func_021BAA30(char *);
extern void func_021BA050(char *);
extern void func_021B9A6C(char *);
int func_021BC2CC(char *p)
{
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_021BB954(p); func_021BADFC(p); func_021BAD68(p);
    func_021BAA30(p); func_021BA050(p); func_021B9A6C(p);
    *(unsigned *)(p+0x10)=0;
    return 12;
}
