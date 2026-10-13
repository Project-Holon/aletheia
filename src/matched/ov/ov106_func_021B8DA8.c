/*
 * function: IRC_RANKING_InputUpdate
 * address: 0x021B8DA8
 * packet: pkt_ov106_021B8DA8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return, before 0x021B8E50.
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 */

typedef unsigned int u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
void IRC_RANKING_InputUpdate(int *p) {
    int x,y;
    int d;
    if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        p[0]=x;p[1]=y;p[2]=x;p[3]=y;p[4]=x;p[5]=y;
        p[6]=0;p[7]=0;p[8]=0;
    } else if(TOUCHPANEL_GetPointCont((u32 *)(&x),(u32 *)(&y))) {
        d=y-p[1];
        if(d<0)d=-d;
        if(d>=1) {
            p[6]=x-p[4];p[7]=y-p[5];p[4]=x;p[5]=y;
        }
        p[2]=x;p[3]=y;p[8]++;p[9]=0;
    } else p[9]++;
    if(KEY_GetTrg()&192) {p[10]=0;return;}
    if(KEY_GetCont()&192)p[10]++;
}
