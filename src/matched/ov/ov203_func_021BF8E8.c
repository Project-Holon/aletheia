/*
 * function: func_021BF8E8
 * address: 0x021BF8E8
 * packet: pkt_ov203_021BF8E8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203101C 0x0203101C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02012FFC 0x02012FFC thumb
 */
struct Tcbl;struct GfFont;
extern struct Tcbl *func_0203101C(unsigned,unsigned short,unsigned,unsigned);
extern struct GfFont *func_0201D7EC(int,int,int,int,unsigned);
extern void *func_020490F4(unsigned,unsigned short);
extern signed char func_02012FFC(void);
void func_021BF8E8(char *p){*(struct Tcbl **)(p+0x20)=func_0203101C(*(unsigned short *)p,*(unsigned short *)p,16,128);*(struct GfFont **)(p+0x24)=func_0201D7EC(23,0,0,0,*(unsigned short *)p);*(void **)(p+0x28)=func_020490F4(161,*(unsigned short *)p);p[0x18]=func_02012FFC();}
