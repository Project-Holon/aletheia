/*
 * function: func_021DF4AC
 * address: 0x021DF4AC
 * packet: pkt_ov137_021DF4AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Mutable range table is reloaded after RNG; updating low in place preserves r4/r5 colouring.
 * symbols:
 *   func_021E14E4 0x021E14E4 thumb ov137
 *   func_021E026C 0x021E026C thumb ov137
 *   func_021E1988 0x021E1988 thumb ov137
 *   func_020056EC 0x020056EC thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007E50 0x02007E50 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E1F34 0x021E1F34 data a4
 */
#include "../include/Obj05430.h"
#include "../include/Obj23759.h"
#include "../include/Obj23760.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Range { u32 low, high; };
extern struct Range d_021E1F34[];
extern void func_021E14E4(const char *p);
struct BigObj;
extern void func_021E026C(u8 *p, int message, unsigned value);
extern void func_021E1988(unsigned int n);
extern u32 func_020056EC(u32);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *, u16, u16, u16);
int func_021DF4AC(u8 *p)
{
    u32 low, high, value;
    int count;
    func_021E14E4((const char *)p);
    if ((((struct Obj05430 *)p)->f1C & (1 << (*(int **)(p + 40))[3])) == 0) {
        ((struct Obj05430 *)p)->f0 = 42;
        return 0;
    }
    count = ((struct Obj05430 *)p)->f30;
    low = d_021E1F34[count].low;
    high = d_021E1F34[count].high;
    low += func_020056EC(65535) % (high - low + 1);
    if (low < d_021E1F34[count].low) low = d_021E1F34[count].low;
    else if (low > high) low = high;
    func_021E026C(p, 3, low);
    value = func_02007E50(func_0201292C((((struct Obj23760 *)(*(u8 * *)&((struct Obj23759 *)(*(u8 * *)&((struct Obj05430 *)p)->fD8))->f14))->f4)), low, 1, 114);
    func_021E1988(1302);
    if (value == 1) ((struct Obj05430 *)p)->f0 = 39;
    else ((struct Obj05430 *)p)->f0 = 40;
    return 0;
}
