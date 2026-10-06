/*
 * function: func_021D46A4
 * address: 0x021D46A4
 * packet: pkt_ov120_021D46A4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 020399A8's r0 is consumed by 02039CB4 despite its void definition.
 * evidence: 020458F8 returns ldrh r0; this caller uses full-word r0+1 without narrowing.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02008510 0x02008510 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0217BC44 0x0217BC44 arm ov009
 *   func_02045808 0x02045808 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4608 0x021D4608 thumb ov120
 */
#include "../include/Obj05341.h"
#include "../include/Obj22824.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern void *func_02008510(void *, int);
extern void func_02082BCC(void *, u8, u32);
struct U16Vec;
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern int func_0217BC44(u16 **, int, char *, int, char *, int *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4608(u8 *);
void func_021D46A4(u8 *p)
{
    void *str;
    u16 *chars;
    u32 i;
    void *value = ((struct Obj22824 *)(*(u8 * *)&((struct Obj05341 *)p)->f48))->f18;
    if (func_02039CB4((struct Link *)func_020399A8(), 3, 0x22) != 0) {
        str = func_02008510(value, 31);
        func_02082BCC(p + 0x188, 0, 40);
        ((struct Obj05341 *)p)->f1AC = 31;
        chars = func_02045A90(str);
        for (i = 0; i < func_020458F8(str) + 1u; i++) {
            u16 c = chars[i];
            if (c == func_02045A98()) ((u16 *)(p + 0x188))[i] = 0;
            else ((u16 *)(p + 0x188))[i] = c;
        }
        ((struct Obj05341 *)p)->f1A0 = p + 0x188;
        ((struct Obj05341 *)p)->f1A8 = 0;
        func_0217BC44((u16 **)(p + 0x1a0), 1, 0, 0, (char *)(p + 0x1a4), (int *)(p + 0x1a8), 128);
        func_02045808(str);
        func_021D4244((int *)p, (int)func_021D4608, 0x29c);
    }
}
