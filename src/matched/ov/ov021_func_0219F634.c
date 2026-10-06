/*
 * function: func_0219F634
 * address:  0x0219F634
 * packet:   pkt_ov021_0219F634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 *   func_0219F628  0x0219F628  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0219F5D4  0x0219F5D4  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   d_021D854C     0x021D854C  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec;

typedef struct {
    u16 id;
    u8  b2;
    u8  b3;
    u8  b4;
    u8  b5;
} E;

extern const Vec d_021D854C;

struct Trip;
extern void *func_0216D6F0(void *p);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern u32 func_0219FFD4(u32);
extern u16 func_0216D678(void *p);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_0205085C(void *p, int idx, u32 v);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_0219FFBC(u32 a, u32 *p);
extern u16 func_02050848(u8 *p, int i);
extern u16 func_02050880(u8 *p, int i);
extern int func_0219F628(u32 a, u32 b, u32 c, u32 d);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_0219F5D4(u32 a, s32 *b, s32 *c);
extern void func_0207C9D0(Vec *, Vec *, Vec *);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);

void func_0219F634(u32 o)
{
    E *e;
    u32 h;
    u32 a;
    u32 b;
    u16 c;
    Vec pos;
    Vec d;
    Vec tmp;
    u32 flag;
    u32 x;

    flag = 0;
    e = func_0216D6F0((void *)o);
    if (e->id == 0xFFFF) {
        return;
    }
    h = func_0219C9DC((u8 *)func_0216D910(o));
    a = func_0219FFD4(o);
    b = func_0216D678((void *)o);
    c = a + b * 4;
    if (a != e->b4 || e->b5 != b) {
        e->b4 = a;
        flag = 1;
        e->b5 = b;
        func_0205082C((void *)h, e->id, c);
        func_0205085C((void *)h, e->id, 0);
    }
    func_021A000C(o, h, e->id, flag, 1);
    func_02197CCC((u8 *)o, (s32 *)(&pos));
    func_0219FFBC(o, (u32 *)(&pos));
    x = func_02050848((u8 *)h, e->id);
    func_0219F628(o, x, func_02050880((u8 *)h, e->id), (u32)(&d));
    pos.x += d.x;
    pos.y += d.y;
    pos.z += d.z;
    if (e->b2 == 0) {
        tmp = d_021D854C;
        func_0219F5D4(func_0218EC2C(func_02188C58((void *)func_0216D534(func_0216D67C((void *)o)))), (s32 *)(&tmp), (s32 *)(&tmp));
        func_0207C9D0(&pos, &tmp, &pos);
    } else {
        pos.y -= 0xC000;
        pos.z += 0x8000;
    }
    func_0204F638((u8 *)func_02050080((u32 *)h), e->id, (struct Trip *)(&pos));
}
