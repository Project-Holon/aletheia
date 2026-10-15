/*
 * function: WIFIBATTLEMATCH_SYS_WaitTask
 * address: 0x022126F4
 * packet: pkt_ov199_022126F4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_SYS_RunScreen 0x02213754 thumb ov199
 *   WIFIBATTLEMATCH_SYS_GetResult 0x02213800 thumb ov199
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 */
#include "../include/Obj08367.h"
struct S;
extern int WIFIBATTLEMATCH_SYS_RunScreen(struct S *s);
extern int WIFIBATTLEMATCH_SYS_GetResult(char *p);
typedef unsigned int   u32;
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
int WIFIBATTLEMATCH_SYS_WaitTask(int unused,int *state,int unused2,char *p)
{
    switch(*state) {
    case 0:
        if(WIFIBATTLEMATCH_SYS_RunScreen((struct S *)(((struct Obj08367 *)p)->f18))) *state=1;
        if(((struct Obj08367 *)p)->f1CC) --((struct Obj08367 *)p)->f1CC;
        {
            int x=WIFIBATTLEMATCH_SYS_GetResult((char *)(((struct Obj08367 *)p)->f18));
            if(x==2 || x==0) GFL_NET_ERR_ShowScreen(0);
        }
        break;
    case 1: return 1;
    }
    return 0;
}
