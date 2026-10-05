/*
 * function: func_021E0A44
 * address: 0x021E0A44
 * packet: pkt_ov137_021E0A44
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave P12 lane A8): 33 of 208 bytes differ. The logic and all constants
 *   match (pool 0x021E1FDC and 65535, 0x168000, 0x15c, 0x2e0 return). Residue: the original loads the
 *   table pool word into r4 straight after the count load and keeps count in lr and the insertion key in
 *   ip; the draft loads the pool word later into r1, keeps count in ip and the key in lr. Tried, no
 *   change or worse: table first statement, raw unsigned local for the table, direct extern use,
 *   2D table d[count][index] (182), table[count*5+index] (182), named row=count*10 as in matched
 *   func_021DEE4C (182, extra copy of count), int count (182), unsigned count (182), long fields in Obj,
 *   unsigned long count (38), declaration order of the arrays (38), base before count (44), const table
 *   pointer, long/unsigned key, long i/j; pragmas opt_lifetimes off (67), opt_propagation off (184),
 *   opt_common_subs off (190), opt_dead_assignments off (184), scheduling off (33), peephole off (33).
 *   No callees.
 * note 2026-10-05 (final push G7L3): 33 to 26 of 208 bytes differ. Lever: initialised declarations
 *   in the order count, table, base (long count=p->count; const u16 *table=d_021E1FDC; base=p+0x1a0):
 *   count now takes lr and the key ip as in the original. Residue: the original loads the table pool
 *   word into r4 before the movs #10 of count*10; ours loads it into r1 after (also moves the first
 *   loop's i/r3 and the inner loop's value register). Tried after that, no gain: table declared first (26),
 *   raw unsigned table (26), direct extern use (26), index local first (26), scheduling off (26),
 *   peephole off (26), opt_lifetimes off (66), opt_common_subs off (194), opt_propagation off (188),
 *   inline helper (182), named row (181-182), pointer-typed row arithmetic (181), operand orders of the
 *   sum (47-53), angle before count (54), block-scoped key/value (70), base declared first (58).
 *   scheduling off leaves the same bytes: the table load is placed by IR order, not the scheduler.
 * symbols:
 *   d_021E1FDC 0x021E1FDC data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const u16 d_021E1FDC[];
typedef struct {u8 pad[0x2c]; int index,count;} Obj;
void *func_021E0A44(Obj *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta;
    long count=p->count;
    const u16 *table=d_021E1FDC;
    const u8 *base=(const u8 *)p+0x1a0;
    angle=*(const u16 *)((unsigned)table+count*10+p->index*2)<<12;
    i=0;
    do {indices[i]=i;distance[i]=65535;i++;} while(i<count);
    for(i=0;i<count;i++) {
        value=*(int *)(base+i*0xb4+0x15c);
        delta=angle-value;
        if(delta<0)delta=angle+0x168000-value;
        distance[i]=delta/4096;
    }
    for(i=1;i<count;i++) {
        key=indices[i];value=distance[key];
        j=i-1;
        while(j>=0 && distance[indices[j]]>value) {indices[j+1]=indices[j];j--;}
        indices[j+1]=key;
    }
    return (void *)(base+0x140+indices[0]*0xb4);
}
