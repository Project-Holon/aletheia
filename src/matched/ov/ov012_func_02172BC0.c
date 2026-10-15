/*
 * function: UNION_COMM_Create
 * address:  0x02172BC0
 * packet:   pkt_ov012_02172BC0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   func_02030734  0x02030734  arm
 *   UNION_COMM_InitSituation  0x021734E0  thumb  ov012
 *   UNION_COMM_InitChatLog  0x0217365C  thumb  ov012
 *   REGULATION_Create  0x0200ADF0  thumb
 *   str_02175600   0x02175600  data  ov012  a1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 field0;
    u8  pad004[0x282a - 4];
    u8  f282a;
    u8  pad282b[0x283e - 0x282b];
    u8  f283e;
    u8  pad283f[0x30e0 - 0x283f];
    u8  f30e0[0x352c - 0x30e0];
    u32 f352c;
    u8  pad3530[0x3570 - 0x3530];
} Work;

extern char str_02175600[];
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Work;
extern void UNION_COMM_InitSituation(struct Work *w);
extern void UNION_COMM_InitChatLog(u8 *p);
struct Reg;
extern struct Reg *REGULATION_Create(u32 heap);

Work *UNION_COMM_Create(u32 a)
{
    Work *w;

    GFL_HEAP_CreateChildHeap(4, 0x41, 0x8a00);
    w = func_02030734(0x41, sizeof(Work), 1, str_02175600, 0x89);
    w->field0 = a;
    UNION_COMM_InitSituation((struct Work *)w);
    w->f283e = 1;
    UNION_COMM_InitChatLog(w->f30e0);
    w->f352c = (u32)REGULATION_Create(0x41);
    w->f282a = 1;
    return w;
}
