/*
 * function: func_021D4864
 * address: 0x021D4864
 * packet: pkt_ov120_021D4864
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399EC 0x020399EC arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02009EA8 0x02009EA8 thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4808 0x021D4808 thumb ov120
 */
#include "../include/Obj02831.h"
#include "../include/Obj13929.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Rec0200E6FC;
struct Sub02009D9CObj;
extern int func_021D7AF4(char *p);
extern int func_0203CD98(void);
extern int func_020399EC(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *func_02012F14(void **h);
extern u32 func_02009EA8(const struct Sub02009D9CObj *obj);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4808(int *a);
void func_021D4864(u8 *p)
{
    u8 *q;
    int value;
    if (func_021D7AF4((char *)(((struct Obj02831 *)p)->f40))) {
        if (func_0203CD98() == 0) {
            func_021D4244((int *)p, (int)func_021D4808, 0x2fe);
            return;
        }
        if (((struct Obj02831 *)p)->f14 > 0) {
            ((struct Obj02831 *)p)->f14 = ((struct Obj02831 *)p)->f14 - 1;
            return;
        }
        if (func_020399EC() == 2) {
            q = *(u8 * *)&((struct Obj02831 *)p)->f48;
            value = (int)func_0200E6E8(((struct Obj02831 *)p)->f30);
            ((struct Obj13929 *)q)->f4 = ((struct Obj02831 *)p)->f144;
            ((struct Obj13929 *)q)->f8 = ((struct Obj02831 *)p)->f13C;
            func_0200E6FC((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(p + 0x168));
            ((struct Obj02831 *)p)->f170 = func_02009EA8(func_02012F14((void **)(((struct Obj02831 *)p)->f2C)));
            func_02039C68((struct Link *)func_020399A8(), 2, 0x22);
            func_021D4244((int *)p, (int)func_021D4808, 0x314);
        }
    }
}
