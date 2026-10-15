/*
 * function: STA_ACT_SCRIPT_Update
 * address: 0x021FABD8
 * packet: pkt_ov132_021FABD8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: two bytes of zero padding follow the epilogue before 021FAC74.
 * symbols:
 *   STA_ACT_EFFECT_GetSceneOwner 0x021F9E44 thumb ov132
 *   STA_ACT_SCRIPT_RunScript 0x021FAD2C thumb ov132
 *   func_020307B0 0x020307B0 arm
 *   TCB_Main 0x02030D28 arm
 */
#include "../include/Obj10540.h"
#include "../include/Obj14094.h"
#include "../include/Obj23234.h"
#include "../include/Obj23235.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
extern u32 STA_ACT_EFFECT_GetSceneOwner(u8 *p);
extern int STA_ACT_SCRIPT_RunScript(void *, char *);
extern u32 func_020307B0(void *p);
extern void TCB_Main(struct Ctx *c);
void STA_ACT_SCRIPT_Update(char *p)
{
    char **slot;
    u8 i;
    int ready;
    int count;
    ready = 1;
    count = STA_ACT_EFFECT_GetSceneOwner(((struct Obj14094 *)p)->f34);
    while (count != 0) {
        for (i = 0; i < 10; i++) {
            slot = (char **)(p + i * 4);
            if (slot[3] != 0) {
                if (STA_ACT_SCRIPT_RunScript(p, slot[3]) == 1) {
                    func_020307B0(slot[3]);
                    slot[3] = 0;
                } else {
                    if ((((struct Obj23234 *)(slot[3]))->f16 & 2) && !(((struct Obj23235 *)(slot[3]))->f16 & 4)) ready = 0;
                }
            }
        }
        if (ready == 1) {
            for (i = 0; i < 10; i++) {
                char *q;
                q = *(char **)(p + 0xc + i * 4);
                if (q != 0 && (((struct Obj10540 *)q)->f16 & 2) && (((struct Obj10540 *)q)->f16 & 4)) ((struct Obj10540 *)q)->f16 ^= 4;
            }
        }
        TCB_Main(((struct Obj14094 *)p)->f4);
        count--;
    }
}
