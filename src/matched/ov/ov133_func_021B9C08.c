/*
 * function: func_021B9C08
 * address: 0x021B9C08
 * packet: pkt_ov133_021B9C08
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C724 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02045EC0(void *, unsigned int);
extern void func_0201C6EC(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, u8);
extern void *func_020457B0(unsigned int, unsigned int);
extern void func_0201F250(void *, void *, void *);
extern void func_02045808(void *);
extern void func_0201C724(void *, void *, unsigned int, unsigned int, const void *, void *, u16);
void func_021B9C08(u8 *p, unsigned int index, void *object)
{
    void *text = func_02045EC0(*(void **)(p + 0x18d8), index);
    void *copy;
    func_0201C6EC(*(void **)(p + 0x18e8));
    func_02043B5C(func_02045770(*(void **)(p + 0x18ec)), 15);
    if (object) {
        copy = func_020457B0(128, *(u16 *)p);
        func_0201F250(object, copy, text);
        func_02045808(text);
        text = copy;
    }
    func_0201C724(*(void **)(p + 0x18e8), func_02045770(*(void **)(p + 0x18ec)), 2, 2, text, *(void **)(p + 0x18e4), 1088);
    func_02045808(text);
    *(int *)(p + 0x18cc) = 1;
}
