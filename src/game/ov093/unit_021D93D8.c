/*
 * file:     unit_021D93D8.c
 * unit:     yes
 * function: func_021D93D8, func_021D93EC, func_021D93FC, func_021D940C, func_021D9418, func_021D9460, func_021D9478, func_021D9484, func_021D9498, func_021D94A8, func_021D94B8, func_021D94C4, func_021D94D8, func_021D94E8, func_021D94F8, func_021D9504, func_021D9518, func_021D9528, func_021D9538, func_021D9544, func_021D9558, func_021D956C, func_021D957C, func_021D958C, func_021D9598, func_021D95AC, func_021D95BC, func_021D95CC, func_021D963C, func_021D9648, func_021D9670, func_021D96CC, func_021D96DC, func_021D96FC, func_021D9744, func_021D9754, func_021D9760, func_021D9770, func_021D977C, func_021D978C, func_021D9798, func_021D97A8, func_021D97B4, func_021D97EC, func_021D9830, func_021D983C, func_021D9848, func_021D9858, func_021D9864, func_021D9874, func_021D9880, func_021D98DC, func_021D9934, func_021D9978, func_021D99A4, func_021D99C8, func_021D99E0, func_021D99F8, func_021D9A24, func_021D9A44, func_021D9A5C, func_021D9A68, func_021D9AD0
 * address:  0x021D93D8
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   d_021F0BFC     0x021F0BFC  data   ov093  a4
 *   d_021F0D3C     0x021F0D3C  data   ov093  a4
 *   d_021F0C4C     0x021F0C4C  data   ov093  a4
 *   d_021F0C74     0x021F0C74  data   ov093  a4
 *   d_021F0BB4     0x021F0BB4  data   ov093  a4
 *   d_021F0C9C     0x021F0C9C  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0CC4     0x021F0CC4  data   ov093  a4
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   d_021F08D0     0x021F08D0  data   ov093  a4
 *   d_021F08E0     0x021F08E0  data   ov093  a4
 *   d_021F08F0     0x021F08F0  data   ov093  a4
 *   d_021F0900     0x021F0900  data   ov093  a4
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0930     0x021F0930  data   ov093  a4
 *   d_021F0CEC 0x021F0CEC data a4
 *   func_021E85F8 0x021E85F8 thumb ov093
 *   d_021F0910     0x021F0910  data   ov093  a4
 *   d_021F05C0     0x021F05C0  data   ov093  a4
 *   d_021F0670     0x021F0670  data   ov093  a4
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   d_021F05A8     0x021F05A8  data   a4
 *   d_021F0A88     0x021F0A88  data   ov093  a4
 */
#include "../../matched/include/Obj09218.h"
#include "../../matched/include/Obj10056.h"
#include "../../matched/include/Obj09219.h"
#include "../../matched/include/Obj10057.h"
#include "../../matched/include/Obj13463.h"
#include "../../matched/include/Obj07809.h"

struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D76BC(int key, u32 val);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void *func_021C7CF4(int *p, int i);
int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021C8288(u8 *p);
extern int func_0201C1E8(int a);
extern void func_021D7704(int key, s32 m);
extern int func_021E85F8(int);
extern int func_021D62A8(struct Unk021D62A8 *p);
void func_021D93D8(int a, int b, int c, u32 *out);
void func_021D93EC(int a, int b, int c);
void func_021D93FC(int a, void *b, int c);
int *func_021D940C(int *p);
void func_021D9418(int a, int b, int c, int *out);
void func_021D9440(int a, int b, int c);
void func_021D9450(int a, void *b, int c);
void func_021D9460(int a, int b, int c);
int *func_021D9478(int *p);
void func_021D9484(int a, int b, int c, u32 *out);
void func_021D9498(int a, int b, int c);
void func_021D94A8(int a, int b, int c);
int *func_021D94B8(int *p);
void func_021D94C4(int a, int b, int c, u32 *out);
void func_021D94D8(int a, int b, int c);
void func_021D94E8(int a, int b, int c);
int *func_021D94F8(int *p);
void func_021D9504(int a, int b, int c, u32 *out);
void func_021D9518(int a, int b, int c);
void func_021D9528(int a, void *b, int c);
int *func_021D9538(int *p);
void func_021D9544(int a, int b, int c, u32 *out);
void func_021D9558(int a, int b, int c, int d);
void func_021D956C(int a, int b, int c);
void func_021D957C(int a, void *b, int c);
int *func_021D958C(int *p);
void func_021D9598(int a, int b, int c, u32 *out);
void func_021D95AC(int a, int b, int c);
void func_021D95BC(int a, void *b, int c);
void func_021D95CC(int a, void *b, int c);
int *func_021D963C(int *p);
int func_021D9648(int a, int b, int c);
void func_021D9670(void *a, void *b, int c, int *d, u16 e);
void func_021D96CC(void *a, void *b, int c, int *d);
void func_021D96DC(int a,int b,int c);
void func_021D96FC(void *a, int b, int c);
void func_021D9744(int a, void *b, int c);
int *func_021D9754(int *p);
void func_021D9760(int a, void *b, int c);
int *func_021D9770(int *p);
void func_021D977C(int a, void *b, int c);
int *func_021D978C(int *p);
void func_021D9798(int a, void *b, int c);
int *func_021D97A8(int *p);
void func_021D97B4(void *a,int b,int c);
void func_021D97EC(void *a, void *b, int c);
void func_021D9830(void);
int *func_021D983C(int *p);
void func_021D9848(int a, void *b, int c);
int *func_021D9858(int *p);
void func_021D9864(int a, void *b, int c);
int *func_021D9874(int *p);
void func_021D9880(void *a, int b, int c);
void func_021D98DC(int a, void *b, int c);
void func_021D9934(int a, int b, int c);
int *func_021D996C(int *p);
void func_021D9978(int a,int b,int c);
void func_021D99A4(int a,int b,int c);
void func_021D99C8(int a, int b, int c);
void func_021D99E0(int a, int b, int c);
void func_021D99F8(int a,int b,int c);
void *func_021D9A18(int *p);
void func_021D9A24(int a,int b,int c);
void func_021D9A44(int a, int b, int c);
int *func_021D9A5C(int *p);
void func_021D9A68(int a, void *b, int c);
int *func_021D9AD0(int *p);
extern int d_021F0BFC[];
/* 021D9484  shape F5: out-param store of func_021D9648(..., 3) */
extern int d_021F0D3C[];
/* 021D94C4  shape F5: out-param store of func_021D9648(..., 5) */
extern int d_021F0C4C[];
/* 021D9504  shape F5: out-param store of func_021D9648(..., 4) */
extern int d_021F0C74[];
extern int d_021F0BB4[];
/* 021D9544  shape F5: out-param store of func_021D9648(..., 6) */
extern int d_021F0C9C[];
extern int d_021F0CC4[];
extern int d_021F08D0[];
extern int d_021F08E0[];
extern int d_021F08F0[];
extern int d_021F0900[];
extern int d_021F0930[];
extern unsigned int d_021F0CEC;
extern int d_021F0910[];
extern int d_021F05C0[];
extern int d_021F0670[];
extern int d_021F05A8[];
extern int d_021F0A88[];










/* 021D93D8  shape F5: out-param store of func_021D9648(..., 1) */
/*
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #1; adds r4, r3, #0; bl func_021D9648; str r0, [r4]; pop {r4, pc}.
 */
void func_021D93D8(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 1);
}










void func_021D93EC(int a, int b, int c)
{
    func_021D96DC(b, c, 1);
}










void func_021D93FC(int a, void *b, int c)
{
    func_021D96FC(b, c, 1);
}










int *func_021D940C(int *p)
{
    *p = 5;
    return d_021F0BFC;
}










void func_021D9418(int a, int b, int c, int *out)
{
    int r;

    r = func_021D9648(b, c, 2);
    *out = r;
    if (r == 0)
        *out = func_021D9648(b, c, 0xe);
}











void func_021D9440(int a, int b, int c)
{
    func_021D96DC(b, c, 2);
}











void func_021D9450(int a, void *b, int c)
{
    func_021D96FC((void *)b, c, 2);
}











/* 021D9460  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D9476; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D9460(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x41, 1);
}









int *func_021D9478(int *p)
{
    *p = 6;
    return d_021F0D3C;
}









/*
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #3; adds r4, r3, #0; bl func_021D9648; str r0, [r4]; pop {r4, pc}.
 */
void func_021D9484(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 3);
}








void func_021D9498(int a, int b, int c)
{
    func_021D96DC(b, c, 3);
}








void func_021D94A8(int a, int b, int c)
{
    func_021D96FC((void *)b, c, 3);
}








/*
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 */
int *func_021D94B8(int *p)
{
    *p = 5;
    return d_021F0C4C;
}








void func_021D94C4(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 5);
}







void func_021D94D8(int a, int b, int c)
{
    func_021D96DC(b, c, 5);
}







void func_021D94E8(int a, int b, int c)
{
    func_021D96FC((void *)b, c, 5);
}







int *func_021D94F8(int *p)
{
    *p = 5;
    return d_021F0C74;
}







