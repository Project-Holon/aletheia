/*
 * function: func_0219603C
 * address:  0x0219603C
 * packet:   pkt_ov021_0219603C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   d_021D40A0     0x021D40A0  data  ov021  a4
 *   d_021D40C0     0x021D40C0  data  ov021  a4
 *   d_021D40E0     0x021D40E0  data  ov021  a4
 *   d_021D4100     0x021D4100  data  ov021  a4
 *   d_021D4120     0x021D4120  data  ov021  a4
 *   d_021D4140     0x021D4140  data  ov021  a4
 */

typedef struct { int w[8]; } B32;

extern const B32 d_021D40A0;
extern const B32 d_021D40C0;
extern const B32 d_021D40E0;
extern const B32 d_021D4100;
extern const B32 d_021D4120;
extern const B32 d_021D4140;
extern void func_0203FCA0(int, void *, int);
extern void func_020414AC(int);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);
extern void func_02040588(u32 which, u32 enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);

void func_0219603C(void)
{
    B32 t0;
    B32 t1;
    B32 t4;
    B32 t5;
    B32 t6;
    B32 t7;

    t0 = d_021D40A0;
    func_0203FCA0(0, &t0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 1);

    t1 = d_021D40C0;
    func_0203FCA0(1, &t1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 1);

    t4 = d_021D40E0;
    func_0203FCA0(4, &t4, 0);
    func_02040588(4, 1);
    func_020409B4(4);

    t5 = d_021D4100;
    func_0203FCA0(5, &t5, 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    t6 = d_021D4120;
    func_0203FCA0(6, &t6, 0);
    func_02040588(6, 1);
    func_020409B4(6);

    t7 = d_021D4140;
    func_0203FCA0(7, &t7, 0);
    func_02040588(7, 1);
    func_020409B4(7);
}
