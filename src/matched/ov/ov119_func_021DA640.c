/*
 * function: func_021DA640
 * address: 0x021DA640
 * packet: pkt_ov119_021DA640
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021E1E00 0x021E1E00 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_02027A08 0x02027A08 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA318 0x021DA318 thumb ov119
 *   d_021E7594 0x021E7594 data a4
 */

typedef struct { int a,b; } Pair;
extern const Pair d_021E7594;
extern void func_021DF7AC(void *,int);
extern void func_021B6558(int,int,int);
extern void func_021E1410(void *,Pair *,int);
extern int func_021D8D4C(int,int,int,char *);
extern void func_021E1E00(void *,int,int);
extern void func_020307B0(int);
extern void func_0204B3DC(int,int);
extern void func_021D8C84(void *);
extern void func_021D8B38(void *);
extern int func_020355C4(void);
extern void func_02027A08(int,int);
extern void func_021D8E84(void *,int);
extern void func_021DA318(void *);
void func_021DA640(char *p) {
    Pair t;
    int n;
    int zero=0;
    func_021DF7AC(p,0);
    func_021B6558(*(int *)(p+0x9C0),1,0);
    func_021B6558(*(int *)(p+0x9C0),7,0);
    func_021B6558(*(int *)(p+0x9C0),9,1);
    t=d_021E7594;
    func_021E1410(p,&t,2);
    n=func_021D8D4C(*(int *)(p+0x828),*(int *)(p+0xF98),*(int *)(p+0xF94),p);
    *(int *)(p+0x10A0)=zero;
    func_021E1E00(p,0,n);
    func_020307B0(n);
    func_0204B3DC(*(int *)(p+0xF04),0);
    func_021D8C84(p);
    func_021D8B38(p);
    if(func_020355C4()) func_02027A08(*(int *)(p+0x64C),zero);
    else func_02027A08(*(int *)(p+0x64C),1);
    func_021D8E84(p,(int)func_021DA318);
}
