/*
 * function: func_021C1374
 * address: 0x021C1374
 * packet: pkt_ov099_021C1374
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../include/Obj13702.h"
typedef unsigned short u16;
extern int func_021C1154(char *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern int func_02008468(void);
typedef unsigned char  u8;
extern u8 *func_02012944(void *p);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021BA8EC(char *);
int func_021C1374(char *p, int ret)
{
    int h;
    unsigned count;
    void *q;
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 14, 10) != 0) {
            h = (int)func_020399A8();
            count = func_02008468();
            q = func_02012944(((struct Obj13702 *)p)->fC4);
            if (func_0203D3A8((void *)h, (u16)0xa04, (u16)count, (u32)q) != 0) {
                func_021BA8EC(p);
                ((struct Obj13702 *)p)->f1CC = 135;
            }
        }
    }
    return ret;
}
