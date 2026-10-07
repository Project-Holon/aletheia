/*
 * function: func_021F34C8
 * address:  0x021F34C8
 * packet:   pkt_021F34C8
 * region:   ov032
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_02025774  0x02025774  thumb
 *   func_0202570C  0x0202570C  thumb
 *   func_020437AC  0x020437AC  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef struct {
    char _pad0[0xc];
    unsigned f0c;
    unsigned f10;
    unsigned f14;
    unsigned f18;
    unsigned f1c;
    unsigned f20;
    unsigned f24;
} T_021F34C8;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Grid;
struct Obj;
struct Obj020437AC;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02025774(u8 *g, u32 a);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);

void func_021F34C8(char *a0, int a1)
{
    T_021F34C8 *p = (T_021F34C8 *)(a0 + 0x1B8 + a1 * 0x34);

    func_02045808((struct U16Vec *)p->f24);
    func_02045808((struct U16Vec *)p->f20);
    func_02025774((u8 *)p->f18, 0);
    func_0202570C((struct Grid *)p->f18);
    func_020437AC((struct Obj020437AC *)p->f1c);
    func_0204B3DC((struct Obj *)p->f14, 0);
    func_0204B3B4((struct Obj *)p->f14);
    func_0204B3DC((struct Obj *)p->f10, 0);
    func_0204B3B4((struct Obj *)p->f10);
    func_0204B3DC((struct Obj *)p->f0c, 0);
    func_0204B3B4((struct Obj *)p->f0c);
    func_02082BCC(p, 0, 0x34);
}
