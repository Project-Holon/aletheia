/*
 * function: func_021B8904
 * address:  0x021B8904
 * packet:   pkt_ov070_021B8904
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_021BA41C  0x021BA41C  thumb  ov070
 *   func_021BA4A4  0x021BA4A4  thumb  ov070
 *   func_021B9ED8  0x021B9ED8  thumb  ov070
 *   func_021BB73C  0x021BB73C  thumb  ov070
 *   func_020310C4  0x020310C4  arm
 */

typedef unsigned int   u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
typedef unsigned char  u8;
struct Tcbl;
extern void func_021BA41C(char *p);
extern void func_021BA4A4(char *p);
extern void func_021B9ED8(char *p);
extern void func_021BB73C(u8 *p);
extern void func_020310C4(struct Tcbl *p);

int func_021B8904(int a, int b, int c, int p)
{
    void (*fn)(int) = *(void (**)(int))((char *)p + 0x4F8);
    if (fn == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, *(unsigned short *)((char *)p + 0x544));
        return 1;
    }
    *(int *)((char *)p + 0x818) = *(int *)((char *)p + 0x814);
    fn(p);
    if (*(unsigned short *)((char *)p + 0x83E) != 0) {
        func_021BA41C((char *)p);
        *(unsigned short *)((char *)p + 0x83E) = 0;
    }
    if (*(unsigned short *)((char *)p + 0x83C) != 0) {
        func_021BA4A4((char *)p);
        *(unsigned short *)((char *)p + 0x83C) = 0;
    }
    func_021B9ED8((char *)p);
    func_021BB73C((u8 *)p);
    func_020310C4((struct Tcbl *)(*(int *)((char *)p + 0x730)));
    return 0;
}
