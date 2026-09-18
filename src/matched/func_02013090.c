/*
 * function: func_02013090
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
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013090.c \
 *       --func func_02013090 --addr 0x02013090 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file,
                           u32 line);
extern void  func_020130C4(void *p);
extern u8    sZonedataFile;

void *func_02013090(u32 heap)
{
    void *p;

    p = func_02030734(heap, 0xf0, 0, (const char *)&sZonedataFile, 0x31);
    func_020130C4(p);
    return p;
}
