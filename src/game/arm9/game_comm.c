/*
 * file:     game_comm.c
 * function: GAME_COMM_CallHandler
 * address:  0x02026388
 * packet:   pkt_0202627C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Parked: every concrete byte is right; the only unresolved site is the
 * data table base 0x0209FB70, whose word has no witness outside this range
 * (`literal` has nothing to stand on, and no branch anywhere names it).
 * Blocker: 0x0209FB70 (data).
 *
 * symbols:
 *   gGameCommHandlers  0x0209FB70  data
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct GameCommEntry {
    u8  pad0[4];
    u8  reserved4;
    u8  kind;
    u8  pad6[0xA];
    u8  mode;
    u8  pad11[3];
    u32 param0;
    u32 param1;
} GameCommEntry;

typedef void (*GameCommHandler)(u32 param0, u32 param1, u32 arg);

extern u8 gGameCommHandlers[];

void GAME_COMM_CallHandler(GameCommEntry *entry, u32 arg)
{
    if (entry->mode != 5) {
        GameCommHandler handler = *(GameCommHandler *)(gGameCommHandlers + entry->kind * 0x1C);

        if (handler != 0) {
            handler(entry->param0, entry->param1, arg);
        }
    }
}
