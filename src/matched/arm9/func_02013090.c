/*
 * function: BTL_SETUP_Create
 * address:  0x02013090
 * packet:   pkt_02013090
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sZonedataFile  0x020A729C  data
 *   BTL_SETUP_Clear  0x020130C4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_Create.c \
 *       --func BTL_SETUP_Create --addr 0x02013090 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BTL_SETUP_Clear(u8 *p);
extern u8    sZonedataFile;

void *BTL_SETUP_Create(u32 heap)
{
    void *p;

    p = func_02030734(heap, 0xf0, 0, (const char *)&sZonedataFile, 0x31);
    BTL_SETUP_Clear(p);
    return p;
}
