/*
 * function: COMM_PLAYER_SUPPORT_Create
 * address:  0x0202E770
 * packet:   pkt_0202E560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   COMM_PLAYER_SUPPORT_Init  0x0202E79C  thumb
 *   g_020A77EC     0x020A77EC  data
 */
typedef unsigned int u32;

extern void *func_02030734(u32 heap, u32 size, int flags, const char *file, unsigned short line);
typedef unsigned char  u8;
extern void COMM_PLAYER_SUPPORT_Init(u8 *p);
extern const char g_020A77EC[];

void *COMM_PLAYER_SUPPORT_Create(void *heap)
{
    void *p = func_02030734((u32)heap, 0x4c, 1, g_020A77EC, 0x2c);

    COMM_PLAYER_SUPPORT_Init(p);
    return p;
}
