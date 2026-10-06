/*
 * function: func_021FA020
 * address:  0x021FA020
 * packet:   pkt_021FA020
 * region:   ov186
 * status:   EXACT
 * symbols:
 *   func_021FAE70  0x021FAE70  thumb
 *   func_021FAFA0  0x021FAFA0  thumb
 *   func_021FAFB0  0x021FAFB0  thumb
 *   func_02034714  0x02034714  arm
 *   d_02200D18     0x02200D18  data  a1
 */
#include "../include/Obj03339.h"
typedef unsigned char u8;
typedef unsigned short u16;

struct Record;
void func_021FAE70(void *ctx, struct Record *dest, const struct Record *source, int mode);
void func_021FAFA0(u8 *elem, int x);
void func_021FAFB0(u8 *elem, int x);
typedef unsigned int   u32;
void func_02034714(const char *expr, u32 line, const char *file);
extern u8 d_02200D18[];

void func_021FA020(u8 *ctx, int a1, int a2)
{
    int i;

    if (ctx[0x3b] >= ctx[0x3a])
        func_02034714((const char *)d_02200D18, 0, (const char *)d_02200D18);
    func_021FAE70(ctx, (struct Record *)(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + ctx[0x3b] * 0x44), (const struct Record *)a1, a2);
    ctx[0x3b]++;
    for (i = 0; i < ctx[0x3b]; i++) {
        func_021FAFA0(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + i * 0x44,
                      (u16)((ctx[0x3b] - i) * 2 + 1));
        func_021FAFB0(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + i * 0x44, 1);
    }
}
