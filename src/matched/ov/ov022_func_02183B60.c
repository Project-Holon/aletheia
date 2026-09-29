/*
 * function: func_02183B60
 * address:  0x02183B60
 * packet:   pkt_ov022_02183B60
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02183FB8  0x02183FB8  thumb  ov022
 *   func_02184114  0x02184114  thumb  ov022
 *   func_0218416C  0x0218416C  thumb  ov022
 *   d_021841C0     0x021841C0  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Rec20 {
    u32 w[8];
} Rec20;

extern u8 d_021841C0[];

extern u8 *func_02030734(int heap, int size, int clear, u8 *file, int line);
extern int func_0203D378(void);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern int func_020399A8(void);
extern u32 func_0203D1A4(u32 v);
extern void func_02183FB8(u8 *s, u8 *a, int idx, u8 *src);
extern int func_02184114(u8 *s);
extern void func_0218416C(u8 *s);

u8 *func_02183B60(u8 *a, int heap, int kind, Rec20 *src)
{
    u8 *s;
    u8 buf[0x28];

    s = func_02030734(heap, 0x100, 1, d_021841C0, 0x4d);
    if (func_0203D378() == 1) {
        s[1] = 3;
    }
    s[0] = kind;
    s[0x10] = 0xff;
    s[0x11] = 0xff;
    func_02082BCC(buf, 0, 0x28);
    *(Rec20 *)buf = *src;
    func_02087C6C(buf + 0x20);
    func_02183FB8(s, a, func_0203D1A4(func_020399A8()), buf);
    func_02184114(s);
    func_0218416C(s);
    return s;
}
