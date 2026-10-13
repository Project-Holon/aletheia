/*
 * packet: pkt_ov186_021FFEA8
 * function: func_021FFEA8
 * address: 0x021FFEA8
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   d_02200DAC 0x02200DAC data a1
 */
#include "../include/Obj04590.h"
typedef struct Request { unsigned short x, y, id; unsigned char flag, pad; } Request;
typedef unsigned int   u32;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC124(void *, unsigned, void *);
extern void *func_021FB378(void *, int, int, int, int, int, int, int, void *, unsigned short);
extern void *MI_CpuFill8(void *, int, unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02200DAC[];
void func_021FFEA8(char *p)
{
    Request req;
    int info[3];
    int a = func_021FC20C(*(char * *)&((struct Obj04590 *)p)->f28);
    int b = func_021FC214(*(char * *)&((struct Obj04590 *)p)->f28);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x50; req.y = 0xa8; req.id = 0; req.flag = 1;
    if (!func_021FC124(((struct Obj04590 *)p)->f28, 6, info))
        func_02034714(d_02200DAC, 0, d_02200DAC);
    ((struct Obj04590 *)p)->f2C = func_021FB378(&req, 4, 0x60, 1, ((struct Obj04590 *)p)->f34, ((struct Obj04590 *)p)->f38, a, b, info, ((struct Obj04590 *)p)->f24);
}
