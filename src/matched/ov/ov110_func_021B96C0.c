/*
 * function: func_021B96C0
 * address: 0x021B96C0
 * packet: pkt_ov110_021B96C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02024150, unresolved Thumb code witness; Ilias owns.
 *   Verified EXACT in scratch b24150-r2.log:
 *   typedef struct {unsigned char pad[3];unsigned char flag:1;unsigned char rest:7;} Bits;
 *   int func_02024150(Bits *p){return p->flag;}
 * symbols:
 *   func_02024150 0x02024150 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02024150(void *);
u32 func_021B96C0(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    u32 i;
    if(func_02024150(*(void **)p)){
        for(i=0;i<count;i++){
            u32 id= *ids;
            p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
            ids++;
            *out++=id;
        }
        return count;
    }
    return 0;
}
