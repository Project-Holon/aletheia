/*
 * file:     musical_dressup_sys_p06.c
 * unit:     yes
 * function: func_02156AD4, func_02156B74, func_02156BAC, func_02156BCC, func_02156BD0, func_02156C28, func_02156C4C, func_02156CAC, func_02156CD8, func_02156CE0, func_02156EDC
 * address:  0x02156AD4
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
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_021568A8  0x021568A8  thumb  ov010
 *   func_02157384  0x02157384  thumb  ov010
 *   func_021FCE44  0x021FCE44  thumb  ov132
 *   func_02012944  0x02012944  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EF14  0x0201EF14  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021FD954  0x021FD954  thumb  ov132
 *   func_021FD95C  0x021FD95C  thumb  ov132
 *   func_02157028  0x02157028  thumb  ov010
 *   func_02157278  0x02157278  thumb  ov010
 *   func_021572A8  0x021572A8  thumb  ov010
 *   func_0200FB24   0x0200FB24  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02030734  0x02030734  arm
 *   d_02172730  0x02172730  data
 *   ov133_id  0x00000085  data
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021B6100  0x021B6100  thumb ov133
 *   func_021B63BC  0x021B63BC  thumb  ov133
 *   func_021B6294  0x021B6294  thumb ov133
 *   func_021FD904  0x021FD904  thumb ov132
 *   func_021FD52C  0x021FD52C  thumb ov132
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_02156F68  0x02156F68  thumb  ov010
 *   func_02156FD0  0x02156FD0  thumb  ov010
 *   func_0215700C  0x0215700C  thumb  ov010
 *   func_02157174  0x02157174  thumb  ov010
 *   func_021F685C  0x021F685C  thumb  ov112
 *   func_021F68BC  0x021F68BC  thumb  ov112
 *   ov112_id       0x00000070  data
 *   func_0215716C  0x0215716C  thumb
 *   func_021F6888  0x021F6888  thumb
 *   func_02156F98  0x02156F98  thumb
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17619.h"

struct MsgBank;
struct Rec;
struct Table;
struct U16Vec;
struct WordSet;
struct Deal;
struct Src;
struct Obj0203159C;
struct S020315D4;
struct Party;
struct Stage;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Work_02156AD4 {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[0x14 - 0x08];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1C[0x28 - 0x1C];
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    u8 pad3C[0x4C - 0x3C];
    u8 f4c;             /* 0x4C */
} Work_02156AD4;

typedef struct Work_02156B74 {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
} Work_02156B74;

typedef signed short   s16_02156AD4;

typedef struct Obj_02156BD0 {
    u32 *f00;
    u32 pad[2];
    u32 *f0c;
} Obj_02156BD0;

typedef signed int     s32;

typedef struct S S;

typedef struct Obj_02156CAC { int f00; int f04; int f08; } Obj_02156CAC;

typedef short s16_02156CE0;

typedef struct Member {
    u8 pad00[0x4A];
    u16 total;          /* 0x4A */
} Member;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Member *f04[4];     /* 0x04 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1c[0x20 - 0x1C];
} Stage;

typedef struct Work {
    Stage *stage;       /* 0x00 */
    u32 f04;
    u32 f08;
} Work;

typedef struct Ctx {
	void *f00;
	unsigned int f04;
	int *f08;
	unsigned int f0c;
	unsigned int f10;
	void *f14;
	void *f18;
	unsigned int f1c;
	unsigned int f20;
	unsigned int f24;
	struct Req *f28;
	unsigned char pad2c[0xc];
	void *f38;
	void *f3c[4];
	unsigned int f4c;
	unsigned int f50;
	unsigned int f54;
	int f58;
	void *f5c;
	unsigned int f60;
	void *f64;
	void *f68[4];
	unsigned char b78[4];
	unsigned int f7c;
	unsigned char b80[8];
	struct Info *f88;
	unsigned char slot[0x40];
	unsigned int fcc;
	unsigned int fd0;
	unsigned int fd4;
	unsigned int fd8;
	unsigned int fdc;
	void *fe0;
	unsigned int fe4;
} Ctx;

