/*
 * function: func_021E129C
 * address: 0x021E129C
 * packet: pkt_ov137_021E129C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E22B8 0x021E22B8 data a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E121C 0x021E121C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021E22B8[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
struct Obj;
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B8D4(u32, int);
extern void func_02030DA8(void *, void (*)(void *, int *), void *, int);
extern void func_021E121C(void *, int *);
void func_021E129C(char *p)
{
    struct { u16 x, y, z; u8 a, b; } pos;
    int *q = func_02030734(0x8072, 24, 0, d_021E22B8, 5638);
    func_02082BCC(q, 0, 24);
    pos.x = 128;
    pos.y = 100;
    pos.z = 0;
    pos.b = 0;
    pos.a = 0;
    q[5] = (int)func_0204B294((void *)*(u32 *)(p+0xd68), *(u32 *)(p+0xd6c), *(u32 *)(p+0xd70), *(u32 *)(p+0xd74), &pos, 0, 114);
    func_0204B8D4(q[5], 4096);
    q[4] = (int)p;
    func_02030DA8(*(void **)(p+0xd98), func_021E121C, q, 0);
}
