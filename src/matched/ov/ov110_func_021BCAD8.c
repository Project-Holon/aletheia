/*
 * function: func_021BCAD8
 * address: 0x021BCAD8
 * packet: pkt_ov110_021BCAD8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02028148 0x02028148 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef struct { void *s; unsigned short x; unsigned short pad; int flag; } Record;
typedef struct { u8 pad[0x40]; Record records[3]; void *windows[3]; void *items[8]; void *other[2]; } Object;
typedef unsigned int   u32;
struct Obj;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02028148(u8 *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020409B4(u32 index);
void func_021BCAD8(Object *p) {
    int i;
    for(i=0;i<3;i++) {
        if(p->records[i].s) { func_02045808(p->records[i].s); p->records[i].s=0; }
        if(p->windows[i]) { func_02028148(p->windows[i]); p->windows[i]=0; }
    }
    for(i=0;i<8;i++) func_0204B3DC(p->items[i],0);
    for(i=0;i<2;i++) func_0204B3DC(p->other[i],0);
    func_020409B4(0);
    func_0204B3DC(*(void **)((u8 *)p+0x28),0);
}
