/*
 * function: BILLBOARD_ACT_DeleteEntries
 * address:  0x02050468
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   BILLBOARD_FreeElem  0x0204F5A8  arm
 *   BILLBOARD_ACT_InitEntry  0x020500B8  arm
 *   AREAMAN_Free  0x0203422C  arm
 *
 * billboard_act.c: release `count` entries from `first` and give the index
 * range back to the pool.  The earlier 2-byte floor (add operand order) and
 * the hand-copied stride came from writing the address arithmetic by hand;
 * the source is plain subscripts, o->f18[first + i], in a for loop.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BbActEntry { u32 f00; u8 pad[0x24]; };

struct BbActSys {
    u16 f00;
    u16 f02;
    void *f04;
    u8  pad_08[0x10];
    struct BbActEntry *f18;
    u16 f1C;
    u16 f1E;
    void *f20;
};

extern void BILLBOARD_FreeElem(void *board, u32 idx);
extern void BILLBOARD_ACT_InitEntry(u32 *p);
typedef signed int     s32;
struct AreaMan;
extern void AREAMAN_Free(struct AreaMan *p, u32 start, s32 len);

void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        BILLBOARD_FreeElem(o->f04, o->f18[first + i].f00);
        BILLBOARD_ACT_InitEntry((u32 *)(&o->f18[first + i]));
    }
    AREAMAN_Free(o->f20, first, count);
}

