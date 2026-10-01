/*
 * function: func_021BCB50
 * address: 0x021BCB50
 * packet: pkt_ov110_021BCB50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: counter initialized before record-base assignment; existing
 *   a-loop-counter-zero-before-an-offset-assignment-schedules-before-its-spill.
 * evidence: own CAD8 establishes records[3], windows[3], items[8], other[2]
 *   and their offsets. Both loops use indices0..1; all selected fields are
 *   in those arrays. Stores/pointers keep original call order and word width.
 * abi: F7C4 own void thunk tail-forwards input00 to ARM9 24158; full
 *   8-byte target returns byte03 bit2 (0/1), consumed by original CB50.
 *   27FEC fourth argument explicitly truncated to u8 by original caller.
 * symbols:
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FEC 0x02027FEC thumb
 *   func_020282AC 0x020282AC thumb
 *   func_021BCD44 0x021BCD44 thumb ov110
 *   func_020409B4 0x020409B4 arm
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BCCA8 0x021BCCA8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct Obj;
struct T;
typedef struct Record { void *s; u16 x,pad; int flag; } Record;
typedef struct Object {
    u32 f00;
    u8 *f04;
    u8 pad08[0x28];
    struct MsgBank *bank;
    u16 *windows[3];
    Record records[3];
    struct T *menus[3];
    struct Obj *items[8];
    struct Obj *other[2];
} Object;
extern void func_021BCAD8(Object *);
extern void *func_02045EC0(struct MsgBank *,u32);
extern u32 func_02027FEC(u32,u32,u32,u8,u8,u16);
extern void func_020282AC(struct T *,u16 *,u32,u32,u16);
extern void func_021BCD44(Object *);
extern void func_020409B4(u32);
extern u32 func_021BF7C4(u8 *);
extern u32 func_021BF6D8(u8 *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021BCCA8(Object *);
void func_021BCB50(Object *p)
{
    int i;
    Record *records;
    func_021BCAD8(p);
    i=0;
    records=p->records;
    for(;i<2;i++) {
        p->records[i].s=func_02045EC0(p->bank,i+14);
        p->records[i].x=0x39e3;
        p->records[i].flag=(i==1);
        p->menus[i]=(struct T *)func_02027FEC((u32)p->windows[i],(u32)&records[i],23,i*3+18,9,42);
        func_020282AC(p->menus[i],p->windows[i],8,0x3545,0x7b2c);
    }
    func_021BCD44(p);
    func_020409B4(0);
    if(func_021BF7C4(p->f04)==0 && func_021BF6D8(p->f04)==2) {
        func_0204B3DC(p->items[0],1);
        func_0204B3DC(p->items[1],1);
        func_0204B3DC(p->items[2],1);
        func_0204B3DC(p->items[3],1);
        func_0204B3DC(p->items[4],1);
        func_0204B3DC(p->items[5],1);
        func_0204B3DC(p->items[6],1);
        for(i=0;i<2;i++) func_0204B3DC(p->other[i],1);
    }
    func_021BCCA8(p);
}
