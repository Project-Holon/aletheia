/*
 * function: func_021C4A3C
 * address:  0x021C4A3C
 * packet:   pkt_ov021_021C4A3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the field effect object above the owner's position and starts it.
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021DE478     0x021DE478  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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

extern int func_021AC1AC(u32 a);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u32 func_02050340(u32, u32, Desc *, u32, u32);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u16 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern u8 d_021DE478[];

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
    r->h8 = func_02050340(t, 0, &d, 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)t, r->h8, (u32)d_021DE478, 1);
    k = r->h8;
    func_0205082C((void *)t, k, 0);
    func_020507F0((void *)t, k, 1);
}
