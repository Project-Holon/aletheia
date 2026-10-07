/*
 * file:     script_work_p05.c
 * unit:     yes
 * function: func_02157E34, func_02157E6C, func_02157E78, func_02157E8C, func_02157E9C, func_02158318, func_02158344, func_02158378, func_0215839C, func_021583CC, func_021583EC, func_0215840C, func_0215841C, func_02158428, func_02158434, func_0215843C, func_02158468, func_021584A4
 * address:  0x02157E34
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
 *   func_02157E08  0x02157E08  thumb
 *   func_02157960  0x02157960  thumb
 *   func_02157DB8  0x02157DB8  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203CEAC  0x0203CEAC  arm
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
 *   func_02045A98  0x02045A98  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   d_02170068     0x02170068  data
 *   d_0209DF08     0x0209DF08  data  a1
 *   d_0209DF0C     0x0209DF0C  data  a1
 *   d_020A7370     0x020A7370  data
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020127B8   0x020127B8  thumb
 *   func_020127AC   0x020127AC  thumb
 *   func_02012950   0x02012950  thumb
 *   func_02012B80   0x02012B80  thumb
 *   func_0200855C 0x0200855C thumb
 *   func_02012984  0x02012984  thumb
 *   func_02012B98  0x02012B98  thumb
 */
#include "../../matched/include/Obj07276.h"
#include "../../matched/include/Obj18745.h"

struct Mon;
struct MsgBank;
struct U16Vec;
struct Sub0200852CObj;
struct Ctx;
struct BigObj;
struct SaveBlock;
struct Rec44;
struct Sub24;
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

typedef struct { u8 a : 4; u8 f : 2; u8 b : 2; } Fl;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct RecHolder {
    u8 pad[0x1AC];
    Rec28 recs[1];      /* 0x1AC */
} RecHolder;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

