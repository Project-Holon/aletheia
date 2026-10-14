/*
 * unit: no
 * function: GURU2_MAIN_IsTouched
 * address: 0x021E04C4
 * packet: pkt_ov137_021E04C4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gGuru2TouchRects 0x021E1CB0 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern int TOUCHPANEL_HitTrg(const void *);
extern const u8 gGuru2TouchRects[];
int GURU2_MAIN_IsTouched(char *a0){if(TOUCHPANEL_HitTrg(gGuru2TouchRects)!=-1)return 1;return 0;}
