/*
 * function: func_021C51E4
 * address:  0x021C51E4
 * packet:   pkt_ov111_021C51E4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6FA0  0x021C6FA0  thumb  ov111
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x98];
    void *obj[8];
} Anim;

typedef struct {
    u8 pad0[0x3070];
    Anim anim;
} Work;

extern void func_021C6FA0(Anim *a, int idx, u8 x, u8 y);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void func_021C51E4(Work *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0(&p->anim, 2, 0xB, 1);
        CLACT_SetActorDrawEnable(p->anim.obj[4], 0);
        CLACT_SetActorDrawEnable(p->anim.obj[5], 0);
    } else {
        func_021C6FA0(&p->anim, 2, 0xD, 1);
        CLACT_SetActorDrawEnable(p->anim.obj[4], 1);
        CLACT_SetActorDrawEnable(p->anim.obj[5], 1);
    }
}
