/*
 * function: func_021BF858
 * address: 0x021BF858
 * packet: pkt_ov203_021BF858
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   func_021BE990 0x021BE990 thumb ov203
 *   func_021BF9B8 0x021BF9B8 thumb ov203
 */
typedef struct {int kind,time;int values[8];} Record;
typedef struct {int heaps;int config;int ended;int done;int previous;int index;char flags[4];int owner;void *task;} Context;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void func_021BF9B8(Context *,int,Record *);
extern Record *func_021BE990(int);
void func_021BF858(Context *p,int time,int flag)
{
    Record *r;
    int owner,i;
    owner=p->owner;
    p->flags[2]=flag?1:0;
    TCBL_Main(p->task);
    if(p->ended==0 && time!=-4096) {
        r=func_021BE990(p->config)+p->index;
        time>>=12;
        if(r->time==time && p->previous!=time) {
            i=0;
            do {
                func_021BF9B8(p,owner,r);
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
