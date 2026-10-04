/*
 * function: func_021C8FA4
 * address:  0x021C8FA4
 * packet:   pkt_ov093_021C8FA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D55D8  0x021D55D8  thumb  ov093
 *   func_021C6080  0x021C6080  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B7C(void *m);
extern int func_021D55D8(u8 *p, int i, int s);
extern void func_021C6080(u8 *p, u8 *a, int b, int c, int d);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 rest : 19;
    u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent;

int func_021C8FA4(int p, const Ent *e)
{
    u8 *a;
    int r;

    func_021B9934(*(char **)(p + 8), (u8)e->idx);
    a = func_021B9934(*(char **)(p + 8), e->b5);
    if (func_021D5B7C(a) || e->f7b) {
        r = !e->f7a;
        if (func_021D55D8(a, e->b6, r) == 0) {
            func_021C6080((u8 *)p, a, e->b6, e->b4, r);
            func_021C99A0((void *)p, (void *)((u8 *)e + 8));
            return 1;
        }
    }
    return 0;
}
