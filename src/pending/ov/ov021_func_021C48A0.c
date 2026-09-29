/*
 * function: func_021C48A0
 * address:  0x021C48A0
 * packet:   pkt_ov021_021C48A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Blockers: func_0205082C (0x0205082C) and func_020507F0 (0x020507F0) are
 * unlabelled arm9 leaves (Ilias's), no witness outside this range. Verified C,
 * both EXACT under --arm --region arm9 (func_020500A0 is the arm9 label at 0x020500A0):
 *     void func_020507F0(void *p, int idx, u32 v)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u32 *)(e + 24) = v; }
 *     void func_0205082C(void *p, int idx, u16 h)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u16 *)(e + 14) = h; func_020500A0(e); }
 * (taken from the header of ov021_func_0219C6B8.c, not re-verified here.)
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021DE464     0x021DE464  data  a4
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

typedef struct Src { u32 f0; V3 v; } Src;
typedef struct Res { u32 f0; u16 h4; } Res;
typedef struct Head { u8 pad[4]; u32 f4; u16 h8; } Head;

extern Src *func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, V3 *v);
extern u32 func_02050340(u32, u32, Desc *, u32, u32);
extern void func_021AC154(u32 a);
extern void func_02050804(u32, u32, u32, u32);
extern void func_0205082C(u32, u32, u32);
extern void func_020507F0(u32, u32, u32);
extern u8 d_021DE464[];

void func_021C48A0(u32 a, Res *r)
{
    Src *s = func_021AC1AC(a);
    Head *h;
    u32 t, k;
    Desc d;

    r->f0 = s->f0;
    func_021AC1CC(a, &s->v);
    h = (Head *)r->f0;
    t = h->f4;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = s->v;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h4 = func_02050340(t, 0, &d, 1, 3);
    if (r->h4 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804(t, r->h4, (u32)d_021DE464, 1);
    k = r->h4;
    func_0205082C(t, k, 0);
    func_020507F0(t, k, 1);
}
