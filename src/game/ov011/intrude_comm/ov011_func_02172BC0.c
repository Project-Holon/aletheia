/*
 * function: func_02172BC0
 * address:  0x02172BC0
 * packet:   pkt_ov011_02172BC0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The call to arm9 0x02008494 (an unlabelled 32-byte copy leaf) is attested
 * by its own EXACT shard, pkt_02008494.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   str_02177000   0x02177000  data  ov011  a1
 *   func_02167518  0x02167518  thumb  ov010
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_0217576C  0x0217576C  thumb  ov011
 *   func_02173590  0x02173590  thumb  ov011
 *   func_02161F54  0x02161F54  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008494  0x02008494  thumb
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Param {
    u32   field00;
    void *field04;
    u8    pad08[6];
    u8    field0e;
} Param;

typedef struct Work {
    u32   field000;
    void *field004;
    void *field008;
    u8    pad00c[0x8fd - 0x00c];
    u8    field8fd;
    u8    pad8fe[3];
    u8    field901;
    u8    field902;
    u8    pad903[0x928 - 0x903];
    void *field928[2];
    u8    pad930[0x94c - 0x930];
} Work;

extern char  str_02177000[];
extern u32 func_02026478(void *obj);
struct BigObj;
struct Rec44;
struct Sub24;
struct U16Vec;
extern u8 *func_02012944(void *p);
extern int   func_02158590(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02167518(int a, void *b, u16 heap, int c);
extern void func_0217538C(u8 *p, int a);
extern void func_0217576C(u8 *p);
extern void  func_02173590(void *a, void *b, u32 c);
extern int func_02161F54(int a0);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02012B64(struct BigObj *p, u8 v);
extern void func_02012B8C(struct BigObj *p, u32 v);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void  func_02008494(void *a, void *b);

Work *func_02172BC0(void *unused, Param *p)
{
    void *sv;
    void *bag;
    u32 mode;
    Work *w;
    int i;
    u8 j;

    sv = (void *)func_02026478(p->field04);
    bag = func_02012944(sv);
    mode = 3;
    if (p->field0e == 1 && func_02158590(sv) == 0) {
        mode = 2;
    }
    w = func_02030734(5, sizeof(Work), 1, str_02177000, 0x9a);
    w->field000 = p->field00;
    w->field004 = p->field04;
    w->field8fd = 1;
    w->field008 = func_02167518(3, (void *)p->field00, 5, 0);
    w->field902 = 1;
    w->field901 = 1;
    func_0217538C((u8 *)w, 4);
    func_0217576C((u8 *)w + 0x1ac);
    func_02173590(sv, (u8 *)w + 0xc, mode);
    func_02161F54((int)((u8 *)w + 0x35c));
    for (i = 0; i < 2; i++) {
        w->field928[i] = func_020457B0(8, 5);
    }
    func_02012B64(sv, 0);
    func_02012B8C(sv, 0);
    func_02012B4C(sv, 1);
    for (j = 0; j < 3; j++) {
        func_02008494(bag, func_02012950(sv, j));
    }
    return w;
}
