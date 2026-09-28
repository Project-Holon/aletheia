/*
 * function: ov208_func_021C5CF0
 * address:  0x021C5CF0
 * packet:   pkt_ov208_021C5CF0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 19 bytes out: register rotation in the `(cur + 1) % 2` block (image keeps the
 * 0x144 offset in r0 and the sum in r1; compiled uses r3 and r0).
 *
 * symbols:
 *   func_0204B3DC        0x0204B3DC  arm
 *   func_021C53E0        0x021C53E0  thumb
 *   ov208_func_021C57A4  0x021C57A4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Ent {
    u32 kind;
    u32 mode;
    u16 pad8;
    u8  forms;
    u8  padb;
    u16 species;
    u16 pade;
};

struct Ov208Menu {
    u32 owner;
    u8  pad4[0x124];
    u32 arc;
    u32 res[2];
    u32 j;
    u32 k;
    u32 obj[2];
    int cur;
    struct Ov208Ent ents[8];
    u8  pad1c8[0x386];
    u16 sel;
};

extern void func_0204B3DC(u32 obj, int on);
extern void func_021C53E0(u32 res);
extern void ov208_func_021C57A4(u16 *heap, struct Ov208Menu *p, int key, u16 idx);

void ov208_func_021C5CF0(u16 *heap, struct Ov208Menu *p, int key)
{
    if (p->obj[p->cur] != 0)
        func_0204B3DC(p->obj[p->cur], 0);
    p->cur = (p->cur + 1) % 2;
    if (p->obj[p->cur] != 0) {
        if (p->obj[p->cur] != 0)
            func_021C53E0(p->res[p->cur]);
        p->obj[p->cur] = 0;
    }
    ov208_func_021C57A4(heap, p, key, p->sel);
}
