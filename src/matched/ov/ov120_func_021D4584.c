/*
 * function: func_021D4584
 * address: 0x021D4584
 * packet: pkt_ov120_021D4584
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D880C 0x021D880C thumb ov120
 *   func_021D74B0 0x021D74B0 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4544 0x021D4544 thumb ov120
 */
#include "../include/Obj04484.h"
#include "../include/Obj06433.h"
typedef unsigned char u8;
extern int func_0203CD98(void);
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_021D880C(char *p, void *q, u32 n);
extern void func_021D74B0(u8 *p, int n);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4544(int *a);
void func_021D4584(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj06433 *)p)->f48;
    int value;
    int mode = 2;
    if (func_0203CD98() == 0) {
        value = (int)func_02012944((void *)(((struct Obj04484 *)q)->f0));
    } else {
        value = ((struct Obj04484 *)q)->f18;
        mode = ((struct Obj06433 *)p)->f17C;
        *(int *)(q + ((struct Obj04484 *)q)->f1AC * 4 + 0x1c) = func_02008530((const struct Sub0200852CObj *)value);
        ((struct Obj04484 *)q)->f1AC = ((struct Obj04484 *)q)->f1AC + 1;
        if (((struct Obj04484 *)q)->f1AC >= 100)
            ((struct Obj04484 *)q)->f1AC = 0;
    }
    func_021D880C((char *)(((struct Obj06433 *)p)->f40), (void *)value, mode);
    func_021D74B0((u8 *)(((struct Obj06433 *)p)->f3C), func_02008554((const struct Sub0200852CObj *)value));
    ((struct Obj06433 *)p)->f14 = 0xb4;
    func_021D4244((int *)p, (int)func_021D4544, 0x265);
}
