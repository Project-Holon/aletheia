/*
 * function: TOWNMAP_TownInit
 * address:  0x021BA86C
 * packet:   pkt_ov072_021BA86C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: f3c as `if (s5) f3c = 1; else f3c = f38 && f(...);` (a nested
 * ternary cross-jumps the two `movs r0,#1` arms). TOWNMAP_GRH_GetTownInfoValue's second
 * parameter is u16 here (the caller truncates it before each bl).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   TOWNMAP_GRH_GetTownInfoValue  0x021BBB3C  thumb  ov072
 *   SYMBOL_MAP_CheckEventFlag  0x02166CD0  thumb  ov010
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   TOWNMAP_TownUnhighlight  0x021BAE44  thumb  ov072
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Pos;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern void MI_CpuFill8(void *p, int v, int n);
extern unsigned short TOWNMAP_GRH_GetTownInfoValue(char *p, int a, int b);
extern int SYMBOL_MAP_CheckEventFlag(void *a, u32 msg);
extern int TOWNMAP_TownGetField(char *p, int i);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Node;
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorBgPriority(int obj, int v);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void TOWNMAP_TownUnhighlight(W *p);

void TOWNMAP_TownInit(W *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5)
{
    Pos pos;
    u32 r;
    int i;

    MI_CpuFill8(p, 0, 0x44);
    p->f34 = 0x1000;
    p->f4 = a;
    p->f8[0] = b;
    r = TOWNMAP_GRH_GetTownInfoValue((char *)a, (u16)b, 15);
    if (r != 0xFFFF)
        p->f38 = SYMBOL_MAP_CheckEventFlag(s3, r);
    else
        p->f38 = 0;
    if (s5)
        p->f38 = 1;
    for (i = 0; i < 9; i++)
        p->f8[i + 1] = TOWNMAP_GRH_GetTownInfoValue((char *)p->f4, (u16)p->f8[0], i + 2);
    if (s5)
        p->f3c = 1;
    else
        p->f3c = p->f38 && TOWNMAP_GRH_GetTownInfoValue((char *)p->f4, (u16)p->f8[0], 12);
    r = TOWNMAP_GRH_GetTownInfoValue((char *)p->f4, (u16)p->f8[0], 16);
    if (r != 0xFFFF)
        p->f40 = SYMBOL_MAP_CheckEventFlag(s3, r) == 0;
    else
        p->f40 = 0;
    if (s5)
        p->f40 = 0;
    switch (TOWNMAP_TownGetField((char *)p, 11)) {
    case 0:
        p->f31 = 2;
        p->f30 = 1;
        break;
    case 2:
        p->f31 = 3;
        p->f30 = 0xff;
        break;
    case 1:
        p->f31 = 0xff;
        p->f30 = 0xff;
        break;
    case 3:
        p->f31 = 3;
        p->f30 = 0xd;
        break;
    case 4:
        p->f31 = 0xf;
        p->f30 = 0xe;
        break;
    case 5:
        p->f31 = 0x12;
        if (p->f38)
            p->f30 = 0x11;
        else
            p->f30 = 0x10;
        break;
    }
    if (TOWNMAP_TownGetField((char *)p, 11) != 1) {
        MI_CpuFill8(&pos, 0, 8);
        pos.x = TOWNMAP_TownGetField((char *)p, 2);
        pos.y = TOWNMAP_TownGetField((char *)p, 3);
        p->obj = (int)CLACT_CreateActor((void *)c, s0, s2, s1, &pos, 0, s4);
        CLACT_SetActorAffineMode((struct Actor *)p->obj, 2);
        CLACT_SetActorBgPriority(p->obj, 2);
        CLACT_SetActorDrawPriority((struct Node *)p->obj, 4);
    }
    TOWNMAP_TownUnhighlight(p);
}
