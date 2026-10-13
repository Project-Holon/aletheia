/*
 * function: FRAME_LIST_Delete
 * address:  0x021B796C
 * packet:   pkt_ov067_021B796C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020452E8       0x020452E8  arm
 *   BGWINFRM_Delete       0x0202CA0C  thumb
 *   func_0202EA20       0x0202EA20  thumb
 *   func_0201C4C0       0x0201C4C0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Elem2 {
    void *p;
    u32 _4;
};

struct S {
    u8 _0[0x16];
    u16 cnt16;
    u8 _18[0x28 - 0x18];
    void *f28;
    void *f2c;
    void *f30;
    void *f34;
    struct Elem2 *arr38;
    void *f3c;
    void **arr40;
    u8 count44;
};

struct WinMgr;
extern void ENV_SetResourceSet(void *p);
struct Descriptor;
struct Obj0202EA20;
struct PrintSys;
extern u32 func_020452E8(struct Descriptor *d);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_0201C4C0(struct PrintSys *p);

void FRAME_LIST_Delete(struct S *s)
{
    u32 i;

    ENV_SetResourceSet(s->f2c);
    for (i = 0; i < s->count44; i++)
        func_020452E8((struct Descriptor *)((int)s->arr38[i].p));
    ENV_SetResourceSet(s->arr38);
    BGWINFRM_Delete(s->f3c);
    if (s->cnt16 != 0) {
        for (i = 0; i < s->cnt16; i++)
            ENV_SetResourceSet(s->arr40[i]);
        ENV_SetResourceSet(s->arr40);
    }
    ENV_SetResourceSet(s->f28);
    func_0202EA20((struct Obj0202EA20 *)((int)s->f30));
    func_0201C4C0((struct PrintSys *)((int)s->f34));
    ENV_SetResourceSet(s);
}
