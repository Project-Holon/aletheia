/*
 * function: func_0220C60C
 * address: 0x0220C60C
 * packet: pkt_ov198_0220C60C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02043B5C 0x02043B5C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_02045EC0(void *, u32);
extern u32 func_02045770(void *);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern void func_02045808(void *);
extern void func_02043B5C(void *, u8);
struct Flags { u8 pad[0x2177]; u8 low:4; u8 high:4; };
void func_0220C60C(char *p, int id)
{
    void *t;
    void *f;
    func_02043B5C((void *)func_02045770(*(void **)(p + 0x1F60)), 15);
    t = func_02045EC0(*(void **)(p + 0x1EA0), id);
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, func_02045770(*(void **)(p + 0x1F60)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x440);
    *(u8 *)(p + 0x1F64) = 1;
    func_02045808(t);
    ((struct Flags *)p)->high = 1;
}
