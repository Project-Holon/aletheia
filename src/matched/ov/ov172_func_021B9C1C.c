/*
 * function: func_021B9C1C
 * address: 0x021B9C1C
 * packet: pkt_ov172_021B9C1C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes zero alignment padding follow the return.
 * symbols:
 *   func_021BE034 0x021BE034 thumb ov172
 *   func_021BE03C 0x021BE03C thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 */
typedef unsigned int u32;
extern u32 func_021BE034(void *);
extern u32 func_021BE03C(void *);
extern u32 func_021BE044(void *);
extern void func_0201C6EC(u32);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(u32, int);
extern u32 func_02045EC0(u32, int);
extern void func_0201C724(u32, u32, int, int, u32, u32, int);
extern void func_02045808(u32);
extern void func_02045334(u32);
extern void func_02045374(u32);
extern void func_0201F73C(u32, int, int, int);
void func_021B9C1C(void *p, char *q, int id)
{
    u32 font = func_021BE034(p);
    u32 msgs = func_021BE03C(p);
    u32 sys = func_021BE044(p);
    u32 text;
    func_0201C6EC(sys);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 124)), 15);
    text = func_02045EC0(msgs, id);
    func_0201C724(sys, (u32)func_02045770((struct Descriptor *)*(u32 *)(q + 124)), 0, 0, text, font, 1088);
    func_02045808(text);
    func_02045334(*(u32 *)(q + 124));
    func_02045374(*(u32 *)(q + 124));
    func_0201F73C(*(u32 *)(q + 124), 1, 320, 9);
    *(u32 *)(q + 40) = 1;
}
