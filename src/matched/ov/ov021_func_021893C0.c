/*
 * function: func_021893C0
 * address:  0x021893C0
 * packet:   pkt_ov021_021893C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02012974  0x02012974  thumb
 *   func_0203D12C  0x0203D12C  arm
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_020141E0  0x020141E0  thumb
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_0216DF1C  0x0216DF1C  thumb  ov010
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_0216242C  0x0216242C  thumb  ov010
 *   func_021643AC  0x021643AC  thumb  ov010
 *   func_02189518  0x02189518  thumb  ov021
 *   func_0218958C  0x0218958C  thumb  ov021
 *   func_02189560  0x02189560  thumb  ov021
 *   func_021895D0  0x021895D0  thumb  ov021
 *   func_021895BC  0x021895BC  thumb  ov021
 *   func_02189684  0x02189684  thumb  ov021
 *   func_020120D8  0x020120D8  thumb
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_0202735C  0x0202735C  thumb
 *   func_0215A014  0x0215A014  thumb  ov010
 *   func_02158AE0  0x02158AE0  thumb  ov010
 *   func_021894E0  0x021894E0  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_0215874C  0x0215874C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x, y, z;
} Vec;

extern void *func_020120F4(u32 a);
extern u32 func_02012844(void *sys);
extern u32 func_02012974(u32 a);
extern void func_0203D12C(u32 a);
extern void func_021AA8EC(u32 a);
extern void func_020141E0(void *src, Vec *out);
extern u32 func_02159BD4(u32 a, int x, int z);
extern void func_0216DF1C(u32 a);
extern void func_021623DC(u32 a);
extern u8 func_02012984(void *sys);
extern void func_0216242C(u32 a, u16 b, u8 c);
extern void func_021643AC(void *sys, u8 *p);
extern void func_02189518(u8 *p, u32 v);
extern void func_0218958C(u8 *p, u32 v);
extern void func_02189560(u8 *p, u32 v);
extern void func_021895D0(u8 *p, u32 v);
extern void func_021895BC(void *sys, u32 v);
extern void func_02189684(u8 *p, u32 v);
extern int func_020120D8(u32 a);
extern void func_021BC550(u32 a, u32 v);
extern void func_0202735C(u16 v, void *sys);
extern void func_0215A014(void *sys, u32 v);
extern void func_02158AE0(u32 a, int b);
extern void func_021894E0(void *sys, u32 a, u32 b, u32 v);
extern void *func_02012138(u32 a);
extern void func_0215874C(void *a);

void func_021893C0(u8 *p)
{
    u8 *q = p + 0xD4;
    void *sys;
    u32 v;
    Vec pos;
    u32 s4;
    u32 s0;

    sys = func_020120F4(*(u32 *)(p + 4));
    s4 = func_02012844(sys);
    s0 = *(u32 *)(p + 0x38);
    v = func_02012974(*(u32 *)(p + 8));
    func_0203D12C(2);
    func_021AA8EC(*(u32 *)(p + 0x90));
    func_020141E0(q, &pos);
    v = func_02159BD4(v, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0216DF1C(s0);
    func_021623DC(s4);
    func_0216242C(s4, v, func_02012984(sys));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021643AC(sys, p);
    func_02189518(p, v);
    func_0218958C(p, v);
    func_02189560(p, v);
    func_021895D0(p, v);
    func_021895BC(sys, v);
    func_02189684(p, v);
    if (*(u32 *)(p + 0x30) != 0 && func_020120D8(*(u32 *)(p + 4)) == 0)
        func_021BC550(*(u32 *)(p + 0x30), v);
    *(short *)(q + 4) = v;
    func_0202735C(v, sys);
    func_0215A014(sys, v);
    func_02158AE0(*(u32 *)(p + 4), 4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021894E0(sys, s0, s4, v);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_0215874C(func_02012138(*(u32 *)(p + 4)));
}
