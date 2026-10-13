/*
 * function: OS_GetInitArenaLo
 * address:  0x02086694
 * packet:   pkt_02086694
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
 *   SDK_LTDMAIN_ARENA_LO          0x02735B40  data
 *   SDK_MAIN_ARENA_LO             0x02213D20  data
 *   SDK_LTDMAIN_EX_ARENA_LO       0x0D000000  data
 *   SDK_SECTION_ARENA_EX_START    0x02400060  data
 *   SDK_SECTION_ARENA_ITCM_START  0x01FF8820  data
 *   SDK_SECTION_ARENA_DTCM_START  0x02FE00C0  data
 */

typedef unsigned int u32;

typedef struct OsArenaBss {
    u32 isInitialized;
    u32 exArenaEnabled;
} OsArenaBss;

extern int OS_IsRunOnTwl(void);
extern u32 func_02085CBC(void);
extern OsArenaBss g_02151264;
extern char SDK_LTDMAIN_ARENA_LO[];
extern char SDK_MAIN_ARENA_LO[];
extern char SDK_LTDMAIN_EX_ARENA_LO[];
extern char SDK_SECTION_ARENA_EX_START[];
extern char SDK_SECTION_ARENA_ITCM_START[];
extern char SDK_SECTION_ARENA_DTCM_START[];

void *OS_GetInitArenaLo(int id)
{
    switch (id) {
    case 0:
        return OS_IsRunOnTwl() ? (void *)SDK_LTDMAIN_ARENA_LO : (void *)SDK_MAIN_ARENA_LO;
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
                    arena = (void *)SDK_LTDMAIN_EX_ARENA_LO;
                }
            } else {
                arena = 0;
                if (type != 1) {
                    arena = (void *)SDK_SECTION_ARENA_EX_START;
                }
            }
            return arena;
        }
    case 3:
        return (void *)SDK_SECTION_ARENA_ITCM_START;
    case 4:
        return (void *)SDK_SECTION_ARENA_DTCM_START;
    case 5:
        return (void *)0x02FFF000;
    case 6:
        return (void *)0x03040000;
    default:
        return 0;
    }
}
