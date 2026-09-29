/*
 * function: func_0217993C
 * address:  0x0217993C
 * packet:   pkt_ov015_0217993C
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_0217AAC0     0x0217AAC0  data   ov015  a4
 *   d_0217AB40     0x0217AB40  data   ov015  a4
 *   d_0217ABA0     0x0217ABA0  data   ov015  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_02179F74  0x02179F74  arm    ov015
 *   func_0217A584  0x0217A584  arm    ov015
 *   func_02179B38  0x02179B38  thumb  ov015
 *   func_020056EC  0x020056EC  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct s_aac0 {
    u8 pad0[8];
    u32 f8;
    u8 pad1[4];
    u8 f10;
};
struct s_ab40 {
    u8 pad[0x3C];
    u32 f3c;
};
struct s_aba0 {
    u8 pad[6];
    u8 b6;
};

extern struct s_aac0 d_0217AAC0;
extern struct s_ab40 d_0217AB40;
extern struct s_aba0 d_0217ABA0;

extern void func_02082BCC(void *p, int v, u32 n);
extern u8 func_0208F1B4(void);
extern void func_02179F74(int a);
extern void func_0217A584(void (*cb)(void));
extern void func_02179B38(void);
extern u32 func_020056EC(u32 x);

void func_0217993C(u32 a, u8 b)
{
    func_02082BCC(&d_0217AAC0, 0, 0xE8);
    d_0217AB40.f3c = a;
    d_0217ABA0.b6 = func_0208F1B4();
    func_02179F74(3);
    func_0217A584(func_02179B38);
    d_0217AAC0.f8 = func_020056EC(0);
    if (d_0217AAC0.f8 == 0)
        d_0217AAC0.f8 = 1;
    d_0217AAC0.f10 = b;
}
