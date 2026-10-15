/*
 * function: UN_SELECT_GRAPHIC_Delete
 * address: 0x021BA8F0
 * packet: pkt_ov218_021BA8F0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display registers 04000050/04001050 are cleared at A916/A91C; 04000000/04001000 read and masked at A91E-A92C.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   UN_SELECT_GRAPHIC_DeleteCamera 0x021BAB00 thumb ov218
 *   UN_SELECT_GRAPHIC_DeleteClact 0x021BAA64 thumb ov218
 *   UN_SELECT_GRAPHIC_CleanupBg 0x021BA9E0 thumb ov218
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj26050.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void UN_SELECT_GRAPHIC_DeleteCamera(int *);
extern void UN_SELECT_GRAPHIC_DeleteClact(char *);
extern void UN_SELECT_GRAPHIC_CleanupBg(void *p);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *, int, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void UN_SELECT_GRAPHIC_Delete(char *ctx)
{
    func_02030EAC(((struct Obj26050 *)ctx)->fC);
    UN_SELECT_GRAPHIC_DeleteCamera((int *)(ctx + 8));
    UN_SELECT_GRAPHIC_DeleteClact(ctx + 4);
    UN_SELECT_GRAPHIC_CleanupBg(ctx);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    MI_CpuFill8(ctx, 0, 16);
    func_020307B0(ctx);
}
