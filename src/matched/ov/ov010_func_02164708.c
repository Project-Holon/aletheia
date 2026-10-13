/*
 * function: EVENTDATA_SYSTEM_GetHiddenItemFlag
 * address:  0x02164708
 * packet:   pkt_ov010_02164708
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag id of an entry: the first halfword of its 10-byte record in
 * HiddenItemTable, offset by 900.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetHiddenItemIndex  0x021646E8  thumb  ov010
 *   HiddenItemTable     0x02171534  data
 */

typedef unsigned short u16;

typedef struct Rec10 {
    u16 flag;
    u16 rest[4];
} Rec10;

typedef unsigned int   u32;
extern u16 EVENTDATA_SYSTEM_GetHiddenItemIndex(u32 n);
extern const Rec10 HiddenItemTable[];

u16 EVENTDATA_SYSTEM_GetHiddenItemFlag(u16 id)
{
    return HiddenItemTable[EVENTDATA_SYSTEM_GetHiddenItemIndex(id)].flag + 900;
}
