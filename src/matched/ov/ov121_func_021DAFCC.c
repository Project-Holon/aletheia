/*
 * unit: yes
 * function: MYSTERY_ALBUM_UpdateWindows, MYSTERY_ALBUM_GetWindowState
 * address: 0x021DAFCC
 * packet: pkt_ov121_021DAFCC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: unit includes tail-call follower MYSTERY_ALBUM_GetWindowState (function-start seed).
 * symbols:
 *   MYSTERY_UTIL_IsWindowListDone 0x021DA2C8 thumb ov121
 *   MYSTERY_UTIL_IsMessageDone 0x021D9B34 thumb ov121
 *   MYSTERY_ALBUM_StepIntro 0x021DD9CC thumb ov121
 *   MYSTERY_UTIL_GetTaskField04 0x021DA8AC thumb ov121
 */
#include "../include/Obj10417.h"
#include "../include/Obj22899.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int MYSTERY_UTIL_IsWindowListDone(u8 *p);
extern int MYSTERY_UTIL_IsMessageDone(u8 *p);
extern void MYSTERY_ALBUM_StepIntro(char *p);
extern int MYSTERY_UTIL_GetTaskField04(u32 *p);
static inline void update(void *p)
{
    if(p) MYSTERY_ALBUM_StepIntro(p);
}
void MYSTERY_ALBUM_UpdateWindows(char *p)
{
    int i;
    MYSTERY_UTIL_IsWindowListDone(((struct Obj10417 *)p)->fAB8);
    if(((struct Obj10417 *)p)->fAB4) MYSTERY_UTIL_IsMessageDone(((struct Obj10417 *)p)->fAB4);
    for(i=0;i<12;i++) {
        void *q=*(void **)(p+i*4+0xa7c);
        if(q) update(q);
    }
}
int MYSTERY_ALBUM_GetWindowState(char *p)
{
    return MYSTERY_UTIL_GetTaskField04(((struct Obj22899 *)p)->fAC4);
}
