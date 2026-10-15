/*
 * function: CTVT_COMM_StopSession
 * address:  0x021B8084
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Chooses the +8 state from the +0x174 code and latches +0x178.
 *
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03853.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern int GFL_NET_Exit(int a);

void CTVT_COMM_StopSession(void *a, char *q)
{
    if (((struct Obj03853 *)q)->f4 <= 1) {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 0xc;
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
        } else {
            GFL_NET_Exit(0);
            ((struct Obj03853 *)q)->f8 = 0xb;
        }
    } else {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 9;
        } else {
            ((struct Obj03853 *)q)->f8 = 8;
        }
    }
    ((struct Obj03853 *)q)->f178 = 1;
}
