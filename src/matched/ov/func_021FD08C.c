/*
 * function: func_021FD08C
 * address:  0x021FD08C
 * packet:   pkt_021FD08C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u8 pad0[0xBC0];
    void *res;
    void *set[3];
    u8 padBD0[0xD08 - 0xBD0];
    void *obj;
} Obj;

extern void MI_CpuFill8(void *p, int v, int n);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, unsigned short f, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void func_021FD08C(Obj *p)
{
    ObjPos pos;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = 0xD0;
    pos.y = 0x3A;
    p->obj = CLACT_CreateActor(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->obj, 1);
    CLACT_SetActorAnimSeq(p->obj, 0x24);
    CLACT_SetActorDrawEnable(p->obj, 1);
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}
