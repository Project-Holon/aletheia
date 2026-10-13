/*
 * function: func_021EE850
 * address:  0x021EE850
 * packet:   pkt_ov170_021EE850
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj24039.h"

typedef unsigned int u32;

struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern void func_021DD238(char *p);

unsigned func_021EE850(char *p)
{
    unsigned r = func_02025DE8(((struct Obj24039 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
    if (r == -1) {
        if (KEY_GetTrg() & 0x800) {
            func_021DD238(p);
            return 0x28;
        }
        if (KEY_GetRepeat() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}
