/*
 * function: func_0216C028
 * address:  0x0216C028
 * packet:   pkt_ov010_0216C028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The heap id is a u16, as in func_0216BFD4; that keeps its entry spill
 * at the front of the prologue.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045838  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern int func_020457B0(int, unsigned short);
extern void func_02045838(int, int);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern char d_02172A60[];

int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x59);
    func_02082BCC(p, 0, 0x2c);
    p[0] = 1;
    p[6] = a2;
    p[2] = a1;
    p[10] = s0;
    if (a1) {
        int t;
        *(short *)((char *)p + 4) = func_02017E1C((void *)a1, 5, 0);
        t = func_02017E1C((void *)a1, 0x6f, 0);
        *(short *)((char *)p + 6) = (func_02017E1C((void *)a1, 0x6e, 0) << 8) | t;
    }
    p[8] = func_020457B0(0xb, a0);
    if (a3)
        func_02045838(p[8], a3);
    return p;
}
