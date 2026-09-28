/*
 * function: func_02087B20
 * address:  0x02087B20
 * packet:   pkt_02087B20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_IsCodecTwlMode (os_systemwork.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   g_02151360     0x02151360  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

/* os_systemwork.o .bss from 0x02151360, addressed from one pool word: the
   function's statics retval and initialized. */
typedef struct OsSystemWorkBss {
    BOOL retval;
    BOOL initialized;
} OsSystemWorkBss;

extern OsSystemWorkBss g_02151360;
extern BOOL OS_IsRunOnTwl(void);

BOOL func_02087B20(void)
{
    if (!g_02151360.initialized) {
        g_02151360.retval = (OS_IsRunOnTwl() == 1 && (*(u8 *)0x02FFE1BF & 1) == 1) ? 1 : 0;
    }
    g_02151360.initialized = 1;
    return g_02151360.retval;
}
