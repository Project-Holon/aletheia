/*
 * function: func_021EFEC0
 * address:  0x021EFEC0
 * packet:   pkt_ov032_021EFEC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EFEC0  0x021EFEC0  thumb
 *   func_02021EE4  0x02021EE4  thumb
 *   func_021F0AC0  0x021F0AC0  thumb  ov032
 *   func_021F0B10  0x021F0B10  thumb  ov032
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_021659F0  0x021659F0  thumb  ov010
 *   func_021F0F44  0x021F0F44  thumb  ov032
 *   func_021F0F30  0x021F0F30  thumb  ov032
 *   func_021F1144  0x021F1144  thumb  ov032
 *   func_021F0EA4  0x021F0EA4  thumb  ov032
 *   func_021F0E24  0x021F0E24  thumb  ov032
 *   func_021F0E7C  0x021F0E7C  thumb  ov032
 *   func_021F0DF4  0x021F0DF4  thumb  ov032
 *   func_0203D34C  0x0203D34C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void func_02021EE4(int, u32);
extern void func_021F0AC0(void *);
extern void func_021F0B10(void *, int, int);
extern void func_02165AC4(int, int, void *, int);
extern int func_021659F0(int, int);
extern u8 *func_021F0F44(u8 *p, int a);
extern void func_021F0F30(u8 *, u8, u8);
extern void func_021F1144(void *, u8 *, int, int, int, int);
extern void func_021F0EA4(u8 *, int);
extern void func_021F0E24(void *);
extern void func_021F0E7C(void *);
extern void func_021F0DF4(int, int);
extern void func_0203D34C(u32 a, u32 b);

void func_021EFEC0(u8 *o)
{
    int i;
    u8 *q;
    u8 *e;
    int s;
    int t;

    func_02021EE4(*(int *)(o + 0xAC), 1);
    func_021F0AC0(o);
    func_021F0B10(o, 1, 0);
    for (i = 0; i < o[0x7D]; i++) {
        q = o + 0x48;
        t = o[0x7C];
        func_02165AC4(*(int *)(o + 0x3C), *(int *)(o + 0x40), q, t + i);
        s = func_021659F0(*(int *)(o + 0x3C), t + i);
        e = func_021F0F44(o, 0xFF);
        func_021F0F30(e, s, i + 1);
        func_021F1144(o, e, *(int *)(o + 0x40), 2, 0, 0);
        func_021F0EA4(e, 1);
    }
    func_021F0E24(o);
    func_021F0E7C(o);
    if (*(int *)(o + 0x28) == 0x30)
        func_021F0DF4(*(int *)(o + 0x2BC), 3);
    func_0203D34C(0, *(u16 *)(o + 0x96));
}
