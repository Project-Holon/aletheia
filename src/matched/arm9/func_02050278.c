/*
 * function: func_02050278
 * address:  0x02050278
 * packet:   pkt_02050278
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0204F150  0x0204F150  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02050088  0x02050088  arm
 *   func_0203422C  0x0203422C  arm
 *
 * billboard_act.c: release `count` slot records from `first`: the board
 * record through func_0204F150(board, id) when the id is live, the payload
 * through func_02046EFC when nonzero, then reset the record and return the
 * index range to the pool.  func_0204F150 takes TWO arguments (the loaded
 * id is the r1 the image compares); the rest is plain subscripts.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BbActSlot { u16 id; u16 pad; u32 val; };

struct BbActSys {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    void *f14;
};

extern void func_0204F150(void *board, u32 idx);
extern void func_02046EFC(u32 v);
extern void func_02050088(struct BbActSlot *s);
extern void func_0203422C(void *pool, u32 first, u32 count);

void func_02050278(struct BbActSys *o, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        if (o->f0C[first + i].id != 0xFFFF) {
            func_0204F150(o->f04, o->f0C[first + i].id);
        }
        if (o->f0C[first + i].val != 0) {
            func_02046EFC(o->f0C[first + i].val);
        }
        func_02050088(&o->f0C[first + i]);
    }
    func_0203422C(o->f14, first, count);
}

