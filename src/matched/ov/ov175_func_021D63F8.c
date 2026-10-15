/*
 * function: WIFIBATTLEMATCH_NET_StartBoxAnim
 * address: 0x021D63F8
 * packet: pkt_ov175_021D63F8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * mode: original assigns constructor selectors only for mode 0 or 1.
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreateRecordWindow 0x021E7520 thumb ov177
 */
typedef unsigned int u32;
extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *);
extern u32 WIFIBATTLEMATCH_VIEW_CreateRecordWindow(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32);
void WIFIBATTLEMATCH_NET_StartBoxAnim(u32 *p,u32 arg)
{
    u32 b,a;
    if (p[7] == 0) {
        u32 base = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)p[0]);
        u32 mode = ((u32 *)p[16])[0];
        if (mode == 0) { a=1; b=2; }
        else if (mode == 1) { a=0; b=3; }
        p[7]=WIFIBATTLEMATCH_VIEW_CreateRecordWindow(arg,base,p[1],p[2],p[3],p[4],p[5],b,a,0,87);
    }
}
