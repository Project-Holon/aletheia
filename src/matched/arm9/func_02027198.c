/*
 * function: func_02027198
 * address:  0x02027198
 * packet:   pkt_02027198
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146940  0x02146940  data
 *   func_02012EBC    0x02012EBC  thumb
 *   func_0200C0F0    0x0200C0F0  thumb
 *   func_02045A98    0x02045A98  arm
 *   func_0200C1F4    0x0200C1F4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Inner {
    u8  pad00[0x20];
    u16 arr[8];         /* 0x20 */
    u8  pad30[0x2e];
    u8  f5e;            /* 0x5e */
};

struct Outer {
    u32 f00;
    struct Inner in;
};

extern struct Outer *g_02146940;

struct Big;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sv);
extern u16 func_02045A98(void);
extern u16  *func_0200C1F4(u32 a0);

void func_02027198(void)
{
    struct Outer *g = g_02146940;
    struct Inner *in;
    u16 *q;
    u32 v;
    u32 t;
    int i;

    in = &g->in;
    t = (u32)func_0200C0F0(func_02012EBC((void *)g->f00));
    v = func_02045A98();
    q = func_0200C1F4(t);
    for (i = 0; i < 8; i++) {
        in->arr[i] = q[i];
        if (q[i] == v) {
            break;
        }
    }
    in->f5e = 1;
}
