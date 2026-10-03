/*
 * function: func_021C9CC0
 * address: 0x021C9CC0
 * packet: pkt_ov093_021C9CC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: truncated accessor results live in u32 locals; u16 locals rotate seven spill offsets.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C7A54 0x021C7A54 thumb ov093
 *   func_021C7AA0 0x021C7AA0 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C2250 0x021C2250 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u8 id,pad5[3]; u8 msg[108]; } Ent;
extern u8 *func_021B9934(void *, u8);
extern int func_021D5B40(u8 *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern int func_021C7A54(u8 *, u8 *, u32);
extern void func_021C7AA0(u8 *, u8 *);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern int func_021C99A0(void *, const void *);
extern void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
int func_021C9CC0(u8 *p, const Ent *e)
{
    u8 *a;
    u8 *b;
    u16 x;
    u16 y;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(*(void **)(p + 8), e->id);
    b = func_021B9934(*(void **)(p + 8), e->index);
    x = (u16)func_021D5B40(b);
    y = (u16)func_021D5B40(a);
    s = func_021CC8D8(p + 0x1d74, 15671);
    f = func_021C7A54(p, a, x);
    func_021CC95C(p + 0x1d74, s, 15673);
    if (f) {
        t = func_021CC8D8(p + 0x1d74, 15676);
        func_021C7AA0(p, a);
        func_021CC95C(p + 0x1d74, t, 15678);
        return 0;
    }
    if (e->flag) func_021C5A1C(p, b);
    func_021C99A0(p, e->msg);
    func_021C99A0(p, e->msg + 36);
    func_021C99A0(p, e->msg + 72);
    if (e->flag) func_021C5A34(p, b);
    func_021C2250(p, b, y, 0);
    func_021C2250(p, a, x, 0);
    func_021C195C(p, b, 0);
    func_021C195C(p, a, 0);
    return 1;
}
