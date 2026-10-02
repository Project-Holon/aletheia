/*
 * function: func_021D935C
 * address: 0x021D935C
 * packet: pkt_ov119_021D935C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021D94A0 0x021D94A0 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020399A8(void);
extern u32 func_0203D1A4(void *);
extern void func_021D94A0(void *, int);
void func_021D935C(u32 a, u32 b, u32 c, void *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4(func_020399A8()))
            func_021D94A0(base, 1);
    }
}
