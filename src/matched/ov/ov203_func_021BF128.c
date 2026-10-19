/*
 * function: DEMO3D_DATA_TaskBrightnessSeq
 * address: 0x021BF128
 * packet: pkt_ov203_021BF128
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_ScaleTime 0x021BF7AC thumb ov203
 *   DEMO3D_DATA_CreateBrightnessSeq 0x021BF168 thumb ov203
 */
extern int DEMO3D_DATA_ScaleTime(char *,int);
extern void DEMO3D_DATA_CreateBrightnessSeq(char *,unsigned char,signed char,signed char,signed char,int,int);
void DEMO3D_DATA_TaskBrightnessSeq(char *p,int unused,int *s)
{
    int a,b;
    a=DEMO3D_DATA_ScaleTime(p,s[4]);b=DEMO3D_DATA_ScaleTime(p,s[5]);
    DEMO3D_DATA_CreateBrightnessSeq(p,s[0],s[1],s[2],s[3],a,b);
}
