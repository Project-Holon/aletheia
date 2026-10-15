/*
 * function: BR_BTN_PushRecord
 * address:  0x021FA020
 * packet:   pkt_021FA020
 * region:   ov186
 * status:   EXACT
 * symbols:
 *   BR_BTN_CopyRecord  0x021FAE70  thumb
 *   BR_BTN_SetDrawPriority  0x021FAFA0  thumb
 *   BR_BTN_SetBgPriority  0x021FAFB0  thumb
 *   func_02034714  0x02034714  arm
 *   d_02200D18     0x02200D18  data  a1
 */
#include "../include/Obj03339.h"
typedef unsigned char u8;
typedef unsigned short u16;

struct Record;
void BR_BTN_CopyRecord(void *ctx, struct Record *dest, const struct Record *source, int mode);
void BR_BTN_SetDrawPriority(u8 *elem, int x);
void BR_BTN_SetBgPriority(u8 *elem, int x);
typedef unsigned int   u32;
void func_02034714(const char *expr, u32 line, const char *file);
extern u8 d_02200D18[];

void BR_BTN_PushRecord(u8 *ctx, int a1, int a2)
{
    int i;

    if (ctx[0x3b] >= ctx[0x3a])
        func_02034714((const char *)d_02200D18, 0, (const char *)d_02200D18);
    BR_BTN_CopyRecord(ctx, (struct Record *)(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + ctx[0x3b] * 0x44), (const struct Record *)a1, a2);
    ctx[0x3b]++;
    for (i = 0; i < ctx[0x3b]; i++) {
        BR_BTN_SetDrawPriority(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + i * 0x44,
                      (u16)((ctx[0x3b] - i) * 2 + 1));
        BR_BTN_SetBgPriority(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + i * 0x44, 1);
    }
}
