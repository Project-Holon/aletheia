/*
 * function: BTLV_SCU_GetBallStates
 * address: 0x021EE104
 * packet: pkt_ov093_021EE104
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021EE1FE..021EE200 is zero alignment padding.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 */
#include "../include/Obj00027.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *, u8, u32);
struct Q1;
struct S2;
struct Unk021D62A8;
extern char *func_021B9AF8(char *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
void BTLV_SCU_GetBallStates(u8 *p, u32 *out, u32 a, u32 b, u32 flag)
{
    void *groups[2] = {0, 0};
    int counts[2] = {0, 0};
    int i;
    int side;
    s8 slot;
    void *entry;
    func_02082BCC(out, 0, 28);
    groups[0] = func_021B9AF8(((struct Obj00027 *)p)->f138, a);
    counts[0] = func_021B9B94(groups[0]);
    if (b < 4) {
        groups[1] = func_021B9AF8(((struct Obj00027 *)p)->f138, b);
        counts[1] = func_021B9B94(groups[1]);
        if (counts[0] > 3) counts[0] = 3;
        if (counts[1] > 3) counts[1] = 3;
    }
    out[0] = flag;
    for (i = 0; i < 6; i++) {
        if (i < counts[0] + counts[1]) {
            if (i < counts[0]) { side = 0; slot = i; }
            else { side = 1; slot = i - counts[0]; }
            entry = func_021B9C00(groups[side], (u8)slot);
            if (BTL_POKEPARAM_IsFainted(entry)) out[side * 3 + slot + 1] = 2;
            else if (BTL_POKEPARAM_GetMajorStatusIndex(entry)) out[side * 3 + slot + 1] = 3;
            else if (!BTL_POKEPARAM_IsAbleToBattle(entry)) out[side * 3 + slot + 1] = 0;
            else out[side * 3 + slot + 1] = 1;
        }
    }
}
