/*
 * function: DEMO3D_DATA_TaskFadeBrightness
 * address: 0x021BEF84
 * packet: pkt_ov203_021BEF84
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 021BEFC2.
 * symbols:
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   DEMO3D_DATA_ScaleTime 0x021BF7AC thumb ov203
 *   DEMO3D_DATA_CreateBrightnessFade 0x021BEFC4 thumb ov203
 */
typedef unsigned int   u32;
struct Owner;
extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);
extern int DEMO3D_DATA_ScaleTime(char *,int);
extern void DEMO3D_DATA_CreateBrightnessFade(struct Owner *owner, int mask, int kind, int start, int end, int duration, int *counter);
void DEMO3D_DATA_TaskFadeBrightness(char *p,int unused,int *s)
{
    if(s[1]==0){BRIGHTNESS_Set((short)s[2],0x3f,s[0]);}
    else {DEMO3D_DATA_CreateBrightnessFade((struct Owner *)p,s[0],0x3f,s[2],s[3],DEMO3D_DATA_ScaleTime(p,s[1]),0);}
}
