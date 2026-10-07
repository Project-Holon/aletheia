/*
 * file:     comm_player_p11.c
 * unit:     yes
 * function: func_021684E8, func_0216869C, func_02168800
 * address:  0x021684E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020186C8  0x020186C8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02019C90  0x02019C90  thumb
 *   sub_02045B38   0x02045B38  arm
 *   func_02045F5C  0x02045F5C  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02172084     0x02172084  data
 *   func_02017528  0x02017528  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02045924  0x02045924  arm
 *   func_02045808  0x02045808  arm
 *   func_02018430  0x02018430  thumb
 *   func_02048F4C  0x02048F4C  arm
 */
struct MsgBank;
struct MsgData;
struct Rec;
struct Mon;
struct Sav;
struct Strbuf;
struct U16Vec;
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

typedef struct BattleMon_021684E8 {
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
} BattleMon_021684E8;

typedef unsigned long long u64;

typedef struct BattleMon_0216869C {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    u32 ivs;            /* 0x14 */
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 f20;             /* 0x20 */
    u8 f21;             /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 f38;             /* 0x38 */
} BattleMon_0216869C;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02017528(struct Sav *p);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020185B0(void *p, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02018430(void *p);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
u32 func_021684E8(BattleMon_021684E8 *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
void func_0216869C(const BattleMon_0216869C *src, void *mon);
void func_02168800(void *dst, u32 member);
extern const u16 d_02172084[];


/*
 * Build a battle-facility Pokemon from its a/2/1/4 record (the reader is
 * func_02168800). Levers: the pid store in both arms of an if/else, the
 * ability as a nested if storing in all three arms, and (2026-09-28
 * tree_ov010_4) the EV share as an int local computed straight from the
 * division with the count n reused as the second loop's counter.
 */
u32 func_021684E8(BattleMon_021684E8 *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap)
{
    FacRec rec;
    int i;
    int n;
    u8 friendship;
    int ev;
    u32 ability;
    void *bank;

    MI_CpuFill8(out, 0, sizeof(BattleMon_021684E8));
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
    bank = sub_02045B38(0, 2, 0x46, heap);
    func_02045F5C(bank, out->species, out->nick, 11);
    func_02045C04(bank);
    return pid;
}


/*
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through func_02017E1C goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 */
void func_0216869C(const BattleMon_0216869C *src, void *mon)
{
    u16 name[11];
    void *buf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *n;

    func_02017528(mon);
    func_02017588(mon, src->species, 50, (u64)-1, src->ivs & 0x3FFFFFFF, src->pid);
    func_02017E40(mon, 0x6F, (u8)src->form);
    func_02017E40(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        func_02017E40(mon, 0x36 + i, src->moves[i]);
        func_02017E40(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = func_02017E1C(mon, 0x42 + i, 0);
        func_02017E40(mon, 0x3A + i, pp);
    }
    func_02017E40(mon, 7, src->otId);
    func_02017E40(mon, 0xD, src->ev[0]);
    func_02017E40(mon, 0xE, src->ev[1]);
    func_02017E40(mon, 0xF, src->ev[2]);
    func_02017E40(mon, 0x10, src->ev[3]);
    func_02017E40(mon, 0x11, src->ev[4]);
    func_02017E40(mon, 0x12, src->ev[5]);
    func_02017E40(mon, 0xA, src->f20);
    func_02017E40(mon, 9, src->f21);
    func_020185B0(mon, src->f38);
    buf = func_020457B0(11, 4);
    eos = func_02045A98();
    n = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = n[i];
    name[i - 1] = eos;
    func_02045924(buf, name);
    func_02017E40(mon, 0x73, (u32)buf);
    func_02045808(buf);
    func_02017E40(mon, 0xC, src->lang);
    func_02017E40(mon, 0x9E, func_02018430(mon));
}


/*
 * The reader for a/2/1/4: copy one 16-byte record into the caller's buffer.
 * 214 is the archive id and it never appears as an immediate at any call to
 * the arc_tool.c entry points, because this accessor reaches func_02048F4C
 * by pool word and `bx` rather than by `bl`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): a plain scan of `bl`
 * sites misses it entirely.
 *
 * The record is a battle-facility Pokemon: func_021684E8, three functions
 * up in the same file (fld_btl_inst_tool.c, by the __FILE__ anchors either
 * side of this address), reads the buffer field by field into a party
 * slot: +0 species (masked to 11 bits), +2/+4/+6/+8 the four move ids,
 * +10 a six-bit "which stats are EV-invested" mask (the caller divides 510
 * EVs between the set bits), +11 the nature (0..24 over the whole archive),
 * +12 the held item and +14 the form (five bits, always zero here).  The
 * member ids come from a/2/1/5, whose own reader is func_0216880C
 * immediately below this one.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02168800.c \
 *       --func func_02168800 --addr 0x02168800 --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void func_02168800(void *dst, u32 member)
{
    func_02048F4C(dst, 214, member);
}
