/*
 * file:     unit_021D87C8.c
 * unit:     yes
 * function: func_021D87C8, func_021D87FC, func_021D8808, func_021D8838, func_021D8844, func_021D8874, func_021D88AC, func_021D88B8, func_021D88D0, func_021D88E8, func_021D890C, func_021D8940, func_021D8964, func_021D8974, func_021D89B8, func_021D8A30, func_021D8A3C, func_021D8A64, func_021D8A8C, func_021D8A9C, func_021D8AA8, func_021D8AD0, func_021D8AE0, func_021D8AEC, func_021D8B1C
 * address:  0x021D87C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F0668 0x021F0668 data ov093 a4
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   d_021F0748     0x021F0748  data   ov093  a4
 *   func_021D84F0 0x021D84F0 thumb ov093
 *   d_021F05A0 0x021F05A0 data a4
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C804C   0x021C804C  thumb ov093
 *   d_021F09C0     0x021F09C0  data   ov093  a4
 *   d_021F0650 0x021F0650 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   d_021F0D6C     0x021F0D6C  data   ov093  a4
 *   d_021F09E0     0x021F09E0  data   ov093  a4
 *   d_021F0738 0x021F0738 data a4
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   d_021F09F0     0x021F09F0  data   ov093  a4
 */
#include "../../matched/include/Obj21270.h"
#include "../../matched/include/Obj04900.h"

struct Unk021D62A8;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D62A8(struct Unk021D62A8 *p);
void func_021D7704(int a, int b);
int func_021D76BC(int key, u32 val);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_0201C1E8(int a);
u32 func_021D7B10(u32 a, u32 b);
extern unsigned int func_021D84F0(unsigned int,unsigned int);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, u32 a);
void func_021C88C8(void *a, void *b);
int func_021C804C(int a, int b, void *v);
extern int func_021C8288(u8 *p);
extern int func_021D7AD4(int);
void func_021D87C8(void *a, int b, int c);
int *func_021D87FC(int *p);
void func_021D8808(int a,int b,int c);
u8 *func_021D8838(u32 *p);
void func_021D8844(int a, int b, int c);
void func_021D8874(void *a, int b, int c);
int *func_021D88AC(int *p);
void func_021D88B8(int a, int b, int c);
void *func_021D88D0(unsigned int *p);
void func_021D88E8(int a, int b, int c, int *d);
void func_021D890C(int a, int b, int c, int *d);
void func_021D8940(void *a, int b, int c, int *d);
void func_021D8964(void *a, int b, int c, int *d);
void func_021D8974(void *a, int b, int c, int *d);
void func_021D89B8(void *a, int b, int c, void *d);
int *func_021D8A30(int *p);
void func_021D8A3C(int a, int b, int c);
void *func_021D8A58(int *p);
void func_021D8A64(int a, int b, int c);
void func_021D8A8C(int a, int b, int c, int d);
int *func_021D8A9C(int *p);
void func_021D8AA8(int a, int b, int c);
void func_021D8AD0(int a, int b, int c, int d);
int *func_021D8AE0(int *p);
void func_021D8AEC(int a, int b, int c, int d, unsigned char e);
void func_021D8B1C(int a, int b, int c);
void *func_021D8B44(int *p);
extern u8 d_021F0668[];
extern int d_021F0748[];
extern unsigned char d_021F05A0[];
/* 021D88B8  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D88CE; movs r0, #0x11; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
extern int d_021F09C0[];
extern unsigned char d_021F0650[];
extern int d_021F0D6C[];
extern int d_021F09E0[];
extern unsigned char d_021F0738[];
extern int d_021F09F0[];






void func_021D87C8(void *a, int b, int c)
{
    void *r;
    if (c == func_021D775C(2)) {
        r = func_021C7CF4((int *)b, c);
        if (func_021D62A8(r) != 0) {
            func_021D7704(0x35, 6 << 10);
            func_021D76BC(0x51, 0);
        }
    }
}






int *func_021D87FC(int *p)
{
    *p = 1;
    return d_021F0748;
}






/*
 * evidence: 021D881C loads r1=c and 021D8822 forwards the returned r0.
 * func_021C7CF4's legacy void signature is read as a pointer result;
 * its ldr r0,[r0,#8] tail forwards the full-word payload unchanged.
 */
void func_021D8808(int a,int b,int c) { if (c==func_021D775C(4)) { if (func_021D62C4(func_021C7CF4((int *)b,c),6)) func_021D7704(53,2048); } }






u8 *func_021D8838(u32 *p) { *p=1; return d_021F0668; }








