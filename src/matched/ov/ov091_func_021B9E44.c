/*
 * unit:     yes
 * function: func_021B9E44, func_021B9EB0
 * address:  0x021B9E44
 * packet:   pkt_ov091_021B9E44
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA65C  0x021BA65C  thumb ov091
 *   func_021BB7A4  0x021BB7A4  thumb ov091
 *   func_021B7B98  0x021B7B98  thumb ov091
 *   func_021BB97C  0x021BB97C  thumb ov091
 *   func_021BB9AC  0x021BB9AC  thumb ov091
 *   func_021B9788  0x021B9788  thumb ov091
 *   func_021BB98C  0x021BB98C  thumb ov091
 *   func_021B9E3C  0x021B9E3C  thumb ov091
 *   func_021B9804  0x021B9804  thumb ov091
 *   func_021B9EC0  0x021B9EC0  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern u32 func_021BA65C(u8 *p, u16 id);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021B7B98(u8 *p);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E3C(char *p);
extern void func_021B9804(u8 *p, int a1);
extern void func_021B9EC0(u8 *p, u32 state);

void func_021B9E44(u8 *p)
{
    if (func_021BA65C(p, *(u16 *)(W(0x280) + 0x44))) {
        func_021BB7A4(p, (u32 *)W(0x150));
        p[0xc] = 2;
        func_021B7B98(p);
        return;
    }
    func_021BB7A4(p, (u32 *)W(0x150));
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB9AC((int)p, W(0x150), 0, *(u16 *)(W(0x280) + 0x44));
    func_021B9788(p, 0xb3, 1, (int)func_021B9E3C);
    func_021BB98C(p, W(0x150));
}

void func_021B9EB0(u8 *p)
{
    func_021B9804(p, (int)func_021B9EC0);
}
