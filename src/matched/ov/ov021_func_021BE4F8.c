/*
 * function: FLD_EXP_OBJ_Draw
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
 *   FLD_EXP_OBJ_Draw  0x021BE4F8  thumb
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 */
#include "../include/Obj06057.h"
#include "../include/Obj09660.h"
#include "../include/Obj20144.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A00(u8 *a0, int i);
struct Arg;
extern u32 func_02048A18(u8 *a0, int i);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void FLD_EXP_OBJ_Draw(char *p)
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
                    void *r = (void *)func_02048A18(((struct Obj09660 *)p)->f4, (u16)(base + j));
                    ent = *(char * *)&((struct Obj06057 *)e)->fC + j * 0x44;
                    if (((struct Obj20144 *)ent)->f0 != 0) {
                        G3D_SYSTEM_DrawObjectCulling(r, (struct Arg *)(ent + 8));
                    } else {
                        G3D_SYSTEM_DrawObject(r, (struct Arg *)(ent + 8));
                    }
                }
            }
        }
    }
}
