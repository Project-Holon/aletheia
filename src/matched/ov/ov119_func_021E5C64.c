/*
 * function: func_021E5C64
 * address: 0x021E5C64
 * packet: pkt_ov119_021E5C64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040618 0x02040618 arm
 *   func_02049238 0x02049238 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   d_021E81D4 0x021E81D4 data a4
 */
#include "../include/Obj01055.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef struct { u32 x, y; } Pos;
extern Pos d_021E81D4[26];
struct Cfg;
struct Descriptor;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02041B6C(u32 bit);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02049238(void *);
extern void func_0201DD78(u32, u32, u32);
struct MsgBank;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
void func_021E5C64(char *p)
{
    u32 i;
    void *h;
    func_02040588(4, 0);
    func_02040588(6, 0);
    h = func_020490F4(0x66, ((struct Obj01055 *)p)->f5F4);
    func_02049990(h, 16, 4, 0, (u16)((struct Obj01055 *)p)->f870, 0, 0, ((struct Obj01055 *)p)->f5F4);
    func_02041B6C(4);
    func_02040618(4, 0, -4);
    func_02040618(6, 0, -4);
    func_02049238(h);
    func_0201DD78(1, 2, 15);
    for (i = 0; i < 26; i++) {
        *(void **)(p + i * 4 + 0x750) = (void *)func_020450F0(6, (u8)d_021E81D4[i].x, (u8)d_021E81D4[i].y, 2, 2, 14, 0);
        func_02045CAC((struct MsgBank *)(((struct Obj01055 *)p)->f720), i + 0x35, (void *)(*(int *)&((struct Obj01055 *)p)->f730));
        func_0201C7A4(func_02045770(*(void **)(p + i * 4 + 0x750)), 0, 0, ((struct Obj01055 *)p)->f730, ((struct Obj01055 *)p)->f728);
        func_02045374(*(void **)(p + i * 4 + 0x750));
        func_02045334(*(void **)(p + i * 4 + 0x750));
    }
    func_02041B6C(6);
    func_02040588(4, 1);
    func_02040588(6, 1);
}
