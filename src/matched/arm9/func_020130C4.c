/*
 * function: BTL_SETUP_Clear
 * address:  0x020130C4
 * packet:   pkt_020130C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_Clear.c \
 *       --func BTL_SETUP_Clear --addr 0x020130C4 --cc 1.1p1 --thumb
 *
 * symbols:
 *   BTL_SETUP_InitFieldSituation  0x02013220  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void MI_CpuFill8(void *dst, int c, u32 n);
extern void BTL_SETUP_InitFieldSituation(char *p);

void BTL_SETUP_Clear(u8 *p)
{
    MI_CpuFill8(p, 0, 0xf0);
    BTL_SETUP_InitFieldSituation((char *)(p + 8));
}
