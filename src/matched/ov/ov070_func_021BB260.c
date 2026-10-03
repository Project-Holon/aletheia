/*
 * function: func_021BB260
 * address:  0x021BB260
 * packet:   pkt_ov070_021BB260
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: each window address bound to its own pointer local (win before the
 * first statement, win2 at the top of the if block, before the
 * func_021B619C call). With the addresses spelled inline the compiler CSEs
 * the stack-argument zero into r7 and spills val; with the locals val keeps
 * r7 and every zero is rematerialised. The same lever closed
 * ov070_func_021BAB04 (MATCH, arm9 leaf blocker).
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_021BB724  0x021BB724  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02045CAC(int, int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, int, int);
extern void func_021BB6E0(u8 *p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void func_021BB724(u32 *);
extern int func_021B619C(int a, int b, unsigned int id);

void func_021BB260(u8 *p, int val)
{
    int v;
    u32 *win2;
    u32 *win;

    win = (u32 *)(p + 0x754);

    func_02043B5C(func_02045770(*win), 5);
    func_02045CAC(*(int *)(p + 0x51C), 0x83, *(int *)(p + 0x524));
    func_0201EFA4(*(int *)(p + 0x520), 0, val, 3, 0, 1);
    func_0201F250(*(int *)(p + 0x520), *(int *)(p + 0x528), *(int *)(p + 0x524));
    func_021BB6E0(p, win, *(u32 *)(p + 0x528), 0, 0, 0x3DC5);
    func_021BB724(win);
    if (*(int *)(p + 0x7EC) == 2) {
        win2 = (u32 *)(p + 0x76C);
        v = func_021B619C(*(u32 *)(p + 0x84C), *(int *)(p + 0x7F4), *(u16 *)(p + 0x544));
        func_02043B5C(func_02045770(*win2), 5);
        func_02045CAC(*(int *)(p + 0x51C), 0x54, *(int *)(p + 0x524));
        func_0201EFA4(*(int *)(p + 0x520), 0, v, 7, 0, 1);
        func_0201F250(*(int *)(p + 0x520), *(int *)(p + 0x528), *(int *)(p + 0x524));
        func_021BB6E0(p, win2, *(u32 *)(p + 0x528), 0, 0, 0x3DC5);
        func_021BB724(win2);
    }
}
