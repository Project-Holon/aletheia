/*
 * function: WF2DMAP_TOUCH_DeleteEditWidgets
 * address: 0x021C9730
 * packet: pkt_ov128_021C9730
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C979E before next label 021C97A0.
 * symbols:
 *   WF2DMAP_TOUCH_ClearSlotArray 0x021CA444 thumb ov128
 *   WF2DMAP_TOUCH_AddSlot 0x021CA458 thumb ov128
 *   WF2DMAP_TOUCH_ClearTileRecord 0x021C9EFC thumb ov128
 *   WF2DMAP_TOUCH_Noop 0x021C9EF0 thumb ov128
 *   BMP_WIN_Delete 0x020452E8 arm
 *   WF2DMAP_TOUCH_DeleteTileScreens 0x021C9EB4 thumb ov128
 *   WF2DMAP_TOUCH_DeleteWidgetHandles 0x021C9E54 thumb ov128
 */
typedef unsigned char u8;
extern void WF2DMAP_TOUCH_ClearSlotArray(char *p);
extern void WF2DMAP_TOUCH_AddSlot(char *p, void *q);
extern void WF2DMAP_TOUCH_ClearTileRecord(void *,int);
extern void WF2DMAP_TOUCH_Noop(void *);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void WF2DMAP_TOUCH_DeleteTileScreens(u8 *,void *);
extern void WF2DMAP_TOUCH_DeleteWidgetHandles(u8 *);
void WF2DMAP_TOUCH_DeleteEditWidgets(u8 *p,void *unused,u8 *q)
{
    u8 *base;
    int j;
    int i;
    WF2DMAP_TOUCH_ClearSlotArray((char *)q);
    WF2DMAP_TOUCH_AddSlot((char *)q,q+12);
    base=p+20;
    for(i=0;i<3;i++) {
        for(j=0;j<8;j++) WF2DMAP_TOUCH_ClearTileRecord(base+i*76,j);
        WF2DMAP_TOUCH_Noop(base+i*76);
    }
    for(i=0;i<2;i++) BMP_WIN_Delete(*(void **)(p+i*8+0x118));
    WF2DMAP_TOUCH_DeleteTileScreens(p,q);
    p+=0xf8;
    WF2DMAP_TOUCH_DeleteWidgetHandles(p);
}
