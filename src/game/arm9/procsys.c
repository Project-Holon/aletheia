/*
 * file:     procsys.c
 * unit:     yes
 * function: func_0203129C, func_020312B4, func_020312CC, func_020312F8, func_02031324, func_02031330, func_0203133C, func_02031348, func_02031354, func_020313A0, func_020313EC, func_020314B8, func_020314DC, func_020314F4, func_02031538, func_02031590, func_0203159C, func_020315D4, func_020315F0
 * address:  0x0203129C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146990 0x02146990 data
 *   data_020A783C  0x020A783C  data
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020882D0       0x020882D0  arm
 *   func_02030734       0x02030734  arm
 *   func_02031538_File  0x020A783C  data
 *   func_020307B0  0x020307B0  arm
 *   func_0203159C_File 0x020A783C  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 */

struct Obj020314F4;
struct S020314DC;
struct S020314B8;
struct Obj02031538;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct Node Node;

struct Node {
    u32 pad[6];
    Node *prev;
    Node *next;
};

typedef struct {
    u16 heap;
    u16 pad02;
    u32 f04;
    Node *node;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
} Obj;

struct S020314B8 {
    char  pad[8];
    void *field8;
};

struct S020314DC {
    char pad[0x10];
    u32  field10;
    u32  field14;
    u32  field18;
    u32  field1c;
};

