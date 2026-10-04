/*
 * function: func_021B97AC
 * address: 0x021B97AC
 * packet: pkt_ov110_021B97AC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02024160, unresolved Thumb code witness; Ilias owns.
 *   Verified EXACT in scratch b24160-r1.log:
 *   typedef struct {unsigned char pad[3];unsigned char rest:3;unsigned char flag:1;unsigned char last:4;} Bits;
 *   int func_02024160(Bits *p){return p->flag;}
 * symbols:
 *   func_02024160 0x02024160 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02024160(void *);
u32 func_021B97AC(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    u32 i;
    u32 n;
    if(!func_02024160(*(void **)p))return 0;
    i=0;
    n=0;
    for(;i<count;i++){
        u32 id=ids[i];
        p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
        *out++=i+0x801;
        n++;
    }
    return n;
}
