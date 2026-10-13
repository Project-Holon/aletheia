/*
 * function: BTL_HANDLER_ITEM_GetTwistedSpoonHandlers
 * address: 0x021DF864
 * packet: pkt_ov093_021DF864
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF840.c and filed here.
 *
 * symbols:
 *   gTwistedSpoonHandlers 0x021F1484 data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetTwistedSpoonHandlers(int *p);
extern int gTwistedSpoonHandlers[];

/*
 * omits G3D_CAMERA_SetRoll from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void G3D_CAMERA_SetRoll(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
int *BTL_HANDLER_ITEM_GetTwistedSpoonHandlers(int *p)
{
    *p = 1;
    return gTwistedSpoonHandlers;
}
