/*
 * function: func_021C9288
 * address: 0x021C9288
 * packet: pkt_ov212_021C9288
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: branch-local calls retain the original boolean polarity and hoist
 * the shared output-address setup; initializing selected follows the call.
 * symbols:
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_021C976C 0x021C976C thumb ov212
 */
typedef unsigned short u16;
struct Blk37;
extern unsigned func_0200CA70(struct Blk37 *);
extern unsigned func_0200CED4(struct Blk37 *,u16);
extern unsigned func_0200D064(struct Blk37 *,u16);
typedef unsigned int   u32;
extern u32 func_021C976C(u32 mode, int heap, u16 **out);
u16 func_021C9288(struct Blk37 *save,u16 **out,unsigned heap)
{
    u16 *list;
    unsigned count,i;
    u16 selected;
    if(func_0200CA70(save)==1)count=func_021C976C(0,heap,&list);
    else count=func_021C976C(1,heap,&list);
    selected=0;
    for(i=0;i<count;i++){
        if(func_0200CED4(save,list[i])==1||func_0200D064(save,list[i])==1)selected=i+1;
    }
    *out=list;
    return selected;
}
