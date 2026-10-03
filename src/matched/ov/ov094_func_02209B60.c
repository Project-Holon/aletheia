/*
 * function: func_02209B60
 * address:  0x02209B60
 * packet:   pkt_ov094_02209B60
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The f24 store is written out in both arms (the cross-jumped-tail idiom):
 * then-arm `str` is cross-jumped onto the else-arm copy, giving beq/b/movs.
 *
 * symbols:
 *   d_0220AC10     0x0220AC10  data   ov094  a4
 *   func_02209C18  0x02209C18  thumb  ov094
 *   func_02209C30  0x02209C30  thumb  ov094
 *   func_0204B324  0x0204B324  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA00  0x0204BA00  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *h;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u16 f2c;
} P;

typedef struct {
    u16 x;
    u16 y;
    u32 rest[5];
} Cfg;

typedef struct {
    u16 a;
    u16 b;
    void *p;
    void *cb;
} Msg;

extern Cfg d_0220AC10;
extern void func_02209C18(P *p);
extern void func_02209C30(void *p);
extern void *func_0204B324(u32 a, u32 b, u32 c, u32 d, Cfg *cfg, int n, u16 v);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204BA00(void *h, Msg *m);

int func_02209B60(P *p, u16 a, u16 b, u32 c, u32 e, u32 f)
{
    Cfg cfg = d_0220AC10;
    Msg msg;

    if (p->f28 != 0)
        return 0;
    if (p->h != 0) {
        func_02209C18(p);
        p->h = 0;
    }
    cfg.x = a;
    cfg.y = b;
    p->h = func_0204B324(p->f0, p->fc, p->f10, p->f14, &cfg, 1, p->f2c);
    func_0204B878(p->h, 0);
    func_0204B8C4(p->h, 0);
    func_0204B92C(p->h, 1);
    func_0204B3DC(p->h, 1);
    if (c != 0)
        p->f1c = c;
    else
        p->f1c = 1;
    if (f != 0)
        p->f24 = f;
    else
        p->f24 = 1;
    p->f18 = 0;
    p->f20 = e;
    p->f28 = 0;
    msg.p = p;
    msg.a = 0;
    msg.b = 0;
    msg.cb = (void *)func_02209C30;
    func_0204BA00(p->h, &msg);
    return 1;
}
