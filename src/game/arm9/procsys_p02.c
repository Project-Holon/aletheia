/*
 * file:     procsys_p02.c
 * unit:     yes
 * function: func_020313EC, func_020314B8, func_020314DC, func_020314F4
 * address:  0x020313EC
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
 *   func_020313A0  0x020313A0  arm
 *   func_020315F0  0x020315F0  arm
 *   func_02031590  0x02031590  arm
 *   func_02031538  0x02031538  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020882D0       0x020882D0  arm
 */
struct Obj02031538;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

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

extern int func_020313A0(int a0);
extern u32   func_020315F0(Node *n);
extern void func_02031590(void *ptr);
extern struct Obj02031538 *func_02031538(u32 a0, u32 a1, u32 a2, u32 heap);
extern void func_020882D0(void *p);
extern void ENV_SetResourceSet(void *p);
u32 func_020313EC(Obj *p);
void sub_020314B8(struct S020314B8 *p);
void sub_020314DC(struct S020314DC *p, u32 a, u32 b, u32 c);
void func_020314F4(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);


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
        func_020313A0((int)p);
    }
    r = func_020315F0(p->node);
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
