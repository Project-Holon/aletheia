/*
 * function: func_0217E380,func_0217E40C
 * unit: yes
 * address: 0x0217E380
 * packet: pkt_ov176_0217E380
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: two alignment bytes follow func_0217E40C
 * symbols:
 *   DELIVERY_IRC_Main 0x02157E78 thumb ov010
 *   DELIVERY_IRC_Start 0x02157E34 thumb ov010
 *   DELIVERY_IRC_GetResult 0x02157E6C thumb ov010
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 */
#include "../include/Obj01957.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void DELIVERY_IRC_Main(u8 *p);
extern int DELIVERY_IRC_Start(void *p);
extern unsigned char DELIVERY_IRC_GetResult(char *p);
extern int DELIVERY_IRC_Delete(void *a0);
extern u32 GFL_NET_IsIdle(void);
int func_0217E380(char *p)
{
    if (((struct Obj01957 *)p)->f1018)
        DELIVERY_IRC_Main(((struct Obj01957 *)p)->f1018);
    switch (((struct Obj01957 *)p)->f0) {
    case 0:
        DELIVERY_IRC_Start(((struct Obj01957 *)p)->f1018);
        (((struct Obj01957 *)p)->f0)++;
        break;
    case 1:
        ((struct Obj01957 *)p)->f101C = DELIVERY_IRC_GetResult(((struct Obj01957 *)p)->f1018);
        if (((struct Obj01957 *)p)->f101C)
            (((struct Obj01957 *)p)->f0)++;
        break;
    case 2:
        DELIVERY_IRC_Delete((void *)(((struct Obj01957 *)p)->f1018));
        ((struct Obj01957 *)p)->f1018 = 0;
        (((struct Obj01957 *)p)->f0)++;
        break;
    case 3:
        if (GFL_NET_IsIdle()) {
            switch (((struct Obj01957 *)p)->f101C) {
            case 1: return 1;
            case 3: return 3;
            case 2: break;
            }
            return 2;
        }
        break;
    }
    return 0;
}
void func_0217E40C(int *p) { *p = 0; }
