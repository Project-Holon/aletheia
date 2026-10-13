/*
 * function: EVENT_FIELD_PROCLINK_IsHopDone
 * address:  0x02161B1C
 * packet:   pkt_ov010_02161B1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   d_02171404     0x02171404  data  a1
 *   d_021713FC     0x021713FC  data  a1
 *   d_021713F4     0x021713F4  data  a1
 *   d_021713EC     0x021713EC  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char d_02171404[];
extern const char d_021713FC[];
extern const char d_021713F4[];
extern const char d_021713EC[];

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_FreeAcmd(char *p);
extern int FLDMMDL_ACMD_ListCreate(void *a, const char *b);

int EVENT_FIELD_PROCLINK_IsHopDone(void *a)
{
    const char *s;
    void *p;

    p = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(a));
    switch (FLDMMDL_GetDirDisp(p)) {
    case 0:
        s = d_02171404;
        break;
    case 1:
        s = d_021713FC;
        break;
    case 2:
        s = d_021713F4;
        break;
    case 3:
        s = d_021713EC;
        break;
    }
    FLDMMDL_FreeAcmd(p);
    return FLDMMDL_ACMD_ListCreate(p, s);
}
