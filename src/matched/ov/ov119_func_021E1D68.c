/*
 * function: func_021E1D68
 * address: 0x021E1D68
 * packet: pkt_ov119_021E1D68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D658 0x0207D658 arm
 *   func_021E3230 0x021E3230 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021E2438 0x021E2438 thumb ov119
 *   func_021E5958 0x021E5958 thumb ov119
 *   func_021E219C 0x021E219C thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021E5998 0x021E5998 thumb ov119
 *   func_021E3F30 0x021E3F30 thumb ov119
 *   func_021E2A98 0x021E2A98 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 */
extern void func_02040588(int,int);
extern void func_02043534(int);
extern void func_020435F4(int);
extern void func_0207D658(int,int,int);
extern void func_021E3230(void *);
extern void func_021E1098(void *);
extern void func_021E2438(char *,int);
extern void func_021E5958(void *);
extern void func_021E219C(void *,int,int,int);
extern int func_021D8AA8(void *);
extern void func_021E5998(void *);
extern void func_021E3F30(void *);
extern void func_021E2A98(void *,void *);
extern void func_020056A0(void (*)(void *,void *),void *,int);
extern void func_021B6558(int,int,int);
void func_021E1D68(char *p,int a)
{
    func_02040588(3,0);
    func_021E3230(p);
    func_021E1098(p);
    func_021E2438(p,0);
    func_021E2438(p,1);
    func_021E5958(p);
    func_021E219C(p,a,0,1);
    if(func_021D8AA8(p)==0) {
        func_021E5998(p);
        func_021E3F30(p);
        func_02043534(29);
        func_020435F4(31);
        func_0207D658(0x04001050,26,-8);
        p[0x11f9]=1;
        func_020056A0(func_021E2A98,p,0);
    }
    func_021B6558(*(int *)(p+0x9c0),1,1);
}
