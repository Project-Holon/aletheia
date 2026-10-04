/*
 * function: func_021D18F4
 * address:  0x021D18F4
 * packet:   pkt_ov021_021D18F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011590  0x02011590  thumb
 *   func_02011558  0x02011558  thumb
 *   func_021D1988  0x021D1988  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   d_021DD5E0     0x021DD5E0  data    ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

extern int func_02011590(u32 a, u32 v);
extern void func_02011558(u32 a);
extern void func_021D1988(u32 a, u32 b, u8 *c);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_0216D5F8(u32 a);
extern void func_0216E014(u32 a, Vec3 *b, u32 c);
extern void func_0216D570(u32 a, u32 b);
extern void func_0216D758(u32 a);
extern u32 d_021DD5E0[];

void func_021D18F4(u32 a, u32 b, u8 *p)
{
    Vec3 v;

    if (p[0x19A] == 0) {
        return;
    }
    if (p[0x19A] == 1) {
        if (func_02011590(*(u32 *)(p + 0x184), 0x1000) == 0) {
            func_021D1988(*(u32 *)(p + 0x184), *(u32 *)p, p + 0x18C);
        } else {
            func_02011558(*(u32 *)(p + 0x184));
            *(u32 *)(p + 0x184) = 0;
            p[0x19A] = 0;
            func_0216D88C((const struct Actor *)*(u32 *)p, (struct VecFx32 *)&v);
            func_0216E014(*(u32 *)p, &v, func_0216D5F8(*(u32 *)p));
            if (d_021DD5E0[p[0x199]] != 0) {
                func_0216D570(*(u32 *)p, 0x8000);
            }
        }
        func_0216D758(*(u32 *)p);
    }
}
