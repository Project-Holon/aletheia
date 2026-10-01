/*
 * function: func_021C1FE0
 * address: 0x021C1FE0
 * packet: pkt_ov208_021C1FE0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   func_021C1D30 0x021C1D30 thumb ov208
 *   func_021C2238 0x021C2238 thumb ov208
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
struct PrintSys;
struct Descriptor;
struct CharBuf;
extern unsigned func_0204B3F4(struct Obj *);
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void func_0204B3DC(struct Obj *, unsigned);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern void func_021C1D30(u16 *, u8 *, int);
extern void func_021C2238(u16 *, u8 *, int);
void func_021C1FE0(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj **)(p + 0xc8))) {
        if (*(unsigned *)(p + 0x90) == 1) {
            *(unsigned *)(p + 0x30) = 0;
            func_0201C6EC(*(struct PrintSys **)(p + 0x40));
            func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x20)), 0);
            func_02045334(*(struct Descriptor **)(p + 0x20));
            func_0204B3DC(*(struct Obj **)(p + 0xc8), 0);
        }
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (*(unsigned *)(p + 0x90) == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            func_0204B3DC(*(struct Obj **)(p + 0xcc), 0);
            func_0204B3DC(*(struct Obj **)(p + 0xd0), 0);
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
        }
    }
}
