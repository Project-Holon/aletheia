/*
 * function: func_021C1374
 * address: 0x021C1374
 * packet: pkt_ov099_021C1374
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1154 0x021C1154 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   MYSTATUS_GetSize  0x02008468  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj13702.h"
typedef unsigned short u16;
extern int func_021C1154(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern int MYSTATUS_GetSize(void);
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetMyStatus(void *p);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021BA8EC(char *);
int func_021C1374(char *p, int ret)
{
    int h;
    unsigned count;
    void *q;
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 14, 10) != 0) {
            h = (int)GFL_NET_HANDLE_GetCurrentHandle();
            count = MYSTATUS_GetSize();
            q = GAME_DATA_GetMyStatus(((struct Obj13702 *)p)->fC4);
            if (GFL_NET_SendToHandle((void *)h, (u16)0xa04, (u16)count, (u32)q) != 0) {
                func_021BA8EC(p);
                ((struct Obj13702 *)p)->f1CC = 135;
            }
        }
    }
    return ret;
}
