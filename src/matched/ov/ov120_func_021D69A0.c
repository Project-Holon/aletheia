/*
 * function: func_021D69A0
 * address: 0x021D69A0
 * packet: pkt_ov120_021D69A0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D69F2.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x, y, z; u8 a, b; } Record;
extern void *func_0204B294(u32, u32, u32, u32, Record *, u16, u16);
struct Actor;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021D69A0(u8 *p)
{
    Record r;
    r.x = 0; r.y = 0; r.z = 0; r.a = 0; r.b = 2;
    *(void **)(p + 0x134) = func_0204B294(*(u32 *)(p + 0x10), *(u32 *)(p + 0x28), *(u32 *)(p + 0x18), *(u32 *)(p + 0x74), &r, 1, *(u16 *)(p + 0xf4));
    func_0204B92C(*(void **)(p + 0x134), 1);
    func_0204B3DC(*(void **)(p + 0x134), 0);
    func_0204B688(*(void **)(p + 0x134), 1);
}
