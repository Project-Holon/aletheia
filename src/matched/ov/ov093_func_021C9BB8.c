/*
 * function: func_021C9BB8
 * address: 0x021C9BB8
 * packet: pkt_ov093_021C9BB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C7A54 0x021C7A54 thumb ov093
 *   func_021C7AA0 0x021C7AA0 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C2250 0x021C2250 thumb ov093
 *   func_021D6738 0x021D6738 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a,b,c; u8 padA[2]; u8 msg[36]; } Ent;
extern u8 *func_021B9934(char *p, int i);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern int func_021C7A54(u8 *, u8 *, u32);
extern void func_021C7AA0(u8 *, u8 *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C99A0(void *, const void *);
extern void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
extern void func_021D6738(u8 *);
extern void func_021C195C(u8 *, u8 *, u32);
int func_021C9BB8(u8 *p, const Ent *e)
{
    u8 *a;
    int line;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(*(void **)(p + 8), e->id);
    if (e->index != e->id) {
        line = 15615;
        s = func_021CC8D8(p + 0x1d74, line);
        f = func_021C7A54(p, a, e->value);
        func_021CC95C(p + 0x1d74, s, line + 2);
        if (f) {
            t = func_021CC8D8(p + 0x1d74, line + 6);
            func_021C7AA0(p, a);
            func_021CC95C(p + 0x1d74, t, line + 8);
            return 0;
        }
    }
    if (e->flag) func_021CD4B0(*(void **)(p + 12), 87, (u8)e->index);
    func_021C99A0(p, e->msg);
    func_021C2250(p, a, e->value, 0);
    if (e->flag) func_021CD4B0(*(void **)(p + 12), 88, (u8)e->index);
    if (e->a) {
        func_021D6738(a);
        func_021CD4B0(*(void **)(p + 12), 43, e->id);
    }
    if (e->b) {
        func_021D6738(func_021B9934(*(void **)(p + 8), e->c));
        func_021CD4B0(*(void **)(p + 12), 43, e->c);
    }
    func_021C195C(p, a, 0);
    return 1;
}
