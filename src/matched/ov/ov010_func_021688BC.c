/*
 * function: func_021688BC
 * address:  0x021688BC
 * packet:   pkt_ov010_021688BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216880C  0x0216880C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_02045B38(int, int, int, int);
extern void func_02082BCC(void *, int, int);
extern void *func_0216880C(u32 group, u32 heap);
extern int func_02045EC0(int, int);
struct U16Vec;
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern void func_02045808(int);
extern void func_02045C04(int);

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    u8 f8[16];
    u16 f18;
    u16 f1a;
} Blk;

u16 *func_021688BC(Blk *a, int b, int c)
{
    int h = func_02045B38(0, 2, 11, c);
    u16 *r;
    int t;
    func_02082BCC(a, 0, 0x120);
    r = func_0216880C(b, c);
    a->f0 = b + 1;
    a->f18 = 0xFFFF;
    a->f1a = b * 3;
    a->f4 = *r;
    t = func_02045EC0(h, b);
    func_02045A38((struct U16Vec *)t, (u16 *)a->f8, 16);
    func_02045808(t);
    func_02045C04(h);
    return r;
}
