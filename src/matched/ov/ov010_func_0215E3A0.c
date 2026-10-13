/*
 * function: MOVE_POKEMON_MoveActiveEntriesChecked
 * address:  0x0215E3A0
 * packet:   pkt_ov010_0215E3A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D488  0x0200D488  thumb
 *   MOVE_POKEMON_MoveEntry  0x0215E358  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Big;
struct Blk38;
struct GdsEnt;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200D418(void *p);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void MOVE_POKEMON_MoveEntry(int a, int b, int c);

void MOVE_POKEMON_MoveActiveEntriesChecked(void *a)
{
    u8 i;
    void *q;
    void *p;

    p = func_0200D418(GAME_DATA_GetSaveControl(a));
    q = (void *)GAME_DATA_GetSeason(a);
    for (i = 0; i < 2; i++) {
        func_0200D4AC(p, i);
        if (func_0200D488(p, i) != 0) {
            MOVE_POKEMON_MoveEntry((int)p, (int)q, i);
        }
    }
}
