/*
 * function: ISS_DUNGEON_SYS_Create
 * address:  0x0202B3A0
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_DUNGEON_SYS_Create.c is now a manifest entry (matched class)
 *
 * Allocates a 0x38-byte node, fills its header fields, resolves the +0x14
 * sub-object through ISS_DUNGEON_SYS_CreateTable and runs ISS_DUNGEON_SYS_ResetTracks over it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_Create.c \
 *       --func ISS_DUNGEON_SYS_Create --addr 0x0202B3A0 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_DUNGEON_SYS_CreateTable  0x0202B2FC  thumb
 *   ISS_DUNGEON_SYS_ResetTracks  0x0202B454  thumb
 */
#include "../include/Obj03438.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Node;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *ISS_DUNGEON_SYS_CreateTable(u32 heapId);
extern void ISS_DUNGEON_SYS_ResetTracks(char *p);

struct Node *ISS_DUNGEON_SYS_Create(u32 a, u32 b, u32 heapId)
{
    struct Node *p = (struct Node *)func_02030734(heapId, 0x38, 0,
                                                  (const void *)0x020A7718, 0x109);

    ((struct Obj03438 *)((u8 *)p))->f0 = (u16)heapId;
    ((struct Obj03438 *)p)->f8 = a;
    ((struct Obj03438 *)p)->f4 = b;
    ((struct Obj03438 *)p)->fC = 0;
    ((struct Obj03438 *)p)->f10 = 0xffff;
    ((struct Obj03438 *)p)->f12 = 0xffff;
    ((struct Obj03438 *)p)->f14 = (u32)ISS_DUNGEON_SYS_CreateTable(heapId);
    ((struct Obj03438 *)p)->f18 = 0;
    ISS_DUNGEON_SYS_ResetTracks((char *)p);
    return p;
}
