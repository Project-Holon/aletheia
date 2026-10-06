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
#include "../include/Obj03104.h"
#include "../include/Obj05698.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x, y, z;
} Vec;

struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02012974(const struct BigObj *p);
extern void func_0203D12C(int a);
extern void func_021AA8EC(u8 *p);
struct Rec020141E0;
struct Vec020141E0;
extern void func_020141E0(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern int func_02159BD4(int a0, int a1, int a2);
extern void func_0216DF1C(u32 a);
extern void func_021623DC(char *p);
extern u8 func_02012984(const struct BigObj *p);
extern void func_0216242C(u32 a, u16 b, u8 c);
extern void func_021643AC(void *a, void *b);
extern void func_02189518(char *p, unsigned int idx);
extern void func_0218958C(unsigned char *p, int id);
extern void func_02189560(int *p, int b);
extern void func_021895D0(u8 *p, u32 v);
extern void func_021895BC(void *sys, u32 v);
extern void func_02189684(char *p, unsigned int id);
extern int func_020120D8(char *p);
extern void func_021BC550(void *p, int v);
extern void func_0202735C(u32 a0, u32 a1);
extern void func_0215A014(void *a, int b);
extern void func_02158AE0(void *a0, void *a1);
extern void func_021894E0(int a, int b, int c, int d);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern void func_0215874C(void *a);

void func_021893C0(u8 *p)
{
    u8 *q = p + 0xD4;
    void *sys;
    u32 v;
    Vec pos;
    u32 s4;
    u32 s0;

    sys = func_020120F4((const struct Ctx *)(((struct Obj03104 *)p)->f4));
    s4 = func_02012844(sys);
    s0 = ((struct Obj03104 *)p)->f38;
    v = func_02012974((const struct BigObj *)(((struct Obj03104 *)p)->f8));
    func_0203D12C(2);
    func_021AA8EC((u8 *)(((struct Obj03104 *)p)->f90));
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&pos));
    v = func_02159BD4(v, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0216DF1C(s0);
    func_021623DC((char *)s4);
    func_0216242C(s4, v, func_02012984(sys));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021643AC(sys, p);
    func_02189518((char *)p, v);
    func_0218958C(p, v);
    func_02189560((int *)p, (u32)v);
    func_021895D0(p, v);
    func_021895BC(sys, v);
    func_02189684((char *)p, v);
    if (((struct Obj03104 *)p)->f30 != 0 && func_020120D8((char *)((struct Obj03104 *)p)->f4) == 0)
        func_021BC550((void *)(((struct Obj03104 *)p)->f30), v);
    ((struct Obj05698 *)q)->f4 = v;
    func_0202735C((u16)v, (u32)sys);
    func_0215A014(sys, v);
    func_02158AE0((void *)(((struct Obj03104 *)p)->f4), (void *)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021894E0((int)sys, s0, s4, v);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_0215874C((void *)func_02012138((const struct Ctx *)((struct Obj03104 *)p)->f4));
}
