/*
 * function: func_02172CB0
 * address:  0x02172CB0
 * packet:   pkt_ov011_02172CB0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * recoup 2026-10-05: the old draft (196 B, c as u8* with c[0x8fd]) failed on register
 * colours and a second pool load of 0x8fd. Typed parameters closed it to 192 B, all bytes equal:
 * b as a struct with the byte at 0x0E, c as a struct with the step byte at 0x8FD (written
 * c->step = 3 / 4 in each arm, no local v), callee types from matched twins (func_02026478 and
 * func_02030734 return u32, func_02012E40 takes const u8 *). The only open item is the pool
 * word func_02173568: the leaf is filed at src/matched/ov/ov011_func_02173568.c (EXACT);
 * the integrator needs a shard for it, then this file is EXACT.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02030734  0x02030734  arm
 *   func_02158590  0x02158590  thumb  ov010
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203D10C  0x0203D10C  arm
 *   func_0203CFF0  0x0203CFF0  arm
 *   func_02173568  0x02173568  thumb  ov011
 *   d_02177000     0x02177000  data  ov011
 *   d_021768C8     0x021768C8  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 w[28];
} T70;

typedef struct Param {
    void *field00;
    void *field04;
    u8 pad08[6];
    u8 field0e;
} Param;

typedef struct Work {
    u8 pad[0x8fd];
    u8 step;
} Work;

extern char d_02177000[];
extern const T70 d_021768C8;

extern u32 func_02026478(void *obj);
extern u8 func_02012E40(const u8 *o);
typedef unsigned short u16;
struct Req;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02158590(void *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_020307B0(void *p);
extern int func_0203D10C(int a0);
extern void func_0203CFF0(void *p);
extern void func_02173568(u8 *w);

int func_02172CB0(int *a, Param *b, Work *c)
{
    u8 *h;
    T70 *p;

    h = (u8 *)func_02026478(b->field04);
    if (func_02012E40(h) == 1)
        return 0;
    switch (*a) {
    case 0:
        p = (T70 *)func_02030734(0x8005, 0x70, 0, d_02177000, 0xcf);
        *p = d_021768C8;
        if (b->field0e == 1) {
            if (func_02158590(h) == 0)
                *((u8 *)p + 0x60) = 2;
        }
        func_0203CBAC((struct Req *)p, (u32)func_02173568, (u32)c);
        func_020307B0(p);
        *a = *a + 1;
        break;
    case 1:
        if (c->step >= 2) {
            if (b->field0e == 1) {
                func_0203D10C(0);
                c->step = 3;
            } else {
                func_0203CFF0((u8 *)b + 8);
                c->step = 4;
            }
            return 1;
        }
        break;
    }
    return 0;
}
