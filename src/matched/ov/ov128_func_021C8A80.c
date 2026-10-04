/*
 * function: func_021C8A80
 * address: 0x021C8A80
 * packet: pkt_ov128_021C8A80
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: The colors and four-halfword position descriptor are fields of
 * one stack aggregate, fixing their 0x28 and 0x2E frame positions.
 * bounds: 02009864 field 9 reads the two-bit value at entry+0x2f,
 * so 3 also reads the initialized position halfword at aggregate+6.
 * heap: 021C8644 and 021C89B0 load the incoming heap as a halfword;
 * 021C8904 forwards that value to this eighth argument at 021C896A.
 * symbols:
 *   func_021C8B90 0x021C8B90 thumb ov128
 *   func_021C40BC 0x021C40BC thumb ov127
 *   func_021C42A8 0x021C42A8 thumb ov127
 *   func_020457B0 0x020457B0 arm
 *   func_02045924 0x02045924 arm
 *   func_02045808 0x02045808 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   d_021CA6C8 0x021CA6C8 data a2
 */
#include "../include/Obj05381.h"
#include "../include/Obj05382.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y, rest[3]; } Entry;
extern const Entry d_021CA6C8[];
extern int func_02009864(void *, int, int);
extern void func_021C8B90(void *, void *, int, int, u16);
extern void *func_021C40BC(void *, s16 *, int, u32);
struct obj;
extern void func_021C42A8(struct obj *p, int idx, int a);
struct Strbuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 *func_020099D4(void *, int);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_021B6AE4(u8 *, u32, u16, u16, u32, u32, u16, u32);
void func_021C8A80(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap)
{
    struct { u16 colors[3]; s16 pos[4]; } local;
    int result8, result9;
    void *str;
    local.colors[0] = 0x14c0;
    local.colors[1] = 0xc80;
    local.colors[2] = 0x440;
    result8 = func_02009864(base, idx, 8);
    result9 = func_02009864(base, idx, 9);
    if (result9 == 2) {
        func_021C8B90(p, b, unused, i, heap);
    } else {
        local.pos[0] = (((struct Obj05381 *)p)->f0 + d_021CA6C8[i].x) * 8 + 8;
        local.pos[1] = (((struct Obj05381 *)p)->f2 + d_021CA6C8[i].y) * 8 + 10;
        local.pos[2] = 8;
        local.pos[3] = 1;
        *(void **)(p + 12 + (int)((u32)i * 4u)) = func_021C40BC(a, local.pos, result8, heap);
        func_021C42A8(*(void **)(p + 12 + (int)((u32)i * 4u)), 0, 1);
    }
    str = func_020457B0(128, heap);
    func_02045924(str, func_020099D4(base, idx));
    func_021B6AE4(*(u8 * *)&((struct Obj05381 *)p)->f8, ((struct Obj05382 *)b)->f34, d_021CA6C8[i].x * 8,
                 d_021CA6C8[i].y * 8 - 24, (u32)str, ((struct Obj05382 *)b)->f17C, *(u16 *)((u8 *)&local + result9 * 2), 0);
    func_02045808(str);
}
