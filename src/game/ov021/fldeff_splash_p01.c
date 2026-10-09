/*
 * file:     fldeff_splash_p01.c
 * unit:     yes
 * function: func_021C48A0, func_021C4938, func_021C4954, func_021C4974, func_021C4978, func_021C49AC
 * address:  0x021C48A0
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021DE464     0x021DE464  data  a4
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_021C49C0  0x021C49C0  thumb  ov021
 *   d_021DE47C     0x021DE47C  data  ov021
 *   func_021C4A00  0x021C4A00  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
struct BbActDesc;
struct BbActSys;
struct P;
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

typedef struct {
    u32 *p;
    u16 id;
} S;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R;

typedef signed int     s32;

extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, V3 *v);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern void func_021C49C0(struct P *p);
extern void func_021C4A00(void *p);
extern u32 func_020307B0(void *p);
void func_021C48A0(u32 a, Res *r);
void func_021C4938(void *a, S *s);
void func_021C4954(void *a, S *s);
void func_021C4974(void);
R *func_021C4978(u8 *owner, u32 heap);
void func_021C49AC(u32 a, u8 *p);
extern u8 d_021DE464[];
extern char d_021DE47C[];




/*
 * func_0205082C and func_020507F0 are witnessed by
 * src/matched/arm9/func_0205082C.c and src/matched/arm9/func_020507F0.c.
 */
void func_021C48A0(u32 a, Res *r)
{
    Src *s = (Src *)func_021AC1AC(a);
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
    r->h4 = func_02050340((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h4 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)t, r->h4, (u32)d_021DE464, 1);
    k = r->h4;
    func_0205082C((void *)t, k, 0);
    func_020507F0((void *)t, k, 1);
}





/*
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */
void func_021C4938(void *a, S *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}





void func_021C4954(void *a, S *s)
{
    u32 tmp;

    if (func_020508EC((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        func_021AC154((u32)a);
}



void func_021C4974(void) {}



/*
 * Allocates the 0xC-byte field-object record (second kind) and initialises
 * it.
 */
R *func_021C4978(u8 *owner, u32 heap)
{
    R *r = func_02030734(heap, 0xC, 1, d_021DE47C, 0x7D);

    r->owner = owner;
    r->obj = func_02188C90((u8 *)func_021ABE14(owner));
    func_021C49C0((struct P *)r);
    return r;
}



/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C49AC(u32 a, u8 *p)
{
    func_021C4A00(p);
    func_020307B0(p);
}
