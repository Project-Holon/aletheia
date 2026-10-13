/*
 * function: VCT_MAIN_InitAudio
 * address:  0x021AEB20
 * packet:   pkt_ov013_021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0208B24C  0x0208B24C  arm
 *   func_0208B8B0  0x0208B8B0  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   VCT_SESSION_SetSendEnabled  0x021B0CD8  arm  ov013
 *   func_020726D0  0x020726D0  arm
 *   func_020737C0  0x020737C0  arm
 *   func_02082AC0  0x02082AC0  arm
 *   VCT_SESSION_SetFilterEnabled  0x021B0D08  arm  ov013
 *   gVctWork     0x021B3C80  data  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct Work *gVctWork;

extern void func_0208B24C(void);
extern void func_0208B8B0(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern unsigned int func_0208BF38(unsigned int gain);
extern void VCT_SESSION_SetSendEnabled(int x);
extern void func_020726D0(void);
struct S;
extern void func_020737C0(struct S *p);
extern void func_02082AC0(int v, void *p, u32 n);
extern void VCT_SESSION_SetFilterEnabled(int x);

void VCT_MAIN_InitAudio(void)
{
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF38(3);
    VCT_SESSION_SetSendEnabled(1);
    func_020726D0();
    func_020737C0((struct S *)(((u8 *)gVctWork) + 0x19B8));
    func_02082AC0(0, ((u8 *)gVctWork) + 0x1104, 0x880);
    *(u32 *)(((u8 *)gVctWork) + 0x1A44) = 0;
    VCT_SESSION_SetFilterEnabled(1);
}
