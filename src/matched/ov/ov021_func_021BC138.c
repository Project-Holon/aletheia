/*
 * function: func_021BC138
 * address:  0x021BC138
 * packet:   pkt_ov021_021BC138
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 *
 * The u16 `slot` local is what truncates func_020507D0's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 *
 * symbols:
 *   func_02050080  0x02050080  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020507D0  0x020507D0  arm
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021BC340  0x021BC340  thumb  ov021
 *   func_021BC338  0x021BC338  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_0204F638  0x0204F638  arm
 *   func_020508C4  0x020508C4  arm
 *   func_0204F5E4  0x0204F5E4  arm
 *   func_0204F604  0x0204F604  arm
 *   func_0204F654  0x0204F654  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F684  0x0204F684  arm
 *   func_0204F794  0x0204F794  arm
 *   func_0204F748  0x0204F748  arm
 *   func_0204F764  0x0204F764  arm
 *   d_021D9B40     0x021D9B40  data  a4
 *   d_021D9B58     0x021D9B58  data  a4
 *   d_021D9B4C     0x021D9B4C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            fx32;

typedef struct { fx32 x, y, z; } Vec;

typedef struct {
    u8 pad0[7];
    u8 f7;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 padC[0x14 - 0xC];
    u32 *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Param;

extern const fx32 d_021D9B40[];
extern const fx32 d_021D9B58[];
extern const fx32 d_021D9B4C[];

extern u32 func_02050080(u32 a);
extern int func_0216D7A8(u32 a, int b);
extern u32 func_021ABE14(u32 a);
extern u16 func_02188C9C(u32 a);
extern int func_020507D0(u32 a, u16 b);
extern void func_020507A0(u32 a, u32 id, u32 x);
extern void func_020507F0(u32 a, u32 id, u32 x);
extern Info *func_0216E3C4(u32 a);
extern void func_0216D88C(u32 a, Vec *v);
extern void func_0216D8B0(u32 a, Vec *v);
extern int func_02163E58(u32 a, Vec *v, int *y);
extern void func_0216D8D0(u32 a, Vec *v);
extern u32 func_0216D7DC(u32 a);
extern u32 func_021AB0F8(u32 a);
extern int func_021BC340(int a, int b);
extern int func_021BC338(u32 a);
extern u32 func_02188C58(u32 a);
extern u32 func_0218EC2C(u32 a);
extern void func_02048B30(u32 cam, Vec *out);
extern void func_0204F638(u32 h, u32 id, Vec *v);
extern u32 func_020508C4(u32 a, u16 b);
extern void func_0204F5E4(u32 h, u32 i, s16 *v);
extern void func_0204F604(u32 h, u32 i, s16 *v);
extern void func_0204F654(u32 h, u32 i, s16 *v);
extern void func_0204F66C(u32 h, u32 i, s16 *v);
extern void func_0204F684(u32 h, u32 i, s16 *a, s16 *b);
extern void func_0204F794(u32 h, u32 i, u32 *v);
extern u32 func_0204F748(u32 h, u32 i);
extern void func_0204F764(u32 h, u32 i, u32 *v);

void func_021BC138(u16 id, Param *p)
{
    Vec v;
    Vec w;
    Vec u;
    int y;
    u32 flag;
    s16 rot[4];
    u16 kind;
    u32 h2;
    u32 h;
    int idx;
    u32 obj;
    Info *info;
    u32 i1;
    u32 i2;
    u16 slot;

    h2 = p->f24;
    h = func_02050080(h2);
    idx = func_0216D7A8(p->f1C, 0);
    if (id == 0xFFFF) {
        return;
    }
    kind = func_02188C9C(func_021ABE14(*p->f14));
    slot = func_020507D0(h2, idx);
    func_020507A0(h2, id, slot);
    func_020507F0(h2, id, 0);
    obj = p->f1C;
    info = func_0216E3C4(obj);
    func_0216D88C(obj, &v);
    v.z += d_021D9B40[info->f7];
    func_0216D8B0(obj, &w);
    v.x += w.x;
    v.z -= w.z;
    if (func_02163E58(obj, &v, &y) == 1) {
        v.y = y;
    }
    v.y += d_021D9B58[p->f18];
    func_0216D8D0(obj, &w);
    v.x += w.x;
    v.y -= w.y;
    v.z -= w.z;
    v.y += d_021D9B4C[info->f7];
    if (info->f7 == 2) {
        if (func_021AB0F8(func_0216D7DC(obj)) & 0x40) {
            v.y -= 0x3800;
        } else {
            v.y -= 0x8000;
        }
    }
    v.y += func_021BC340(kind, info->f7);
    func_02048B30(func_0218EC2C(func_02188C58(func_021ABE14(*p->f14))), &u);
    v.x += (v.x / 4096 - u.x / 4096) * 298;
    func_0204F638(h, id, &v);
    flag = 1;
    i1 = func_020508C4(h2, idx);
    i2 = func_020508C4(h2, id);
    rot[3] = p->f8;
    rot[2] = p->f4;
    rot[2] += (s16)func_021BC338(kind);
    rot[1] = 0;
    rot[0] = 0;
    func_0204F5E4(h, i1, &rot[1]);
    func_0204F604(h, i2, &rot[1]);
    func_0204F654(h, i1, &rot[0]);
    func_0204F66C(h, i2, &rot[0]);
    func_0204F684(h, i2, &rot[3], &rot[2]);
    func_0204F794(h, i2, &flag);
    flag = func_0204F748(h, i1);
    func_0204F764(h, i2, &flag);
}
