/*
 * function: func_0219A150
 * address:  0x0219A150
 * packet:   pkt_ov021_0219A150
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0219B0C4  0x0219B0C4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0219A1E8  0x0219A1E8  thumb  ov021
 *   func_0219B200  0x0219B200  thumb  ov021
 *   func_0219B0F0  0x0219B0F0  thumb  ov021
 *   func_0219B104  0x0219B104  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   d_021D4FA4     0x021D4FA4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef struct { u16 x; s16 n; u32 v; } St;
extern St *func_0216D69C(u32);
extern u32 func_0216D5A8(u8 *p);
extern int func_02164168(int a);
extern int func_0219B0C4(void);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D5A0(void *p);
extern u16 func_0219A1E8(u32, u32);
extern int func_0219B200(int a, int id, int end);
extern u16 func_0219B0F0(void *, int);
extern u32 func_0219B104(u32, u32);
extern void func_0216D5E0(u32, u16);
extern void func_02163F10(u32);
extern u8 d_021D4FA4[];

void func_0219A150(u32 a)
{
    St *p;
    u32 r;
    u32 t;
    u16 q;
    p = func_0216D69C(a);
    if (func_0216D5A8((u8 *)a) == 11) {
        if (func_02164168(a) == 1 && func_0219B0C4() == 1) {
            t = func_0216D5F8((void *)a);
            q = func_0219A1E8(func_0216D5A0((void *)a), t);
            if (q != 9)
                func_0216D5E0(a, q);
        }
    } else {
        r = func_0219B200(a, p->v, 9);
        if (r != 9) {
            func_0216D5E0(a, r);
        } else if (p->x == 0) {
            p->n = p->n - 1;
            if (p->n <= 0) {
                p->n = func_0219B0F0(d_021D4FA4, -1);
                r = func_0219B104(p->v, 9);
                func_0216D5E0(a, r);
            }
        }
    }
    func_02163F10(a);
}
