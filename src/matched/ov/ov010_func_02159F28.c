/*
 * function: MAP_REPLACE_SetFlag
 * address: 0x02159F28
 * packet: pkt_ov010_02159F28
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x02159F52.
 * symbols:
 *   MAP_REPLACE_FindFlagEntry 0x02159F04 thumb ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ent { u8 f00; u8 f01; u16 f02; u16 f04; } Ent;
extern Ent *MAP_REPLACE_FindFlagEntry(int, int);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 func_020143CC(u32, u32);
void MAP_REPLACE_SetFlag(int a, int b, int flag)
{
    Ent *p = MAP_REPLACE_FindFlagEntry(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(GAME_DATA_GetEventWork((const struct BigObj *)a), p->f02);
        if (flag)
            *q = p->f04;
        else
            *q = 0;
    }
}
