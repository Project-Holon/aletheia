/*
 * function: func_021D4A48
 * address:  0x021D4A48
 * packet:   pkt_ov117_021D4A48
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006984  0x02006984  thumb
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   d_021D5200     0x021D5200  data
 *   d_021D52F8     0x021D52F8  data
 *   d_021D53D0     0x021D53D0  data
 *   d_021D5600     0x021D5600  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00342.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 v[4];
} Quad;

extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02006984(u32, u32, u32, u32, u32, u32, u32, u32);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void func_021DFD24(u32 *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern const Quad d_021D5200;
extern const u8 d_021D52F8[];
extern const u8 d_021D53D0[];
extern u8 d_021D5600[];

void func_021D4A48(u8 *p, int idx)
{
    void *x;
    u32 buf[3];

    x = func_021D8FA4(p, 1 - func_021D8AA8(p));
    func_02017E1C(x, 7, 0);
    if (func_02017E1C(x, 0x4c, 0) == 0) {
        func_02006984(func_02017E1C(x, 0xab, 0), func_02017E1C(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj00342 *)p)->f11EE == 0) {
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868));
        if (((struct Obj00342 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x14, buf, d_021D5600, ((struct Obj00342 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x28, buf, (void *)d_021D53D0, ((struct Obj00342 *)p)->f5F4);
        }
    } else {
        Quad t = d_021D5200;
        u32 obj = ((u32 *)(p + 0x844))[t.v[idx]];
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        func_021DFD24((u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868));
        if (((struct Obj00342 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x14, buf, d_021D5600, ((struct Obj00342 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)func_021DFBB4((void *)obj, (void *)0x12, buf, (void *)d_021D52F8, ((struct Obj00342 *)p)->f5F4);
        }
    }
}
