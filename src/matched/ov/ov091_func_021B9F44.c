/*
 * function: func_021B9F44
 * address:  0x021B9F44
 * packet:   pkt_ov091_021B9F44
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb ov091
 *   func_021BB97C  0x021BB97C  thumb ov091
 *   func_021BB99C  0x021BB99C  thumb ov091
 *   func_021BB9CC  0x021BB9CC  thumb ov091
 *   func_021B9788  0x021B9788  thumb ov091
 *   func_021BB98C  0x021BB98C  thumb ov091
 *   func_021BC6C0  0x021BC6C0  thumb ov091
 *   func_021B9E3C  0x021B9E3C  thumb ov091
 *   func_021B9EB0  0x021B9EB0  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void func_021BB7A4(void *p, u32 *s);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC6C0(char *p);
extern void func_021B9E3C(char *p);
extern void func_021B9EB0(u8 *p);

void func_021B9F44(u8 *p, u32 state)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (state == 14) {
        *(u32 *)(W(0x280) + 0x40) = 10;
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
        if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
            func_021B9788(p, 0x26, 1, (int)func_021BC6C0);
        } else {
            func_021B9788(p, 0x26, 1, (int)func_021B9E3C);
        }
        func_021BB98C(p, W(0x150));
        return;
    }
    func_021BB97C((u16 *)p, W(0x150));
    func_021BB99C((int)p, W(0x150), 0, W(0x38));
    func_021BB9CC((int)p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    func_021B9788(p, 0x20, 0, (int)func_021B9EB0);
    func_021BB98C(p, W(0x150));
}
