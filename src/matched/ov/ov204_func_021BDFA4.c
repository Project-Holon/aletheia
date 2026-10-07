/*
 * function: func_021BDFA4
 * address: 0x021BDFA4
 * packet: pkt_ov204_021BDFA4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the fourth 02048A24 argument is the pooled 0x1555 (earlier notes
 * decoded it as 0x155, which also moved the pool order). The heap parameter
 * is u8: with the callees' own prototypes (02046440 s16 heap, 02048A24 u16
 * heap, 02048BC4 u32 heap) a u8 converts to all three with no code, matching
 * the original's unnarrowed full-word stack stores; u16/s16/u32 each add a
 * lsls/asr|lsr pair (156-160 bytes). Twin: ov204_func_021BE03C.c.
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_021BDB70 0x021BDB70 thumb ov204
 *   d_021BFD68 0x021BFD68 data a4
 *   d_021BFD5C 0x021BFD5C data a4
 *   d_021BFD74 0x021BFD74 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021BFD4C 0x021BFD4C data a4
 */

#include "../include/G_021BFD68.h"
#include "../include/G_021BFD5C.h"
#include "../include/G_021BFD74.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u32 x, y, z; } Vec3;
struct Light; struct LightSet; struct LightSlot;
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16 heap, void (*setup)(void));
extern u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                          Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048B60(struct Light *l, const u32 *in);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_021BDB70(void);
extern struct G_021BFD68 d_021BFD68;
extern struct G_021BFD5C d_021BFD5C;
extern struct G_021BFD74 d_021BFD74;
extern const short d_020A1EB8[];
extern const struct LightSet d_021BFD4C;
void func_021BDFA4(char *p, u8 heap)
{
    u32 far_clip, near_clip;
    func_02046440(0, 4, 0, 2, 0, heap, func_021BDB70);
    *(u32 **)p = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, ((Vec3 *)&d_021BFD68), ((Vec3 *)&d_021BFD5C), ((Vec3 *)&d_021BFD74), heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    func_02048B6C(*(struct Light **)p, &far_clip);
    func_02048B60(*(struct Light **)p, &near_clip);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFD4C, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}
