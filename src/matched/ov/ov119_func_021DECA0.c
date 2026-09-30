/*
 * function: func_021DECA0
 * address: 0x021DECA0
 * packet: pkt_ov119_021DECA0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4000 0x021E4000 thumb ov119
 *   func_021DF7D0 0x021DF7D0 thumb ov119
 *   func_021DF8E0 0x021DF8E0 thumb ov119
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021DD588 0x021DD588 thumb ov119
 *   func_021E4570 0x021E4570 thumb ov119
 *   func_021DD9DC 0x021DD9DC thumb ov119
 *   func_021E4888 0x021E4888 thumb ov119
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_02041570 0x02041570 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021E24E8 0x021E24E8 thumb ov119
 *   func_021E6B90 0x021E6B90 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEC4C 0x021DEC4C thumb ov119
 */
typedef unsigned short u16;
extern void func_021E4000(void *);
extern void func_021DF7D0(void *);
extern void func_021DF8E0(void *);
extern void func_021E64B8(void *);
extern void func_021DD588(void *);
extern void func_021E4570(void *);
extern void func_021DD9DC(unsigned char *);
extern void func_021E4888(void *);
extern void func_021DD528(char *,int);
extern void func_02041570(int,int);
extern void func_0204B3DC(int,int);
extern void func_021B6558(int,int,int);
extern void func_021B6548(int,int,int);
extern void func_021E24E8(void *,int);
extern void func_021E6B90(void *);
extern void func_0202208C(int,int,int,int,int,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DEC4C(void *);
void func_021DECA0(char *p) {
 func_021E4000(p);func_021DF7D0(p);func_021DF8E0(p);func_021E64B8(p);func_021DD588(p);func_021E4570(p);func_021DD9DC((unsigned char *)p);func_021E4888(p);
 func_021DD528(p,1);func_02041570(6,0);func_0204B3DC(*(int *)(p+0xf04),0);
 func_021B6558(*(int *)(p+0x9c0),1,1);func_021B6548(*(int *)(p+0x9c0),1,0);func_021E24E8(p,6);
 *(int *)(p+0x108c)=0;*(int *)(p+0x1084)=1;func_021E6B90(p);
 func_0202208C(0,1,1,0,6,1,*(u16 *)(p+0x5f4));func_021D8E84(p,(int)func_021DEC4C);
}
