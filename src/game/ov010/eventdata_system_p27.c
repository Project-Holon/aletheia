/*
 * file:     eventdata_system_p27.c
 * unit:     yes
 * function: func_021638CC, func_02163994
 * address:  0x021638CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02163C9C  0x02163C9C  thumb  ov010
 *   func_02163D04  0x02163D04  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02163BAC  0x02163BAC  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D52C  0x0216D52C  thumb  ov010
 *   func_0218DC04  0x0218DC04  thumb  ov021
 *   func_0216D88C 0x0216D88C thumb ov010
 */
struct Grid;
struct Actor;
struct VecFx32_02163994;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32_021638CC {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021638CC;

typedef struct Obj {
    u32 f00;
    fx32 f04;           /* 0x04 */
} Obj;

typedef struct { int x, y, z; } VecFx32_02163994;

extern int func_02163C9C(int a, int b, int c);
extern int func_02163D04(void *m, u32 kind, VecFx32_021638CC pos);
extern int func_02163E58(void *m, VecFx32_021638CC *pos, fx32 *y);
extern int func_02163BAC(int a, int b, int c, int d);
extern void *func_0216D67C(void *m);
extern u32 func_0216D52C(void *p);
extern int func_0218DC04(struct Grid *g, struct VecFx32_021638CC *pos);
extern void func_0216D88C(const struct Actor *p, struct VecFx32_02163994 *out);
u32 func_021638CC(void *m, Obj *o, s16 x, s16 y, int z, u16 kind);
u32 func_02163994(void *p, s16 x, s16 y, int z, u16 kind);


/*
 * Collects five placement-test failures into a bit mask: 1 from
 * func_02163C9C, 2 from func_02163D04 (the cell-centre position by
 * value), 8 when the ground-height probe func_02163E58 fails or lands
 * 0x14000 or more from the object's height, 4 from func_02163BAC, 0x10
 * from the ov021 test at 0x0218DC04.
 *
 * x and y are s16 register parameters (their spill homes are stored at
 * entry); z is read as `*(s16 *)&z` from an int stack parameter: an s16
 * z is copied into a fresh spill slot, while this spelling keeps the
 * incoming slot as its home and reloads it with ldrsh after the calls.
 */
u32 func_021638CC(void *m, Obj *o, s16 x, s16 y, int z, u16 kind)
{
    u32 flags = 0;
    VecFx32_021638CC pos;
    fx32 h;

    pos.x = (x << 16) + 0x8000;
    pos.y = o->f04;
    pos.z = (*(s16 *)&z << 16) + 0x8000;
    if (func_02163C9C((int)m, x, *(s16 *)&z) == 1)
        flags |= 1;
    if (func_02163D04(m, kind, pos) == 1)
        flags |= 2;
    if (func_02163E58(m, &pos, &h) == 1) {
        fx32 d = o->f04 - h;
        if (d < 0)
            d = -d;
        if (d >= 0x14000)
            flags |= 8;
        y = (h >> 4) / 0x1000;
    } else {
        flags |= 8;
    }
    if (func_02163BAC((int)m, x, y, *(s16 *)&z) == 1)
        flags |= 4;
    if (func_0218DC04((struct Grid *)func_0216D52C(func_0216D67C(m)), &pos) == 1)
        flags |= 0x10;
    return flags;
}

/*
 * trailing: two-byte zero alignment at 0x021639BE before func_021639C0.
 */
u32 func_02163994(void *p, s16 x, s16 y, int z, u16 kind)
{
    VecFx32_02163994 pos;
    func_0216D88C((const struct Actor *)p, (struct VecFx32_02163994 *)&pos);
    return func_021638CC(p, (struct Obj *)(&pos), x, y, z, kind);
}
