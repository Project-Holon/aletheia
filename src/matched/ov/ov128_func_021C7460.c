/*
 * function: Wf2dmapFriend_ListTouchInput
 * address: 0x021C7460
 * packet: pkt_ov128_021C7460
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021CA58A 0x021CA58A data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WF2DMAP_TOUCH_SetTopHighlight1 0x021CA154 thumb ov128
 *   WF2DMAP_TOUCH_SetTopHighlight 0x021CA184 thumb ov128
 *   func_020355D8 0x020355D8 arm
 */
typedef unsigned char u8;
extern const char d_021CA58A[];
extern int TOUCHPANEL_HitTrg(const void *p);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WF2DMAP_TOUCH_SetTopHighlight1(u8 *,int);
extern void WF2DMAP_TOUCH_SetTopHighlight(u8 *,int,int);
extern void func_020355D8(u8 v);
int Wf2dmapFriend_ListTouchInput(int *p,int *q,u8 *ctx)
{
    int v;
    v=TOUCHPANEL_HitTrg(d_021CA58A);
    if(v!=-1) {
        if(v==3) {
            GFL_USE_PlaySeDefaultVolume(1361);
            WF2DMAP_TOUCH_SetTopHighlight1(ctx,*p);
        } else if(v==4) {
            GFL_USE_PlaySeDefaultVolume(1366);
            WF2DMAP_TOUCH_SetTopHighlight1(ctx,*p);
        } else {
            GFL_USE_PlaySeDefaultVolume(1356);
            WF2DMAP_TOUCH_SetTopHighlight(ctx,v,*p);
        }
        *p=v;
        func_020355D8(1);
        *q=1;
    }
    return v;
}
