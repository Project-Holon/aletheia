/*
 * function: func_021BA338
 * address:  0x021BA338
 * packet:   pkt_ov088_021BA338
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EA40  0x0202EA40  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BC0AC  0x021BC0AC  thumb  ov088
 *   func_0200C2F0  0x0200C2F0  thumb
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_0203633C  0x0203633C  arm
 *   func_021BB890  0x021BB890  thumb  ov088
 */
#include "../include/Obj00271.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Row;
typedef signed int     s32;
extern s32 func_0202EA40(struct Row *p);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern int func_021BC0AC(char *p, int v);
struct Blk34;
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
extern int func_021BC080(char *p, int v);
extern unsigned int func_0203633C(void);
extern int func_021BB890(char *p, int d);

int func_021BA338(char *p)
{
    func_0202EA40(((struct Obj00271 *)p)->f11C);
    if (func_020362DC() & 1) {
        func_020061E4(0x54c);
        switch (*(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120)) {
        case 0:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 7);
        case 1:
            return func_021BC0AC(p, 8);
        case 2:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 3:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 1, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 4:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 2, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 7:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 3, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 5:
            return func_021BC0AC(p, 9);
        case 6:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        }
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        ((struct Obj00271 *)p)->f129 = 8;
        return func_021BC080(p, 1);
    }
    if (func_0203633C() & 0x40) {
        if (func_021BB890(p, -1) == 1) {
            func_020061E4(0x548);
            return 6;
        }
    }
    if (func_0203633C() & 0x80) {
        if (func_021BB890(p, 1) == 1) {
            func_020061E4(0x548);
            return 6;
        }
    }
    return 5;
}
