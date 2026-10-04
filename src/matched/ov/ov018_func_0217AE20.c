/*
 * function: func_0217AE20
 * address:  0x0217AE20
 * packet:   pkt_ov018_0217AE20
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026454  0x02026454  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0217B968  0x0217B968  thumb  ov018
 *   func_0217BBD8  0x0217BBD8  thumb  ov018
 *   func_0217C11C  0x0217C11C  thumb  ov018
 *   func_0217BAB4  0x0217BAB4  thumb  ov018
 *   func_02175004  0x02175004  thumb  ov011
 *   func_02175598  0x02175598  thumb  ov011
 *   func_02167590  0x02167590  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   func_021679C4  0x021679C4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct SaveBlock;
struct Sub24;
struct Rec44;

typedef struct {
    int f0;
    u8 pad4[0x12];
    u16 lo : 9;
    u16 mode : 6;
    u16 hi : 1;
    u16 f18;
    u16 pad1a;
} Rec;

typedef struct {
    u8 a : 2;
    u8 state : 2;
    u8 rest : 4;
} Flags;

typedef struct {
    u8 pad0[8];
    int f8;
    u8 padc[0x78];
    u16 f84;
    u8 pad86[6];
    Rec recs[3];
    u8 padE0[0x81B];
    u8 f8fb;
    u8 pad8fc;
    u8 f8fd;
    u8 pad8fe[6];
    Flags f904;
    u8 pad905[0xB];
    u8 f910;
} Obj;

extern u32 func_02012138(const struct Ctx *p);
struct Work;
extern u32 func_02026474(void *obj);
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern u8 func_02012E40(const u8 *o);
extern u32 func_02026454(void *obj);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern u32 func_0200FB24(void);
extern u8 func_02012B70(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_0217B968(int a0, void *a1, void *a2, void *a3);
extern void func_0217BBD8(int a, int b, u8 *c);
extern int func_0217C11C(u32 value);
extern void func_0217BAB4(int a0, void *a1, void *a2, u8 *p);
extern void func_02175004(u8 *p);
extern u16 func_02175598(u8 *o, u32 id);
extern void func_02167590(void *a, struct Work *w);
extern int func_021677E4(void *p, int i);
extern void func_021675D0();
extern void func_02167848(char *a0, int a1, char *a2);
extern int func_021679C4(struct Work *w, int i);

void func_0217AE20(int a0, int a1, int a2)
{
    int h;
    Obj *p;
    void *ctx;
    int skip;
    int i;
    int r;

    h = func_02012138((const struct Ctx *)a1);
    p = (Obj *)func_02026474((void *)h);
    ctx = func_020120F4((const struct Ctx *)a1);
    if (func_02012E40(ctx) == 1)
        return;
    func_0217B968(a0, (void *)a1, (void *)h, (void *)a2);
    if (func_02026454((void *)h) != 2 || p == 0)
        return;
    h = func_02012AC8(func_020127A4(ctx));
    if (p->f910 == 0 && func_02013D5C(h) == 1)
        p->f910 = 1;
    func_0217BBD8(a0, a1, (u8 *)p);
    if (p->f8fd != 7 || func_0200FB24() != 0)
        return;
    if (func_02012B70(ctx) == 0) {
        if (p->f904.state == 0) {
            if (func_0217C11C(p->f84) == 1)
                p->f904.state = 1;
            else
                p->f904.state = 2;
        }
        if (p->f904.state == 2)
            return;
    }
    skip = func_02012B58(ctx);
    func_02175004((u8 *)p);
    func_02167590((void *)a1, (struct Work *)p->f8);
    for (i = 0; i < 3; i++) {
        if (i == skip || !(p->f8fb & (1 << i)))
            continue;
        if (func_021677E4((void *)p->f8, i) == 0) {
            func_02012950(ctx, i);
            r = func_02175598((u8 *)(&p->recs[i]), (u32)func_02012950(ctx, i));
            if (p->recs[i].f18 != 0 || func_02012B70(ctx) != 0)
                func_021675D0(p->f8, i, r, &p->recs[i]);
        } else {
            func_02167848((char *)p->f8, i, (char *)(&p->recs[i]));
            if (p->recs[i].f0 == 0) {
                if ((u16)(p->recs[i].mode + 0xFFFE) <= 1)
                    func_021679C4((struct Work *)p->f8, i);
            }
        }
    }
    func_0217BAB4(a0, (void *)a1, (void *)a2, (u8 *)p);
}
