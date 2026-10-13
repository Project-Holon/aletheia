/*
 * function: func_021C143C
 * address: 0x021C143C
 * packet: pkt_ov099_021C143C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the narrowed callee result before comparing the indexed field.
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj06359.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);
extern int func_021C1154(char *);
extern int func_021BDD54(char *, void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned, unsigned);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
int func_021C143C(char *p, int ret)
{
    int index = 0;
    u16 value;
    if (GFL_NET_IsParentAid() != 0) index = 1;
    if (func_021C1154(p) == 0) {
        if (((u16 *)(p + 0x1f4))[index] != 0) {
            value = func_021BDD54(p, ((struct Obj06359 *)p)->f8);
            if (value == ((u16 *)(p + 0x1f4))[index]) {
                func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 15, 10);
                ((struct Obj06359 *)p)->f1CC = 44;
            } else {
                func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
                func_021BAAB8(p, 13, 0);
                ((struct Obj06359 *)p)->f1CC = 19;
            }
        }
    }
    return ret;
}
