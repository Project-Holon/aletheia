/*
 * function: func_021BC398
 * address: 0x021BC398
 * packet: pkt_ov216_021BC398
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   d_021BDB4C 0x021BDB4C data a4
 */
typedef struct {unsigned char *f0;unsigned f4;int f8;unsigned fC,f10,f14;int f18,f1c;} A;
typedef struct R R;
extern const unsigned char d_021BDB4C[];
extern void func_02082BCC(void *,int,int);
extern R *func_021B62E0(A *,int);
R *func_021BC398(int manager,int heap){A a;enum {Zero} zero=Zero;func_02082BCC(&a,0,32);a.f0=(unsigned char *)d_021BDB4C;a.f4=3;a.f10=13;a.f14=11;a.f8=manager;a.fC=zero;a.f18=zero;return func_021B62E0(&a,heap);}
