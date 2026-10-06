/*
 * function: func_021E0240
 * address: 0x021E0240
 * packet: pkt_ov119_021E0240
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012F14 0x02012F14 thumb
 *   func_02009D9C 0x02009D9C thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void *func_02012F14(void **);
extern unsigned func_02009D9C(void);
extern void func_02082D44(void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E0240(void **h, void *dst)
{
    void *src = func_02012F14(h);
    func_02082D44(dst, src, func_02009D9C());
    func_020307B0(dst);
}
