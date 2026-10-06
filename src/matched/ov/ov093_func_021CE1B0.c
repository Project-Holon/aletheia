/*
 * function: func_021CE1B0
 * address: 0x021CE1B0
 * packet: pkt_ov093_021CE1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CE2E8 0x021CE2E8 thumb ov093
 *   func_021EE6B8 0x021EE6B8 thumb ov093
 *   func_021D3F54 0x021D3F54 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 */
#include "../include/Obj01893.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a : 5; u8 flag : 1; } Flags;
typedef struct { u32 kind : 4; u32 rest : 28; } Command;
extern void func_021CE2E8(u8 *);
extern u32 *func_021EE6B8(void *,u8,u8 *,u8 *);
extern void func_021D3F54(u8 *p);
extern void func_021D3FD0(unsigned char *p);
typedef unsigned short u16;
struct L;
extern void func_021EAF18(struct L *p, int kind, u16 id);
struct H;
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
int func_021CE1B0(u8 *p,int *state)
{
    u8 count;
    u8 flag;
    u32 *data;
    switch (*state) {
    case 0:
        if (((Flags *)(p+0x1b2))->flag) {
            func_021CE2E8(p);
            return 1;
        }
        data = func_021EE6B8(((struct Obj01893 *)p)->f14,p[0x1a6],&count,&flag);
        if (flag) func_021D3F54(p+0x18);
        *(u32 * *)&((struct Obj01893 *)p)->fD8 = data;
        ((struct Obj01893 *)p)->fDC = count * 4;
        if (((Command *)data)->kind == 8) {
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb7);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                (*state)++;
            } else {
                func_021CE2E8(p);
                p[0x1b2] |= 0x10;
                return 1;
            }
        } else if (((Command *)data)->kind == 9) {
            p[0x1b2] |= 0x20;
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb8);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                *state += 2;
            } else {
                func_021CE2E8(p);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            p[0x1b2] |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            return 1;
        }
        break;
    }
    return 0;
}
