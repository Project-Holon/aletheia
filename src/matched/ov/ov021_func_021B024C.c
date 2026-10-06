/*
 * function: func_021B024C
 * address:  0x021B024C
 * packet:   pkt_ov021_021B024C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_0215A77C  0x0215A77C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern void *func_02158F74(void *p);
extern u32 func_0215A60C(u8 *p);
extern u32 func_0215A77C(u32, u32, u32, u32, u32, u32, u32, u32, u32);

int func_021B024C(Ctx *c, u32 b)
{
    u8 *q;
    u32 v2, r;
    void *t0;
    void *t1;
    u8 v0, v1, v3;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 0, r, (u32)func_02158F74(t0), func_0215A60C((u8 *)b));
    return 1;
}
