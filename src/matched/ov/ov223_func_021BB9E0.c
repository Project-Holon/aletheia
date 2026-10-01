/*
 * function: func_021BB9E0
 * address: 0x021BB9E0
 * packet: pkt_ov223_021BB9E0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3F0 0x021BC3F0 thumb ov223
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9740 0x021B9740 thumb ov223
 *   func_021B9830 0x021B9830 thumb ov223
 *   func_021BAAB8 0x021BAAB8 thumb ov223
 *   func_021BAE00 0x021BAE00 thumb ov223
 *   func_021BB38C 0x021BB38C thumb ov223
 * 0201C440's pointer parameter is used as the full-width heap id here;
 * the original forwards its ldrh result unchanged to the wrapper.
 */
typedef unsigned short u16;
struct GfFont;
extern void *func_021BC3F0(int, int);
extern struct GfFont *func_0201D7EC(int, int, int, int, unsigned);
extern unsigned func_0201C440(void *);
extern void func_0204047C(int, u16);
extern void *func_020056A0(void (*)(void *, char *), void *, int);
extern void func_021B9740(void *, char *);
extern void func_021B9830(char *);
extern void func_021BAAB8(void *);
extern void func_021BAE00(void *);
extern void func_021BB38C(void *);
int func_021BB9E0(char *p)
{
    *(void **)(p + 0x14) = func_021BC3F0(1, *(u16 *)p);
    *(struct GfFont **)(p + 0x18) = func_0201D7EC(23, 0, 0, 0, *(u16 *)p);
    *(unsigned *)(p + 0x1C) = func_0201C440((void *)(unsigned)*(u16 *)p);
    func_0204047C(0, 2);
    func_0204047C(1, 3);
    func_0204047C(2, 1);
    func_0204047C(3, 0);
    func_0204047C(4, 3);
    func_0204047C(5, 2);
    func_0204047C(6, 1);
    func_0204047C(7, 0);
    *(void **)(p + 0x20) = func_020056A0(func_021B9740, p, 1);
    *(int *)(p + 0x24) = 0;
    func_021B9830(p);
    func_021BAAB8(p);
    func_021BAE00(p);
    func_021BB38C(p);
    return 2;
}
