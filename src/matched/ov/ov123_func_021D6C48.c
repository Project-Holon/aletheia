/*
 * function: func_021D6C48
 * address: 0x021D6C48
 * packet: pkt_ov123_021D6C48
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_02082D44 0x02082D44 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 x[9]; } Desc;
struct Obj;
struct Struct36;
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void func_02082D44(void *,void *,int);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void func_021D6C48(char *p,int i,void *h)
{
    Desc d;
    CLACT_GetActorImageProxy(h,(struct Struct36 *)(&d));
    func_02082D44(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    CLACT_SetActorPaletteOffset(h,(u8)(*(u32 *)(p+i*0x224+0x2dc)),1);
}
