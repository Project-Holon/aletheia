/*
 * function: func_021BA0A8
 * address: 0x021BA0A8
 * packet: pkt_ov091_021BA0A8
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: preserve duplicated branch bodies for cross-jumping; parenthesize
 *   (base + scaled index) + field offset for the indexed actor load.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021BA65C 0x021BA65C thumb ov091
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB9AC 0x021BB9AC thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021B7B98 0x021B7B98 thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021BA4E4 0x021BA4E4 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern u32 func_021BA65C(u8 *p, u16 id);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(u8 *,void *);
extern int func_021BDC5C(u8 *,void *);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021BDC3C(u32 p, void *m);
extern void func_021BDCA0(u32 p, void *m);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B7B98(u8 *);
extern void func_021B9E20(u8 *p);
extern void func_021B9E3C(void);
extern void func_021BA4E4(u8 *p);
#define W(k) (*(u32 *)(p+(k)))
#define S (*(u8 **)(p+0x280))
void func_021BA0A8(u8 *p,int action)
{
    u32 old;
    int a,b;
    if (action == 0xe) {
        old = func_02017E1C((void *)W(0x38),6,0);
        if (func_021BA65C(p,old) == 0x3e7) {
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                func_021BB7A4(p,(u32 *)W(0x150));
                func_021B9788(p,0x3f,1,(int)func_021B9E20);
            } else {
                p[0xc] = 0x13;
                func_021BB7A4(p,(u32 *)W(0x150));
                func_021B9788(p,0x3f,1,(int)func_021B9E3C);
            }
        } else if (func_0202136C(*(u16 *)(S+0x44)) == 1) {
            *(u32 *)(S+0x3c) = W(0x2c);
            p[0xc] = 0x13;
            *(int *)(S+0x40) = 6;
        } else {
            func_021BB7A4(p,(u32 *)W(0x150));
            func_021BA624(p,(void *)W(0x38),*(u16 *)(S+0x44));
            func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            func_021BC24C(p,(void *)W(0x38),(u16)(*(u16 *)(S+0x44)));
            func_021BC288((int)p,(int)((void *)W(0x38)),*(u16 *)(S+0x44));
            a = func_021BDBF8(p,(void *)W(0x38));
            b = func_021BDC5C(p,(void *)W(0x38));
            func_021BB97C((u16 *)p,W(0x150));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
            func_021BB9AC((int)p,(u32)W(0x150),(u32)2,(u16)(*(u16 *)(S+0x44)));
            if (*(int *)(S+0x34) == 0xa) {
                *(int *)(S+0x34) = 0;
                if (a == 1) {
                    func_021BDC3C((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 1;
                } else if (b == 1) {
                    func_021BDCA0((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 2;
                } else {
                    func_021B9788(p,0x40,1,(int)func_021B9E20);
                }
            } else {
                *(int *)(S+0x40) = 0xa;
                if (a == 1) {
                    func_021BDC3C((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 1;
                } else if (b == 1) {
                    func_021BDCA0((u32)p,(void *)W(0x38));
                    func_021B9788(p,0x40,1,(int)func_021BA4E4);
                    W(0x264) = 2;
                } else {
                    func_021B9788(p,0x40,1,(int)func_021B9E3C);
                }
            }
            func_021BB98C(p,W(0x150));
        }
    } else {
        if (*(int *)(S+0x34) == 0xa) {
            *(int *)(S+0x34) = 0;
            func_021BB7A4(p,(u32 *)W(0x150));
            p[0xc] = 2;
            func_021B7B98(p);
        } else p[0xc] = 0x13;
    }
}
