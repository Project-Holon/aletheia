/*
 * function: IRC_RHYTHM_ScreenVBlankTask
 * address: 0x021B7980
 * packet: pkt_ov104_021B7980
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow compiled code.
 * symbols:
 *   IRC_RHYTHM_VBlankBackgrounds 0x021B7B24 thumb ov104
 *   IRC_RHYTHM_VBlankActorSystem 0x021B7D14 thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_RHYTHM_VBlankBackgrounds(void *);
extern void IRC_RHYTHM_VBlankActorSystem(void *);
void IRC_RHYTHM_ScreenVBlankTask(u32 unused,u8 *p) { IRC_RHYTHM_VBlankBackgrounds(p); IRC_RHYTHM_VBlankActorSystem(p+4); }
