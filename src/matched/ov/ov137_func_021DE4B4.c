/*
 * function: func_021DE4B4
 * address: 0x021DE4B4
 * packet: pkt_ov137_021DE4B4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void *func_020457B0(int, int);
extern void func_02045CAC(void *, int, void *);
extern void func_0201F250(void *, void *, void *);
extern void func_02045808(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, unsigned);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201CE48(void *);
extern void *func_0201CCE4(void *, int, int, void *, void *, int, void *, int, u16, u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void *func_02045730(void *);
extern void func_020409B4(void *);
void func_021DE4B4(char *p, int message, int unused) {
    void *text;
    void *window;
    text = func_020457B0(0xb4, 0x72);
    func_02045CAC(*(void **)(p+0x40), message, text);
    func_0201F250(*(void **)(p+0x3c), *(void **)(p+0x5c), text);
    func_02045808(text);
    func_02043B5C(func_02045770(*(void **)(p+0xd4)), 0xf);
    func_0201F73C(*(void **)(p+0xd4), 0, 1, 0xa);
    if (*(void **)(p+0xf0) != 0)
        func_0201CE48(*(void **)(p+0xf0));
    *(void **)(p+0xf0) = func_0201CCE4(*(void **)(p+0xd4), 0, 0, *(void **)(p+0x5c), *(void **)(p+0x38), 0, *(void **)(p+0xf4), 0, 0x72, 0xf);
    window = *(void **)(p+0xd4);
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
}
