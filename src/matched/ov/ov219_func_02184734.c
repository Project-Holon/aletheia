/*
 * function: BEACON_DETAIL_MarkCurrentRecord
 * address: 0x02184734
 * packet: pkt_ov219_02184734
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: full context member offsets preserve the c2f4 pool base; a cast Tail pointer instead hoists p+c2f4 and raw scalar offsets pool c33c.
 * extent: unlabelled92-byte follower inside handed021846B8 extent; next labelled stub02184790 excluded.
 */
typedef unsigned short u16;
typedef struct {int words[9];} Matrix;
typedef struct {short x,y;Matrix matrix;u16 state,a,b,pad;} Record;
typedef struct {unsigned heap;void *ctx,*save,*field,*data;unsigned count;Record records[];} Records;
typedef struct {unsigned heap;void *ctx,*save,*field,*data;unsigned count;char pad[0xc2dc];int x,y;char pad2[0x40];unsigned a,b;} State;
void BEACON_DETAIL_MarkCurrentRecord(State *p)
{
    unsigned i;
    for(i=0;i<p->count;i++){
        if(((Records *)p)->records[i].a==p->a && ((Records *)p)->records[i].b==p->b){
            ((Records *)p)->records[i].state=3;
            p->x=((Records *)p)->records[i].x;
            p->y=((Records *)p)->records[i].y;
        }
    }
}
