/*
 * function: func_021B9608
 * address: 0x021B9608
 * packet: pkt_ov110_021B9608
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C1E80 0x021C1E80 data a4
 */
typedef unsigned short u16;
typedef struct {void *save;void *words;int counts[12];int starts[12];u16 values[1];} Object;
typedef struct {int (*fn)(Object *,const u16 *,unsigned int,u16 *); const u16 *data;unsigned int count;} Entry;
extern const Entry d_021C1E80[];
void func_021B9608(Object *p)
{
    int i;
    int n;
    i=0;
    n=0;
    for(;i<12;i++){
        p->starts[i]=n;
        p->counts[i]=d_021C1E80[i].fn(p,d_021C1E80[i].data,d_021C1E80[i].count,p->values+n);
        n+=p->counts[i];
    }
}