extern int func_02157E08(void *);
extern void func_02157960(int a, int b, int c);
extern void func_02157DB8(int p);
extern u32 func_020307B0(void *p);
extern int func_0203CEAC(int a0);
extern u32 func_020056EC(u32 n);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020173F0(u16 species, u16 level, u64 id, int heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void *func_020185F0(void *p);
extern void func_020185C4(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u16 func_02045A98(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_0202648C(void *obj);
extern u32 func_02026474(void *obj);
extern u32 func_0200FB24(void);
extern u32 func_02026454(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_02012B98(const struct BigObj *p, u32 i);
int func_02157E34(void *p);
unsigned char func_02157E6C(char *p);
void func_02157E78(u8 *p);
int func_02157E8C(void *a0);
void *func_02157E9C(const GiftMon *g, int heap, void *save);
int func_02158318(int a0);
int func_02158344(int a0);
int func_02158378(void *p);
int func_0215839C(u8 *p, int m, int a2);
int func_021583CC(void *a0, int a1);
int func_021583EC(void *a0, int a1);
Rec28 *func_0215840C(RecHolder *h, int idx);
u8 func_0215841C(void *p);
u8 func_02158428(u8 *p);
void *func_02158434(char *p);
int func_0215843C(void *p);
int func_02158468(int a0);
int func_021584A4(int unused, int a, int mode);
extern u32 d_02170068[];
extern u8 d_0209DF08[];
extern u8 d_0209DF0C[];
extern void *d_020A7370;


int func_02157E34(void *p)
{
    int r = func_02157E08(p);
    *((u8 *)p + 0x675) = 0;
    *((u8 *)p + 0x676) = 0;
    *((u8 *)p + 0x677) = 0;
    ((struct Obj07276 *)p)->f66C = 0;
    func_02157960((int)p, (int)((void *)func_02157DB8), 0x231);
    return r;
}

/*
 * extent: Accessor ends at 02157E78, followed by labelled callback function.
 */
unsigned char func_02157E6C(char *p)
{
    return ((struct Obj18745 *)p)->f674;
}

void func_02157E78(u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))(p + 0x678);
    if (callback != 0)
        callback(p);
}


int func_02157E8C(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_02157E92:
a0 = 0;
    a0 = (void *)func_0203CEAC((int)a0);
loc_02157E98:
    return (int)a0;}


/*
 * Wave 76 lever: gender is a u8 local, loaded from GiftMon.gender and
 * remapped from 0xFF to 2. With the form extern parameter u8, this restores
 * both personality-call setup schedules: 19 differing bytes become EXACT.
 * Signed 64-bit PID and ID were flat19; union PID worsened to38. The u8
 * form extern alone stayed19. Old seed7201 budget400 was not repeated.
 * checks: 1 own callees and forwarding bodies re-read, six personality inputs; 2 021684E8/ov121 DEFAC inspected; 3 byte form flat19, byte gender EXACT; 4 existing width/const idioms inspected; 5 current neighbours and idioms inspected before filing.
 * Wave 75 fresh pass: unsigned-long species, enum flag argument, enum slot, u16 form argument, and nonconst GiftMon each19/1148 B; retain original const best. All54 relocations resolved. Old seed7201 budget400 consumed; never rerun.
 * Prior recorded evidence (retained):
 * func_02157E9C (ov010, Thumb, 1148 bytes), tree_ov010_2, 2026-09-28
 *
 * Best source: src/pending/ov010_func_02157E9C.c (DIFF, size right, 54 of 54
 * relocations resolved, 10 instructions out). The residue is the argument
 * setup of the first and third func_020186C8 calls:
 *
 *   image  (pidType 0): ldr r1,[sp,#0x20]; str r0,[sp]; movs r0,#0; lsls r1;
 *                       ldrb r2,[r4,#0x1c]; str r0,[sp,#0x28]; str r0,[sp,#4]
 *   this C (pidType 0): str r0,[sp]; movs r0,#0; ldr r1,[sp,#0x20];
 *                       str r0,[sp,#4]; str r0,[sp,#0x28]; lsls r1; ldrb r2
 *   image  (pidType 2): ldr r1; ldrb r2; str r0,[sp,#4]; lsls r1
 *   this C (pidType 2): ldr r1; str r0,[sp,#4]; lsls r1; ldrb r2
 *
 * Measured:
 * - 288-shape grid (species u32/int/u16 x species arg plain/(u16) x callee
 *   a1 u16/int/u32 x form arg plain/(int) x slot u32/int x gender u32/int x
 *   if-chain/switch on pidType): flat at 10 or 11, never lower.
 * - pid as two u32 locals (the ov121 func_021DEFAC spelling, hi written
 *   before the call in pidType 0 and after in 1 and 2): 431 at every one of
 *   the 46 declaration positions (level leaves its stack slot for r7).
 * - pid as u32[2]: 432. Half writes through ((u32 *)&pid)[k]: 52 (pid moves
 *   to sp+0x34).
 * - permuter seed 7201, budget 400, focus 0x17E: no gain.
 *
 * The same function exists in ov121 (src/pending/func_021DEFAC.c, DIFF); a
 * lever found for one should be tried on the other.
 *
 * 2026-09-28, tree_ov010_3: not re-drafted (the lane's time went to the
 * open roots); the residue above is unchanged at 10 instructions.
 *
 * Builds a gift Pokemon from a mystery-gift record. 1148/1148 bytes, every
 * relocation resolved, 10 instructions out in two argument-setup schedules
 * of the func_020186C8 calls (pid types 0 and 2). See
 * docs/notes/pkt_ov010_02157E9C.c.txt.
 */
void *func_02157E9C(const GiftMon *g, int heap, void *save)
{
    u16 moves[4];
    u8 iv[6];
    u32 month;
    u32 ability;
    u8 gender;
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
        otId = func_02008530((const struct Sub0200852CObj *)func_02012944(save));
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
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 0);
    } else if (g->pidType == 1) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 2);
    } else if (g->pidType == 2) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 1);
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
        func_02017E40(pp, 0x9A, func_02008550((const struct Sub0200852CObj *)func_02012944(save)));
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


