/*
 * function: func_021563D0
 * address:  0x021563D0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls the ov013 routine when the word at +0x76c of the module pointer is set.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   func_021AF13C  0x021AF13C  thumb  ov013

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_021563D0(void)
{
    extern char *g_021A8264;
    void func_021AF13C(void);
    if (*(u32 *)(g_021A8264 + 0x76c)) func_021AF13C();
}