/*
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #4; adds r4, r3, #0; bl func_021D9648; str r0, [r4]; pop {r4, pc}.
 */
void func_021D9504(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 4);
}






void func_021D9518(int a, int b, int c)
{
    func_021D96DC(b, c, 4);
}






void func_021D9528(int a, void *b, int c)
{
    func_021D96FC(b, c, 4);
}






int *func_021D9538(int *p)
{
    *p = 5;
    return d_021F0C9C;
}






/*
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #6; adds r4, r3, #0; bl func_021D9648; str r0, [r4]; pop {r4, pc}.
 */
void func_021D9544(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 6);
}








void func_021D9558(int a, int b, int c, int d)
{
    func_021D9670((void *)a, (void *)b, c, (int *)d, 0x165);
}








void func_021D956C(int a, int b, int c)
{
    func_021D96DC(b, c, 6);
}








void func_021D957C(int a, void *b, int c)
{
    func_021D96FC((void *)b, c, 6);
}








int *func_021D958C(int *p)
{
    *p = 4;
    return d_021F0BB4;
}







/* 021D9598  shape F5: out-param store of func_021D9648(..., 7) */
/*
 * Leaf with no calls and no pool; 8 instructions, 18 bytes: push {r4, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #7; adds r4, r3, #0; bl func_021D9648; str r0, [r4]; pop {r4, pc}.
 */
void func_021D9598(int a, int b, int c, u32 *out)
{
    *out = func_021D9648(b, c, 7);
}





void func_021D95AC(int a, int b, int c)
{
    func_021D96DC(b, c, 7);
}





void func_021D95BC(int a, void *b, int c)
{
    func_021D96FC(b, c, 7);
}





void func_021D95CC(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(4) && (u16)func_021D775C(0x12) == 0x1bd) {
        if (func_021D76BC(0x40, 1) != 0) {
            func_021C88B4(b, 2, c);
            p = func_021C88A4(b, 4, c);
            func_021C8838(p + 4, 2, 0xd2);
            func_021C8860((struct S *)(p + 4), c);
            func_021C88C8(b, p);
            func_021C88B4(b, 3, c);
        }
    }
}







int *func_021D963C(int *p)
{
    *p = 5;
    return d_021F0CC4;
}







int func_021D9648(int a, int b, int c)
{
    if (b == func_021D775C(4) && c == func_021D775C(0x1d))
        return func_021D76BC(0x41, 1);
    return 0;
}








void func_021D9670(void *a, void *b, int c, int *d, u16 e)
{
    u8 *p;

    if (c == func_021D775C(4) && *d == 1) {
        func_021C88B4(b, 2, c);
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, e);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
        func_021C88B4(b, 3, c);
        *d = 0;
    }
}








/* 021D96CC  stack-arg wrapper: func_021D9670(a, b, c, d, 0xd2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0xd2; str r4, [sp]; bl func_021D9670; add sp, #4; pop {r3, r4, pc}.
 */
void func_021D96CC(void *a, void *b, int c, int *d)
{
    func_021D9670(a, b, c, d, 0xd2);
}







void func_021D96DC(int a,int b,int c) { if(b==func_021D775C(2)) func_021D96FC((void *)a,b,c); }







/*
 * Build the record for (a, b) after a two-step gate, fill in c, publish it
 * through func_021C88C8, then emit the "3" event through func_021C88B4.
 */
void func_021D96FC(void *a, int b, int c)
{
    if (func_021D62C4(func_021C7CF4(a, b), c) != 0) {
        u8 *p;
        func_021C88B4(a, 2, b);
        p = func_021C88A4(a, 0xb, b);
        ((struct Obj09218 *)p)->f4 = c;
        ((struct Obj09218 *)p)->f14 = 1;
        ((struct Obj09218 *)p)->f8 = b;
        func_021C88C8(a, p);
        func_021C88B4(a, 3, b);
    }
}




void func_021D9744(int a, void *b, int c)
{
    func_021D97B4(b, c, 2);
}




int *func_021D9754(int *p)
{
    *p = 2;
    return d_021F08D0;
}




/*
 * Extent ends with two bytes of zero alignment padding.
 */
void func_021D9760(int a, void *b, int c)
{
    func_021D97B4(b, c, 1);
}




int *func_021D9770(int *p)
{
    *p = 2;
    return d_021F08E0;
}




void func_021D977C(int a, void *b, int c)
{
    func_021D97B4(b, c, 4);
}




int *func_021D978C(int *p)
{
    *p = 2;
    return d_021F08F0;
}




void func_021D9798(int a, void *b, int c)
{
    func_021D97B4(b, c, 3);
}




int *func_021D97A8(int *p)
{
    *p = 2;
    return d_021F0900;
}




