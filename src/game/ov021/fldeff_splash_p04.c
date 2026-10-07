/*
 * file:     fldeff_splash_p04.c
 * unit:     yes
 * function: func_021C4A10, func_021C4A3C, func_021C4AE8
 * address:  0x021C4A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA2C     0x021DAA2C  data  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021DE478     0x021DE478  data  a4
 */
struct Actor;
struct VecFx32;
struct BbActDesc;
struct BbActSys;
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} P2;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Pair { u32 f0; u32 f4; } Pair;

typedef struct Res { Pair p; u16 h8; } Res;

typedef struct Head { u8 pad[4]; u32 f4; u16 h8; } Head;

typedef struct {
    u32 *p;
    u32 f4;
    u16 id;
} S;

extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *fn, u32 c, u32 d, P2 *e, u32 f);
extern int func_021AC1AC(u32 a);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
void func_021C4A10(void *a, u32 b);
void func_021C4A3C(u32 a, Res *r);
void func_021C4AE8(void *a, S *s);
extern char d_021DAA2C[];
extern u8 d_021DE478[];


/*
 * Queues callback d_021DAA2C with a two-word argument block.
 */
void func_021C4A10(void *a, u32 b)
{
    P2 t;

    t.a = func_021ABEA0((u32)a, 8);
    t.b = b;
    func_021ABFA8(a, d_021DAA2C, 0, 0, &t, 0);
}


/*
 * Spawns the field effect object above the owner's position and starts it.
 */
void func_021C4A3C(u32 a, Res *r)
{
    Pair *s = (Pair *)func_021AC1AC(a);
    Head *h;
    u32 t, k;
    V3 pos;
    Desc d;

    r->p = *s;
    func_0216D88C((const struct Actor *)r->p.f4, (struct VecFx32 *)&pos);
    h = (Head *)r->p.f0;
    t = h->f4;
    pos.y -= 0xE000;
    pos.z -= 0xA000;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = pos;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h8 = func_02050340((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)t, r->h8, (u32)d_021DE478, 1);
    k = r->h8;
    func_0205082C((void *)t, k, 0);
    func_020507F0((void *)t, k, 1);
}


/*
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */
void func_021C4AE8(void *a, S *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}
