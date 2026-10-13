/*
 * function: TOWNMAP_CursorInit
 * address:  0x021BA04C
 * packet:   pkt_ov072_021BA04C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   func_020355C4  0x020355C4  arm
 */

typedef unsigned short u16;

typedef struct {
    void *f0;
    void *f4;
    u16 f8;
    u16 fA;
    int pad[3];
} S;

extern void MI_CpuFill8(void *p, int v, int n);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Node;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorBgPriority(void *a, int b);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u8 func_020355C4(void);

void TOWNMAP_CursorInit(S *p, void *a, void *b)
{
    int z = 0;
    int one;

    MI_CpuFill8(p, 0, 0x18);
    p->f0 = a;
    p->f4 = b;
    p->f8 = 0x80;
    p->fA = 0x60;
    CLACT_AddActorSurfacePos(a, (const struct Vec2 *)(&p->f8), 0);
    CLACT_AddActorSurfacePos(p->f4, (const struct Vec2 *)(&p->f8), 0);
    CLACT_SetActorDrawEnable(p->f0, 1);
    one = 1;
    CLACT_SetActorDrawEnable(p->f4, 0);
    CLACT_SetActorBgPriority(p->f0, 0);
    CLACT_SetActorDrawPriority(p->f0, 0);
    CLACT_SetActorBgPriority(p->f4, 2);
    CLACT_SetActorDrawPriority(p->f4, 3);
    CLACT_SetActorAutoAnim(p->f4, 1);
    if (func_020355C4() == 0) {
        CLACT_SetActorDrawEnable(p->f0, one);
    } else {
        CLACT_SetActorDrawEnable(p->f0, z);
    }
}
