/*
 * function: func_021EFF78
 * address:  0x021EFF78
 * packet:   pkt_ov035_021EFF78
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EFF78 0x021EFF78 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021F000C 0x021F000C thumb ov035
 *   func_021F0140 0x021F0140 thumb ov035
 *   func_021F0168 0x021F0168 thumb ov035
 *   func_0203D34C 0x0203D34C arm
 *   func_021A12D4 0x021A12D4 thumb ov021
 */
#include "../include/Obj04315.h"

struct GfFont;
struct MsgBank;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern void func_0201DD68(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int func_0201C440(void *p);
typedef unsigned int   u32;
extern void func_021F000C(char *p, u32 heap);
extern void func_021F0140(void *, int);
extern void func_021F0168(int *p, int a1);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021A12D4(u32 *p, u32 x);

void func_021EFF78(char *p, void *a1)
{
    *(int *)&((struct Obj04315 *)p)->f34 = (int)func_0201D7EC(0x17, 0, 0, 0, (unsigned int)a1);
    func_0201DD68();
    ((struct Obj04315 *)p)->f38 = (int)func_02045B38(0, 2, 0x16, (unsigned int)a1);
    *(int *)&((struct Obj04315 *)p)->f3C = func_0201C440(a1);
    func_021F000C(p, (u32)a1);
    func_021F0140(p, (int)a1);
    func_021F0168((int *)p, (int)a1);
    func_0203D34C(0, (u32)a1);
    func_021A12D4((u32 *)(((struct Obj04315 *)p)->fC), (int)a1);
}
