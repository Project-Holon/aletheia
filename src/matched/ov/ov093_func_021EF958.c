/*
 * function: BTL_FIELD_Create
 * address:  0x021EF958
 * packet:   pkt_ov093_021EF958
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gBtlFieldFileName  0x021F3AF8  data  a4
 *   BTL_FIELD_Init  0x021EF988  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char gBtlFieldFileName[];
extern void BTL_FIELD_Init(S *p, u32 v);

S *BTL_FIELD_Create(u32 heap)
{
    S *p = func_02030734(heap, 0x168, 1, gBtlFieldFileName, 0x10c);

    BTL_FIELD_Init(p, 0);
    return p;
}
