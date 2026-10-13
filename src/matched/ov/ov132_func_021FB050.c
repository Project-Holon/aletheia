/*
 * function: func_021FB050
 * address: 0x021FB050
 * packet: pkt_ov132_021FB050
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_021F9E00 0x021F9E00 thumb ov132
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB0DC 0x021FB0DC thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
#include "../include/Obj03819.h"
#include "../include/Obj06490.h"
#include "../include/Obj08159.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_021F9DFC(void *);
extern void func_021F9E00(void *, u16);
extern void *func_021FADA0(char *, u32, u32, u32);
extern void func_021FB0DC(void *unused, char *p);
int func_021FB050(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct Obj06490 *)ctx)->f0;
    time = VM_GetU32(((struct Obj06490 *)ctx)->f4);
    target = VM_GetU32(((struct Obj06490 *)ctx)->f4);
    wait = VM_GetU32(((struct Obj06490 *)ctx)->f4);
    if (time == 0) {
        func_021F9E00(((struct Obj08159 *)owner)->f34, target);
    } else {
        p = func_02030734(((struct Obj08159 *)owner)->f0, 0x18, 0, d_021FDD00, 0x1e9);
        *(char * *)&((struct Obj03819 *)p)->f10 = owner;
        ((struct Obj03819 *)p)->f0 = ((struct Obj08159 *)owner)->f34;
        ((struct Obj03819 *)p)->fE = 0;
        ((struct Obj03819 *)p)->f4 = func_021F9DFC(((struct Obj08159 *)owner)->f34);
        ((struct Obj03819 *)p)->f8 = target;
        ((struct Obj03819 *)p)->fC = time;
        ((struct Obj03819 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
        if (wait == 1) {
            ((struct Obj06490 *)ctx)->f14 = ((struct Obj03819 *)p)->fC;
            return 1;
        }
    }
    return 0;
}
