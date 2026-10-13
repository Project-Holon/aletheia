/*
 * function: BTL_MAIN_IsOwnWindowWaiting
 * address:  0x021BA5D8
 * packet:   pkt_ov093_021BA5D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsWindowWaiting  0x021CDDA0  thumb  ov093
 */
#include "../include/Obj07748.h"
#include "../include/Obj21016.h"

typedef unsigned char  u8;
extern int BTL_CLIENT_IsWindowWaiting(u8 *p);

int BTL_MAIN_IsOwnWindowWaiting(char *p)
{
    int *q = *(int * *)&((struct Obj07748 *)p)->f0;
    if (((struct Obj21016 *)q)->f23 == 0) {
        if (((struct Obj07748 *)p)->f440 != 0)
            return BTL_CLIENT_IsWindowWaiting((u8 *)(*(int *)(p + (((struct Obj07748 *)p)->f46C << 2) + 0x10)));
        return 0;
    }
    return BTL_CLIENT_IsWindowWaiting((u8 *)(*(int *)(p + (((struct Obj07748 *)p)->f46C << 2) + 0x10)));
}
