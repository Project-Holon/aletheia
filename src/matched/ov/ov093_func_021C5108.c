/*
 * function: func_021C5108
 * address: 0x021C5108
 * packet: pkt_ov093_021C5108
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 198 compiled bytes followed by two zero padding bytes at 021C51CE.
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C51D0 0x021C51D0 thumb ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021DCF24 0x021DCF24 thumb ov093
 *   func_021D8538 0x021D8538 thumb ov093
 *   func_021DCFA4 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021BD2B4 0x021BD2B4 thumb ov093
 *   func_021BD338 0x021BD338 thumb ov093
 *   func_021BD34C 0x021BD34C thumb ov093
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021EF90C 0x021EF90C thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021C51D0(u8 *, u8 *);
extern void func_021BFF60(u8 *, u8 *, int);
extern void func_021D8510(void *p);
extern void func_021DCF24(u8 *);
extern void func_021D8538(void *p);
extern void func_021DCFA4(void *p);
extern void func_021E0434(u8 *);
extern void func_021BD2B4(u8 *, u8 **);
extern void func_021BD338(u8 *, u8 *);
extern int func_021BD34C(u8 *, u8 **, u8 **);
struct UtilSlots;
extern void func_021D6264(struct UtilSlots *p, int v);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021EF90C(int a);
extern int func_021BC2B0(u8 *);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C3FDC(u8 *, u8 *);
void func_021C5108(u8 *p, u8 *a, int b)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021C51D0(p, a);
    func_021BFF60(p, a, 0);
    if (b == 0) {
        func_021D8510(a);
        func_021DCF24(a);
    } else {
        func_021D8538(a);
        func_021DCFA4(a);
    }
    func_021E0434(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    func_021BD338((u8 *)&it, p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        func_021D6264((struct UtilSlots *)cur, k);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x2c, func_021D5440(cur), k);
    }
    func_021EF90C(k);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x23, k);
    if (!func_021BC2B0(p) && (u16)func_021D59B4(a, 0x11) == 0x7f)
        func_021C3FDC(p, a);
}
