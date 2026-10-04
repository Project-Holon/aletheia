/*
 * function: func_021D6E84
 * address: 0x021D6E84
 * packet: pkt_ov120_021D6E84
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D6ED6.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x, y, z; u8 a, b; } Record;
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021D6E84(u8 *p)
{
    Record r;
    r.x = 128; r.y = 200; r.z = 0; r.a = 1; r.b = 1;
    *(void **)(p + 0x138) = func_0204B294((void *)*(u32 *)(p + 0x10), *(u32 *)(p + 0x70), *(u32 *)(p + 0x24), *(u32 *)(p + 0xbc), &r, 1, *(u16 *)(p + 0xf4));
    func_0204B92C(*(void **)(p + 0x138), 1);
    func_0204B3DC(*(void **)(p + 0x138), 1);
}
