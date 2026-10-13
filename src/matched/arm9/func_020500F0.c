/*
 * function: BILLBOARD_ACT_CreateSlots
 * address:  0x020500F0
 * packet:   pkt_020500F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   AREAMAN_Alloc  0x02033CA8  arm
 *   BILLBOARD_AddImage  0x0204EF58  arm
 *   BILLBOARD_TrimImageResource  0x0204F10C  arm
 *
 * billboard_act.c: take n slot indices from the pool at +0x14 and fill one
 * slot record per request (0: board slot, 1: board slot plus BILLBOARD_TrimImageResource,
 * 2: an external payload word with the 0xFFFF sentinel id).  The 28-byte
 * scheduling wall of the earlier notes was the missing `const` on the
 * request array (its byte loads then batch ahead of the outgoing-argument
 * stores, and case 2's payload load hoists above the sentinel store); with
 * it the plain subscript o->f0C[base + i] and literal zeros are exact.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BbActSlot { u16 id; u16 pad; u32 val; };

struct BbActRec { u32 f00; u8 b4; u8 b5; u8 b6; u8 b7; u32 type; };

struct BbActSys {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    u32 f14;
};

typedef signed int     s32;
struct AreaMan;
extern s32 AREAMAN_Alloc(struct AreaMan *p, u32 len);
extern u16  BILLBOARD_AddImage(void *board, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void BILLBOARD_TrimImageResource(void *board, u32 id);

u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *o, const struct BbActRec *recs, u32 n)
{
    int base;
    u32 i;

    base = AREAMAN_Alloc((struct AreaMan *)o->f14, n);
    for (i = 0; i < n; i++) {
        const struct BbActRec *e = &recs[i];
        u16 id;
        switch (e->type) {
        case 0:
            o->f0C[base + i].id = BILLBOARD_AddImage(o->f04, e->f00, e->b4, e->b5, e->b6, e->b7);
            o->f0C[base + i].val = 0;
            break;
        case 1:
            id = BILLBOARD_AddImage(o->f04, e->f00, e->b4, e->b5, e->b6, e->b7);
            BILLBOARD_TrimImageResource(o->f04, id);
            o->f0C[base + i].id = id;
            o->f0C[base + i].val = 0;
            break;
        case 2:
            o->f0C[base + i].id = 0xFFFF;
            o->f0C[base + i].val = e->f00;
            break;
        }
    }
    return base;
}

