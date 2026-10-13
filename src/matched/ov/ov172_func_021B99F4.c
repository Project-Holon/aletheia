/*
 * function: func_021B99F4
 * address: 0x021B99F4
 * packet: pkt_ov172_021B99F4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Byte at q+15 re-read at 021B9A46 following store at 021B9A44; q+13 re-read at 021B9A7A following store at 021B9A78.
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   d_021C6F8F 0x021C6F8F data a1
 */
#include "../include/Obj00998.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern int TOUCHPANEL_HitTrg(const void *);
extern int TOUCHPANEL_HitCont(const void *);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
extern void GFL_USE_PlaySeInSlot(void *, int);
extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);
extern const u8 d_021C6F8F[];
void func_021B99F4(void *unused, u8 *q)
{
    u32 a = TOUCHPANEL_HitTrg(d_021C6F8F);
    u32 b = TOUCHPANEL_HitCont(d_021C6F8F);
    int flag = -1;
    int changed = 0;
    if (a != -1) {
        q[15] = 0;
        if (a <= 1) { q[14] = 0; flag = 0; }
        else { q[14] = 1; flag = 1; }
    } else if (b != -1) {
        int agree = 0;
        if (b <= 1) { if (q[14] == 0) agree = 1; }
        else { if (q[14] == 1) agree = 1; }
        if (agree == 1) {
            q[15]++;
            if (*(volatile u8 *)&((struct Obj00998 *)q)->fF >= 25) {
                flag = q[14];
                q[15] = 10;
            }
        } else q[14] = 255;
    } else q[14] = 255;
    if (flag == 0) {
        if (q[13] < 8) {
            changed = 1; q[13]++;
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00998 *)q)->f90, (u16)(*(volatile u8 *)&((struct Obj00998 *)q)->fD + 25));
        }
    } else if (flag == 1) {
        if (q[13] > 0) {
            changed = 1; q[13]--;
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00998 *)q)->f90, (u16)(*(volatile u8 *)&((struct Obj00998 *)q)->fD + 25));
        }
    }
    if (changed == 1) {
        int angle;
        angle = (q[13] - 4) * 64;
        GFL_USE_PlaySeInSlot((void *)1644, 1);
        GFL_USE_SetSeSlotParams(1, -1, angle, -1);
    }
}
