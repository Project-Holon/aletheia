/*
 * function: func_0219F634
 * address:  0x0219F634
 * packet:   pkt_ov021_0219F634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; blocked only by unlabelled leaves with no witness outside
 * this range. Four are arm9 (Ilias's), so the overlay leaf is not filed:
 *   func_0205082C, func_02050848, func_02050880, func_02050080 (arm9, arm):
 *     C verified in src/pending/ov/ov021_func_0219F2B0.c and
 *     ov021_func_0219F188.c headers.
 *   func_0216D678 (ov010, thumb, unlabelled; ov009 overlaps):
 *     u16 func_0216D678(u8 *p) { return *(u16 *)(p + 0x2a); }
 *     (`ldrh r0, [r0, #0x2a]; bx lr`, not compiled here)
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

extern E *func_0216D6F0(u32);
extern u32 func_0216D910(u32);
extern u32 func_0219C9DC(u32);
extern u32 func_0219FFD4(u32);
extern u32 func_0216D678(u32);
extern void func_0205082C(u32, u32, u32);
extern void func_0205085C(u32, u32, u32);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void func_02197CCC(u32, Vec *);
extern void func_0219FFBC(u32, Vec *);
extern u32 func_02050848(u32, u32);
extern u32 func_02050880(u32, u32);
extern void func_0219F628(u32, u32, u32, Vec *);
extern u32 func_0216D67C(u32);
extern u32 func_0216D534(u32);
extern u32 func_02188C58(u32);
extern u32 func_0218EC2C(u32);
extern void func_0219F5D4(u32, Vec *, Vec *);
extern void func_0207C9D0(Vec *, Vec *, Vec *);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, Vec *);

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
    e = func_0216D6F0(o);
    if (e->id == 0xFFFF) {
        return;
    }
    h = func_0219C9DC(func_0216D910(o));
    a = func_0219FFD4(o);
    b = func_0216D678(o);
    c = a + b * 4;
    if (a != e->b4 || e->b5 != b) {
        e->b4 = a;
        flag = 1;
        e->b5 = b;
        func_0205082C(h, e->id, c);
        func_0205085C(h, e->id, 0);
    }
    func_021A000C(o, h, e->id, flag, 1);
    func_02197CCC(o, &pos);
    func_0219FFBC(o, &pos);
    x = func_02050848(h, e->id);
    func_0219F628(o, x, func_02050880(h, e->id), &d);
    pos.x += d.x;
    pos.y += d.y;
    pos.z += d.z;
    if (e->b2 == 0) {
        tmp = d_021D854C;
        func_0219F5D4(func_0218EC2C(func_02188C58(func_0216D534(func_0216D67C(o)))), &tmp, &tmp);
        func_0207C9D0(&pos, &tmp, &pos);
    } else {
        pos.y -= 0xC000;
        pos.z += 0x8000;
    }
    func_0204F638(func_02050080(h), e->id, &pos);
}