void func_021D8844(int a, int b, int c)
{
    if(c==func_021D775C(3) && func_0201C1E8((unsigned short)func_021D775C(0x12))==1) func_021D7704(0x35,0xCCD);
}








void func_021D8874(void *a, int b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_0201C1E8((u16)func_021D775C(0x12)) == 1) {
            func_021D76BC(0x33, func_021D7B10(func_021D775C(0x33), 3 << 11));
        }
    }
}





int *func_021D88AC(int *p)
{
    *p = 2;
    return d_021F09C0;
}





void func_021D88B8(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x11, 0);
}







void *func_021D88D0(unsigned int *p)
{
    *p=func_021D84F0(7,1); return d_021F05A0;
}







void func_021D88E8(int a, int b, int c, int *d)
{
    int k=2; if(c==func_021D775C(k) && d[3]!=0) func_021D7704(0x35,k<<10);
}







void func_021D890C(int a, int b, int c, int *d)
{
    if(c==func_021D775C(3) && d[3]!=0 && func_0201C1E8((unsigned short)func_021D775C(0x12))==1) func_021D7704(0x35,0x800);
}







void func_021D8940(void *a, int b, int c, int *d)
{
    if(c==func_021D775C(2)) func_021D8974(a,b,c,d);
}








void func_021D8964(void *a, int b, int c, int *d)
{
    if (d[0] == 0) func_021D8974(a,b,c,d);
}








void func_021D8974(void *a, int b, int c, int *d)
{
    u8 *p;

    d[0] = 1;
    d[1] = 0;
    d[2] = 0;
    d[3] = 1;
    p = func_021C88A4((char *)b, 4, c);
    ((struct Obj21270 *)p)->f0 |= 4 << 21;
    func_021C8838(p + 4, 2, 0x1f0);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
}







/*
 * Gate on func_021D775C(2); the counter at +4 of d must reach 5 -- the
 * func_021C804C(b,c,&v) block bumps it once (rejecting a low nibble of 3) --
 * then record #4 is published as a two-string record and d's flag pair is set
 * to (0, 1).
 */
void func_021D89B8(void *a, int b, int c, void *d)
{
    struct { unsigned int kind : 4; } v;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    if (((struct Obj04900 *)d)->f8 != 0)
        return;
    if (((struct Obj04900 *)d)->f4 < 5) {
        if (func_021C804C(b, c, &v) == 0)
            return;
        if (v.kind == 3)
            return;
        ((struct Obj04900 *)d)->f4 += 1;
    }
    if (((struct Obj04900 *)d)->f4 < 5)
        return;
    p = func_021C88A4((char *)b, 4, c);
    func_021C8838(p + 4, 2, 0x1f3);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    ((struct Obj04900 *)d)->fC = 0;
    ((struct Obj04900 *)d)->f8 = 1;
}




int *func_021D8A30(int *p)
{
    *p = 6;
    return d_021F0D6C;
}




void func_021D8A3C(int a, int b, int c)
{
    if(c==func_021D775C(3)) func_021D7704(0x35,0x14CD);
}






void *func_021D8A58(int *p)
{
    *p = 1;
    return d_021F0650;
}






void func_021D8A64(int a, int b, int c)
{
    if(c==func_021D775C(4) && func_021C8288((u8 *)b)==4) func_021D7704(0x35,0xCCD);
}





/* 021D8A8C  stack-arg wrapper: func_021D8AEC(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021D8AEC; add sp, #4; pop {r3, r4, pc}.
 */
void func_021D8A8C(int a, int b, int c, int d) { func_021D8AEC(a, b, c, d, 0x4); }



int *func_021D8A9C(int *p)
{
    *p = 2;
    return d_021F09E0;
}



void func_021D8AA8(int a, int b, int c)
{
    if(c==func_021D775C(4) && func_021C8288((u8 *)b)==3) func_021D7704(0x35,0xCCD);
}




/* 021D8AD0  stack-arg wrapper: func_021D8AEC(a, b, c, d, 0x3) */
void func_021D8AD0(int a, int b, int c, int d) { func_021D8AEC(a, b, c, d, 0x3); }


int *func_021D8AE0(int *p)
{
    *p = 2;
    return d_021F09F0;
}


void func_021D8AEC(int a, int b, int c, int d, unsigned char e)
{
    if(c==func_021D775C(2) && func_021D775C(0x32)>0 && e==func_021D775C(0x39)) func_021D76BC(0x41,1);
}



void func_021D8B1C(int a, int b, int c)
{
    if(c==func_021D775C(3) && func_021D7AD4(func_021D775C(0x38))==3) func_021D7704(0x35,0x2000);
}



void *func_021D8B44(int *p)
{
    *p = 1;
    return d_021F0738;
}
