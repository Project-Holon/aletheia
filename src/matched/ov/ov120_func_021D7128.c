/*
 * function: func_021D7128
 * address: 0x021D7128
 * packet: pkt_ov120_021D7128
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x, y, z; u8 a, b; } Record;
extern void func_0204B3B4(void *);
extern void *func_0204B294(u32, u32, u32, u32, Record *, u16, u16);
extern void func_0204B92C(void *, u32);
extern void func_0204B3DC(void *, u32);
void func_021D7128(u8 *p, int n, int k)
{
    Record r;
    if (*(void **)(p + 0x14c + n * 4)) func_0204B3B4(*(void **)(p + 0x14c + n * 4));
    r.x = 0; r.y = 0; r.z = 1; r.a = 10; r.b = 2;
    *(void **)(p + 0x14c + n * 4) = func_0204B294(*(u32 *)(p + 0x10), *(u32 *)(p + (k + 6) * 4 + 0x18), *(u32 *)(p + 0x20), *(u32 *)(p + (k + 25) * 4 + 0x18), &r, 1, *(u16 *)(p + 0xf4));
    func_0204B92C(*(void **)(p + 0x14c + n * 4), 1);
    func_0204B3DC(*(void **)(p + 0x14c + n * 4), 0);
}
