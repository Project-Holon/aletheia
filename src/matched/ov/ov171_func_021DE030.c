/*
 * function: func_021DE030
 * address: 0x021DE030
 * packet: pkt_ov171_021DE030
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 */
#include "../include/Obj10660.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern u32 CLACT_GetActorAutoAnim(struct Obj *);
extern void CLACT_AddActorAnimFrame(struct Obj *,u32);
extern void CLACT_DrawSystem(void);
void func_021DE030(u8 *p)
{
    unsigned i;
    u8 *element;
    for(i=0;i<16;i++) {
        element=p+i*4;
        if(((struct Obj10660 *)element)->fB74!=0 && CLACT_GetActorAutoAnim(*(struct Obj * *)&((struct Obj10660 *)element)->fB74)!=1)
            CLACT_AddActorAnimFrame(*(struct Obj * *)&((struct Obj10660 *)element)->fB74,4096);
    }
    CLACT_DrawSystem();
}
