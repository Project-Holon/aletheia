/*
 * function: func_021BB980
 * address: 0x021BB980
 * packet: pkt_ov206_021BB980
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: zero alignment halfword at 0x021BB9DE before 0x021BB9E0.
 * lever: two-dimensional arrays as struct fields avoid hoisted raw-offset bases.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
struct State { char pad[0xb8]; int ids[3][2]; void *objects[2][2]; int selected,mode; };
extern void func_0204B3DC(void *,unsigned);
void func_021BB980(struct State *p)
{
    u8 i,j;
    if (p->mode==0) {
        for(i=0;i<2;i++) {
            if(i != p->selected) {
                for(j=0;j<2;j++) {
                    if(p->ids[i][j]!=-1)
                        func_0204B3DC(p->objects[i][j],0);
                }
            }
        }
    }
}
