/*
 * function: func_021D4864
 * address: 0x021D4864
 * packet: pkt_ov120_021D4864
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02009EA8 0x02009EA8 thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4808 0x021D4808 thumb ov120
 *   GAME_DATA_GetSaveBlock1F  0x02012F14  thumb  arm9
 */
#include "../include/Obj02831.h"
#include "../include/Obj13929.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Rec0200E6FC;
struct Sub02009D9CObj;
extern int func_021D7AF4(char *p);
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *GAME_DATA_GetSaveBlock1F(void **h);
extern u32 func_02009EA8(const struct Sub02009D9CObj *obj);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4808(int *a);
void func_021D4864(u8 *p)
{
    u8 *q;
    int value;
    if (func_021D7AF4((char *)(((struct Obj02831 *)p)->f40))) {
        if (GFL_NET_GetRunState() == 0) {
            func_021D4244((int *)p, (int)func_021D4808, 0x2fe);
            return;
        }
        if (((struct Obj02831 *)p)->f14 > 0) {
            ((struct Obj02831 *)p)->f14 = ((struct Obj02831 *)p)->f14 - 1;
            return;
        }
        if (GFL_NET_HANDLE_GetNegotiationNum() == 2) {
            q = *(u8 * *)&((struct Obj02831 *)p)->f48;
            value = (int)func_0200E6E8(((struct Obj02831 *)p)->f30);
            ((struct Obj13929 *)q)->f4 = ((struct Obj02831 *)p)->f144;
            ((struct Obj13929 *)q)->f8 = ((struct Obj02831 *)p)->f13C;
            func_0200E6FC((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(p + 0x168));
            ((struct Obj02831 *)p)->f170 = func_02009EA8(GAME_DATA_GetSaveBlock1F((void **)(((struct Obj02831 *)p)->f2C)));
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22);
            func_021D4244((int *)p, (int)func_021D4808, 0x314);
        }
    }
}
