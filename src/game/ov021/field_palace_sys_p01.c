/*
 * file:     field_palace_sys_p01.c
 * unit:     yes
 * function: func_021D1164, func_021D1194, func_021D11B0, func_021D11D8, func_021D11F4, func_021D1254, func_021D1264, func_021D13F0, func_021D1400, func_021D1418, func_021D1430
 * address:  0x021D1164
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
 *   d_021DE684     0x021DE684  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_020414AC  0x020414AC  arm
 *   func_021D1488  0x021D1488  thumb  ov021
 *   func_02030EAC  0x02030EAC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0204384C  0x0204384C  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049238  0x02049238  arm
 *   d_021DB97C     0x021DB97C  data    ov021  a4
 *   func_020437AC  0x020437AC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   d_021DB984     0x021DB984  data  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02040588  0x02040588  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02045768  0x02045768  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_02040B1C  0x02040B1C  arm
 */
#include "../../matched/include/Obj04299.h"
#include "../../matched/include/Obj01509.h"
#include "../../matched/include/Obj18372.h"
#include "../../matched/include/Obj18373.h"

struct Anim021D1488;
struct Node;
struct Bmp;
struct Ctx;
struct Sub0200852CObj;
struct Obj020437AC;
struct Obj00020;
struct CharBuf;
struct Light;
struct VecFx32;
struct Descriptor;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } V;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_020414AC(int a);
extern void *func_020056A0(void *, void *, int);
extern void func_021D1488(void *task, struct Anim021D1488 *p);
extern void func_02030EAC(struct Node *n);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049238(void *h);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048AD0(struct Light *l);
extern void func_02048B30(u32 l, V *out);
extern void func_02048AE8(u32 l, V *out);
extern void func_0207CA00(const V *a, const V *b, V *c);
extern void func_0207CCA4(const V *a, V *b);
extern void func_0207CAE8(const V *a, const V *b, V *c);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_0206DF3C(V *a, int *x, int *y);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02040588(u32, u32);
extern void func_02041B6C(u32 bit);
extern void func_02045374(struct Cfg *cfg);
extern void func_020456F8(struct Descriptor *d);
extern u16 func_02045768(struct Descriptor *p);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
void *func_021D1164(u32 heap, u32 v);
int func_021D1194(void *a);
void func_021D11B0(u32 *p);
void func_021D11D8(u32 *p);
void func_021D11F4(u32 *p, u32 b);
u32 func_021D1254(u32 a);
void func_021D1264(u8 *p);
u32 func_021D13F0(u32 a);
int func_021D1400(void *a);
int func_021D1418(void *a);
void func_021D1430(u8 *p, u32 n);
extern char d_021DE684[];
extern const u32 d_021DB97C[];
extern const V d_021DB984;


void *func_021D1164(u32 heap, u32 v)
{
    u32 *p = func_02030734(heap, 0x1c, 1, d_021DE684, 0x8f);

    p[0] = v;
    func_021D11F4(p, heap);
    func_021D1264((u8 *)p);
    return p;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1194(void *a)
{
func_021D11D8((u32 *)a);
func_021D13F0((u32)a);
func_021D1254((u32)a);
return func_020307B0(a);
}


void func_021D11B0(u32 *p)
{
    func_020414AC(3);
    p[5] = 0;
    func_021D1400(p);
    p[3] = (u32)func_020056A0(func_021D1488, p, 0x80);
}


void func_021D11D8(u32 *p)
{
    if (p[3] != 0) {
        func_02030EAC((struct Node *)p[3]);
        p[3] = 0;
        func_021D1418(p);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D11F4(u32 *p, u32 b)
{
    void *h = func_020490F4(200, b);
    u32 idx;

    idx = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(func_02188C80((void *)p[0]))));
    p[4] = (u32)func_0204384C(200, 0, 0, b);
    func_02049BDC(h, 1, 0, d_021DB97C[idx] << 5, 0x120, 0x20, b);
    func_02049238(h);
}


u32 func_021D1254(u32 a)
{
func_020437AC((struct Obj020437AC *)(((struct Obj04299 *)((u8 *)(a)))->f10));
((struct Obj04299 *)((u8 *)(a)))->f10 = 0;
return 0;
}


void func_021D1264(u8 *p)
{
    V pos;
    V d;
    V f;
    V s;
    V u;
    V at;
    V eye;
    int x;
    int y;
    void *o;
    u32 cam;

    o = func_02188CB4(((struct Obj01509 *)p)->f0);
    cam = func_0218EC2C(func_02188C58((void *)(*(u32 *)&((struct Obj01509 *)p)->f0)));
    func_02048AD0((struct Light *)cam);
    func_02048B30(cam, &eye);
    func_02048AE8(cam, &at);
    func_0207CA00(&eye, &at, &d);
    f = d;
    f.y = 0;
    func_0207CCA4(&f, &f);
    func_0207CAE8(&f, &d_021DB984, &s);
    func_0207CAE8(&d, &s, &u);
    func_0207CCA4(&u, &u);
    func_021A3038(o, (struct VecFx32 *)&pos);
    pos.x += (int)(((long long)u.x * -0x1C000 + 0x800) >> 12);
    pos.y += (int)(((long long)u.y * -0x1C000 + 0x800) >> 12);
    pos.z += (int)(((long long)u.z * -0x1C000 + 0x800) >> 12);
    func_0206DF3C(&pos, &x, &y);
    x -= 0x10;
    y -= 0x18;
    ((struct Obj01509 *)p)->f8 = x % 8;
    ((struct Obj01509 *)p)->fA = y % 8;
    x /= 8;
    y /= 8;
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x > 0x1F) {
        x = 0x1F;
    }
    if (y > 0x18) {
        y = 0x18;
    }
    ((struct Obj01509 *)p)->f4 = func_020450F0(3, (u8)x, (u8)y, 5, (u32)5, (u32)9, (u32)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01509 *)p)->f4)), 0);
    func_02045334((struct Descriptor *)((struct Obj01509 *)p)->f4);
    func_021D1430(p, 0);
}


u32 func_021D13F0(u32 a)
{
func_020452E8((struct Descriptor *)(((struct Obj04299 *)((u8 *)(a)))->f4));
((struct Obj04299 *)((u8 *)(a)))->f4 = 0;
return 0;
}


int func_021D1400(void *a)
{
func_02045374((struct Cfg *)(((struct Obj18372 *)((u8 *)(a)))->f4));
func_02041B6C(3);
return func_02040588(3, 1);
}


int func_021D1418(void *a)
{
func_020456F8((struct Descriptor *)(((struct Obj18373 *)((u8 *)(a)))->f4));
func_02041B6C(3);
return func_02040588(3, 0);
}


void func_021D1430(u8 *p, u32 n)
{
    u32 a = func_02045768((struct Descriptor *)(((struct Obj01509 *)p)->f4));
    u32 b = (u32)func_02045770((struct Descriptor *)((struct Obj01509 *)p)->f4);
    u32 x;
    u32 y;

    func_020439A0((struct Bmp *)(((struct Obj01509 *)p)->f10), (struct Bmp *)b, 0, n << 5, ((struct Obj01509 *)p)->f8, ((struct Obj01509 *)p)->fA, 0x20, 0x20, 0xFFFF);
    x = (u32)func_020437D4((const struct Bmp *)b);
    y = func_020437EC((const struct Bmp *)b);
    func_02040B1C(3, (const void *)x, y, a);
}
