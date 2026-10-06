/*
 * function: func_021B9654
 * address: 0x021B9654
 * packet: pkt_ov110_021B9654
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02024148, unresolved Thumb code witness; Ilias owns.
 *   Verified EXACT in scratch b24148-r1.log:
 *   void *func_02024148(char *p){return *(void **)(p+8);}
 * symbols:
 *   func_02024148 0x02024148 thumb
 *   func_0200D064 0x0200D064 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern void *func_02024148(char *p);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
u32 func_021B9654(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    void *save;
    u32 n;
    u32 i;
    save=func_02024148(*(void **)p);
    n=0;
    for(i=0;i<count;i++){
        if(func_0200D064(save,ids[i])){
            u32 id=ids[i];
            p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
            *out++=id;
            n++;
        }
    }
    return n;
}
