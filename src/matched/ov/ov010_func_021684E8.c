/*
 * function: func_021684E8
 * address:  0x021684E8
 * packet:   pkt_ov010_021684E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Build a battle-facility Pokemon from its a/2/1/4 record (the reader is
 * func_02168800). Levers: the pid store in both arms of an if/else, the
 * ability as a nested if storing in all three arms, and (2026-09-28
 * tree_ov010_4) the EV share as an int local computed straight from the
 * division with the count n reused as the second loop's counter.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02168800  0x02168800  thumb  ov010
 *   func_020186C8  0x020186C8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02019C90  0x02019C90  thumb
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02172084     0x02172084  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct FacRec {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} FacRec;

typedef struct BattleMon {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    u32 hpIv : 5;       /* 0x14 */
    u32 atkIv : 5;
    u32 defIv : 5;
    u32 speIv : 5;
    u32 spaIv : 5;
    u32 spdIv : 5;
    u32 ivRest : 2;
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 ability;         /* 0x20 */
    u8 friendship;      /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 nature;          /* 0x38 */
} BattleMon;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02168800(void *dst, u32 member);
struct MsgBank;
struct MsgData;
struct Rec;
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_02045C04(struct Rec *rec);
extern const u16 d_02172084[];

u32 func_021684E8(BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap)
{
    FacRec rec;
    int i;
    int n;
    u8 friendship;
    int ev;
    u32 ability;
    void *bank;

    MI_CpuFill8(out, 0, sizeof(BattleMon));
    func_02168800(&rec, member);
    out->species = rec.species;
    out->form = rec.form;
    if (useItem)
        out->item = d_02172084[itemIdx];
    else
        out->item = rec.item;
    friendship = 0xFF;
    for (i = 0; i < 4; i++) {
        out->moves[i] = rec.moves[i];
        if (rec.moves[i] == 0xDA)
            friendship = 0;
    }
    out->otId = otId;
    if (pid == 0) {
        pid = func_020186C8(otId, rec.species, rec.form, 2, 2, 0);
        out->pid = pid;
    } else {
        out->pid = pid;
    }
    out->nature = rec.nature;
    out->hpIv = iv;
    out->atkIv = iv;
    out->defIv = iv;
    out->speIv = iv;
    out->spaIv = iv;
    out->spdIv = iv;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (rec.evMask & (1 << i))
            n++;
    }
    ev = 510 / n;
    if (ev > 255)
        ev = 255;
    for (n = 0; n < 6; n++) {
        if (rec.evMask & (1 << n))
            out->ev[n] = ev;
    }
    out->ppUps = 0;
    out->lang = 0;
    ability = func_02019C90(out->species, 0, 0x1B);
    if (ability != 0) {
        if (out->pid & 1)
            out->ability = ability;
        else
            out->ability = func_02019C90(out->species, 0, 0x1A);
    } else {
        out->ability = func_02019C90(out->species, 0, 0x1A);
    }
    out->friendship = friendship;
    bank = MSGDATA_CreateFromArchive(0, 2, 0x46, heap);
    MSGDATA_ReadUnits(bank, out->species, out->nick, 11);
    func_02045C04(bank);
    return pid;
}
