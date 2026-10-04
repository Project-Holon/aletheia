/*
 * function: func_021B7BB0
 * address: 0x021B7BB0
 * packet: pkt_ov093_021B7BB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4500 0x021D4500 thumb ov093
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D450C 0x021D450C thumb ov093
 *   func_021D45FC 0x021D45FC thumb ov093
 *   func_021D4648 0x021D4648 thumb ov093
 *   func_021D4674 0x021D4674 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021BA698 0x021BA698 thumb ov093
 *   func_02012EBC 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007B00 0x02007B00 thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj07743.h"
#include "../include/Obj20949.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern int func_021D4270(void);
extern void func_021D4500(void);
extern void func_021D4AF4(int);
extern int func_021D4B18(int);
extern u32 func_021D450C(u32 *);
extern int func_021D45FC(void);
extern void *func_021D4648(u8);
extern void func_021D4674(void);
struct Big;
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern int func_021B9F70(void *,u8);
extern void func_021BA698(void *,u8);
extern void *func_02012EBC(struct Big *p);
extern u32 *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern u32 func_02007B00(void);
extern void func_02082D44(const void *,void *,u32);
int func_021B7BB0(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    void *src;
    q = *(u8 * *)&((struct Obj07743 *)p)->f0;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4500();
        func_021D4AF4(3);
        ++*state;
        break;
    case 1:
        if (func_021D4B18(3)) ++*state;
        break;
    case 2:
        if (func_021D450C(func_02007B44(func_02012EBC(((struct Obj20949 *)q)->f58)))) ++*state;
        break;
    case 3:
        if (func_021D45FC()) {
            for (i = 0; i < 4; ++i) {
                if (func_021B8B9C(p,i) && !func_021B9F70(p,i)) {
                    src = func_021D4648(i);
                    if (src) {
                        *(void **)(p + i * 4 + 0x3e0) = func_02007B20(((struct Obj07743 *)p)->f468);
                        func_02082D44(src, *(void **)(p + i * 4 + 0x3e0),func_02007B00());
                    }
                }
                func_021BA698(p,i);
            }
            func_021D4674();
            ++*state;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
