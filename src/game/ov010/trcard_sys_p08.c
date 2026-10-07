/*
 * file:     trcard_sys_p08.c
 * unit:     yes
 * function: func_0216F7F4, func_0216F830, func_0216F8B8, func_0216F8C8, func_0216F8DC, func_0216F900, func_0216F918, func_0216F940, func_0216F948
 * address:  0x0216F7F4
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
 *   func_02030734 0x02030734 arm
 *   d_02172B64 0x02172B64 data ov010 a1
 *   func_02012EF0  0x02012EF0  thumb
 *   func_02012F44  0x02012F44  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200A73C  0x0200A73C  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021F385C  0x021F385C  thumb  ov059
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F38BC  0x021F38BC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02082BCC 0x02082BCC arm
 *   d_02172B74 0x02172B74 data ov010 a1
 *   func_020307B0  0x020307B0  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 */
struct Big;
struct Blk1AC;
struct Rec1B0;
struct BigObj;
struct Ctx;
struct Rec94;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 *f00; void *f04; void *f08; u32 f0c; u32 f10; u32 f14; } Record;

typedef signed int     s32;

typedef struct Ent {
    u16 move;
    u16 level;
} Ent;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_02012EF0(void **p);
extern void *func_02012F44(void *save);
extern void *func_020127B8(void *save);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, int id);
extern void *func_0200CA1C(void *save);
extern int func_0200D298(void *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0200A73C(struct Big *p);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void func_021F385C(void *);
extern void *func_0215A5F4(void *p);
extern void *func_021F38BC();
extern int func_0215897C();
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_02082BCC(void *,int,int);
extern u32 func_020307B0(void *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
Record *func_0216F7F4(void *a,u8 *b,u32 heap);
int func_0216F830(void *save);
int func_0216F8B8(int a0, int a1);
int func_0216F8C8(int a0, int a1);
int func_0216F8DC(int a0, int a1);
void func_0216F900(void *p);
void *func_0216F918(u32 heap);
void func_0216F940(void *a0, unsigned a1, unsigned a2, unsigned a3);
u16 *func_0216F948(void *mon, u32 heap);
extern char d_02172B64[];
extern char d_02172B74[];

Record *func_0216F7F4(void *a,u8 *b,u32 heap) { Record *p; p=func_02030734(heap,24,1,d_02172B64,0x33a); p->f00=b; p->f04=a; p->f0c=0; b[4]=b[4]&~0x40; p->f00[4]|=0x80; return p; }


/*
 * Counts how many of five save-data conditions hold.
 *
 * Byte-correct (MATCH*, the 136-byte extent includes two bytes of pad).
 * unlabelled ARM9 Thumb thunk (`ldr r0, [r0]; ldr r3, =0x020071CD;
 * movs r1, #0x3a; bx r3`, i.e. `return func_020071CC(*p, 0x3A);`, with the
 * sibling at 0x02012F00 passing 0x3B) whose only caller is this function.
 * Matching that thunk (ARM9 territory) or seeding its start closes this file.
 */
int func_0216F830(void *save)
{
    int n;
    void *a;
    void *b;
    void *c;

    n = 0;
    a = func_02012EF0(save);
    b = func_02012F44(save);
    c = func_020127B8(save);
    if (func_020142E8((void *)func_0201296C(save), 0x960))
        n++;
    if (func_0200D298(func_0200CA1C(save)))
        n++;
    if (func_0200DBA0(a, 7, 0) && func_0200DBA0(a, 8, 0))
        n++;
    if (func_0200A73C(b))
        n++;
    if (func_0200BDF8(c) >= 30 && func_0200BDFC(c) >= 30)
        n++;
    return n;
}


int func_0216F8B8(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216F8C0:
    func_0216F900(v0);
loc_0216F8C4:
a0 = 0;
    return a0;}


/*
 * blocked:
 */
int func_0216F8C8(int a0, int a1)
{
    func_021F385C((void *)func_0201210C((void *)func_0215A5DC((void *)a1)));
    return 0;
}


int func_0216F8DC(int a0, int a1)
{    int t5;
    void *task;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216F8E6:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216F8EE:
    task = func_021F38BC(v1);
loc_0216F8F2:
    a0 = func_0215897C(v0, task);
loc_0216F8FA:
a0 = 1;
    return a0;}

/*
 * Extent: two-byte zero alignment padding at 0216F916.
 * Interface: the call explicitly supplies r1=0x36 even though the leaf reads only r0.
 */
void func_0216F900(void *p) { *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(p)), 0x36) = 1; }

