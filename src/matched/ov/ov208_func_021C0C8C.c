/*
 * function: ov208_func_021C0C8C
 * address:  0x021C0C8C
 * packet:   pkt_ov208_021C0C8C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C0C14  0x021C0C14  thumb  ov208
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u8   ov208_func_021C0C14(u16 *heap, u8 *p, int key);
extern void func_0204B878(u32 obj, u32 anim);
struct Obj;
extern void func_0204B3DC(struct Obj *obj, u32 on);

void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on)
{
    if (on) {
        if (ov208_func_021C0C14(heap, p, key) != 0xff) {
            func_0204B878(*(u32 *)(p + 0xd4), 6);
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd4), 1);
        }
    } else {
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd4), 0);
    }
}