extern u8 func_021568E8(Work_02156AD4 *w, u8 j);
extern u8 func_021568A8(Work_02156AD4 *w, u8 n);
extern u8 func_02157384(struct Table *, int);
extern int func_021FCE44(char *p, u32 index);
extern u8 *func_02012944(void *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_021FD954(char *p);
extern u32 func_021FD95C(char *p);
extern struct Deal *func_02157028(u32 heap, struct Src *src, u16 lim);
extern void func_02157278(u8 *p, u32 v);
extern void func_021572A8(struct Deal *d, u32 v);
extern u32 func_0200FB24(void);
extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(s32 handle);
extern u8 *func_021B6100(u8 *parent, int heap);
extern int func_021B63BC(int);
extern void func_021B6294(char *p);
extern int func_021FD904(int *);
extern void func_021FD52C(struct S *s);
extern void *func_0200A5F8(void *sys);
extern Stage *func_02156F68(u32 heap, void *p);
extern void func_02156FD0(Stage *, u8, u16, u8, u32, u16, u16);
extern void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16_02156CE0 a, u8 b);
extern void func_02157174(u32 heap, struct Deal *d, struct Party *party);
extern void *func_021F685C(u32 a);
extern void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);
extern int func_0215716C(void *);
extern int func_021F6888(void *);
extern int func_02156F98(struct Stage *);
void func_02156AD4(Work_02156AD4 *w, u8 j, void *ws, u32 slot);
void func_02156B74(Work_02156B74 *w);
void func_02156BAC(void *p);
u32 func_02156BCC(void *p);
int func_02156BD0(void *a, u32 *out, u32 *src);
int func_02156C28(void *a, int b, int c, void **d);
int func_02156C4C(int a, int *state, int c, int *d);
Obj_02156CAC *func_02156CAC(int a, int b, int c);
void func_02156CD8(void *a0, unsigned a1, unsigned a2, unsigned a3);
int func_02156CE0(void *proc, void *unused, Stage *prev);
int func_02156EDC(void *a, int b, int c, Ctx **d);
extern char ov133_id[];
extern const char d_02172730[];
extern u8 ov112_id[];



/*
 * Twin of func_02156A3C for the second word-set field: the local player's
 * record at +0x18, the session's record for a remote member (0x021FCE44),
 * or failing both the fallback string from message bank 0x4D.
 *
 * First draft; the ov132 call to 0x021FCE44 resolves since seeds_2 labelled it.
 */
void func_02156AD4(Work_02156AD4 *w, u8 j, void *ws, u32 slot)
{
    int done = 0;
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4c) {
        func_02012944(w->f04);
        func_0201EEF4(ws, slot, w->f18);
        done = 1;
    } else if (w->f14 == 1) {
        p = (void *)func_021FCE44(w->f28, k);
        if (p != 0) {
            func_0201EF14(ws, slot, p);
            done = 1;
        }
    }
    if (!done) {
        u8 n = func_02157384(w->f38, func_021568A8(w, k));
        void *bank = func_02045B38(0, 2, 0x4D, 4);
        void *str = func_02045EC0(bank, n);

        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
    }
}



/*
 * 2026-10-05 (wave D9): EXACT. The callees 0x021FD954 and 0x021FD95C are the
 * two Thumb getters in ov132 (matched in ov132_func_021FD938.c); the symbols
 * lines now carry the ov132 token, which gave the witness.
 */
void func_02156B74(Work_02156B74 *w)
{
    u32 a;
    u32 b;

    a = func_021FD954(w->f28);
    b = func_021FD95C(w->f28);
    if (w->f38 == 0)
        w->f38 = func_02157028(4, w->f24, 0);
    func_02157278(w->f38, a);
    func_021572A8(w->f38, b);
}



/*
 * One-shot state test: only when the mode word is 1, the arm9 predicate
 * agrees and the flag is clear does the flag get set.
 */
void func_02156BAC(void *p)
{
    int v = *(int *)&((struct Obj00005 *)p)->f14;

    if (v == 1) {
        if (func_0200FB24()) {
            if (((struct Obj00005 *)p)->f50 == 0) {
                ((struct Obj00005 *)p)->f50 = 1;
            }
        }
    }
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02156BCC.c \
 *       --func func_02156BCC --addr 0x02156BCC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02156BCC(void *p) { return ((struct Obj17619 *)p)->f50; }



int func_02156BD0(void *a, u32 *out, u32 *src)
{
    Obj_02156BD0 *o;
    *out = 0;
    func_02034AC4((u32)ov133_id);
    func_0203064C(1, 0x2d, 1 << 18);
    o = func_0203159C(a, 0x10, 0x2d);
    o->f00 = func_02030734(0x2d, 0xc, 0, d_02172730, 0x4e);
    o->f0c = src;
    o->f00[0] = src[0];
    o->f00[1] = src[1];
    o->f00[2] = src[2];
    return 1;
}


int func_02156C28(void *a, int b, int c, void **d) { func_020307B0(*d); func_020315D4(a); func_020306F0(0x2d); func_02034A5C((u32)ov133_id); return 1; }



/*
 * Recovered existing source/shard: setup func_02156BD0 loads ov133 (0x85).
 * Its constructor returns the allocation; ov070's same address is a setter.
 * The ov132 getter reads its session argument at +0x48, passed live in r0.
 * The 94-byte body is followed by two bytes of alignment padding.
 */
int func_02156C4C(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)func_021B6100((u8 *)d[0], 0x2d);
        *state = 1;
        if (*(int *)d[3] != 0) {
            if (func_021FD904((int *)*(int *)d[3]) == 1)
                func_021FD52C((S *)*(int *)d[3]);
        }
        break;
    case 1: {
        int r = func_021B63BC(d[1]);
        if (r != 0) {
            d[2] = r;
            *state = 2;
        }
        break;
    }
    case 2:
        func_021B6294((char *)d[1]);
        return 1;
    }
    return 0;
}


