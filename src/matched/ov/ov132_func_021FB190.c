/*
 * function: func_021FB190
 * address: 0x021FB190
 * packet: pkt_ov132_021FB190
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAE1C 0x021FAE1C thumb ov132
 *   func_021F9E08 0x021F9E08 thumb ov132
 *   func_021F9E40 0x021F9E40 thumb ov132
 *   func_021FADF8 0x021FADF8 thumb ov132
 */
#include "../include/Obj08161.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021FAE1C(char *, int *);
typedef unsigned int   u32;
extern void func_021F9E08(u8 *p, u16 v);
extern void func_021F9E40(u8 *p, u32 v);
extern void func_021FADF8(char *, char *);
void func_021FB190(void *unused, char *p)
{
    int v;
    int done = func_021FAE1C(p, &v);
    func_021F9E08(((struct Obj08161 *)p)->f0, v);
    if (done == 1) {
        func_021F9E40(((struct Obj08161 *)p)->f0, 0);
        func_021FADF8(*(char * *)&((struct Obj08161 *)p)->f10, *(char * *)&((struct Obj08161 *)p)->f14);
    }
}
