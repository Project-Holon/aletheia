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
 *   WIFI_2DCHAR_SpawnActor 0x021C40BC thumb ov127
 *   WIFI_2DCHAR_SetActorAnim 0x021C42A8 thumb ov127
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetString 0x02045924 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
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
struct Sub020097BCEnt;
struct Sub020097BCObj;
extern void func_021C8B90(char *p, char *q, int unused, int i, u16 h);
extern void *WIFI_2DCHAR_SpawnActor(void *, s16 *, int, u32);
struct obj;
extern void WIFI_2DCHAR_SetActorAnim(struct obj *p, int idx, int a);
struct Strbuf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
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
        func_021C8B90((char *)p, (char *)b, unused, i, heap);
    } else {
        local.pos[0] = (((struct Obj05381 *)p)->f0 + d_021CA6C8[i].x) * 8 + 8;
        local.pos[1] = (((struct Obj05381 *)p)->f2 + d_021CA6C8[i].y) * 8 + 10;
        local.pos[2] = 8;
        local.pos[3] = 1;
        *(void **)(p + 12 + (int)((u32)i * 4u)) = WIFI_2DCHAR_SpawnActor(a, local.pos, result8, heap);
        WIFI_2DCHAR_SetActorAnim(*(void **)(p + 12 + (int)((u32)i * 4u)), 0, 1);
    }
    str = STRBUF_Create(128, heap);
    STRBUF_SetString(str, (const u16 *)func_020099D4(base, idx));
    TOUCHBAR_PrintAligned(*(u8 * *)&((struct Obj05381 *)p)->f8, (void *)(((struct Obj05382 *)b)->f34), d_021CA6C8[i].x * 8,
                 d_021CA6C8[i].y * 8 - 24, (u32)str, ((struct Obj05382 *)b)->f17C, *(u16 *)((u8 *)&local + result9 * 2), 0);
    STRBUF_Delete(str);
}
