/*
 * file:     scrcmd_proc_p07.c
 * unit:     yes
 * function: func_0215C700, func_0215C72C
 * address:  0x0215C700
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
 *   func_020307B0 0x020307B0 arm
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0202E474  0x0202E474  thumb
 *   func_02030734  0x02030734  arm
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov070_id       0x00000046  data
 *   d_021BB96C     0x021BB96C  data  ov070 a4
 */
struct Pair;
struct BigObj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Outputs { u16 *first; u16 *second; } Outputs;

typedef struct Context { char pad[0x34]; u32 first; u32 second; } Context;

typedef struct Pair { Context *context; Outputs *outputs; } Pair;

typedef unsigned char u8;

extern u32 func_020307B0(void *p);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5F4(void *vm);
extern u32 func_02159B10(void *c, void *vm);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *vm);
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
void func_0215C700(Pair *p);
int func_0215C72C(void *c, void *vm);
extern const char d_021728F0[];
extern const u8 d_021BB96C[];
extern u8 ov070_id[];

/*
 * lever: Stores in both if/else arms retain the zero-first full branch;
 * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33.
 */
void func_0215C700(Pair *p)
{
    Context *c = p->context;
    Outputs *o = p->outputs;
    if (c->first == 0)
        *o->first = B_FALSE;
    else
        *o->first = B_TRUE;
    *o->second = c->second;
    func_020307B0(p->outputs);
    func_020307B0(p->context);
}


/*
 * Script command: reads a selector and two words, maps the selector
 * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built
 * from func_0202E474 with an 8-byte hand-off record.
 *
 * 2026-10-05 (wave D9): EXACT. The ov070 token on the d_021BB96C data line
 * (the proc table lives in ov070, the overlay this function opens) gave the
 * witness; ov070_id then resolved through the overlay_id walk (func_0215C63C
 * is a registered consumer). Source unchanged.
 */
int func_0215C72C(void *c, void *vm)
{
    u32 sel;
    u32 a;
    u32 b;
    u32 k;
    void *work;
    u32 *h;

    func_0215A5DC(vm);
    func_0215A5F4(vm);
    sel = func_02159B10(c, vm);
    a = (u32)func_02159AE8(c, vm);
    b = (u32)func_02159AE8(c, vm);
    if (sel == 0)
        k = 4;
    else if (sel == 1)
        k = 5;
    else
        k = 0;
    work = func_0202E474((const struct BigObj *)func_0215A5E4(vm), 0, k, 4);
    h = func_02030734(4, 8, 1, d_021728F0, 0x118);
    h[0] = a;
    h[1] = b;
    func_0215C63C(c, vm, (u32)ov070_id, d_021BB96C, work, (u32)func_0215C700, (u32)h);
    return 1;
}
