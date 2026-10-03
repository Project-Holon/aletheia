/*
 * function: func_021DD700
 * address: 0x021DD700
 * packet: pkt_ov137_021DD700
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
typedef signed short s16;
extern int func_0201D304(void *, void *, int);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045730(void *);
extern void func_020409B4(void *);
void func_021DD700(void *p, void *text, void *font) {
    int width;
    width = func_0201D304(text, font, 0);
    func_02043B5C(func_02045770(p), 0);
    func_0201C7D0(func_02045770(p), (208-width)/2, 1, text, font, 0x480);
    func_02045334(p);
    func_02045374(p);
    func_020409B4(func_02045730(p));
}
