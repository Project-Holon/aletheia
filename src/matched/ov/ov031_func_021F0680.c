/*
 * function: func_021F0680
 * address:  0x021F0680
 * packet:   pkt_ov031_021F0680
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMS_DRAW_IsPrintEnd  0x0202DC98  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_021F07AC  0x021F07AC  thumb  ov031
 *   func_021F09A0  0x021F09A0  thumb  ov031
 *   func_021F0AA0  0x021F0AA0  thumb  ov031
 *   func_020061E4  0x020061E4  thumb
 *   d_021F10D0     0x021F10D0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    char pad1[0x58 - 0x44];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

typedef struct {
    char pad[0x43C];
    int a;
    int n;
    int m;
} B;

struct Obj0202DC98;
struct PrintSys;
extern u32 PMS_DRAW_IsPrintEnd(struct Obj0202DC98 *o);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void *func_021BBC2C(void *r, int i);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F07AC(struct Obj *p, const u8 *e, u8 k);
extern void func_021F09A0(void *a, char *b);
extern void func_021F0AA0(void *a, char *b, int n);
extern void func_020061E4(u32 se);
extern const char d_021F10D0[];

/*
 * The 0/1 flag the loop tests (movs r0,#1 / movs r0,#0 / cmp r0,#0) is a
 * `!field` returned from an inline helper: the same test written in place,
 * as a ternary, an if/else local, or a helper returning `== 0` or a ternary,
 * all fold into a direct bne.
 */
static inline int slot_free(struct Obj *p, int i)
{
    u32 q = p->w40;
    if (p->s[i].f != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)p->s[i].h))) == 0) {
            func_02045334((struct Descriptor *)p->s[i].h);
            p->s[i].f = 0;
        }
    }
    return !p->s[i].f;
}

void func_021F0680(struct Obj *p, B *b)
{
    int flag;
    int i;
    int d;
    void *e;

    flag = 0;
    if (b->m == b->n)
        return;
    if (PMS_DRAW_IsPrintEnd((struct Obj0202DC98 *)p->w7c) == 0)
        return;
    for (i = 0; i < 3; i++) {
        if (p->b[i] == 1) {
            if (slot_free(p, i) == 0)
                return;
        }
    }
    if (b->a < 3) {
        for (i = b->m; i <= b->n; i++) {
            if (i > -1) {
                e = func_021BBC2C(b, i);
                if (e == 0)
                    func_02034714(d_021F10D0, 0, d_021F10D0);
                func_021F07AC(p, e, i);
            }
        }
    } else {
        d = b->n - b->m;
        if (((d < 0) ? -d : d) >= 3 || b->m < 2)
            func_021F09A0(p, (char *)b);
        else
            func_021F0AA0(p, (char *)b, d);
        flag = 1;
    }
    if (flag == 1)
        func_020061E4(0x548);
    b->m = b->n;
}
