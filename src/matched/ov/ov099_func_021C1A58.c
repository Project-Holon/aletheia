/*
 * function: func_021C1A58
 * address: 0x021C1A58
 * packet: pkt_ov099_021C1A58
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021C377C 0x021C377C data a4
 *   func_021C1C9C 0x021C1C9C thumb ov099
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021C1D1C 0x021C1D1C thumb ov099
 *   func_021C208C 0x021C208C thumb ov099
 *   func_021C2090 0x021C2090 thumb ov099
 */
#include "../include/Obj10212.h"
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, int);
typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
typedef unsigned char  u8;
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern const int d_021C377C[];
extern void func_021C1C9C(u32 a, int b, u32 p);
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_021C1D1C(u8 *p, void *a, int heap);
extern void func_021C208C(char *);
extern void func_021C2090(char *);
void func_021C1A58(char *p, int a, int heap)
{
    MI_CpuFill8(p + 0x8b0, 0, 0xf4);
    BG_SYS_SetSubPlaneVisible(7, 1);
    BG_SYS_SetSubPlaneVisible(8, 0);
    ((struct Obj10212 *)p)->f8C8 = BUTTON_MAN_Create((u8 *)d_021C377C, (int)func_021C1C9C, (int)p, heap);
    ((struct Obj10212 *)p)->f8B0 = func_0201EC64((u16)heap);
    func_021C1D1C((u8 *)p, (void *)a, heap);
    ((struct Obj10212 *)p)->f8F4 = 1;
    func_021C208C(p);
    func_021C2090(p);
}
