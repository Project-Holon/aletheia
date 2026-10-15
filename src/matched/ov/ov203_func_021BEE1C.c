/*
 * function: DEMO3D_DATA_TaskFadeOutBgm
 * address: 0x021BEE1C
 * packet: pkt_ov203_021BEE1C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_IsCaptureDone 0x021BF7AC thumb ov203
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern int DEMO3D_DATA_IsCaptureDone(char *,int);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_FadeOutBgm(u32 a);
void DEMO3D_DATA_TaskFadeOutBgm(char *p,int unused,int *s) { int x;x=DEMO3D_DATA_IsCaptureDone(p,s[1]);if(s[0]==0)GFL_USE_FadeInBgmFull((u16)x);else GFL_USE_FadeOutBgm((u16)x); }
