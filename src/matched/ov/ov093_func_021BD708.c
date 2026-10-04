/*
 * function: func_021BD708
 * address: 0x021BD708
 * packet: pkt_ov093_021BD708
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BD850 0x021BD850 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021BD8AC 0x021BD8AC thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 b0:1, b1:1, b2:1, rest:5; } Bits;
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern int func_021B86E4(u8 *);
extern u8 func_021B8FF4(u8 *p);
extern int func_021B902C(int, int);
extern int func_021D5B68(void *p);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern int func_021BD850(u8 *, u8 *);
extern int func_021BD8AC(u8 *, u8 *);
extern void *func_021B86B8(void ***);
extern u8 func_021B86C0(u8 **p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021D8244(void *, int);

int func_021BD708(u8 *p, u8 *a, int r, int z)
{
    int k = func_021B8DDC(func_021D5440(a));
    u8 f;
    if (func_021B86E4(*(u8 **)(p + 4)) == 0) {
        f = (u8)(func_021B902C(k, func_021B8FF4(*(u8 **)(p + 4))) == 0 ? 1 : 0);
        if (r == 0 && func_021D5B68(a) == 0) {
            u32 l;
            l = func_021CC8D8(p + 0x1d74, 2888);
            r = func_021BD850(p, a);
            func_021CC95C(p + 0x1d74, l, 2890);
            if (r) return 0;
        }
        if (((Bits *)(p + 0x78a))->b2 == 0) {
            if (z == 0) {
                u32 l;
                l = func_021CC8D8(p + 0x1d74, 2904);
                r = func_021BD8AC(p, a);
                func_021CC95C(p + 0x1d74, l, 2906);
            } else {
                r = 0;
            }
            if (r == 0) {
                if (f != 0) {
                    if (func_021B86B8(*(void ****)(p + 4)) == 0)
                        func_021CD64C(*(void **)(p + 0xc), 0x5c, 0x4b, 0x56a, func_021D5440(a), 0xffff0000);
                } else {
                    func_021CD64C(*(void **)(p + 0xc), 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            p[0x78a] |= 4;
        }
    } else {
        if (func_021B86C0((u8 **)(*(u8 **)(p + 4))) != 0 && ((Bits *)(p + 0x78a))->b2 == 0) {
            func_021CD64C(*(void **)(p + 0xc), 0x5a, 0xc6, 0xffff0000);
            p[0x78a] |= 4;
        }
    }
    func_021D8244(p + 0x4b8, k);
    return 1;
}
