/*
 * function: func_021BD8E4
 * address: 0x021BD8E4
 * packet: pkt_ov091_021BD8E4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDBE0 0x021BDBE0 thumb ov091
 *   func_021B7040 0x021B7040 thumb ov091
 *   func_021B6F0C 0x021B6F0C thumb ov091
 *   func_021BBA54 0x021BBA54 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BDBE0(unsigned int p);
extern void func_021B7040(unsigned p);
extern void func_021B6F0C(void *p);
extern void func_021BBA54(unsigned short *a, u32 b);
typedef unsigned short u16;
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E3C(char *p);
extern void func_021B9E20(u8 *);
#define W(o) (*(u32 *)(p+(o)))
void func_021BD8E4(u8 *p)
{
    void (*cb)(u8 *);
    func_021BDBE0((unsigned int)p);
    func_021B7040((unsigned int)p);
    func_021B6F0C(p);
    func_021BBA54((short unsigned int *)p,W(0x150));
    if (W(0x264) == 1) {
        cb = (void (*)(u8 *))func_021B9E3C;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = func_021B9E20;
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)cb);
        func_021BB98C(p,W(0x150));
    } else if (W(0x264) == 2) {
        cb = (void (*)(u8 *))func_021B9E3C;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = func_021B9E20;
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)cb);
        func_021BB98C(p,W(0x150));
    } else if (W(0x264) == 3) {
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)func_021B9E3C);
        func_021BB98C(p,W(0x150));
    } else {
        p[0xc] = 0x13;
    }
}
