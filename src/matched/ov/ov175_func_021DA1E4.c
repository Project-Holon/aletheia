/*
 * function: func_021DA1E4
 * address:  0x021DA1E4
 * packet:   pkt_021DA1E4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215580C  0x0215580C  thumb
 *   func_0203C304  0x0203C304  arm
 *   func_02156BC4  0x02156BC4  thumb
 *   func_0203C554  0x0203C554  arm
 *   func_0203C3EC  0x0203C3EC  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02039338  0x02039338  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021DA384  0x021DA384  thumb
 *   func_021DA390  0x021DA390  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203D378  0x0203D378  arm
 *
 * Matchmaking step (state at +0x40): 0 starts the search with the evaluation callback, then waits for the match, the peer handshake (with a 3600-tick timeout counted at +0x1a4) and the link check; returns 1 when done, 2 on a fatal error and 0 while still running.
 */
#include "../include/Obj00839.h"

typedef unsigned long u32;

extern int func_0215580C(char *filter, int n, void *cb, char *obj);
extern u32 func_0203C304(void);
extern void func_02156BC4(int v);
extern void func_0203C554(u32 a);
extern int func_0203C3EC(void);
typedef unsigned short u16;
extern u32 func_0203CA98(void);
typedef unsigned char  u8;
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern u16 func_02039338(void);
extern int func_02039ACC(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);
extern int func_020399EC(void);
extern unsigned int func_02039CB4(struct Link *h, unsigned int a, unsigned int b);
extern void func_021DA384(char *obj);
extern int func_021DA390(char *obj);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_0200FBA0(void);
extern u32 func_0203D378(void);

int func_021DA1E4(char *obj)
{
    switch (((struct Obj00839 *)obj)->f40) {
    case 0:
        if (func_0215580C(obj + 0x44, 2, ((struct Obj00839 *)obj)->f1218, obj)) {
            func_0203C304();
            func_02156BC4(0);
            ((struct Obj00839 *)obj)->f40 = 1;
        } else {
            func_0203C554(1);
            return 2;
        }
        break;
    case 1:
        ((struct Obj00839 *)obj)->f40 = 2;
        break;
    case 2:
        switch (func_0203C3EC()) {
        case 0:
            if ((u32)(*(u32 *)(func_0203CA98() + 0xc) - 0x3f0) > 1)
                break;
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        case 1:
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 3;
            func_0203D7B0(1);
            func_0203D7BC(1);
            break;
        default:
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        }
        break;
    case 3:
        if (func_02039338()) {
            if (func_02039ACC())
                ((struct Obj00839 *)obj)->f40 = 4;
            if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
                func_021DA384(obj);
                ((struct Obj00839 *)obj)->f40 = 7;
            }
        } else {
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 5;
        }
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 0xf, 0x24);
        ((struct Obj00839 *)obj)->f1A4 = 0;
        ((struct Obj00839 *)obj)->f40 = 6;
        break;
    case 5:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (func_020399EC() && func_02039ACC()) {
            func_02039C68((struct Link *)func_020399A8(), 0xf, 0x24);
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 6;
        }
        break;
    case 6:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (func_02039CB4((struct Link *)func_020399A8(), 0xf, 0x24)) {
            ((struct Obj00839 *)obj)->f40 = 8;
        }
        break;
    case 7:
        if (func_021DA390(obj)) {
            if ((u32)(*(u32 *)(func_0203CA98() + 0xc) - 0x3f0) <= 1) {
                func_0203CA04();
                func_0203C968();
                func_0200FBA0();
                func_0203C554(1);
            }
            return 2;
        }
        break;
    case 8:
        func_0203D378();
        return 1;
    }
    return 0;
}
