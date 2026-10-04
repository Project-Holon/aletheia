/*
 * function: func_021DC93C
 * address: 0x021DC93C
 * packet: pkt_ov134_021DC93C
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   func_021B6114 0x021B6114 thumb ov090
 *   func_02034AC4 0x02034AC4 arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157170 0x02157170 thumb ov009
 *   d_021BED00 0x021BED00 data a4 ov091
 *   d_021DC800 0x021DC800 data a4 ov131
 *   ov91_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 */
#include "../include/Obj00310.h"
#include "../include/Obj06506.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 g_02FFFC3C;
extern void func_021B6114(u8 *);
extern int func_02034AC4(int);
extern void func_02031348(void *, int, const void *, void *);
extern u32 func_02031330(void *);
extern void func_02034A5C(int);
extern void *func_0201AB28(void *, u32);
struct Entry;
struct Party;
struct PartyMon;
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern struct Entry *func_020399A8(void);
extern int func_0201A918(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern u32 func_0200FB24(void);
extern int func_0203CD98(void);
extern int func_02157170(int, int);
extern const u32 d_021BED00[], d_021DC800[];
extern const char ov91_id[], ov131_id[];
int func_021DC93C(void *unused0, void *unused1, u8 *q, u8 *p)
{
    u32 frame;
    u8 elapsed;
    u8 i;
    void *ctx;
    int code;
    if (((struct Obj00310 *)p)->f94 == 1 && ((struct Obj00310 *)p)->f64 != 0) {
        frame = g_02FFFC3C;
        elapsed = frame - ((struct Obj00310 *)p)->fC8;
        p[196] += elapsed;
        ((struct Obj00310 *)p)->fC8 = frame;
        if (p[196] > 60) {
            ((struct Obj00310 *)p)->f64 -= 1;
            p[196] -= 60;
        }
    }
    func_021B6114(p + 4);
    switch (((struct Obj00310 *)p)->f0) {
    case 0:
        func_02034AC4((int)ov91_id);
        func_02031348(((struct Obj00310 *)p)->fCC, -1, d_021BED00, p + 4);
        ((struct Obj00310 *)p)->f0 = 1;
        break;
    case 1:
        if (func_02031330(((struct Obj00310 *)p)->fCC) == 0) ((struct Obj00310 *)p)->f0 = 2;
        break;
    case 2:
        func_02034A5C((int)ov91_id);
        if (((struct Obj00310 *)p)->f44 == 1) {
            p[171] = ((struct Obj00310 *)p)->f40;
            ((struct Obj00310 *)p)->f0 = 3;
        } else {
            ((struct Obj06506 *)q)->f28 = 0;
            ((struct Obj00310 *)p)->f0 = 6;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (p[77 + i] != 0) {
                void *mon;
                mon = func_0201AB28(((struct Obj06506 *)q)->f4, p[77 + i] - 1);
                func_0201A98C(((struct Obj06506 *)q)->f1C, mon);
            }
        }
        ((struct Obj00310 *)p)->f0 = 7;
        break;
    case 7:
        ctx = func_020399A8();
        code = func_0201A918();
        if (func_0203D3F8((u32)ctx, 255, 0x2f00, code, *(u32 *)&((struct Obj06506 *)q)->f1C, 0, 0, 1) != 0) {
            func_02039C68((struct Link *)func_020399A8(), 20, 47);
            ((struct Obj00310 *)p)->f0 = 8;
        }
        break;
    case 8:
        if (func_02039CB4((struct Link *)func_020399A8(), 20, 47) != 0) return 1;
        break;
    case 3:
        func_02034AC4((int)ov131_id);
        func_02031348(((struct Obj00310 *)p)->fCC, -1, d_021DC800, p + 156);
        ((struct Obj00310 *)p)->f0 = 4;
        break;
    case 4:
        if (((struct Obj00310 *)p)->f94 == 1 && ((struct Obj00310 *)p)->f64 == 0) ((struct Obj00310 *)p)->fC0 = 1;
        if (func_0200FB24() != 0) ((struct Obj00310 *)p)->fC0 = 1;
        if (func_02031330(((struct Obj00310 *)p)->fCC) == 0) ((struct Obj00310 *)p)->f0 = 5;
        break;
    case 5:
        func_02034A5C((int)ov131_id);
        ((struct Obj00310 *)p)->f40 = p[171];
        ((struct Obj00310 *)p)->f0 = 0;
        break;
    }
    if (func_0203CD98() != 0 && ((struct Obj00310 *)p)->f0 != 1 && ((struct Obj00310 *)p)->f0 != 2 && ((struct Obj00310 *)p)->f0 != 4 && ((struct Obj00310 *)p)->f0 != 5) {
        if (func_02157170(1, 1) != 0) {
            ((struct Obj06506 *)q)->f28 = 1;
            return 1;
        }
    }
    return 0;
}
