/*
 * function: func_021B9AC0
 * address: 0x021B9AC0
 * packet: pkt_ov133_021B9AC0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021B9AC0(u8 *p, int *a, int *b, u16 duration)
{
    int x, y;
    int count;
    *(int *)(p + 0x18) = 1;
    if (*(u16 *)(p + 0x1844) == 0) *(int *)(p + 0x14) = 1;
    else *(int *)(p + 0x14) = 0;
    count = *(u16 *)(p + 0x1844);
    y = a[1] + (b[1] - a[1]) * count / (int)duration;
    x = a[0] + (b[0] - a[0]) * count / (int)duration;
    *(int *)(p + 0x1c) = x;
    *(int *)(p + 0x20) = y;
    func_0204B3DC(*(void **)(p + 0x1854), 1);
    (*(u16 *)(p + 0x1844))++;
    if (*(u16 *)(p + 0x1844) > duration) {
        *(u16 *)(p + 0x1844) = 0;
        (*(u8 *)(p + 0x1846))++;
    }
}