int func_02158318(int a0)
{
    int t4;
    int t5;
    void *p;

t5 = a0 + 0;
    a0 = func_02012138((const struct Ctx *)a0);
loc_02158320:
t4 = a0 + 0;
a0 = t5 + 0;
    p = func_020120F4((const struct Ctx *)a0);
loc_02158328:
    a0 = func_02012B70(p);
loc_0215832C:
    if (a0 != 1) goto loc_0215833E;
loc_02158330:
a0 = t4 + 0;
    a0 = func_0202648C((void *)a0);
loc_02158336:
    if (a0 == 0) goto loc_0215833E;
loc_0215833A:
a0 = 0;
    return a0;
loc_0215833E:
a0 = 1;
    return a0;}


int func_02158344(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02026474((void *)a0);
loc_0215834C:
t4 = a0 + 0;
    a0 = func_0200FB24();
loc_02158352:
    if (a0 != 0) goto loc_0215836E;
loc_02158356:
a0 = t5 + 0;
    a0 = func_02026454((void *)a0);
loc_0215835C:
    if (a0 != 2) goto loc_0215836E;
loc_02158360:
a0 = t5 + 0;
    a0 = func_02026460((void *)a0);
loc_02158366:
    if (a0 == 1) goto loc_0215836E;
loc_0215836A:
    if (t4 != 0) goto loc_02158372;
loc_0215836E:
a0 = 0;
    return a0;
loc_02158372:
a0 = t4 + 0;
    return a0;}


int func_02158378(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0) {
        return func_02012B58((const struct BigObj *)func_02026478(p));
    }
    return q[0x911];
}


int func_0215839C(u8 *p, int m, int a2)
{
    Fl *s = (Fl *)(p + 0x93F);
    u8 t = s->f;
    if (m & t) {
        s->f ^= 1;
        return 1;
    }
    return 0;
}


/*
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 */
int func_021583CC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_020127B8(a0);

    return (int)func_020127AC(a0, a1);
}


int func_021583EC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_02012944(a0);

    return (int)func_02012950(a0, a1);
}


/*
 * Address of the idx-th 0x28-byte record at +0x1AC.
 */
Rec28 *func_0215840C(RecHolder *h, int idx)
{
    return &h->recs[idx];
}


/*
 * Byte out of the arm9 reader, zero-extended.
 */
u8 func_0215841C(void *p)
{
    return (u8)(unsigned)func_02012B80(p);
}


/*
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * func_0215841C); sole blocker of ov018 func_0217D1C0. Followed by another
 * unlabelled leaf at 0x02158434.
 */
u8 func_02158428(u8 *p)
{
    return p[0x90C];
}

/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021870C4.
 */
void *func_02158434(char *p)
{
    return p + 0x35C;
}

/*
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 */
int func_0215843C(void *p)
{
    void *q = (void *)func_02026478(p);
    u8 id;
    if (func_02012B70(q) == 0)
        return 21;
    id = (int)func_02012B80(q);
    return func_0200855C((const struct Sub0200852CObj *)func_021583EC(q, id));
}


int func_02158468(int a0)
{
    int a1;
    int t4;
    int t5;

    a0 = func_02026478((void *)a0);
loc_0215846E:
t5 = a0 + 0;
    a0 = func_02012B70((const struct BigObj *)a0);
loc_02158474:
    if (a0 != 0) goto loc_02158480;
loc_02158478:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_0215847E:
    return a0;
loc_02158480:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_02158486:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_0215848E:
    if (t4 != a0) goto loc_0215849A;
loc_02158492:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_02158498:
    return a0;
loc_0215849A:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02012B98((const struct BigObj *)a0, a1);
loc_021584A2:
    return a0;}


int func_021584A4(int unused, int a, int mode)
{
    u8 *q = (u8 *)func_02158344(unused);
    int n;
    int cur;
    if (q == 0)
        return 1;
    cur = ((Fh *)(q + 0x86))->f;
    if (mode == 2) {
        n = cur - 1;
        if (n < 0)
            n = q[0x901];
    } else {
        n = cur + 1;
        if (n >= q[0x901] + 1)
            n = 0;
    }
    if (n == func_02012B58((const struct BigObj *)a))
        return 1;
    return 0;
}
