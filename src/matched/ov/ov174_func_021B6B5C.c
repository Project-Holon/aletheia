/*
 * function: LOCAL_TVT_SYS_OnSelect,LOCAL_TVT_SYS_ResetTimer,LOCAL_TVT_SYS_TickTimer
 * address: 0x021B6B5C
 * packet: pkt_ov174_021B6B5C
 * region: ov174
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: counter at +0x8a is read at 021B6BAA and reread at 021B6BB6 after store 021B6BB2.
 * symbols:
 *   LOCAL_TVT_SYS_IsPrintIdle 0x021B68E8 thumb ov174
 *   LOCAL_TVT_SYS_HideActor 0x021B6754 thumb ov174
 *   LOCAL_TVT_SYS_DeleteTextWindow 0x021B6994 thumb ov174
 *   LOCAL_TVT_CHARA_ClearState 0x021B7378 thumb ov174
 * Extent includes clear-counter stub 021B6B8C and counter query 021B6B94.
 */
#include "../include/Obj08268.h"
#include "../include/Obj24202.h"
#include "../include/Obj24203.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int LOCAL_TVT_SYS_IsPrintIdle(char *);
extern void LOCAL_TVT_SYS_HideActor(char *);
extern void LOCAL_TVT_SYS_DeleteTextWindow(u8 *p);
extern void LOCAL_TVT_CHARA_ClearState(char *);
int LOCAL_TVT_SYS_OnSelect(char *p)
{
    if(LOCAL_TVT_SYS_IsPrintIdle(p)==1) {
        LOCAL_TVT_SYS_HideActor(p);
        LOCAL_TVT_SYS_DeleteTextWindow((u8 *)p);
        LOCAL_TVT_CHARA_ClearState(*(char **)(p+0x1c+((struct Obj24202 *)p)->f88*4));
        return 1;
    }
    return 0;
}
void LOCAL_TVT_SYS_ResetTimer(char *p)
{
    ((struct Obj24203 *)p)->f8A=0;
}
int LOCAL_TVT_SYS_TickTimer(char *p)
{
    u8 threshold=*(u16 *)(*(char * *)&((struct Obj08268 *)p)->f40+((struct Obj08268 *)p)->f89*4+2);
    ++*(volatile u16 *)&((struct Obj08268 *)p)->f8A;
    if(*(volatile u16 *)&((struct Obj08268 *)p)->f8A>threshold) return 1;
    return 0;
}
