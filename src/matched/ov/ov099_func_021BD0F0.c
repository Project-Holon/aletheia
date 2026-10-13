/*
 * function: func_021BD0F0
 * address:  0x021BD0F0
 * packet:   pkt_ov099_021BD0F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 */
#include "../include/Obj04415.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct BigObj;
struct Rec534;
extern u32 GFL_NET_IsParentAid(void);
extern int func_021BCBBC(int a, int b, int *out);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021BAAB8(char *p, int a, int b);

int func_021BD0F0(char *p, int v)
{
    int t;
    int out;

    t = 0;
    if (GFL_NET_IsParentAid() == 0) {
        t = 1;
    }
    if (func_021BCBBC(((struct Obj04415 *)p)->f1348, ((struct Obj04415 *)p)->fCC, &out) != 0
        && ((struct Obj04415 *)p)->fCC == 0) {
        POKEPARTY_Copy(GAME_DATA_GetMyParty(((struct Obj04415 *)p)->fC4),
                      *(void **)(*(char * *)&((struct Obj04415 *)p)->f248 + t * 4 + 0x14));
        ((struct Obj04415 *)p)->f1CC = 0x67;
    } else {
        func_021BAAB8(p, 0x71, 0);
        ((struct Obj04415 *)p)->f1CC = 0x65;
    }
    return v;
}
