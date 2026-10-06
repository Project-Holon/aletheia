/*
 * file:     procsys_p03.c
 * unit:     yes
 * function: func_02031538, func_02031590, func_0203159C, func_020315D4, func_020315F0
 * address:  0x02031538
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
 *   func_02030734       0x02030734  arm
 *   func_02031538_File  0x020A783C  data
 *   func_020307B0  0x020307B0  arm
 *   func_0203159C_File 0x020A783C  data
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 */
typedef unsigned int u32;

typedef unsigned short u16;

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void ENV_SetResourceSet(void *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
struct Obj02031538 *func_02031538(u32 a0, u32 a1, u32 a2, u32 heap);
void func_02031590(void *ptr);
u32 func_020315F0(Proc *p);
extern const char func_02031538_File[];
extern const char func_0203159C_File[];


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
