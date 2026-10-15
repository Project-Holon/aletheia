/*
 * function: SHINKA_DEMO_EFFECT_Create
 * address:  0x0220871C
 * packet:   pkt_0220871C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F7C 0x02208F7C data
 *   d_02208ED0 0x02208ED0 data
 *   func_02030734 0x02030734 arm
 *   SHINKA_DEMO_EFFECT_CreateParticle 0x0220887C thumb ov195
 *   SHINKA_DEMO_EFFECT_InitUnit 0x02208A54 thumb ov195
 *   SHINKA_DEMO_EFFECT_SetupNode 0x02208AB0 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Anim {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 f08;
    u32 f0c;
    void *ptc;
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    void *nodes;
    u32 f24;
    u32 f28;
} Anim;

extern char d_02208F7C[];
extern char d_02208ED0[];
struct Ptc;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ptc *SHINKA_DEMO_EFFECT_CreateParticle(u16 heap, u16 a, void *b);
extern void SHINKA_DEMO_EFFECT_InitUnit(char *a);
extern void SHINKA_DEMO_EFFECT_SetupNode(Anim *p);

Anim *SHINKA_DEMO_EFFECT_Create(u16 heap, u32 x)
{
    Anim *p = func_02030734(heap, sizeof(Anim), 1, d_02208F7C, 0x150);

    p->heap = heap;
    p->f04 = x;
    if (x == 0)
        p->f08 = 0;
    else
        p->f08 = 7;
    p->f0c = 0;
    p->ptc = SHINKA_DEMO_EFFECT_CreateParticle(p->heap, 9, d_02208ED0);
    SHINKA_DEMO_EFFECT_InitUnit((char *)p);
    SHINKA_DEMO_EFFECT_SetupNode(p);
    return p;
}
