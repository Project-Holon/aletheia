/*
 * function: EVENT_FIELD_PROCLINK_AnimEventMain
 * address:  0x02161724
 * packet:   pkt_ov010_02161724
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three-step sequence over the field map's objects: step 0 starts the
 * animations that are not yet running and records them in w->busy, step
 * 1 waits until every recorded one has finished, step 2 answers done.
 *
 * The image keeps a second object that is always NULL (`movs r6, #0;
 * beq` reuses the movs flags, and the NULL is still passed to
 * FLDMMDL_CheckMoveBitMove in step 1): written as a pointer local set to 0 and
 * tested. w->field is read into a local before the switch.
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_SysSearchMoveCode  0x0216DE54  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct AnimWork {
    u32 f00;
    void *field;        /* 0x04 */
    u32 f08;
    u8 busy;            /* 0x0C */
} AnimWork;

extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *FLDMMDL_SysSearchPlayer(void *map);
extern void *FLDMMDL_SysSearchMoveCode(void *map, u32 kind);
extern void FLDMMDL_SysPauseMove(void *map);
extern int FLDMMDL_CheckEndAcmd(void *obj);
extern char *FLDMMDL_OffMoveBitMovePause(void *a0);
extern int FLDMMDL_CheckMoveBitMove(void *obj);
extern void FLDMMDL_OnMoveBitMovePause(void *obj);

int EVENT_FIELD_PROCLINK_AnimEventMain(void *task, u32 *seq, AnimWork *w)
{
    void *map;
    void *a;
    void *b;
    void *c;
    void *field;

    field = w->field;
    switch (*seq) {
    case 0:
        map = FIELDMAP_GetMmdlSys(field);
        a = FLDMMDL_SysSearchPlayer(map);
        FLDMMDL_SysSearchMoveCode(map, 0x30);
        w->busy = 0;
        FLDMMDL_SysPauseMove(map);
        if (FLDMMDL_CheckEndAcmd(a) == 0) {
            w->busy |= 1;
            FLDMMDL_OffMoveBitMovePause(a);
        }
        b = 0;
        if (b != 0 && FLDMMDL_CheckMoveBitMove(b) == 1) {
            w->busy |= 4;
            FLDMMDL_OffMoveBitMovePause(b);
        }
        (*seq)++;
        break;
    case 1:
        map = FIELDMAP_GetMmdlSys(field);
        a = FLDMMDL_SysSearchPlayer(map);
        FLDMMDL_SysSearchMoveCode(map, 0x30);
        if ((w->busy & 1) && FLDMMDL_CheckEndAcmd(a) == 1) {
            FLDMMDL_OnMoveBitMovePause(a);
            w->busy &= ~1;
        }
        if (w->busy & 4) {
            b = 0;
            if (FLDMMDL_CheckMoveBitMove(b) == 0) {
                FLDMMDL_OnMoveBitMovePause(b);
                w->busy &= ~4;
            }
        }
        if (w->busy & 2) {
            c = FLDMMDL_SysSearchMoveCode(map, 0x30);
            if (FLDMMDL_CheckMoveBitMove(c) == 0) {
                FLDMMDL_OnMoveBitMovePause(c);
                w->busy &= ~2;
            }
        }
        if (w->busy == 0)
            (*seq)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
