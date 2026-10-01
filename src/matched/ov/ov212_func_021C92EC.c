/*
 * function: func_021C92EC
 * address: 0x021C92EC
 * packet: pkt_ov212_021C92EC
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA8C 0x0200CA8C thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_0200CA78 0x0200CA78 thumb
 */
typedef unsigned short u16;
extern unsigned func_0200CA8C(void *),func_0200D064(void *,u16);
extern void func_0200CA78(void *,u16);
void func_021C92EC(void *p,u16 *ids,unsigned count)
{
    unsigned current;
    u16 chosen,i;
    chosen=0xFFFF;current=func_0200CA8C(p);
    for(i=0;i<count;i++) {
        if(func_0200D064(p,ids[i])==1) {
            if(current==ids[i]) return;
            if(chosen==0xFFFF) chosen=ids[i];
        }
    }
    if(chosen!=0xFFFF) func_0200CA78(p,chosen);
}
