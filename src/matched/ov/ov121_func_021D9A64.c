/*
 * function: func_021D9A64
 * address: 0x021D9A64
 * packet: pkt_ov121_021D9A64
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D9AC6.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021D9BC0 0x021D9BC0 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { int x; int y; } Pair;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D9BC0(void *, int, Pair *);
extern void func_0201C724(void *, void *, s16, s16, void *, int, u16);
void func_021D9A64(u8 *p, int a, int b, int c)
{
    Pair xy;
    void *q;
    func_02043B5C(func_02045770(*(void **)(p + 0xc)), *(u16 *)(p + 0x16) & 31);
    func_02045CAC((struct MsgBank *)a, b, *(void **)(p + 0x10));
    func_021D9BC0(p, c, &xy);
    q = *(void **)(p + 8);
    func_0201C724(q, func_02045770(*(void **)p), (s16)xy.x, (s16)xy.y,
                 *(void **)(p + 0x10), c, *(u16 *)(p + 0x16));
    p[4] = 1;
}
