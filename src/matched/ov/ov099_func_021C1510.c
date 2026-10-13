/*
 * function: func_021C1510
 * address: 0x021C1510
 * packet: pkt_ov099_021C1510
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1154 0x021C1154 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_021C14EC 0x021C14EC thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   GAME_DATA_GetWifiList  0x0201283C  thumb  arm9
 */
#include "../include/Obj10211.h"
typedef unsigned char u8;
extern int func_021C1154(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern int func_021C14EC(char *);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct Sub020097BCFriend;
struct Sub020097BCObj;
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern int func_0200F4E4(void *o);
extern void func_021BA8EC(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern int func_021C23B8(int i);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021C18C8(char *p, int kind, int value);
int func_021C1510(char *p, int ret)
{
    void *s;
    unsigned count;
    if (func_021C1154(p) == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 18, 10) != 0) {
            if (func_021C14EC(p) == 1) {
                func_0200F4E4(func_020099C8((struct Sub020097BCObj *)GAME_DATA_GetWifiList(((struct Obj10211 *)p)->fC4), 0));
                func_021BA8EC(p);
                s = (void *)func_021C23B8(DWC_RAP_GetTargetFriendIndex());
                func_021BDD48(p, s);
                count = func_021BDD54(p, s);
                if (count == 3) {
                    ((struct Obj10211 *)p)->f1CC = 65;
                } else {
                    func_021C18C8(p, 4, count);
                    ((struct Obj10211 *)p)->f1CC = 115;
                }
            }
        }
    }
    return ret;
}
