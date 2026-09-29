/*
 * function: func_021BC2FC
 * address:  0x021BC2FC
 * packet:   pkt_ov088_021BC2FC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_02005B04  0x02005B04  thumb
 *   func_021BD29C  0x021BD29C  thumb  ov088
 *   func_02008730  0x02008730  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008314  0x02008314  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203133C  0x0203133C  arm
 *   func_02007210  0x02007210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb  ov228
 *   func_021DFEB0  0x021DFEB0  thumb  ov228
 *   func_021DFDB8  0x021DFDB8  thumb  ov228
 *   func_02011EEC  0x02011EEC  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   func_020315D4  0x020315D4  arm
 *   func_020312F8  0x020312F8  arm
 *   ov228_id       0x000000E4  data
 *   d_0209DF9C     0x0209DF9C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec12 {
    u32 a, b, c;
} Rec12;

extern void *func_020070A4(void);
extern void func_02005B04(u32);
extern void func_021BD29C(int);
extern void *func_02008730(void *);
extern void func_02008494(void *, void *);
extern void *func_0200873C(void *);
extern void func_02008314(void *, void *);
extern void func_020307B0(void *);
extern void func_0203133C(int);
extern int func_02007210(void *);
extern void func_02034AC4(void *id);
extern void func_02034A5C(void *id);
extern void *func_021DFC20(int heap);
extern u8 func_021DFE90(void *);
extern void func_021DFEB0(void *, void *);
extern void func_021DFDB8(void *);
extern void *func_02011EEC(u32, u16, Rec12 *, int);
extern int func_0216C0C0(int);
extern void func_020315D4(int);
extern void func_020312F8(int, void *, void *);
extern u8 ov228_id[];
extern char d_0209DF9C[];

int func_021BC2FC(int a, int b, int c, char *t)
{
    void *r4 = func_020070A4();
    void *r6;
    Rec12 z = {0, 0, 0};
    func_02005B04(*(u32 *)(t + 0x34));
    func_021BD29C(*(int *)(t + 0x2c));
    func_02008494(*(void **)(t + 0x54), func_02008730(r4));
    func_02008314(*(void **)(t + 0x58), func_0200873C(r4));
    func_020307B0(*(void **)(t + 0x54));
    func_020307B0(*(void **)(t + 0x58));
    func_0203133C(*(int *)(t + 0x30));
    if (func_02007210(r4) == 1) {
        func_02034AC4(ov228_id);
        r6 = func_021DFC20(1);
        if (func_021DFE90(r6) == 1)
            func_021DFEB0(r6, r4);
        func_021DFDB8(r6);
        func_02034A5C(ov228_id);
    }
    r4 = func_02011EEC(0, 0, &z, 0);
    func_0216C0C0(*(int *)(t + 0x28));
    func_020315D4(a);
    func_020312F8(-1, d_0209DF9C, r4);
    return 1;
}
