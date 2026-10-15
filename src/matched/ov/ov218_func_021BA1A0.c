/*
 * function: UN_SELECT_IsFadeDone
 * address: 0x021BA1A0
 * packet: pkt_ov218_021BA1A0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 2 zero alignment bytes at 021BA1BE.
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
extern int FADE_IsActive(void);extern int BRIGHTNESS_IsFinished(int);
int UN_SELECT_IsFadeDone(void){if(FADE_IsActive()==1 || BRIGHTNESS_IsFinished(1)==0)return 0;return 1;}