void *func_0216F918(u32 heap) { void *p; p=func_02030734(heap,28,0,d_02172B74,35); func_02082BCC(p,0,28); return p; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216F940.c \
 *       --func func_0216F940 --addr 0x0216F940 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216F940(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}


static inline int Ent_IsEnd(Ent x)
{
    return x.move == 0xFFFF && x.level == 0xFFFF;
}


static inline u16 Ent_Level(Ent x)
{
    return x.level;
}


static inline u16 Ent_Move(Ent x)
{
    return x.move;
}


/*
 * Builds the list of level-up moves a mon could still learn: reads
 * species/form/level and its 4 current moves, loads the learnset (26
 * {move, level} pairs, 0xFFFF/0xFFFF terminated) with func_0201ADD0, and
 * collects moves at or below its level that it neither knows nor already
 * collected. Returns the 0x34-byte list (caller frees); frees the learnset.
 *
 * pass 2 2026-10-06 P2L52: EXACT (also EXACT with --lang c). Load-bearing:
 *   - Every entry access is a by-value inline helper called on `tbl[j]`
 *     itself (no named entry local). The argument is not a plain local, so
 *     each call keeps its own parameter copy (the 8 stack Ent slots of the
 *     image): CSE makes the shared tbl[j] temp at sp+0x18, loop invariants
 *     make the copies before the k and m loops, and the parameter copies in
 *     the loops keep their stores inside the loop. Named Ent locals or
 *     helpers called on a plain local are copy-propagated or substituted.
 *   - `for` loops everywhere with `n = 0, j = 0` in the j loop (propagation
 *     on: the hoisted zero argument is the copy of i, the m guard is
 *     `cmp n,#0; bls`). A do-while k or m loop hoists the in-loop copy.
 *   - `Ent *tbl` declared first: spill slots species 0x10, form 0xc, tbl 0x14.
 *   - The file name pool word is d_02172B74 (the old header said 02173B74).
 */
u16 *func_0216F948(void *mon, u32 heap)
{
    Ent *tbl;
    u16 cur[4];
    u16 species;
    u8 form;
    u8 level;
    u8 i;
    u8 n;
    u8 j;
    u8 k;
    u8 m;
    u16 *out;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    level = func_02017E1C(mon, 0x9E, 0);
    for (i = 0; i < 4; i++)
        cur[i] = func_02017E1C(mon, 0x36 + i, 0);
    tbl = (Ent *)func_02030734(heap, 0x68, 0, d_02172B74, 0x55);
    out = (u16 *)func_02030734(heap, 0x34, 0, d_02172B74, 0x56);
    func_0201ADD0(species, form, tbl);
    for (n = 0, j = 0; j < 26; j++) {
        if (Ent_IsEnd(tbl[j])) {
            out[n] = 0xFFFF;
            break;
        }
        if (Ent_Level(tbl[j]) > level)
            continue;
        for (k = 0; k < 4; k++) {
            if (cur[k] == Ent_Move(tbl[j]))
                break;
        }
        if (k != 4)
            continue;
        for (m = 0; m < n; m++) {
            if (out[m] == Ent_Move(tbl[j]))
                break;
        }
        if (m != n)
            continue;
        out[n] = Ent_Move(tbl[j]);
        n++;
    }
    func_020307B0(tbl);
    return out;
}
