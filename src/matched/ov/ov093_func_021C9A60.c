/*
 * function: func_021C9A60
 * address: 0x021C9A60
 * packet: pkt_ov093_021C9A60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C9BA8 0x021C9BA8 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C7B3C 0x021C7B3C thumb ov093
 *   func_021C7B7C 0x021C7B7C thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a; u8 pad8[4]; u8 msg[36]; } Ent;
extern u8 *func_021B9934(void *, u8);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C9BA8(u16);
extern int func_021D5B68(void *);
extern void func_021CD4B0(void *, u32, ...);
extern int func_021C99A0(void *, const void *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern void func_021C7B3C(u8 *, u32, u32, u32);
extern void func_021C7B7C(u8 *, int);
extern void func_021D8510(u8 *);
struct QJ;
extern void func_021D66D0(struct QJ *p, u32 v);
extern void *func_021D8484(void *);
extern int func_021D62C4(void *, int);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern void func_021C3FDC(u8 *, u8 *);
int func_021C9A60(u8 *p, const Ent *e)
{
    u8 *a;
    u16 x;
    int line;
    u32 s;
    u32 t;
    a = func_021B9934(*(void **)(p + 8), e->id);
    x = func_021D59B4(a, 16);
    if (func_021C9BA8(x)) return 0;
    if (func_021D5B68(a)) return 0;
    if (e->a || e->value != x) {
        if (e->flag) func_021CD4B0(*(void **)(p + 12), 87, (u8)e->index);
        func_021CD4B0(*(void **)(p + 12), 73, e->id, e->value);
        func_021C99A0(p, e->msg);
        line = 15561;
        s = func_021CC8D8(p + 0x1d74, line);
        func_021C7B3C(p, e->id, x, e->value);
        func_021CC95C(p + 0x1d74, s, line + 2);
        func_021D8510(a);
        func_021D66D0((struct QJ *)a, e->value);
        func_021CD4B0(*(void **)(p + 12), 29, e->id, e->value);
        func_021D8484(a);
        func_021CD4B0(*(void **)(p + 12), 88, e->id);
        if (x != e->value) {
            t = func_021CC8D8(p + 0x1d74, line + 16);
            func_021C7B7C(p, e->id);
            line += 18;
            func_021CC95C(p + 0x1d74, t, line);
        }
        if (e->flag) func_021CD4B0(*(void **)(p + 12), 88, (u8)e->index);
        if (!func_021D62C4(a, 16)) {
            if (x == 103) func_021C195C(p, a, 0);
            if (x == 127) func_021C3FDC(p, a);
        }
        return 1;
    }
    return 0;
}
