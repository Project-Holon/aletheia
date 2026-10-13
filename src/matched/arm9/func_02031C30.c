/*
 * function: BACKUP_SYSTEM_MainLinkedSave
 * address:  0x02031C30
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_InitSaveSeq   0x02032970  arm
 *   BACKUP_SYSTEM_SaveSeqMain  0x02032CD0  arm
 *   BACKUP_SYSTEM_EndSave  0x020331A4  arm
 *
 * Drive a two-copy save through BACKUP_SYSTEM_SaveSeqMain (the write state machine),
 * one step per call, on the state byte at q+0x1E: open a generation on `p`
 * (BACKUP_SYSTEM_InitSaveSeq), write `p`, copy its generation word to *q->f20 and open one
 * on `q`, write `q` (on failure also report it against `p` when p's two
 * area words differ), finish `p` if its two area words differ, then finish
 * `q`, answering 3 when p's result byte says so.  Both objects are the same
 * save-record type (both go to BACKUP_SYSTEM_SaveSeqMain and BACKUP_SYSTEM_EndSave).
 * Wave 11, 2026-09-23.
 *
 * The one lever the 2026-09-21 lanes named and did not reach: case 4 is
 * written with the UNEQUAL test first and the bare `q->f1e++` in the `else`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That moves the
 * `state = s + 1` block out of line (0x02031D78) and lets case 1's
 * `state++; break;` share case 4's `b 0x02031C70`.  All four BACKUP_SYSTEM_SaveSeqMain
 * result tests are negated (`r != 0 && r != 1`), per the note.
 */
typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj {
    u32  f00;
    u32  f04;
    u8   pad08[0x16];
    u8   f1e;
    u8   f1f;
    u32 *f20;
    u8   pad24[4];
    u32  f28;
};

struct SaveBackup;
extern void BACKUP_SYSTEM_InitSaveSeq(struct SaveBackup *p, u32 flag);
extern int  BACKUP_SYSTEM_SaveSeqMain(struct Obj *p, u32 *out);
extern void BACKUP_SYSTEM_EndSave(struct SaveBackup *p, u32 result, u32 flag);

int BACKUP_SYSTEM_MainLinkedSave(struct Obj *q, struct Obj *p)
{
    u32 tmp;
    int r;

    switch (q->f1e) {
    case 0:
        BACKUP_SYSTEM_InitSaveSeq((struct SaveBackup *)p, 1);
        q->f1e++;
        break;
    case 1:
        r = BACKUP_SYSTEM_SaveSeqMain(p, &tmp);
        if (r != 0 && r != 1) {
            BACKUP_SYSTEM_EndSave((struct SaveBackup *)p, r, 1);
            if (r == 3)
                return 3;
            q->f1e++;
            break;
        }
        if (tmp == 1)
            q->f1e++;
        break;
    case 2:
        *q->f20 = p->f28;
        BACKUP_SYSTEM_InitSaveSeq((struct SaveBackup *)q, 0);
        q->f1e++;
        break;
    case 3:
        r = BACKUP_SYSTEM_SaveSeqMain(q, &tmp);
        if (r != 0 && r != 1) {
            BACKUP_SYSTEM_EndSave((struct SaveBackup *)q, r, 1);
            if (p->f00 != p->f04)
                BACKUP_SYSTEM_EndSave((struct SaveBackup *)p, r, 1);
            return 3;
        }
        if (tmp == 1)
            q->f1e++;
        break;
    case 4:
        if (p->f00 != p->f04) {
            r = BACKUP_SYSTEM_SaveSeqMain(p, &tmp);
            if (r != 0 && r != 1) {
                BACKUP_SYSTEM_EndSave((struct SaveBackup *)p, r, 0);
                p->f1f = r;
                q->f1e++;
            }
        } else {
            q->f1e++;
        }
        break;
    case 5:
        r = BACKUP_SYSTEM_SaveSeqMain(q, &tmp);
        if (r != 0 && r != 1) {
            BACKUP_SYSTEM_EndSave((struct SaveBackup *)q, r, 1);
            if (p->f1f == 3)
                r = 3;
            return r;
        }
        break;
    }
    return 0;
}
