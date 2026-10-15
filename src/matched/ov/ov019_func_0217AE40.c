/*
 * function: UNION_CHARA_AddMmdl
 * address:  0x0217AE40
 * packet:   pkt_ov019_0217AE40
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * What closed it: the spilled third parameter is u16, not u32. As u32 the
 * scheduler hoists its reload (`ldr r0,[sp]`) above the `strh` of d into
 * the local; as u16 the reload stays after it (see
 * docs/notes/pkt_ov019_0217AE40.c.txt for the earlier near miss).
 *
 * symbols:
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   CURSOR_MOVE_GetTableValue  0x02025C74  thumb
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   gUnionCharaMmdlHeader     0x0217FFF8  data  ov019  a4
 *   gUnionCharaSeatPos     0x0218001C  data  ov019  a2
 *   gUnionCharaMemberOffset     0x0217FFE4  data  ov019  a2
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef union { u32 w[9]; u16 h[18]; } Tmpl;
typedef struct { s16 x, y; } Pt;

struct BigObj;
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern u32 CURSOR_MOVE_GetTableValue(u32 x);
extern void FLDMMDL_InitPosRecord(void *, u32, u32, int);
extern int FLDMMDL_AddMmdl(int, void *, int);
extern const Tmpl gUnionCharaMmdlHeader;
extern const Pt gUnionCharaSeatPos[];
extern const Pt gUnionCharaMemberOffset[];

int UNION_CHARA_AddMmdl(void *a, int b, u16 c, int d)
{
    int t;
    u16 hi, lo;
    Tmpl l;

    t = GAME_DATA_GetOccupyInfo((const struct BigObj *)b);
    hi = (u16)(d >> 8);
    lo = (u16)((d & 0xff) - 0x20);
    l = gUnionCharaMmdlHeader;
    l.h[0] = d;
    l.h[1] = CURSOR_MOVE_GetTableValue(c);
    if (lo != 0)
        l.h[2] = 15;
    FLDMMDL_InitPosRecord(&l, (u16)(gUnionCharaSeatPos[hi].x + gUnionCharaMemberOffset[lo].x),
                  (u16)(gUnionCharaSeatPos[hi].y + gUnionCharaMemberOffset[lo].y), 0);
    return FLDMMDL_AddMmdl(t, &l, 422);
}

