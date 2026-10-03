/*
 * function: func_021C9178
 * address: 0x021C9178
 * packet: pkt_ov093_021C9178
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C8828 0x021C8828 thumb ov093
 *   func_021C9240 0x021C9240 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C27A0 0x021C27A0 thumb ov093
 *   func_021C2910 0x021C2910 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 value; } S;
typedef struct { u32 low:8, index:5, pad:10, flag:1, high:8; u32 kind; S value; u8 a,b,c,id,d; u8 pad11[3]; u8 msg[36]; } Ent;
extern u8 *func_021B9934(void *, u8);
extern int func_021C8828(const void *);
extern int func_021C9240(void *, u8);
extern int func_021D5B68(void *);
extern int func_021C27A0(u8 *, u8 *, u8 *, u32, S, u8, u32);
extern void func_021C2910(u8 *, u8 *, u8 *, int, S, int, int, const void *);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
int func_021C9178(u8 *p, const Ent *e)
{
    u8 *a;
    u8 f;
    u8 *b;
    if (e->index != 31) a = func_021B9934(*(void **)(p + 8), e->index);
    else a = 0;
    f = func_021C8828(e->msg) == 0 && e->b == 0;
    if (func_021C9240(p + 0x1ab8, e->id)) {
        b = func_021B9934(*(void **)(p + 8), e->id);
        if (!func_021D5B68(b)) {
            if (!func_021C27A0(p, b, a, e->kind, e->value, e->d, e->a)) {
                if (e->flag) func_021C5A1C(p, a);
                func_021C2910(p, b, a, e->kind, e->value, f, e->c, e->msg);
                if (e->flag) func_021C5A34(p, a);
                return 1;
            }
        }
    }
    return 0;
}
