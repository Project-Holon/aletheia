/*
 * file:     unit_021DA624_p02.c
 * unit:     yes
 * function: func_021DAEAC, func_021DAEC4, func_021DAED8, func_021DAEE4, func_021DAF1C, func_021DAF58, func_021DB000, func_021DB00C, func_021DB0D0
 * address:  0x021DAEAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D7324   0x021D7324  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021DA8A8  0x021DA8A8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F0BD4     0x021F0BD4  data   ov093  a4
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   d_021F07E8 0x021F07E8 data a4
 *   d_021F0A28     0x021F0A28  data   ov093  a4
 */
#include "../../matched/include/Obj13469.h"
#include "../../matched/include/Obj13470.h"
#include "../../matched/include/Obj13471.h"

struct UtilWork;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D5BDC(struct UtilWork *,unsigned int);
extern void *func_021C7CF4(int *p, int i);
extern void func_021D7704(int,int);
extern void *func_021C88A4(char *,int,int);
extern void func_021C88C8(void *,void *);
extern int func_021DA8A8(int a, int b, int c);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021C7D00(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
void func_021DAEAC(int a, int b, int c);
int func_021DAEC4(int a, int b, int c, int d, unsigned short e);
int *func_021DAED8(int *p);
void func_021DAEE4(int a, int *b, int c);
void func_021DAF1C(int a, int *b, int c);
void func_021DAF58(int unused, void *a, int id);
int *func_021DB000(int *p);
void func_021DB00C(int a, void *b, int c);
void *func_021DB0D0(int *p);
extern int d_021F0BD4[];
extern int d_021F0A28[];
extern u8 d_021F07E8[];


/* 021DAEAC  shape F3: gate on func_021D775C(2) then func_021D7324 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DAEC2; adds r0, r5, #0; bl func_021D7324; pop {r3, r4, r5, pc}.
 */
void func_021DAEAC(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7324(a);
}


int func_021DAEC4(int a, int b, int c, int d, unsigned short e)
{
    if (c == 4 && e == 0x6A) {
        return 1;
    }
    return 0;
}


int *func_021DAED8(int *p)
{
    *p = 5;
    return d_021F0BD4;
}



void func_021DAEE4(int a, int *b, int c) { if (c == func_021D775C(3) && func_021D5BDC(func_021C7CF4(b,c),13) && func_021D775C(22) == 9) func_021D7704(53,6144); }




/*
 * interface: func_021C7CF4 uses its live r0 result and visibly loaded r1;
 * its own legacy file declares void and one parameter. Preserve this
 * caller's observed result and two-argument setup without editing callee.
 */
void func_021DAF1C(int a, int *b, int c) { char *p; if (c == func_021D775C(2) && func_021D5BDC(func_021C7CF4(b,c),13)) { p = func_021C88A4((char *)b,24,c); p[8] = c; ((struct Obj13469 *)p)->f4 = 13; func_021C88C8((char *)b,p); } }




void func_021DAF58(int unused, void *a, int id)
{
    u8 *r;

    if (func_021DA8A8((int)a, id, 9) != 0) {
        func_021C88B4(a, 2, id);
        if (func_021D5BDC(func_021C7CF4(a, id), 13) == 0) {
            r = (u8 *)func_021C88A4(a, 4, id);
            func_021C8838(r + 4, 2, 0x1ab);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
            r = (u8 *)func_021C88A4(a, 0x17, id);
            r[8] = id;
            ((struct Obj13470 *)r)->f4 = 13;
            func_021C88C8(a, r);
        } else {
            r = (u8 *)func_021C88A4(a, 4, id);
            func_021C8838(r + 4, 2, 0xd2);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
        }
        func_021C88B4(a, 3, id);
    }
}



int *func_021DB000(int *p)
{
    *p = 3;
    return d_021F0A28;
}



/*
 * The unit includes the store-return follower; labelled 021DB0DC is excluded.
 * An 8-bit candidate count keeps its immediate spill/reload; m precedes n
 * in the declaration list to place those spills at +8 and +4 respectively.
 */
void func_021DB00C(int a, void *b, int c)
{
    u8 list[4];
    void *m;
    u8 n;
    int flag;
    u8 *r;
    u8 i;
    if (c == func_021D775C(2)) {
        flag = 0;
        n = func_021C7F68(b, (u16)(func_021C7D00(b, c) | 0x100), list);
        for (i = 0; i < n; i++) {
            m = func_021C7CF4(b, list[i]);
            if (func_021D62C4(m, 2)) {
                if (!flag) {
                    flag = 1;
                    func_021C88B4(b, 2, c);
                }
                r = (u8 *)func_021C88A4(b, 7, c);
                r[6] = list[i];
                ((struct Obj13471 *)r)->f4 = func_021D7B74(m, 8);
                func_021C8838(r + 12, 2, 0x1e4);
                func_021C8860((struct S *)(r + 12), list[i]);
                func_021C88C8(b, r);
            }
        }
        if (flag) func_021C88B4(b, 3, c);
    }
}


void *func_021DB0D0(int *p) { *p = 1; return d_021F07E8; }
