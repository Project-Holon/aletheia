/*
 * function: func_021DDF28
 * address: 0x021DDF28
 * packet: pkt_ov119_021DDF28
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76E4 0x021E76E4 data a4
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDED4 0x021DDED4 thumb ov119
 */
typedef struct { int a,b; } Pair;
extern const Pair d_021E76E4;
typedef unsigned int   u32;
extern int func_021E12AC(char *p);
extern void func_021E1410(void *,Pair *,int);
extern void func_02043534(u32 planes);
extern void func_021B6558(int,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DDED4(unsigned char *p);
void func_021DDF28(char *p)
{
    if(func_021E12AC(p)) {
        Pair t=d_021E76E4;
        func_021E1410(p,&t,2);
        func_02043534(31);
        func_021B6558(*(int *)(p+0x9c0),1,0);
        func_021D8E84(p,(int)func_021DDED4);
    }
}
