/*
 * function: IRC_RHYTHM_UpdateCountdown
 * address: 0x021B8104
 * packet: pkt_ov104_021B8104
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void IRC_RHYTHM_UpdateCountdown(u32 *p) { if(p[5]) { if(p[3]==0) { GFL_USE_PlaySeDefaultVolume(0x66a); CLACT_SetActorDrawEnable((void *)p[0],1); CLACT_SetActorAnimSeq((void *)p[0],4-p[4]); } if(p[3]++>=60) { p[3]=0; p[4]++; } if(p[4]==3) { GFL_USE_PlaySeDefaultVolume(0x66b); p[6]=1; p[5]=0; CLACT_SetActorDrawEnable((void *)p[0],0); } } }
