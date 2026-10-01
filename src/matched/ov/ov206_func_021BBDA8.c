/*
 * function: func_021BBDA8
 * address: 0x021BBDA8
 * packet: pkt_ov206_021BBDA8
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
struct State {
    char pad[0xb8]; int ids[3][2]; void *objects[2][2]; int selected,mode;
    char padE8[0x44]; void *other[17]; u8 a,b; char pad172[0x16]; void *last[2]; int index;
};
extern void func_0204B3DC(void *,unsigned);
void func_021BBDA8(struct State *p,unsigned v)
{
    u8 i;
    func_0204B3DC(p->last[p->index],v);
    if(p->mode) {
        if(p->a!=17) func_0204B3DC(p->other[p->a],v);
        if(p->b!=17) func_0204B3DC(p->other[p->b],v);
    } else {
        for(i=0;i<2;i++) {
            if(p->ids[p->selected][i]!=-1)
                func_0204B3DC(p->objects[p->selected][i],v);
        }
    }
}
