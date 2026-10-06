/*
 * function: func_021D8484
 * address: 0x021D8484
 * packet: pkt_ov120_021D8484
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8B20 0x021D8B20 data ov120 a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj05353.h"
typedef struct { int a, b; } Pair;
extern const Pair d_021D8B20;
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PmsDraw;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
struct Obj;
extern void func_0202DC60(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D8484(char *p, void *n)
{
    Pair c = d_021D8B20;
    void *q;
    if (!((struct Obj05353 *)p)->f88) ((struct Obj05353 *)p)->f88 = (void *)func_020450F0(1, 1, 15, 30, 5, 11, 1);
    q = ((struct Obj05353 *)p)->f88;
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(15, 2, 0);
    func_0202DE5C(((struct Obj05353 *)p)->fCC, 0);
    func_0202DE64(((struct Obj05353 *)p)->fCC, 0x3c40);
    func_0202DC60(((struct Obj05353 *)p)->fCC, (u32)q, n, 0, (u32)(&c));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
