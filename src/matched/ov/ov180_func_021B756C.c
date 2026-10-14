/*
 * function: HALL_OF_FAME_ReleaseAllResources
 * address: 0x021B756C
 * packet: pkt_ov180_021B756C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   HALL_OF_FAME_ReleaseCharacter 0x021B7510 thumb ov180
 *   HALL_OF_FAME_ReleasePalette 0x021B7530 thumb ov180
 *   HALL_OF_FAME_ReleaseCellAnim 0x021B7550 thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void HALL_OF_FAME_ReleaseCharacter(char *,int),HALL_OF_FAME_ReleasePalette(char *,int),HALL_OF_FAME_ReleaseCellAnim(char *,int);
void HALL_OF_FAME_ReleaseAllResources(char *p) { u32 i; for(i=0;i<6;i++) HALL_OF_FAME_ReleaseCharacter(p,i); for(i=0;i<7;i++) HALL_OF_FAME_ReleasePalette(p,i); for(i=0;i<6;i++) HALL_OF_FAME_ReleaseCellAnim(p,i); }
