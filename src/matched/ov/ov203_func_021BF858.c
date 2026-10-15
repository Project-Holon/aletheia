/*
 * function: DEMO3D_CMDSYS_Update
 * address: 0x021BF858
 * packet: pkt_ov203_021BF858
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   DEMO3D_DATA_GetAnimIndex 0x021BE990 thumb ov203
 *   DEMO3D_CMDSYS_Dispatch 0x021BF9B8 thumb ov203
 */
typedef struct {int kind,time;int values[8];} Record;
typedef struct {int heaps;int config;int ended;int done;int previous;int index;char flags[4];int owner;void *task;} Context;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void DEMO3D_CMDSYS_Dispatch(Context *,int,Record *);
extern Record *DEMO3D_DATA_GetAnimIndex(int);
void DEMO3D_CMDSYS_Update(Context *p,int time,int flag)
{
    Record *r;
    int owner,i;
    owner=p->owner;
    p->flags[2]=flag?1:0;
    TCBL_Main(p->task);
    if(p->ended==0 && time!=-4096) {
        r=DEMO3D_DATA_GetAnimIndex(p->config)+p->index;
        time>>=12;
        if(r->time==time && p->previous!=time) {
            i=0;
            do {
                DEMO3D_CMDSYS_Dispatch(p,owner,r);
                r++;
                p->ended=r->kind==18?1:0;
                p->index++;
                if(p->ended==1) break;
                if(r->time!=time) break;
                i++;
            } while(i<9999);
        }
        p->previous=time;
    }
}
