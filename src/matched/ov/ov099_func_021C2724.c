/*
 * function: func_021C2724
 * address: 0x021C2724
 * packet: pkt_ov099_021C2724
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C2438 0x021C2438 thumb ov099
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021BA7F8 0x021BA7F8 thumb ov099
 *   func_0200AE08 0x0200AE08 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_021BDF7C 0x021BDF7C thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_021BCBB0 0x021BCBB0 thumb ov099
 *   func_021BB224 0x021BB224 thumb ov099
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj03736.h"
#include "../include/Obj06360.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C2438(char *);
typedef unsigned int   u32;
struct Reg;
struct S020315D4;
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_NET_GetRunState(void);
extern void func_021BA7F8(char *);
extern void func_0200AE08(const struct Reg *src, struct Reg *dest);
extern u32 func_020307B0(void *p);
extern void func_021BC0C4(char *);
extern void func_021BDF7C(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void func_021BCBB0(void *);
extern void func_021BB224(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
int func_021C2724(void *task, int unused, char *output, char *p)
{
    if (!func_021C2438(p)) return 0;
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) func_021BA7F8(p);
    ((struct Obj06360 *)output)->f49 = ((struct Obj03736 *)p)->f135C;
    if (((struct Obj03736 *)p)->f1348) {
        func_0200AE08(((struct Obj03736 *)p)->f1348, ((struct Obj06360 *)output)->f1C);
        func_020307B0(((struct Obj03736 *)p)->f1348);
        ((struct Obj03736 *)p)->f1348 = 0;
    }
    func_021BC0C4(p);
    func_021BDF7C(p);
    ((struct Obj06360 *)output)->f47 = ((struct Obj03736 *)p)->f242;
    ((struct Obj06360 *)output)->fC = ((struct Obj03736 *)p)->f1D0;
    if (GFL_NET_GetRunState()) ((struct Obj06360 *)output)->f10 = DWC_RAP_GetTargetFriendIndex();
    func_021BCBB0(((struct Obj03736 *)p)->fCC);
    func_021BB224(p);
    func_020315D4(task);
    func_020306F0(33);
    return 1;
}
