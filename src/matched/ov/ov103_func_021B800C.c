/*
 * function: func_021B800C
 * address: 0x021B800C
 * packet: pkt_ov103_021B800C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B831C 0x021B831C thumb ov103
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };
extern void func_021B831C(void *p);
extern void func_02082BCC(void *, int, int);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern int func_020457B0(int, u16);
extern void func_02045334(void *);
extern void func_02045374(int);
extern int func_02045730(int);
extern void func_020409B4(int);
void func_021B800C(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    func_02082BCC(p, 0, 20);
    p->f10 = 15;
    p->f0 = func_020450F0(a, b, c, d, e, f, 1);
    p->fC = func_020457B0(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    func_021B831C(p);
    q = p->f0;
    func_02045334((void *)q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}