struct Obj020314F4 {
    u16 f00;
    u16 pad02;
    u32 pad04;
    void *buffer;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Obj02031538 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Obj0203159C {
    u32 pad00[5];
    void *buffer;
};

struct S020315D4 {
    char  pad[0x14];
    void *field14;
};

typedef u32 (*ProcFunc)(void *proc, u32 *seq, u32 pwork, u32 work);

typedef struct {
    ProcFunc init;
    ProcFunc main;
    ProcFunc end;
} ProcData;

typedef struct {
    const ProcData *data;
    u32 ovl;
    u32 seq;
    u32 subseq;
    u32 pwork;
    u32 work;
} Proc;

typedef signed int     s32;

struct Obj03442 {
    unsigned short f0;
    unsigned char pad_2[2];
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020882D0(void *p);
extern void ENV_SetResourceSet(void *p);
extern u32 func_020307B0(void *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
void func_0203129C(int a0);
int func_020312B4(void);
void func_020312CC(u32 a1, u32 a2, u32 a3);
void func_020312F8(u32 a1, u32 a2, u32 a3);
void *func_02031324(int a0);
unsigned int func_02031330(void *p);
void sub_0203133C(struct S020314B8 *p);
void func_02031348(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);
void *func_02031354(int a0);
Node *func_020313A0(Obj *p);
u32 func_020313EC(Obj *p);
void sub_020314B8(struct S020314B8 *p);
void sub_020314DC(struct S020314DC *p, u32 a, u32 b, u32 c);
void func_020314F4(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);
struct Obj02031538 *func_02031538(u32 a0, u32 a1, u32 a2, u32 heap);
void func_02031590(void *ptr);
void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
void sub_020315D4(struct S020315D4 *p);
u32 func_020315F0(Proc *p);
extern void *g_02146990;
extern char data_020A783C[];
extern const char func_02031538_File[];
extern const char func_0203159C_File[];


void func_0203129C(int a0)
{
    g_02146990 = func_02031354(a0);
}


/*
 * Tail-call forwarder passing g_02146990 to func_020313EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020312B4.c \
 *       --func func_020312B4 --addr 0x020312B4 --cc 1.1p1 --arm
 */
int func_020312B4(void)
{
    return func_020313EC(g_02146990);
}


/*
 * Forwarder: passes the object held in g_02146990 to func_020314F4 with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/func_020312CC.c \
 *       --func func_020312CC --addr 0x020312CC --cc 1.1p1 --arm
 */
void func_020312CC(u32 a1, u32 a2, u32 a3)
{
    func_020314F4(g_02146990, a1, a2, a3);
}


/*
 * Forwarder: passes the object held in g_02146990 to sub_020314DC with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/func_020312F8.c \
 *       --func func_020312F8 --addr 0x020312F8 --cc 1.1p1 --arm
 */
void func_020312F8(u32 a1, u32 a2, u32 a3)
{
    sub_020314DC(g_02146990, a1, a2, a3);
}


void *func_02031324(int a0)
{
    return func_02031354(a0);
}


unsigned int func_02031330(void *p)
{
    return func_020313EC(p);
}


/*
 * A four-instruction tail call to sub_020314B8
 * (src/matched/sub_020314B8.c, this same packet), attested by the
 * `matched` class: sub_020314B8's own EXACT entry pins its address, and
 * this call is the only branch to it found in the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203133C.c \
 *       --func sub_0203133C --addr 0x0203133C --cc 1.1p1
 */
void sub_0203133C(struct S020314B8 *p)
{
    sub_020314B8(p);
}


void func_02031348(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3)
{
    func_020314F4(obj, a1, a2, a3);
}


/*
 * Allocates a 0x20-byte node and lays down a sentinel ring: the first
 * halfword is the caller's key, +4 and +0x14 hold -1 (the two ends of a list
 * with no members) and every other word is 0.  The linker merges the two
 * adjacent zero stores at +4/+8 into one `stmib r0, {r1, r4}`.
 *
 * The first argument handed to func_02030734 is the caller's own parameter -
 * the original never writes r0 before the call, so r0 still holds a0.  A
 * literal first argument makes the compiler materialise it and shifts the
 * whole prologue.
 *
 * The pool word 0x020A783C is a `literal` site: it appears in ten other
 * pools in the image, e.g. 0x0203158C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031354.c \
 *       --func func_02031354 --addr 0x02031354 --cc 1.1p1 --arm
 */
void *func_02031354(int a0)
{
    char *p = func_02030734(a0, 0x20, 0, (const char *)((int)data_020A783C), 0xc5);

    ((struct Obj03442 *)p)->f0 = a0;
    ((struct Obj03442 *)p)->f4 = -1;
    ((struct Obj03442 *)p)->f8 = 0;
    ((struct Obj03442 *)p)->fC = 0;
    ((struct Obj03442 *)p)->f10 = 0;
    ((struct Obj03442 *)p)->f14 = -1;
    ((struct Obj03442 *)p)->f18 = 0;
    ((struct Obj03442 *)p)->f1C = 0;
    return p;
}


Node *func_020313A0(Obj *p)
{
    Node *n = (Node *)func_02031538(p->f14, p->f18, p->f1c, p->heap);

    n->prev = p->node;
    p->node->next = n;
    p->node = n;
    p->f0c = 0;
    p->f14 = 0xFFFFFFFF;
    p->f18 = 0;
    p->f1c = 0;
    return n;
}




/*
 * procsys.c: advance the process chain one frame.  A pending call at +0xC
 * is pushed first (func_020313A0); then the current process at +8 runs one
 * step (func_020315F0) and, when it finishes, is freed and replaced either
 * by a freshly built process from the parked parameters at +0x14..+0x1C
 * (+0x10 set) or by its parent.
 *
 * The earlier 12-byte residue (docs/notes/pkt_020313EC.c.txt) was the
 * `prev = p->node->prev;` load written once above the test: written as
 * the first statement of BOTH arms, the compiler hoists the common load
 * below the compare, which is the image's order (ldr f10, cmp, ldr node,
 * ldr prev, beq).
 */
u32 func_020313EC(Obj *p)
{
    u32 r;
    Node *prev;

    if (p->node == 0) {
        return 0;
    }
    if (p->f0c != 0) {
        func_020313A0(p);
    }
    r = func_020315F0((Proc *)p->node);
    if (r == 1) {
        if (p->f10 != 0) {
            prev = p->node->prev;
            func_02031590(p->node);
            p->node = (Node *)func_02031538(p->f14, p->f18, p->f1c, p->heap);
            if (prev != 0) {
                prev->next = p->node;
            }
            p->node->prev = prev;
            p->f10 = 0;
            p->f14 = 0xFFFFFFFF;
            p->f18 = 0;
            p->f1c = 0;
        } else {
            prev = p->node->prev;
            func_02031590(p->node);
            p->node = prev;
            if (prev != 0) {
                prev->next = 0;
            }
        }
    }
    if (p->node == 0) {
        return 0;
    }
    return (r == 1) ? 2 : 1;
}





/*
 * Frees an owned sub-object at +8 if present, then re-registers the object
 * itself with ENV_SetResourceSet. The same shutdown/re-init shape as
 * sub_02031140 and sub_020315D4 in the neighbouring packets, all working
 * the TwlSDK ENV resource-set table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020314B8.c \
 *       --func sub_020314B8 --addr 0x020314B8 --cc 1.1p1
 */
void sub_020314B8(struct S020314B8 *p)
{
    if (p->field8 != 0) {
        func_020882D0(p->field8);
    }
    ENV_SetResourceSet(p);
}





/*
 * A four-field constructor: marks the object valid (+0x10 = 1) and stores
 * the three remaining arguments at +0x14, +0x18 and +0x1c. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020314DC.c \
 *       --func sub_020314DC --addr 0x020314DC --cc 1.1p1
 */
void sub_020314DC(struct S020314DC *p, u32 a, u32 b, u32 c)
{
    p->field10 = 1;
    p->field14 = a;
    p->field18 = b;
    p->field1c = c;
}





/*
 * procsys.c: queue a call for the process at obj, or start it now.  When
 * the +8 node already exists the three parameters are parked at +0x14..
 * +0x1C with the pending flag at +0xC; otherwise the node is built with
 * the object's own u16 head as the heap id.
 *
 * The earlier DIFF (72 against 68, docs/notes/pkt_020314F4.c.txt) was the
 * polarity, not a predication threshold: written `== 0` with the call
 * first and the stores in the else arm, the compiler predicates the else
 * arm (movne, four strne, popne) and places it ahead of the call.
 */
void func_020314F4(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3)
{
    if (obj->buffer == 0) {
        obj->buffer = func_02031538(a1, a2, a3, obj->f00);
    } else {
        obj->f0c = 1;
        obj->f14 = a1;
        obj->f18 = a2;
        obj->f1c = a3;
    }
}




/*
 * Build a 0x20-byte object from the allocator and fill its tail with the
 * three parameters.  The allocator is three-parameter with the size second
 * (see func_0203159C), plus __FILE__/__LINE__; 0x162 does not fit an ARM
 * immediate so it costs its own pool word loaded early into ip.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031538.c \
 *       --func func_02031538 --addr 0x02031538 --cc 1.1p1 --arm
 */
struct Obj02031538 *func_02031538(u32 a0, u32 a1, u32 a2, u32 heap)
{
    struct Obj02031538 *obj;

    obj = (struct Obj02031538 *)func_02030734(heap, 0x20, 0,
                                              func_02031538_File, 0x162);
    obj->f04 = a0;
    obj->f00 = a1;
    obj->f08 = 0;
    obj->f0c = 0;
    obj->f10 = a2;
    obj->f14 = 0;
    obj->f18 = 0;
    obj->f1c = 0;
    return obj;
}




void func_02031590(void *ptr)
{
    func_020307B0(ptr);
}




/*
 * Allocate the object's +0x14 buffer.  The size never reaches a register
 * of its own: it arrives in r1 and is handed straight to the allocator's
 * r1, which is the arity tell, three parameters with the size second, not
 * two with a size read from the object.
 *
 * __LINE__ is 390 and does not fit an ARM immediate, so it costs its own
 * pool word next to the __FILE__ pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203159C.c \
 *       --func func_0203159C --addr 0x0203159C --cc 1.1p1 --arm
 */
void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap)
{
    obj->buffer = func_02030734(heap, size, 0, func_0203159C_File, 390);
    return obj->buffer;
}




/*
 * Unregisters a stored resource-set pointer at +0x14 with
 * ENV_SetResourceSet and clears the field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020315D4.c \
 *       --func sub_020315D4 --addr 0x020315D4 --cc 1.1p1
 */
void sub_020315D4(struct S020315D4 *p)
{
    ENV_SetResourceSet(p->field14);
    p->field14 = 0;
}




/*
 * procsys.c: run one step of a process.  State at +8 walks 0 (load the
 * overlay at +4 unless it is -1), 1 (init callback), 2 (main callback),
 * 3 (end callback, then unload the overlay and report finished).  Each
 * callback returns 1 when its phase is done; the sub-sequence counter at
 * +0xC is passed by address and cleared on every phase change.
 */
u32 func_020315F0(Proc *p)
{
    switch (p->seq) {
    case 0:
        if (p->ovl != 0xFFFFFFFF) {
            func_02034AC4(p->ovl);
        }
        p->seq = 1;
    case 1:
        if (p->data->init(p, &p->subseq, p->pwork, p->work) == 1) {
            p->seq = 2;
            p->subseq = 0;
        }
        break;
    case 2:
        if (p->data->main(p, &p->subseq, p->pwork, p->work) == 1) {
            p->seq = 3;
            p->subseq = 0;
        }
        break;
    case 3:
        if (p->data->end(p, &p->subseq, p->pwork, p->work) == 1) {
            if (p->ovl != 0xFFFFFFFF) {
                func_02034A5C(p->ovl);
            }
            return 1;
        }
        break;
    }
    return 0;
}
