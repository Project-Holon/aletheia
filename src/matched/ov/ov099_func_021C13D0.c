/*
 * function: func_021C13D0
 * address: 0x021C13D0
 * packet: pkt_ov099_021C13D0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../include/Obj04417.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 a, b; unsigned c; } Request;
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern unsigned func_021BCBD8(char *, int);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
int func_021C13D0(char *p, int ret)
{
    Request request;
    func_021BDD48(p, ((struct Obj04417 *)p)->f8);
    request.a = func_021BDD54(p, ((struct Obj04417 *)p)->f8);
    if (((struct Obj04417 *)p)->f1356 != 0) {
        request.b = ((struct Obj04417 *)p)->f1356 - 1;
        ((struct Obj04417 *)p)->f1356 = 0;
    } else {
        request.b = *((u8 *)((struct Obj04417 *)p)->f248 + 0x46);
    }
    request.c = func_021BCBD8(p, 1);
    if (func_0203D3A8(func_020399A8(), 0xa03, 8, (u32)(&request)) != 0)
        ((struct Obj04417 *)p)->f1CC = 43;
    return ret;
}
