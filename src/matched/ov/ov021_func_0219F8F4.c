/*
 * function: func_0219F8F4
 * address:  0x0219F8F4
 * packet:   pkt_ov021_0219F8F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0219F990  0x0219F990  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x, y, z;
} V3;

typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    u8 pad[4];
    u32 f8;
} St;

extern St *func_0216D6F0(u32);
extern int func_0216D910(int a0);
extern u32 func_0216D5F8(u32);
extern void func_0216D8B0(u32, V3 *);
extern u32 func_0219C9DC(u32);
extern void func_0219F990(u32, St *, u8);
extern void func_0219FFBC(u32, u32 *);
extern void func_02197CCC(u32, u32 *);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void func_0205082C(u32, u32, u32);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, u32 *);

void func_0219F8F4(u32 a)
{
    St *p;
    u8 flag;
    u32 h;
    u32 n;
    u32 buf[3];
    u32 v[3];

    p = func_0216D6F0(a);
    if (p->id != 0xFFFF) {
        flag = 0;
        h = func_0219C9DC(func_0216D910(a));
        n = func_0216D5F8(a);
        if (n != p->f2) {
            flag = 1;
            p->f2 = n;
            p->f3 = 0;
            p->f8 = 0;
            func_0205082C(h, p->id, p->f2);
            {
                V3 *pv = (V3 *)v;
                pv->x = 0;
                pv->y = 0;
                pv->z = 0;
                func_0216D8B0(a, pv);
            }
        }
        func_0219F990(a, p, n);
        func_02197CCC(a, buf);
        func_0219FFBC(a, buf);
        func_0204F638(func_02050080(h), p->id, buf);
        func_021A000C(a, h, p->id, flag, 0);
    }
}
