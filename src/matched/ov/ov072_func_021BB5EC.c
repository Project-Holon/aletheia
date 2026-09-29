/*
 * function: func_021BB5EC
 * address:  0x021BB5EC
 * packet:   pkt_ov072_021BB5EC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 */
typedef unsigned int u32;

struct V { int x; int y; int z; };
struct Obj {
    struct V a;
    struct V b;
    int f18;
    int f1c;
    int f20;
    struct V c;
};

extern int func_02035D20(u32 *a, u32 *b);
extern int func_02035CB8(u32 *a, u32 *b);
extern void func_0207CA00(struct V *a, struct V *b, struct V *c);
extern int func_0207CBD0(struct V *a);

void func_021BB5EC(struct Obj *p)
{
    u32 y;
    u32 x;

    p->f1c = 0;
    if (func_02035D20(&y, &x)) {
        if (x <= 0xA8) {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
        return;
    }
    if (func_02035CB8(&y, &x)) {
        if (x <= 0xA8) {
            if (p->f20 != 0) {
                p->a = p->b;
                p->f20 = 0;
            }
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
            func_0207CA00(&p->b, &p->a, &p->c);
            if (func_0207CBD0(&p->c) >= 0x1000) {
                p->f1c = 1;
            }
        } else {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
    }
}
