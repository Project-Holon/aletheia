/*
 * function: FIELD_EFFECT_InitObjectSystem
 * address:  0x021ABF68
 * packet:   pkt_ov021_021ABF68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   FIELD_EFFECT_CreateObjectMgr  0x021ABFFC  thumb
 *   d_021DE018  0x021DE018  data  a4
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T;

typedef unsigned int   u32;
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Ctx;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern char *FIELD_EFFECT_CreateObjectMgr(u16 heap, int b, int cnt);
extern char d_021DE018[];

void FIELD_EFFECT_InitObjectSystem(T *t, int n)
{
    t->h14 = n;
    t->f18 = func_02030734(t->h4, func_02030CB0(n), 0, d_021DE018, 0x1db);
    t->f1c = (int)func_02030CBC(n, t->f18);
    t->f20 = (int)FIELD_EFFECT_CreateObjectMgr(t->h4, t->f1c, n);
}