void func_021D97B4(void *a,int b,int c) { unsigned char *p; int k=2; if(b==func_021D775C(k)) { p=func_021C88A4(a,0x1d,b); ((struct Obj10056 *)p)->f0 |= k<<22; p[4]=c; p[5]=0xff; func_021C88C8(a,p); } }





/*
 * Shape F1's long-bodied sibling: gate on func_021D775C(2), then build the
 * record via func_021C88A4, set flag bit 22, and hand it to func_021C8838
 * and func_021C88C8.
 */
void func_021D97EC(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        u8 *p = func_021C88A4(b, 0x1d, c);
        ((struct Obj09219 *)p)->f0 |= 2 << 22;
        ((struct Obj09219 *)p)->f4 = 0;
        ((struct Obj09219 *)p)->f6 = 1;
        func_021C8838(p + 8, 1, 0x5e);
        func_021C88C8(b, p);
    }
}



void func_021D9830(void)
{
    func_021D76BC(65, 1);
}



int *func_021D983C(int *p)
{
    *p = 2;
    return d_021F0910;
}



void func_021D9848(int a, void *b, int c)
{
    func_021D9880(b, c, 3);
}



int *func_021D9858(int *p)
{
    *p = 1;
    return d_021F05C0;
}



void func_021D9864(int a, void *b, int c)
{
    func_021D9880(b, c, 2);
}



/*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 */
int *func_021D9874(int *p)
{
    *p = 1;
    return d_021F0670;
}



void func_021D9880(void *a, int b, int c)
{
    void *q;
    u8 *p;

    if (c == func_021D775C(0x39) && b == func_021D775C(2)) {
        q = func_021C7CF4(a, b);
        p = func_021C88A4(a, 5, b);
        ((struct Obj10057 *)p)->f0 |= 0x800000;
        p[6] = b;
        ((struct Obj10057 *)p)->f4 = func_021D7B74(q, 0x10);
        func_021C88C8(a, p);
        func_021D76BC(0x41, 1);
    }
}







void func_021D98DC(int a, void *b, int c)
{
    int h;
    u8 *p;

    if (c == func_021D775C(2) && func_021D775C(0x39) == 1) {
        h = func_021D7B74(func_021C7CF4(b, c), 8);
        func_021C88B4(b, 2, c);
        p = func_021C88A4(b, 7, c);
        p[6] = c;
        ((struct Obj13463 *)p)->f4 = h;
        func_021C88C8(b, p);
        func_021C88B4(b, 3, c);
    }
}







void func_021D9934(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021C8288((u8 *)b) == 1) {
        if (func_0201C1E8((u16)func_021D775C(0x12)) == 2)
            func_021D7704(0x35, 0x1800);
    }
}







int *func_021D996C(int *p)
{
    *p = 2;
    return d_021F0930;
}






void func_021D9978(int a,int b,int c) { if(c==func_021D775C(4) && c!=func_021D775C(3) && func_021D775C(0x1d)!=8) func_021D76BC(0x41,1); }






void func_021D99A4(int a,int b,int c) { if(c==func_021D775C(4) && c!=func_021D775C(3)) func_021D76BC(0x41,1); }







/* 021D99C8  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D99DE; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D99C8(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x41, 1);
}







/* 021D99E0  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D99F6; movs r0, #0x47; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D99E0(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x47, 1);
}





void func_021D99F8(int a,int b,int c) { if(func_021E85F8(c)!=0 && func_021D775C(5)==1) func_021D76BC(0x47,1); }





void *func_021D9A18(int *p) { *p=5; return &d_021F0CEC; }





void func_021D9A24(int a,int b,int c) { unsigned short v; if(c==func_021D775C(3)) { v=func_021D775C(0x26)*2; func_021D76BC(0x26,v); } }




/* 021D9A44  shape F1: gate on func_021D775C(3) */
void func_021D9A44(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x45, 1);
}


int *func_021D9A5C(int *p)
{
    *p = 3;
    return d_021F0A88;
}


void func_021D9A68(int a, void *b, int c)
{
    u8 *p;

    if (c == func_021D775C(2) && func_021C8288(b) == 2) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            func_021C88B4(b, 2, c);
            p = func_021C88A4(b, 0xb, c);
            ((struct Obj07809 *)p)->f4 = 0x24;
            p[8] = c;
            p[0x14] = 1;
            ((struct Obj07809 *)p)->f0 |= 0x2000000;
            func_021C88C8(b, p);
            func_021C88B4(b, 3, c);
        }
    }
}


int *func_021D9AD0(int *p)
{
    *p = 1;
    return d_021F05A8;
}
