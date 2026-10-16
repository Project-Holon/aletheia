/*
 * function: ZUKAN_INFO_DisableOtherRows
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
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
struct State { char pad[0xb8]; int ids[3][2]; void *objects[2][2]; int selected,mode; };
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void ZUKAN_INFO_DisableOtherRows(struct State *p)
{
    u8 i,j;
    if (p->mode==0) {
        for(i=0;i<2;i++) {
            if(i != p->selected) {
                for(j=0;j<2;j++) {
                    if(p->ids[i][j]!=-1)
                        CLACT_SetActorDrawEnable(p->objects[i][j],0);
                }
            }
        }
    }
}
