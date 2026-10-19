/*
 * function: GSYNC_DISP_CopyIconPaletteSub
 * address: 0x021D6C90
 * packet: pkt_ov123_021D6C90
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   DC_FlushRange 0x020862F0 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 */
typedef unsigned int u32;
typedef struct { u32 x[9]; } Desc;
struct Struct36;
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void MI_CpuCopy8(void *,void *,int);
extern void DC_FlushRange(void *,int);
extern void GX_LoadOBJPltt(void *,int,int);
void GSYNC_DISP_CopyIconPaletteSub(char *p,int i,void *h)
{
    Desc d;
    CLACT_GetActorImageProxy(h,(struct Struct36 *)(&d));
    MI_CpuCopy8(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    DC_FlushRange(p+0xbc+i*0x224,0x20);
    GX_LoadOBJPltt(p+0xbc+i*0x224,0x100,0x20);
}
