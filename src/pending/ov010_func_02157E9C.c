/*
 * function: func_02157E9C
 * address:  0x02157E9C
 * packet:   pkt_ov010_02157E9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Builds a gift Pokemon from a mystery-gift record. 1148/1148 bytes, every
 * relocation resolved, 10 instructions out in two argument-setup schedules
 * of the func_020186C8 calls (pid types 0 and 2). See
 * docs/notes/pkt_ov010_02157E9C.c.txt.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017FA8  0x02017FA8  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0202F2AC  0x0202F2AC  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   d_02170068     0x02170068  data
 *   d_0209DF08     0x0209DF08  data  a1
 *   d_0209DF0C     0x0209DF0C  data  a1
 *   d_020A7370     0x020A7370  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

typedef struct GiftMon {
    u32 otId;           /* 0x00 */
    u32 f04;            /* 0x04 */
    u32 pid;            /* 0x08 */
    u16 ribbons;        /* 0x0C */
    u16 ball;           /* 0x0E */
    u16 item;           /* 0x10 */
    u16 moves[4];       /* 0x12 */
    u16 species;        /* 0x1A */
    u8 form;            /* 0x1C */
    u8 lang;            /* 0x1D */
    u16 nick[11];       /* 0x1E */
    u8 nature;          /* 0x34 */
    u8 gender;          /* 0x35 */
    u8 ability;         /* 0x36 */
    u8 pidType;         /* 0x37 */
    u16 eggLoc;         /* 0x38 */
    u16 metLoc;         /* 0x3A */
    u8 f3C;             /* 0x3C */
    u8 contest[6];      /* 0x3D */
    u8 hp;              /* 0x43 */
    u8 atk;             /* 0x44 */
    u8 def;             /* 0x45 */
    u8 spe;             /* 0x46 */
    u8 spa;             /* 0x47 */
    u8 spd;             /* 0x48 */
    u8 pad49;
    u16 otName[8];      /* 0x4A */
    u8 otGender;        /* 0x5A */
    u8 level;           /* 0x5B */
    u8 isEgg;           /* 0x5C */
    u8 pad5D[0xAC - 0x5D];
    s32 date;           /* 0xAC */
    u8 padB0[3];
    u8 fB3;             /* 0xB3 */
} GiftMon;

typedef struct IvMoves {
    u8 iv[6];
    u16 moves[4];
} IvMoves;

extern u32 func_020056EC(u32 n);
extern void *func_02012944(void *p);
extern u32 func_02008530(void *p);
extern u16 *func_020084F4(void *p);
extern u32 func_02008550(void *p);
extern void *func_020173F0(u16 species, u16 level, u64 id, int heap);
extern u32 func_020186C8(u32 a0, u16 a1, int a2, int a3, int a4, int a5);
extern void func_02017588(void *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, u32 move);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void *func_020185F0(void *p);
extern void func_020185C4(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_020307B0(void *p);
extern u16 func_02045A98(void);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *s);

extern u32 d_02170068[];
extern u8 d_0209DF08[];
extern u8 d_0209DF0C[];
extern void *d_020A7370;

