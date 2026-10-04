/*
 * function: func_021C5200
 * address: 0x021C5200
 * packet: pkt_ov093_021C5200
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B85EC 0x021B85EC thumb ov093
 *   func_021C52C8 0x021C52C8 thumb ov093
 *   func_021C52D8 0x021C52D8 thumb ov093
 *   func_021C52E8 0x021C52E8 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021BC310 0x021BC310 thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5308 0x021C5308 thumb ov093
 *   func_021C52F8 0x021C52F8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Flags { u8 a:1; u8 b:1; u8 rest:6; };
typedef unsigned short u16;
extern int func_021B85EC(u32 **p);
extern u32 func_021C52C8(u8 *, int);
extern int func_021C52D8(u8 *, int, u8);
extern int func_021C52E8(u8 *, int, u8);
extern u8 *func_021B9934(u8 *, int);
extern void *func_021B86B8(void ***p);
extern int func_021BC2B0(u8 *);
extern int func_021BC310(u8 *);
extern u16 func_021B86DC(void **p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C5308(u8 *, u8 *);
extern void func_021C52F8(u8 *, int, u8);
int func_021C5200(u8 *p)
{
    int result = 0;
    u32 i;
    u32 count;
    u8 *a;
    if (func_021B85EC(((struct Obj00003 *)p)->f4)) {
        count = func_021C52C8(p + 0x3e0, 0);
        for (i = 0; i < count; i++) {
            if (!func_021C52D8(p + 0x3e0, 0, i)) {
                a = func_021B9934(*(u8 * *)&((struct Obj00003 *)p)->f8, func_021C52E8(p + 0x3e0, 0, i));
                if (!func_021B86B8(((struct Obj00003 *)p)->f4) && !((struct Flags *)(p + 0x78a))->b && func_021BC2B0(p) && func_021BC310(p)) {
                    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x55, func_021B86DC(((struct Obj00003 *)p)->f4));
                    ((struct Flags *)(p + 0x78a))->b = 1;
                }
                if (func_021C5308(p, a)) result = 1;
                func_021C52F8(p + 0x3e0, 0, i);
            }
        }
    }
    return result;
}
