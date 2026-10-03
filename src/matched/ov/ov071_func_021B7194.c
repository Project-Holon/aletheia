/*
 * function: func_021B7194
 * address:  0x021B7194
 * packet:   pkt_ov071_021B7194
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02027778  0x02027778  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { void *s; u16 h; int z; } Item;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02027778(void *, void *);

void *func_021B7194(int *p, void *arg1, u32 heap)
{
    Item it[2];
    struct {
        u32 heapId;
        u8 count;
        u8 pad05[3];
        Item *items;
        u32 unk0c;
        u8 b0, b1, b2, b3;
    } t;
    void *r;

    it[0].s = func_02045EC0((void *)p[0x28 / 4], 0x1e);
    it[1].s = func_02045EC0((void *)p[0x28 / 4], 0x1f);
    it[0].h = 0x39E0;
    it[1].h = 0x39E0;
    it[0].z = 0;
    it[1].z = 0;
    t.heapId = heap;
    t.count = 2;
    t.items = it;
    t.unk0c = 0;
    t.b0 = 0x18;
    t.b1 = 0xc;
    t.b2 = 8;
    t.b3 = 3;
    r = func_02027778(&t, arg1);
    func_02045808(it[0].s);
    func_02045808(it[1].s);
    return r;
}