void *func_02157E9C(const GiftMon *g, int heap, void *save)
{
    u16 moves[4];
    u8 iv[6];
    u32 month;
    u32 ability;
    u32 gender;
    u64 pid;
    u32 species;
    u32 otId;
    u64 id;
    u16 level;
    u32 slot;
    void *ret;
    u32 ivs;
    int i;
    u32 k;
    u16 mv;
    void *pp;
    void *name;
    u32 v;
    u8 day;
    u16 year;
    u32 loc;

    level = g->level;
    otId = g->otId;
    species = g->species;
    gender = g->gender;
    ability = g->ability;
    iv[0] = g->hp;
    iv[1] = g->atk;
    iv[2] = g->def;
    iv[3] = g->spa;
    iv[4] = g->spd;
    iv[5] = g->spe;
    moves[0] = g->moves[0];
    moves[1] = g->moves[1];
    moves[2] = g->moves[2];
    moves[3] = g->moves[3];

    if (g->fB3 != 1) {
        ret = 0;
        goto out;
    }
    if (species > 649) {
        ret = 0;
        goto out;
    }
    if (species == 0) {
        ret = 0;
        goto out;
    }
    if (level > 100) {
        ret = 0;
        goto out;
    }
    if (g->item > 626) {
        ret = 0;
        goto out;
    }

    if (level == 0)
        level = func_020056EC(100) + 1;
    if (g->otId == 0)
        otId = func_02008530(func_02012944(save));
    if (gender == 0xFF)
        gender = 2;
    for (i = 0; i < 6; i++) {
        if (iv[i] == 0xFF)
            iv[i] = func_020056EC(32);
    }

    id = otId;
    pp = func_020173F0(species, level, id, heap);
    ivs = (iv[0] & 0x1F) | ((iv[1] & 0x1F) << 5) | ((iv[2] & 0x1F) << 10)
        | ((iv[3] & 0x1F) << 15) | ((iv[4] & 0x1F) << 20) | ((iv[5] & 0x1F) << 25);

    if (ability == 4)
        ability = (u8)func_020056EC(3);
    switch (ability) {
    case 0:
        slot = 0;
        break;
    case 1:
        slot = 1;
        break;
    case 2:
        slot = 0;
        break;
    case 3:
        slot = 2;
        break;
    default:
        ret = 0;
        goto out;
    }

    if (g->pid != 0) {
        pid = g->pid;
    } else if (g->pidType == 0) {
        pid = func_020186C8(otId, species, g->form, gender, slot, 0);
    } else if (g->pidType == 1) {
        pid = func_020186C8(otId, species, g->form, gender, slot, 2);
    } else if (g->pidType == 2) {
        pid = func_020186C8(otId, species, g->form, gender, slot, 1);
    }

    func_02017588(pp, g->species, level, id, ivs, pid);
    func_02017E40(pp, 6, g->item);
    func_02017FA8(pp);
    for (i = 0; i < 4; i++) {
        mv = moves[i];
        if (mv != 0 && mv < 0x230) {
            if (func_0201808C(pp, mv) == 0xFFFF)
                func_020180F4(pp, mv);
        }
    }
    if (g->pid == 0 && ability == 2)
        func_02018A00(pp, species, g->form);
    func_02017E40(pp, 0x6F, g->form);
    if (g->ball != 0 && g->ball <= 0x19)
        func_02017E40(pp, 0x98, g->ball);
    else
        func_02017E40(pp, 0x98, 4);
    if (g->f3C != 0)
        func_02017E40(pp, 0x99, g->f3C);
    func_02017E40(pp, 0x13, g->contest[0]);
    func_02017E40(pp, 0x14, g->contest[1]);
    func_02017E40(pp, 0x15, g->contest[2]);
    func_02017E40(pp, 0x16, g->contest[3]);
    func_02017E40(pp, 0x17, g->contest[4]);
    func_02017E40(pp, 0x18, g->contest[4]);
    for (k = 0; k < 15; k++) {
        if (g->ribbons & (1 << k))
            func_02017E40(pp, d_02170068[k], 1);
    }
    if (g->f04 == 0)
        func_02017E40(pp, 0x77, d_0209DF08[0]);
    else
        func_02017E40(pp, 0x77, g->f04);
    if (g->lang == 0)
        func_02017E40(pp, 0xC, d_0209DF0C[0]);
    else
        func_02017E40(pp, 0xC, g->lang);
    if (g->nick[0] == 0) {
        func_020307B0(pp);
        ret = 0;
        goto out;
    }
    if (g->nick[0] != func_02045A98())
        func_02017E40(pp, 0x74, (u32)g->nick);
    v = g->nature;
    if (v == 0xFF)
        v = (u8)func_020056EC(25);
    func_02017E40(pp, 0x70, v);
    func_02017E40(pp, 0x95, g->eggLoc);
    func_02017E40(pp, 0x96, g->metLoc);
    if (g->otName[0] == 0) {
        func_020307B0(pp);
        ret = 0;
        goto out;
    }
    if (g->otName[0] == func_02045A98())
        func_02017E40(pp, 0x8E, (u32)func_020084F4(func_02012944(save)));
    else
        func_02017E40(pp, 0x8E, (u32)g->otName);
    if (g->otGender <= 2)
        func_02017E40(pp, 0x9A, g->otGender);
    else
        func_02017E40(pp, 0x9A, func_02008550(func_02012944(save)));
    if (g->isEgg) {
        func_02017E40(pp, 0x4C, 1);
        name = func_02045EC0(d_020A7370, 0x28A);
        func_02017E40(pp, 0x73, (u32)name);
        func_02045808(name);
        func_02017E40(pp, 9, 10);
    }
    year = g->date >> 16;
    month = (u8)(g->date >> 8);
    day = g->date;
    loc = g->isEgg ? g->eggLoc : g->metLoc;
    func_0202F2AC(func_020185F0(pp), loc, year - 2000, month, day);
    func_020185C4(pp);
    ret = 0;
    if (func_02017E1C(pp, 3, 0) != 0)
        func_020307B0(pp);
    else
        ret = pp;
out:
    return ret;
}
