/*
 * function: func_021C75E4
 * address:  0x021C75E4
 * packet:   pkt_ov111_021C75E4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021C8AA0  0x021C8AA0  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int x;
    int y;
    int z;
    int cell;
    int chr;
    int anm;
} ObjTemplate;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u8 pad0[0x48];
    void *res;
    void *obj[36];
    void *set[6];
} Work;

struct Obj;
extern struct Obj *func_0204B294(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, u16 f, u16 heap);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern const ObjTemplate d_021C8AA0[36];

void func_021C75E4(Work *p)
{
    ObjPos pos;
    int i;

    for (i = 0; i < 36; i++) {
        pos.x = d_021C8AA0[i].x;
        pos.y = d_021C8AA0[i].y;
        pos.z = d_021C8AA0[i].z;
        pos.f7 = 0;
        pos.pri = 0x24 - i;
        p->obj[i] = func_0204B294(p->res, (unsigned int)p->set[d_021C8AA0[i].cell], (unsigned int)p->set[d_021C8AA0[i].chr], (unsigned int)p->set[d_021C8AA0[i].anm], &pos, 0, 0x27);
        func_0204B92C(p->obj[i], 1);
    }
}
