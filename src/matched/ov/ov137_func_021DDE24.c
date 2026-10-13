/*
 * function: func_021DDE24
 * address: 0x021DDE24
 * packet: pkt_ov137_021DDE24
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 *   func_021DD924 0x021DD924 thumb ov137
 */
#include "../include/Obj14216.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
typedef unsigned char  u8;
extern void *func_021DCF50(u8 *p);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021DE4B4(char *, int, int);
extern void func_021DD93C(char *, int);
extern void func_021DD924(char *);
int func_021DDE24(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        func_021DE4B4(p, 5, 0);
    } else {
        func_0201F02C(((struct Obj14216 *)p)->f3C, 0, UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p), 0));
        func_021DE4B4(p, 0x10, 0);
    }
    func_021DD93C(p, 0xe);
    ((struct Obj14216 *)p)->f124 = 0;
    func_021DD924(p);
    return state;
}
