/*
 * function: func_02205B90
 * address: 0x02205B90
 * packet: pkt_ov094_02205B90
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0220A558 0x0220A558 data ov094 a4
 *   d_0220A56C 0x0220A56C data ov094 a4
 *   d_0220A544 0x0220A544 data ov094 a4
 *   d_0220A392 0x0220A392 data ov094 a2
 *   d_0220AEB0 0x0220AEB0 data ov094 a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_0220684C 0x0220684C thumb ov094
 *   func_02204A88 0x02204A88 thumb ov094
 *   func_02204AEC 0x02204AEC thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Five { int v[5]; } Five;
typedef struct Point { s16 x, y; } Point;
typedef struct Bits { u32 low : 1; u32 count : 3; u32 high : 28; } Bits;
extern const Five d_0220A558, d_0220A56C, d_0220A544;
extern const u16 d_0220A392[];
extern const char d_0220AEB0[];
extern void *func_0204B294(u32, u32, u32, u32, const void *, u16, u16);
extern void func_0204B404(void *, s16 *, int);
struct Ctx;
struct Node;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B6F4(void *, u8, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void func_0220684C(void *, void *, void *);
extern void func_02204A88(int a0, struct Ctx *c);
extern void func_02204AEC(void *);
void func_02205B90(char *p, int n)
{
    Five a = d_0220A558;
    Five b = d_0220A56C;
    Five c = d_0220A544;
    Point v;
    int index;
    void **q;
    if (n == 0) return;
    *(void **)(p + 0x210) = func_0204B294(*(u32 *)(p + 0x20c), *(u32 *)(p + 0x104), *(u32 *)(p + 0x108), *(u32 *)(p + 0x10c), d_0220A392, 1, *(u16 *)(p + 0x240));
    index = n - 1;
    v.x = 0x130 + b.v[index];
    v.y = 0x20 + c.v[index];
    func_0204B404(*(void **)(p + 0x210), &v.x, 1);
    func_0204B92C(*(void **)(p + 0x210), 1);
    n += 14;
    func_0204B878(*(void **)(p + 0x210), n);
    *(void **)(p + 0x214) = func_0204B294(*(u32 *)(p + 0x20c), *(u32 *)(p + 0x104), *(u32 *)(p + 0x108), *(u32 *)(p + 0x10c), d_0220A392, 1, *(u16 *)(p + 0x240));
    v.x = 0x130;
    v.y = 0x20;
    func_0204B404(*(void **)(p + 0x214), &v.x, 1);
    func_0204B92C(*(void **)(p + 0x214), 1);
    func_0204B878(*(void **)(p + 0x214), 14);
    func_0204B6F4(*(void **)(p + 0x214), a.v[index], 0);
    q = func_02030734((u16)((*(u16 *)(p + 0x240) & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x11ec);
    q[0] = p;
    func_0220684C(p, func_02030DA8(*(void **)p, (u32)func_02204A88, (u32)q, 0), (void *)func_02204AEC);
    ((Bits *)(p + 0x68))->count++;
}
