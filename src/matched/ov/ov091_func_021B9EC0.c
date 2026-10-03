/*
 * unit:     yes
 * function: func_021B9EC0
 * function: func_021B9F34
 * address:  0x021B9EC0
 * packet:   pkt_ov091_021B9EC0
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
 *   func_021BB9CC  0x021BB9CC  thumb ov091
 *   func_021B9788  0x021B9788  thumb ov091
 *   func_021BB98C  0x021BB98C  thumb ov091
 *   func_021B9E3C  0x021B9E3C  thumb ov091
 *   func_021B9F34  0x021B9F34  thumb ov091
 *   func_021B9804  0x021B9804  thumb ov091
 *   func_021B9F44  0x021B9F44  thumb ov091
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void func_021BB7A4(u8 *p, u32 obj);
extern void func_021BB97C(u8 *p, u32 obj);
extern void func_021BB9CC(u8 *p, u32 obj, u32 a, u32 b);
extern void func_021B9788(u8 *p, u32 id, u32 flag, void (*cb)());
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E3C();
extern void func_021B9F34();
extern void func_021B9804(u8 *p, void (*cb)());
extern void func_021B9F44(u8 *p, u32 state);

void func_021B9EC0(u8 *p, u32 state)
{
    func_021BB7A4(p, W(0x150));
    if (state == 14) {
        u32 *q = (u32 *)W(0x280);
        if (q[0x34 / 4] == 5 || q[0x34 / 4] == 8) {
            q[0x40 / 4] = 5;
        } else {
            q[0x40 / 4] = 4;
        }
        func_021B9788(p, 0x27, 1, func_021B9E3C);
        return;
    }
    func_021BB97C(p, W(0x150));
    func_021BB9CC(p, W(0x150), 1, *(u16 *)(W(0x280) + 0x46));
    func_021B9788(p, 0x23, 0, func_021B9F34);
    func_021BB98C(p, W(0x150));
}

void func_021B9F34(u8 *p)
{
    func_021B9804(p, func_021B9F44);
}
