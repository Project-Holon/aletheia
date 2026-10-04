/*
 * function: func_021BE4F8
 * address:  0x021BE4F8
 * packet:   pkt_ov021_021BE4F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE4F8  0x021BE4F8  thumb
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 */
#include "../include/Obj06057.h"
#include "../include/Obj09660.h"
#include "../include/Obj20144.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A00(u8 *a0, int i);
extern void *func_02048A18(void *res, u16 id);
struct Arg;
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void func_02047A60(void *a, void *b);

void func_021BE4F8(char *p)
{
    u8 i;
    u8 j;
    int base;
    int n;
    char *e;
    char *ent;

    for (i = 0; i < 4; i++) {
        e = p + i * 16;
        if (((struct Obj06057 *)e)->f8 == 1) {
            base = func_020489F4(((struct Obj09660 *)p)->f4, ((struct Obj06057 *)e)->f14);
            n = func_02048A00(((struct Obj09660 *)p)->f4, ((struct Obj06057 *)e)->f14);
            for (j = 0; j < n; j++) {
                if (*(int *)(*(char * *)&((struct Obj06057 *)e)->fC + j * 0x44 + 4) == 0) {
                    void *r = func_02048A18(((struct Obj09660 *)p)->f4, base + j);
                    ent = *(char * *)&((struct Obj06057 *)e)->fC + j * 0x44;
                    if (((struct Obj20144 *)ent)->f0 != 0) {
                        func_02047AC8(r, (struct Arg *)(ent + 8));
                    } else {
                        func_02047A60(r, ent + 8);
                    }
                }
            }
        }
    }
}