Obj_02156CAC *func_02156CAC(int a, int b, int c) { Obj_02156CAC *p; int zero = 0; p = func_02030734(a, 12, 0, d_02172730, 0xa7); p->f00 = zero; p->f08 = (int)func_0200A5F8((void *)c); p->f04 = b; return p; }



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
 *   python tools/match.py one --src src/matched/func_02156CD8.c \
 *       --func func_02156CD8 --addr 0x02156CD8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02156CD8(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}



/*
 * Builds the ov010 stage: four members with their records, the ov112 deal
 * and its split. First draft plus two levers: the pooled 0x70 is ov112_id,
 * and the three colour masks come from one `mask` local shifted.
 */
int func_02156CE0(void *proc, void *unused, Stage *prev)
{
    Work *w;
    u32 mask;

    func_0203064C(1, 0x2E, 0xA8000);
    w = func_0203159C(proc, sizeof(Work), 0x2E);
    if (prev == 0) {
        func_02034AC4((u32)ov112_id);
        w->stage = func_02156F68(0x2E, 0);
        mask = 0xFF000000;
        func_02156FD0(w->stage, 0, 0x147, 0, mask, 60, 0x2E);
        func_02156FD0(w->stage, 1, 0x147, 0, mask >> 8, 120, 0x2E);
        func_02156FD0(w->stage, 2, 0x147, 0, mask >> 16, -3, 0x2E);
        func_02156FD0(w->stage, 3, 0x147, 0, 0x000000FF, -1, 0x2E);
        func_0215700C(w->stage, 0, 7, 0x13, 0, 0);
        func_0215700C(w->stage, 0, 8, 0x13, 0, 1);
        func_0215700C(w->stage, 0, 2, 0x10, 0, 2);
        func_0215700C(w->stage, 1, 1, 0x07, 0, 0);
        func_0215700C(w->stage, 1, 5, 0x09, 0, 1);
        func_0215700C(w->stage, 1, 7, 0x18, 0, 2);
        func_0215700C(w->stage, 1, 8, 0x2B, 0, 3);
        func_0215700C(w->stage, 2, 7, 0x1F, 0, 0);
        func_0215700C(w->stage, 2, 8, 0x1E, 0, 1);
        func_0215700C(w->stage, 2, 2, 0x0F, 0, 2);
        func_0215700C(w->stage, 3, 7, 0x1E, 0, 0);
        func_0215700C(w->stage, 3, 8, 0x1E, 0, 1);
        func_0215700C(w->stage, 3, 2, 0x15, 0, 2);
        *(u32 *)w->stage->f04[1] = 0;
        func_0203064C(1, 0x802C, 0x80000);
        w->stage->f18 = func_021F685C(1);
        func_021F68BC(w->stage->f18, 0, 0, 0, 0x2C);
        w->stage->f14 = func_02157028(0x2E, w->stage->f18, 0);
        func_02157174(0x2E, w->stage->f14, (struct Party *)w->stage);
        w->stage->f04[0]->total = 75;
        w->stage->f04[1]->total = 45;
        w->stage->f04[2]->total = 30;
        w->stage->f04[3]->total = 0;
    } else {
        w->stage = prev;
    }
    return 1;
}



int func_02156EDC(void *a, int b, int c, Ctx **d)
{
    if (c == 0) {
        func_0215716C((*d)->f14);
        func_021F6888((*d)->f18);
        func_020306F0(0x2c);
        *(*d)->f08 = 2;
        func_02156F98((struct Stage *)(*d));
        func_02034A5C((u32)ov112_id);
    }
    func_020315D4(a);
    func_020306F0(0x2e);
    return 1;
}
