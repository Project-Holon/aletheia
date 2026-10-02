/*
 * function: func_0216B63C
 * address:  0x0216B63C
 * packet:   pkt_ov010_0216B63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 *   func_0200C358  0x0200C358  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern int func_0215A5F4();
extern int func_0215A5E4();
extern int func_02012EBC(int p);
extern int func_0200C0F0(int sys);
extern void func_0200E394();
extern int func_02159B10();
extern void func_0200C334(int, u8);
extern void func_0200C344(int, u8, u8);
extern void func_0200C358(int, u8, int);
extern u64 func_0203F524();
extern void func_0200C384();

int func_0216B63C(int a0, int a1)
{
    int h;
    u16 s[3];
    int i;
    int w;
    int k;
    int z;
    u64 t;

    func_0215A5F4(a1);
    w = func_02012EBC(func_0215A5E4(a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    k = func_02159B10(a0, a1);
    s[0] = func_02159B10(a0, a1);
    s[1] = func_02159B10(a0, a1);
    s[2] = func_02159B10(a0, a1);
    func_0200C334(h, k);
    z = 0;
    for (i = 0; i < 3; i++) {
        func_0200C344(h, i, s[i]);
        func_0200C358(h, i, z);
    }
    t = func_0203F524();
    func_0200C384(h, (u32)t, (u32)(t >> 32));
    return z;
}
