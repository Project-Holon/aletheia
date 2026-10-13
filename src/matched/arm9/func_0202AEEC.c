/*
 * function: ISS_CITY_UNIT_Create
 * address:  0x0202AEEC
 * packet:   pkt_0202AEEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x28-byte node with func_02030734, wraps it with func_02048F88,
 * runs ISS_CITY_UNIT_Copy over the pair and releases the wrapper.  The pair is
 * passed as (wrapper, node): r0 is left holding the wrapper from the second
 * allocation when ISS_CITY_UNIT_Copy is reached, with the node moved into r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_Create.c \
 *       --func ISS_CITY_UNIT_Create --addr 0x0202AEEC --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_CITY_UNIT_Copy  0x0202AF3C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
struct MyStruct;
extern void ISS_CITY_UNIT_Copy(const struct MyStruct *src, struct MyStruct *dst);
extern u32 func_020307B0(void *p);

u8 *ISS_CITY_UNIT_Create(u32 a, u32 b)
{
    u8 *node = (u8 *)func_02030734(a, 0x28, 0, (const void *)0x020A76F8, 0x6c);
    u8 *wrap = (u8 *)func_02048F88(0x84, b, a, 0, (u32 *)0x28);

    ISS_CITY_UNIT_Copy((const struct MyStruct *)wrap, (struct MyStruct *)node);
    func_020307B0(wrap);
    return node;
}
