/*
 * function: POKETRADE_SAVE_DeletePartnerOfferCard
 * address: 0x021E293C
 * packet: pkt_ov119_021E293C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   POKETRADE_SAVE_DeleteStatusIconActor 0x021E0E4C thumb ov119
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
void POKETRADE_SAVE_DeletePartnerOfferCard(char *p,int i)
{
    if (*(int *)(p+0x5c4+4*i)) {
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5c4+4*i)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5cc+4*i)));
        POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4+20*(i+1));
        *(int *)(p+0x5c4+4*i)=0;
        *(int *)(p+0x5cc+4*i)=0;
    }
}
