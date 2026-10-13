/*
 * function: OS_GetInitArenaHi
 * address:  0x02086594
 * packet:   pkt_02086594
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_02085CBC 0x02085CBC arm
 *   g_02151264 0x02151264 data
 *   SDK_SYS_STACKSIZE             0x00001800  data
 *   SDK_IRQ_STACKSIZE             0x00000800  data
 *   SDK_AUTOLOAD_DTCM_START       0x02FE0000  data
 *   SDK_SECTION_ARENA_DTCM_START  0x02FE00C0  data
 */

typedef unsigned int u32;
typedef long s32;

typedef struct OsArenaBss {
    u32 isInitialized;
    u32 exArenaEnabled;
} OsArenaBss;

extern int OS_IsRunOnTwl(void);
extern u32 func_02085CBC(void);
extern OsArenaBss g_02151264;
extern char SDK_AUTOLOAD_DTCM_START[];
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
extern char SDK_SECTION_ARENA_DTCM_START[];

void *OS_GetInitArenaHi(int id)
{
    switch (id) {
    case 0:
        return OS_IsRunOnTwl() ? (void *)0x02F80000 : (void *)0x023E0000;
    case 2:
        {
            void *arena;
            u32 type;

            if (g_02151264.exArenaEnabled == 0) {
                return 0;
            }
            type = func_02085CBC() & 0xF;
            if (OS_IsRunOnTwl()) {
                arena = 0;
                if (type != 4) {
                    arena = (void *)0x0DF00000;
                }
            } else {
                arena = 0;
                if (type != 1) {
                    arena = (void *)0x02700000;
                }
            }
            return arena;
        }
    case 3:
        return (void *)0x02000000;
    case 4:
        {
            u32 start = (u32)SDK_AUTOLOAD_DTCM_START;
            u32 end = start + 0x3F80;
            u32 top = end - (u32)SDK_IRQ_STACKSIZE;
            s32 sysStack = (s32)SDK_SYS_STACKSIZE;

            if (sysStack == 0) {
                u32 arena = start;

                if (arena < (u32)SDK_SECTION_ARENA_DTCM_START) {
                    arena = (u32)SDK_SECTION_ARENA_DTCM_START;
                }
                return (void *)arena;
            }
            if (sysStack < 0) {
                return (void *)((u32)SDK_SECTION_ARENA_DTCM_START - sysStack);
            }
            return (void *)(top - sysStack);
        }
    case 5:
        return (void *)0x02FFF680;
    case 6:
        return (void *)0x03040000;
    default:
        return 0;
    }
}
