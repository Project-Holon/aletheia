/*
 * function: func_021C2644
 * address:  0x021C2644
 * packet:   pkt_ov208_021C2644
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_021C3638  0x021C3638  thumb  ov208
 *   func_021BC97C  0x021BC97C  thumb  ov208
 *   func_021BCA54  0x021BCA54  thumb  ov208
 *   func_021C2FEC  0x021C2FEC  thumb
 *   func_021C32FC  0x021C32FC  thumb  ov208
 *   func_021C3268  0x021C3268  thumb  ov208
 *   func_021C337C  0x021C337C  thumb  ov208
 *   func_021C3374  0x021C3374  thumb  ov208
 *   func_021C2D88  0x021C2D88  thumb  ov208
 *   func_021BC61C  0x021BC61C  thumb  ov208
 *   func_021BC464  0x021BC464  thumb  ov208
 *   func_021C2BF4  0x021C2BF4  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_021BC34C  0x021BC34C  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern int func_02006650(void);
extern void func_020065D8(void);
extern void func_021C3638(void *a0, u8 *st, void *a2);
extern void func_021BC97C(char *p);
extern void func_021BCA54(u32 a, u32 packed);
extern void func_021C2FEC(void *a0, u8 *st, void *a2, u32 i);
extern void func_021C32FC(void *a0, u8 *st, void *a2);
extern void func_021C3268(void *a0, u8 *st, void *a2);
extern void func_021C337C(void *a0, u8 *st, void *a2);
extern void func_021C3374(void *a0, u8 *st, void *a2);
extern void func_021C2D88(void *a0, u8 *st, void *a2);
extern void func_021BC61C(char *p);
extern void func_021BC464(char *p);
extern void func_021C2BF4(void *a0, u8 *st, void *a2);
extern void func_02030EAC(void *a);
extern void func_021BC34C(char *p);

u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4)
{
    u8 i;

    if (func_02006650() != 0) {
        func_020065D8();
    }
    func_021C3638(a2, st, a4);
    func_021BC97C(*(char **)(st + 0x80));
    func_021BC97C(*(char **)(st + 0x7c));
    func_021BCA54(2, *(u32 *)(st + 0x78));
    for (i = 0; i < 2; i++) {
        func_021C2FEC(a2, st, a4, i);
    }
    func_021C32FC(a2, st, a4);
    func_021C3268(a2, st, a4);
    func_021C337C(a2, st, a4);
    func_021C3374(a2, st, a4);
    func_021C2D88(a2, st, a4);
    func_021BC61C(*(char **)(st + 0xc8));
    func_021BC464(*(char **)(st + 0xc4));
    func_021BC464(*(char **)(st + 0xc0));
    if (*(u32 *)(st + 0xb8) != 3) {
        func_021C2BF4(a2, st, a4);
    }
    func_02030EAC(*(void **)(st + 0xbc));
    func_021BC34C((char *)a0);
    return 1;
}
