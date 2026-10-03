/*
 * function: func_021C091C
 * address: 0x021C091C
 * packet: pkt_ov093_021C091C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C19D8 0x021C19D8 thumb ov093
 *   func_021C0A1C 0x021C0A1C thumb ov093
 *   func_021C71E0 0x021C71E0 thumb ov093
 *   func_021C14E0 0x021C14E0 thumb ov093
 *   func_021C0A2C 0x021C0A2C thumb ov093
 *   func_021C1194 0x021C1194 thumb ov093
 *   func_021C0A3C 0x021C0A3C thumb ov093
 *   func_021C0F24 0x021C0F24 thumb ov093
 *   func_021C0D90 0x021C0D90 thumb ov093
 *   func_021C2048 0x021C2048 thumb ov093
 *   func_021C1A54 0x021C1A54 thumb ov093
 *   func_021BFBD0 0x021BFBD0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[5]; u8 a:1; u8 b:1; };
extern void func_021C19D8(u8 *, u8 *, u8 *);
extern void func_021C0A1C(u8 *);
extern int func_021C71E0(u8 *, u8 *, u32, u8 *);
extern void func_021C14E0(u8 *, u8 *, int, u8 *);
extern int func_021C0A2C(u8 *);
extern u8 func_021C1194(u8 *p);
extern int func_021C0A3C(u8 *);
extern u32 func_021C0F24(u8 *, u8 *, u8 *, u8 *, u32);
extern u32 func_021C0D90(u8 *, u8 *, u8 *, u8 *, u32, u32 *, u32);
extern void func_021C2048(u8 *, u8 *, u32, u32);
extern void func_021C1A54(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern void func_021BFBD0(u8 *, u32, u8 *, u32);
void func_021C091C(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 d)
{
    u32 result = 0;
    int flag = 0;
    u32 out;
    p[0x1fe9] = 0;
    func_021C19D8(p, a, q);
    func_021C0A1C(*(u8 **)(p + 0x860));
    func_021C71E0(p, a, *(u16 *)q, *(u8 **)(p + 0x4b4));
    func_021C14E0(p, a, (int)q, b);
    if (func_021C0A2C(b) != 0) {
        if (func_021C1194(*(u8 **)(p + 0x4b4)) != 0 && func_021C0A3C(b) == 1) {
            result = func_021C0F24(p, q, a, b, c);
        } else {
            result = func_021C0D90(p, q, a, b, c, &out, d);
            flag = 1;
        }
        func_021C2048(p, a, *(u16 *)q, result);
    }
    func_021C1A54(p, q, a, *(u8 **)(p + 0x860), result, d);
    if (flag != 0) {
        struct State *s = *(struct State **)(p + 0x4a8);
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        func_021BFBD0(p, *(u16 *)q, *(u8 **)(p + 0x4a8), out);
    }
}
