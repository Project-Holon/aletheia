/*
 * function: func_021BA114
 * address:  0x021BA114
 * packet:   pkt_ov088_021BA114
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009448  0x02009448  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_0200C2F0  0x0200C2F0  thumb
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_021BA9D4  0x021BA9D4  thumb  ov088
 *   func_021BA9E8  0x021BA9E8  thumb  ov088
 *   func_021BAB64  0x021BAB64  thumb  ov088
 *   func_021BAC74  0x021BAC74  thumb  ov088
 *   func_021BB4B4  0x021BB4B4  thumb  ov088
 *   func_021BB544  0x021BB544  thumb  ov088
 *   func_021BAD08  0x021BAD08  thumb  ov088
 *   func_021BB184  0x021BB184  thumb  ov088
 *   func_021BB380  0x021BB380  thumb  ov088
 *   func_021BB608  0x021BB608  thumb  ov088
 *   func_021BAC24  0x021BAC24  thumb  ov088
 *   func_021BB484  0x021BB484  thumb  ov088
 *   func_021BA9B0  0x021BA9B0  thumb  ov088
 */

extern void *func_02009448(int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009210Obj;
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void func_0200C2F0(int, int, int);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_021BA9D4(void);
extern void func_021BA9E8(void);
extern void func_021BAB64(void);
extern void func_021BAC74(void *);
extern void func_021BB4B4(void *);
extern void func_021BB544(void *);
extern void func_021BAD08(void *);
extern void func_021BB184(int *p);
extern void func_021BB380(void *);
extern void func_021BB608(void *);
extern void func_021BAC24(void *);
extern void func_021BB484(void);
extern void func_021BA9B0(int *p);

int func_021BA114(int *p)
{
    unsigned short z;
    if (func_020092EC(func_02009448(p[0])) == 1)
        func_0200C2F0(p[2], 2, 2);
    z = 0;
    func_02043534(0);
    func_020435F4(0);
    *(unsigned short *)0x04000050 = z;
    *(unsigned short *)0x04001050 = z;
    func_0204363C(1);
    func_021BA9D4();
    func_021BA9E8();
    func_021BAB64();
    func_021BAC74(p);
    func_021BB4B4(p);
    func_021BB544(p);
    func_021BAD08(p);
    func_021BB184(p);
    func_021BB380(p);
    func_021BB608(p);
    func_021BAC24(p);
    func_021BB484();
    func_021BA9B0(p);
    return 4;
}
