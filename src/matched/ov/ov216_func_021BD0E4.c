/*
 * function: func_021BD0E4
 * address: 0x021BD0E4
 * packet: pkt_ov216_021BD0E4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_0204B3DC 0x0204B3DC arm
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   func_0202DCB0 0x0202DCB0 thumb
 *   sub_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
struct Obj0202DCC4;
struct Obj0202DC98;
extern void sub_0204B3DC(struct Obj *, u32);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *, u32);
extern void func_0202DCB0(struct Obj0202DC98 *, int, u32);
extern void sub_02040588(u32, u8);
void func_021BD0E4(char *p, u32 index, u32 enable)
{
    char *entry;
    entry = p + 0x15c + index * 128;
    sub_0204B3DC(*(struct Obj **)(entry + 0x78), enable);
    if (*(u8 *)(entry + 0x7d) != 0)
        sub_0204B3DC(*(struct Obj **)(entry + 0x74), enable);
    if (sub_0202DCC4(*(struct Obj0202DCC4 **)(p + 0x158), index) != 0)
        func_0202DCB0(*(struct Obj0202DC98 **)(p + 0x158), index, enable);
    sub_02040588(*(u8 *)(entry + 0x7e), enable);
}
