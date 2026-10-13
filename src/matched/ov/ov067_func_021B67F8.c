/*
 * function: TOUCHBAR_InitButton
 * address:  0x021B67F8
 * packet:   pkt_ov067_021B67F8
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   TOUCHBAR_GetGfxWord  0x021B6730  thumb  ov067
 *   gTouchBarButtonLooks     0x021B942C  data  ov067  a4
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   TOUCHBAR_OnPressPlain  0x021B6A28  thumb  ov067
 *   TOUCHBAR_SetEnabledPlain  0x021B6A68  thumb  ov067
 *   TOUCHBAR_OnPressToggle  0x021B6A44  thumb  ov067
 *   TOUCHBAR_SetEnabledToggle  0x021B6A98  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct {
    int kind;
    s16 x;
    s16 y;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 pad16;
    u32 w18;
    u32 w1C;
} Src;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 padA;
    u32 f;
    u32 g;
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
    u32 f14;
    Src src;
} Obj;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u16 pad;
} Pos;

extern Ent gTouchBarButtonLooks[];

extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern int TOUCHBAR_GetGfxWord(void *p, int i);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pos, u16 f, u16 g);
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
struct S;
extern void TOUCHBAR_OnPressPlain(u8 *p);
extern void TOUCHBAR_SetEnabledPlain(struct S *p, u32 flag);
extern void TOUCHBAR_OnPressToggle(u8 *p);
extern void TOUCHBAR_SetEnabledToggle(struct S *p, u32 flag);

void TOUCHBAR_InitButton(Obj *p, u32 a1, void *a2, Src *src, u32 a4, u16 a5)
{
    Pos pos;
    u32 v0;
    u32 v1;
    u32 v2;
    int i;

    MI_CpuFill8(p, 0, 0x38);
    p->src = *src;
    p->f4 = 1;
    MI_CpuFill8(&pos, 0, 8);
    pos.x = src->x;
    pos.y = src->y;
    if (src->kind >= 7) {
        v0 = src->h8;
        v1 = src->hA;
        v2 = src->hC;
        p->f14 = 0;
    } else {
        v0 = TOUCHBAR_GetGfxWord(a2, 1);
        v1 = TOUCHBAR_GetGfxWord(a2, 0);
        v2 = TOUCHBAR_GetGfxWord(a2, 2);
        i = src->kind;
        p->src.hE = gTouchBarButtonLooks[i].a;
        p->src.h10 = gTouchBarButtonLooks[i].b;
        p->src.h12 = gTouchBarButtonLooks[i].c;
        p->src.h14 = gTouchBarButtonLooks[i].d;
        p->src.w18 = gTouchBarButtonLooks[i].f;
        p->src.w1C = gTouchBarButtonLooks[i].e;
        p->f14 = gTouchBarButtonLooks[i].g;
    }
    p->f8 = p->src.hE;
    pos.z = p->f8;
    p->f0 = (u32)CLACT_CreateActor((void *)a1, v0, v1, v2, &pos, a4, a5);
    CLACT_SetActorAutoAnim((struct Obj *)p->f0, 1);
    switch (p->f14) {
    case 0:
        p->fC = TOUCHBAR_OnPressPlain;
        p->f10 = TOUCHBAR_SetEnabledPlain;
        break;
    case 1:
        p->fC = TOUCHBAR_OnPressToggle;
        p->f10 = TOUCHBAR_SetEnabledToggle;
        break;
    }
}
