/*
 * function: func_021BBFA8
 * address: 0x021BBFA8
 * packet: pkt_ov093_021BBFA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021BDC2C 0x021BDC2C thumb ov093
 *   func_021BC0E8 0x021BC0E8 thumb ov093
 *   func_021BCCE0 0x021BCCE0 thumb ov093
 *   func_021C5200 0x021C5200 thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021C446C 0x021C446C thumb ov093
 *   func_021BC0D8 0x021BC0D8 thumb ov093
 *   func_021C8534 0x021C8534 thumb ov093
 *   func_021BC4DC 0x021BC4DC thumb ov093
 *   func_021C6158 0x021C6158 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a, b, c; u8 d, f; unsigned short pad; } E;
typedef struct { u8 pad[0x14]; u32 state; u8 pad2[0x76a]; u8 n; u8 pad3[0x5d]; E e[6]; } S;
extern u32 func_021D8454(u32 *);
extern void func_021BDC2C(S *);
extern void func_021BC0E8(S *, E *, u32);
extern u32 func_021BCCE0(S *, E *);
extern int func_021C5200(S *);
extern int func_021BC2B0(S *);
extern int func_021C446C(S *);
extern int func_021BC0D8(void *, int);
extern int func_021C8534(S *);
extern int func_021BC4DC(S *, u8 *);
extern void func_021C6158(S *, u8 *);
u32 func_021BBFA8(S *p, u32 i)
{
    u32 previous = 0;
    for (; i < p->n; i++) {
        u32 current = func_021D8454(&p->e[i].b);
        u8 stop;
        if (previous == 6 && current != 6) {
            func_021BDC2C(p);
            func_021BC0E8(p, &p->e[i], p->n - i);
        }
        previous = func_021BCCE0(p, &p->e[i]);
        stop = func_021C5200(p);
        if ((u8)func_021BC2B0(p)) { p->state = 4; return i + 1; }
        if (p->state == 6) return i + 1;
        if (p->state == 1) return i + 1;
        if (stop) { p->state = 3; return i + 1; }
    }
    if (p->state == 0) {
        u8 stop = func_021C446C(p);
        int present;
        if ((u8)func_021BC2B0(p)) { p->state = 4; return p->n; }
        if (stop) { p->state = 3; return p->n; }
        present = func_021BC0D8((u8 *)p + 0x3e0, 0);
        if (func_021C8534(p) || present) {
            func_021BC4DC(p, (u8 *)p + 0x4ce);
            func_021C6158(p, (u8 *)p + 0x4ce);
            p->state = 2;
            return p->n;
        }
        p->state = 0;
    }
    return p->n;
}
