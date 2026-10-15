/*
 * function: MYSTERY_NET_RunIrc
 * address: 0x021DE910
 * packet: pkt_ov121_021DE910
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DELIVERY_IRC_Main 0x02157E78 thumb ov010
 *   DELIVERY_IRC_GetResult 0x02157E6C thumb ov010
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_DeleteIrc 0x021DE8D0 thumb ov121
 */
#include "../include/Obj08102.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void DELIVERY_IRC_Main(u8 *p);
extern unsigned char DELIVERY_IRC_GetResult(char *p);
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_DeleteIrc(void *, int *, char *);
void MYSTERY_NET_RunIrc(void *a, int *state, char *p)
{
    int result;
    DELIVERY_IRC_Main(((struct Obj08102 *)p)->f79C);
    result = DELIVERY_IRC_GetResult(((struct Obj08102 *)p)->f79C);
    if (result != 0) {
        switch (result) {
        case 1: ((struct Obj08102 *)p)->f17A4 = 1; break;
        case 2:
        case 3: ((struct Obj08102 *)p)->f17A4 = 2; break;
        }
        MYSTERY_NET_SetHandler(a, MYSTERY_NET_DeleteIrc);
    }
}
