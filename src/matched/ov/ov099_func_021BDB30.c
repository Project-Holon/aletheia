/*
 * function: func_021BDB30
 * address: 0x021BDB30
 * packet: pkt_ov099_021BDB30
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: BCB70 matched callers declare void; original consumes r0 after BL, so the return is int here. 399A8 own void tail-forwarder leaves r0 live and caller passes that result to D1E8/39C68. BDD54 own u8 return is widened to retain the original explicit u16 truncation.
 * symbols:
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BC104 0x021BC104 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_NotifyUserEvent 0x0203D1E8 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj02155.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BDD54(char *, void *);
extern void func_021BC104(char *);
extern void func_021C24A4(void *, int);
extern void func_021BAADC(char *, int, int);
struct BigObj;
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32 *mask);
extern int func_021BCBBC(int, int, int *);
extern void func_021BAAB8(char *, int, int);
extern void *GFL_NET_GetInitParam(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_NotifyUserEvent(u32, void *);
extern u32 GFL_NET_IsParentAid(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
int func_021BDB30(char *p, int v)
{
    u16 state;
    int out;
    state = (u16)func_021BDD54(p, ((struct Obj02155 *)p)->f8);
    switch (state) {
    case 4:
        GFL_NET_GetInitParam();
        func_021BC104(p);
        func_021C24A4(p, 0);
        func_021BAADC(p, 0x7b, 0);
        ((struct Obj02155 *)p)->f1355 = 0;
        ((struct Obj02155 *)p)->f1CC = 0x10;
        return v;
    case 5:
        ((struct Obj02155 *)p)->f1D0 = state;
        return 2;
    case 6:
        func_021BC104(p);
        ((struct Obj02155 *)p)->f1D0 = state;
        return 2;
    default:
        GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
        if (GFL_NET_IsParentAid()) {
            if (func_021BCB70((void *)(((struct Obj02155 *)p)->f1348), (const struct BigObj *)(((struct Obj02155 *)p)->fC4), (u32 *)(&out)) &&
                func_021BCBBC(((struct Obj02155 *)p)->f1348, ((struct Obj02155 *)p)->fCC, &out)) {
                func_021BAAB8(p, 0x68, 0);
                ((struct Obj02155 *)p)->f1CC = 0x74;
                return v;
            }
            ((struct Obj02155 *)p)->f1CC = 0x5b;
        } else {
            GFL_NET_HANDLE_SetTimingSyncRange((void *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
            ((struct Obj02155 *)p)->f1CC = 0x49;
        }
        return v;
    }
}
