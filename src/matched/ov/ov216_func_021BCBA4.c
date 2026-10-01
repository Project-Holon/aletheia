/*
 * function: func_021BCBA4
 * address: 0x021BCBA4
 * packet: pkt_ov216_021BCBA4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCF08 0x021BCF08 thumb ov216
 *   func_02165AC4 0x02165AC4 thumb ov010
 *   func_021BD174 0x021BD174 thumb ov216
 *   func_021BD0E4 0x021BD0E4 thumb ov216
 *   func_021BD448 0x021BD448 thumb ov216
 *   func_021BCD60 0x021BCD60 thumb ov216
 *   func_0203D34C 0x0203D34C arm
 */
extern void func_021BCF08(void *);
extern void func_02165AC4(void *,void *,void *,unsigned char);
extern void func_021BD174(void *,void *,unsigned short,unsigned char);
extern void func_021BD0E4(void *,unsigned char,int);
extern void func_021BD448(void *);
extern void func_021BCD60(void *);
extern void func_0203D34C(int,unsigned short);
void func_021BCBA4(unsigned char *p)
{
    func_021BCF08(p);
    func_02165AC4(*(void **)(p+0x24),*(void **)(p+0x28),p+0x2c,*(p+p[0x30]+0x31));
    func_021BD174(p,*(void **)(p+0x28),*(unsigned short *)(p+0x2c),p[0x2e]);
    func_021BD0E4(p,p[0x2e],1);
    func_021BD0E4(p,p[0x2e]^1,0);
    func_021BD448(p); func_021BCD60(p);
    func_0203D34C(0,*(unsigned short *)(p+2));
}
