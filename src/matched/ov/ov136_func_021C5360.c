/*
 * function: func_021C5360
 * address: 0x021C5360
 * packet: pkt_ov136_021C5360
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 byte-exact; waiting on arm9 witness shard for PMSI_PARAM_IsEnabled
 * symbols:
 *   func_021C5360 0x021C5360 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00160.h"
#include "../include/Obj14187.h"
#include "../include/Obj23499.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMS_DRAW_Print(u32 a, u32 b, u32 c, u32 d);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);

void func_021C5360(u8 *p)
{
    int i;
    u8 *q;
    u32 t;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled((u16 *)(*(u8 * *)&((struct Obj00160 *)p)->f1C + 0x16 + i * 8))) {
            PMS_DRAW_Print(*(u32 *)&((struct Obj00160 *)p)->f148, *(u32 *)(p + i * 4 + 0x48), (u32)(*(u8 * *)&((struct Obj00160 *)p)->f1C + 0x16 + i * 8), (u8)i);
        }
    }
    q = *(u8 * *)&((struct Obj00160 *)p)->f1C;
    if (((struct Obj14187 *)q)->f32 != 0xFFFF) {
        ((struct Obj00160 *)p)->f14C = 6;
        ((struct Obj00160 *)p)->f14E = 0;
        ((struct Obj00160 *)p)->f150 = ((struct Obj14187 *)q)->f32;
        PMS_DRAW_Print(*(u32 *)&((struct Obj00160 *)p)->f148, ((struct Obj00160 *)p)->f54, (u32)(p + 0x14C), (u8)3);
    }
    if (p[0xB] == 0) {
        u32 a = *(u32 *)&((struct Obj00160 *)p)->f98;
        func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)((struct Obj00160 *)p)->f88), 0, 2, (u32)(((struct Obj23499 *)(*(u8 * *)&((struct Obj00160 *)p)->f1C))->fC), *(u32 *)&((struct Obj00160 *)p)->f24, 0x440);
        p[0x8C] = 1;
        t = ((struct Obj00160 *)p)->f58;
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_020409B4(func_02045730((struct Descriptor *)t));
    }
}
