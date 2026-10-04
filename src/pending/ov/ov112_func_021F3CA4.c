/*
 * function: func_021F3CA4
 * address:  0x021F3CA4
 * packet:   pkt_ov112_021F3CA4
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wave D3 lane 13): complete draft, instruction stream matches
 *   through the 2048A24 call except for register residency of two constants.
 *   Original: `movs r0,#3; movs r7,#3` before func_0204044C and `movs r4,#1` after it;
 *   r7 (3) and r4 (1) then feed `lsls r1,r7,#0xe` (3 << 14) and `lsls r0,r4,#0x10` /
 *   `lsls r0,r4,#0xc` (1 << 16, 1 << 12) and the argument 1 of func_02046BE0.  Ours
 *   rematerialises 3 and 1 (compiled 512 bytes vs 520).  Tried int locals and enum
 *   typed locals for the constants (no change).  The later part (DISP3DCNT RMW,
 *   stack table copies after the second func_02046BE0, 0x4000050/0x400004A tails)
 *   was written from the listing and not yet checked line by line.  Data pool words
 *   d_021F81AC and d_021F81C4 are contested between overlays (need a witness or a
 *   region token), the other six have no witness outside this function.
 *
 * symbols:
 *   func_02046440  0x02046440  arm
 *   func_0204044C  0x0204044C  arm
 *   func_02046BE0  0x02046BE0  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   func_0204EBD4  0x0204EBD4  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_021F3EAC  0x021F3EAC  thumb  ov112
 *   func_02040618  0x02040618  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02049238  0x02049238  arm
 *   func_0207D63C  0x0207D63C  arm
 *   d_021F81AC  0x021F81AC  data  ov112  a4
 *   d_021F81B8  0x021F81B8  data  ov112  a4
 *   d_021F81A0  0x021F81A0  data  ov112  a4
 *   d_021F81C4  0x021F81C4  data  ov112  a4
 *   d_021F8274  0x021F8274  data  ov112  a4
 *   d_021F8258  0x021F8258  data  ov112  a4
 *   d_021F8214  0x021F8214  data  ov112  a4
 *   d_021F81D4  0x021F81D4  data  ov112  a4
 *   d_021F81F4  0x021F81F4  data  ov112  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[7]; } T28;
typedef struct { u32 w[3]; } T12;

extern void func_02046440(int, int, int, int, int, int, int);
extern void func_0204044C(u32 mode);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_02048A24(int, int, int, int, int, int, int, int, const void *, const void *, const void *, int);
extern void func_02048AD0(void *l);
extern void func_0207DCF8(const void *a);
extern void *func_0204EBD4(T28 *src, int heap);
extern void func_0204ED70(void *h, T12 *t);
extern void func_021F3EAC(const void *a, u32 b, u32 c);
extern void func_02040618(u32, u32, u32);
extern void *func_020490F4(u32 id, u16 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 index);
extern void func_02049238(void *h);
extern void func_0207D63C(u32, u32, u32, u32, u32);

extern const char d_021F81AC[];
extern const char d_021F81B8[];
extern const char d_021F81A0[];
extern const char d_021F81C4[];
extern const T28 d_021F8274;
extern const T12 d_021F8258;
extern const char d_021F8214[];
extern const char d_021F81D4[];
extern const char d_021F81F4[];

void func_021F3CA4(char *p)
{
    int three = 3;
    int one = 1;
    void *h;
    void *cam;

    func_02046440(0, 2, 0, 4, 0, *(u16 *)p, 0);
    func_0204044C(three);
    func_02046BE0(0, one);
    cam = func_02048A24(2, three << 14, 0, 0, one << 16, one << 12, 0x3E8000, 0,
                        d_021F81AC, d_021F81B8, d_021F81A0, *(u16 *)p);
    *(void **)(p + 0x18) = cam;
    func_02048AD0(cam);
    func_0207DCF8(d_021F81C4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    func_02046BE0(0, 0);
    T28 a = d_021F8274;
    T12 b = d_021F8258;
    T12 *pb = &b;
    h = func_0204EBD4(&a, *(u16 *)p);
    *(void **)(p + 0x1C) = h;
    func_0204ED70(h, pb);
    func_021F3EAC(d_021F8214, 1, 0);
    func_021F3EAC(d_021F81D4, 2, 0);
    func_021F3EAC(d_021F81F4, 3, 0);
    func_02040618(2, 3, 0xE0);
    h = func_020490F4(0x2F, *(u16 *)p);
    func_02049BDC(h, 3, 0, 0, 0, 0x20, *(u16 *)p);
    func_02049658(h, 9, 2, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xF, 2, 0, 0, 0, *(u16 *)p);
    func_02049BDC(h, 2, 0, 0x20, 0x20, 0x20, *(u16 *)p);
    func_02049658(h, 8, 3, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xE, 3, 0, 0, 0, *(u16 *)p);
    func_020409B4(2);
    func_020409B4(3);
    func_02049238(h);
    func_0207D63C(0x04000050, 8, 1, 0, 0xA);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    *(volatile u16 *)0x0400004A = (*(volatile u16 *)0x0400004A & ~0x3F00) | 0x1700 | 0x2000;
    *(volatile u16 *)0x0400004A = (*(volatile u16 *)0x0400004A & ~0x3F) | 0x1F | 0x20;
}
