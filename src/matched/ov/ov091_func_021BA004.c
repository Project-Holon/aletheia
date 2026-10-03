/*
 * unit:     yes
 * function: func_021BA004
 * function: func_021BA098
 * address:  0x021BA004
 * packet:   pkt_ov091_021BA004
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
 *   func_021BA60C  0x021BA60C  thumb ov091
 *   func_021BB98C  0x021BB98C  thumb ov091
 *   func_021BA5E0  0x021BA5E0  thumb ov091
 *   func_021BC6C0  0x021BC6C0  thumb ov091
 *   func_021B9E3C  0x021B9E3C  thumb ov091
 *   func_021B9804  0x021B9804  thumb ov091
 *   func_021BA0A8  0x021BA0A8  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void func_021BB7A4(u8 *p, u32 obj);
extern void func_021BB97C(u8 *p, u32 obj);
extern void func_021BB99C(u8 *p, u32 obj, u32 a, u32 b);
extern void func_021BB9CC(u8 *p, u32 obj, u32 a, u32 b);
extern void func_021B9788(u8 *p, u32 id, u32 flag, void (*cb)());
extern void func_021BA60C(u8 *p, u32 v);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BA5E0(u8 *p, u32 v, u32 w);
extern void func_021BC6C0(char *p);
extern void func_021B9E3C();
extern void func_021B9804(u8 *p, void (*cb)());
extern void func_021BA0A8(u8 *p, int action);

void func_021BA004(u8 *p)
{
    func_021BB7A4(p, W(0x150));
    func_021BB97C(p, W(0x150));
    func_021BB99C(p, W(0x150), 0, W(0x38));
    func_021BB9CC(p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    if (*(u32 *)(W(0x280) + 0x34) == 5 || *(u32 *)(W(0x280) + 0x34) == 8) {
        func_021B9788(p, 0x29, 1, func_021BC6C0);
    } else {
        func_021B9788(p, 0x29, 1, func_021B9E3C);
        func_021BA60C(p, W(0x38));
        *(u32 *)(W(0x280) + 0x40) = 10;
    }
    func_021BB98C(p, W(0x150));
    func_021BA5E0(p, W(0x38), *(u8 *)(W(0x280) + 0x48));
}

void func_021BA098(u8 *p)
{
    func_021B9804(p, func_021BA0A8);
}
