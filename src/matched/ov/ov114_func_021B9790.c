/*
 * function: NHTTP_RAP_PollConnection
 * address: 0x021B9790
 * packet: pkt_ov114_021B9790
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * NHTTP_GetConnectionError 0x021BF488 arm ov114
 * NHTTP_GetConnectionProgress 0x021BF4B0 arm ov114
 * NHTTP_GetHeaderAll 0x021BE838 arm ov114
 * NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 * GFL_NET_STATE_SetError 0x0203C9AC arm
 */
#include "../include/Obj03763.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTP_GetConnectionError(int a);
extern int NHTTP_GetConnectionProgress(u32, int *, int *);
extern int NHTTP_GetHeaderAll(void *handle, char **value_pp);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern void NHTTP_RAP_DeleteConnection(u8 *);
int NHTTP_RAP_PollConnection(u8 *p)
{
    int a,b,c;
    int result;
    if (p == 0) return -1;
    if (((struct Obj03763 *)p)->fC == 0) return 0;
    result = NHTTP_GetConnectionError(((struct Obj03763 *)p)->fC);
    if (result == 15) {
        NHTTP_GetConnectionProgress(((struct Obj03763 *)p)->fC, &a, &b);
    } else {
        int x = NHTTP_GetConnectionError(((struct Obj03763 *)p)->fC);
        if (x == 0) NHTTP_GetHeaderAll((void *)(((struct Obj03763 *)p)->fC), (char **)(&c));
        else GFL_NET_STATE_SetError(x, 2, x, 0x3f6);
        NHTTP_RAP_DeleteConnection(p);
        return result;
    }
    return result;
}
