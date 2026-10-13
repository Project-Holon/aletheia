/*
 * function: ISS_DUNGEON_SYS_CreateTable
 * address:  0x0202B2FC
 * packet:   pkt_0202B2FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_DUNGEON_SYS_Create.c is now a manifest entry (matched class)
 *
 * Builds a table node: a count byte is fetched from func_02049030, then that
 * many 0x1c-byte records are allocated and each one formatted in place.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_DUNGEON_SYS_CreateTable.c \
 *       --func ISS_DUNGEON_SYS_CreateTable --addr 0x0202B2FC --thumb --cc 1.1p1
 */
#include "../include/Obj05726.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02049030(u32 a);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);

u8 *ISS_DUNGEON_SYS_CreateTable(u32 heapId)
{
    u32 i;
    u8 *p = (u8 *)func_02030734(heapId, 8, 0, (const void *)0x020A7718, 0x77);

    p[0] = (u8)func_02049030(0x92);
    ((struct Obj05726 *)p)->f4 = (u32)func_02030734(heapId, 0x1c * p[0], 0,
                                         (const void *)0x020A7718, 0x79);

    for (i = 0; (int)i < (int)p[0]; i++) {
        func_02048F74((u8 *)(((struct Obj05726 *)p)->f4 + i * 0x1c), 0x92, i, 0, (u32 *)0x1c);
    }
    return p;
}
