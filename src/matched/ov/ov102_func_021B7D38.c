/*
 * function: func_021B7D38
 * address: 0x021B7D38
 * packet: pkt_ov102_021B7D38
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: narrow c parameter places its reload immediately before the call.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *, int, int);
extern int func_020450F0(int, int, u8, u8, u8, u8, u8);
extern int func_020457B0(int, u16);
extern int func_02045770(int);
extern void func_02043B5C(int, u8);
extern void func_02045334(int);
extern void func_02045374(int);
extern int func_02045730(int);
extern void func_020409B4(int);
void func_021B7D38(u8 *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g, u8 h, u16 heap)
{
    int win;
    func_02082BCC(p, 0, 20);
    *(u16 *)(p + 16) = g;
    *(int *)p = func_020450F0(a, b, c, d, e, f, h);
    *(int *)(p + 12) = func_020457B0(255, heap);
    *(int *)(p + 4) = *(int *)p;
    p[8] = 0;
    func_02043B5C(func_02045770(*(int *)p), *(u16 *)(p + 16));
    win = *(int *)p;
    func_02045334(win);
    func_02045374(win);
    func_020409B4(func_02045730(win));
}
