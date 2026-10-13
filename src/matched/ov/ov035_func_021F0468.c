/*
 * function: func_021F0468
 * address:  0x021F0468
 * packet:   pkt_ov035_021F0468
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0468 0x021F0468 thumb
 *   func_021F0254 0x021F0254 thumb ov035
 *   func_021F02FC 0x021F02FC thumb ov035
 *   func_021F0340 0x021F0340 thumb ov035
 *   func_021F0354 0x021F0354 thumb ov035
 *   func_021F0364 0x021F0364 thumb ov035
 *   func_021F0370 0x021F0370 thumb ov035
 *   func_020221A4 0x020221A4 thumb
 *   func_02012204 0x02012204 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02026400 0x02026400 thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 */
#include "../include/Obj01362.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F0254(char *p, int a1, int a2);
extern void func_021F02FC(char *p, int a1);
extern void func_021F0340(char *p);
extern void func_021F0354(char *p);
extern u8 func_021F0364(char *p);
extern u32 func_021F0370(char *p);
extern u32 func_020221A4(void);
struct Comm;
struct Ctx;
extern u32 func_02012204(const struct Ctx *p);
extern u32 func_02026454(void *h);
extern void func_02026400(struct Comm *p);
extern void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v);

int func_021F0468(char *p)
{
    u16 v;

    switch (((struct Obj01362 *)p)->f4A) {
    case 0:
        func_021F0254(p, ((struct Obj01362 *)p)->f18, 2);
        func_021F0254(p, ((struct Obj01362 *)p)->f1C, 3);
        func_021F02FC(p, ((struct Obj01362 *)p)->f0);
        (((struct Obj01362 *)p)->f4A)++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (((struct Obj01362 *)p)->f4A)++;
        break;
    case 2:
        if (func_021F0370(p) != 0 || func_02012204(((struct Obj01362 *)p)->f4) == 1) {
            if (func_021F0364(p) == 0 || func_02012204(((struct Obj01362 *)p)->f4) == 1) {
                if (func_02026454(((struct Obj01362 *)p)->f8))
                    func_02026400(((struct Obj01362 *)p)->f8);
                v = 1;
            } else {
                v = 0;
            }
            ((struct Obj01362 *)p)->f4C = v;
            ((struct Obj01362 *)p)->f4A = 3;
            func_021F0340(p);
        }
        break;
    case 3:
        if (((struct Obj01362 *)p)->f4C != 0) {
            if (func_02026454(((struct Obj01362 *)p)->f8) != 0)
                break;
            GAMESYSTEM_SetAlwaysNetFlag(((struct Obj01362 *)p)->f4, 0);
        }
        (((struct Obj01362 *)p)->f4A)++;
        break;
    case 4:
        return 1;
    }
    func_021F0354(p);
    return 0;
}
