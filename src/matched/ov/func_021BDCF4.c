/*
 * function: WIFICLUB_CopyFriendEntry
 * address:  0x021BDCF4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   func_02009C24  0x02009C24  thumb
 *
 * Same handle at +0xC4 of the third argument, its accessor result forwarded
 * together with the first two arguments.
 */
#include "../include/Obj18251.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct Sub020097BCObj;
extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);

void WIFICLUB_CopyFriendEntry(int a, int b, char *p)
{
    func_02009C24((struct Sub020097BCObj *)GAME_DATA_GetWifiList(((struct Obj18251 *)p)->fC4), a, b);
}
