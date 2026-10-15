/*
 * function: WORLDTRADE_ENTER_InitDwcTrade
 * address: 0x021F8AB0
 * packet: pkt_ov135_021F8AB0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 * symbols:
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   DPW_TR_Init 0x021C7BA0 arm ov114
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb  arm9
 */
#include "../include/Obj23396.h"
#include "../include/Obj23397.h"
#include "../include/Obj23398.h"
#include "../include/Obj23399.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Sub020097BCObj;
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int WIFILIST_GetGsProfileId(void *a0);
struct DWCstAccUserData;
struct Sub0200852CObj;
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
extern void DPW_TR_Init(u32 a, u32 b, u32 c, int d);
int WORLDTRADE_ENTER_InitDwcTrade(u8 **p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = func_02009860(((struct Obj23396 *)(*p))->f14);
    func_02008540(((struct Obj23397 *)(*p))->f1C, WIFILIST_GetGsProfileId(((struct Obj23398 *)(*p))->f14));
    id = func_0200853C(((struct Obj23399 *)(*p))->f1C);
    key = DWC_CreateFriendKey(handle);
    DPW_TR_Init(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}
