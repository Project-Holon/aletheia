/*
 * function: func_021FA2B0
 * address:  0x021FA2B0
 * packet:   pkt_021FA2B0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9EEC  0x021F9EEC  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_021FB2F0  0x021FB2F0  thumb
 *   func_021FBF04  0x021FBF04  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *str;
    int val;
} Item;

typedef struct {
    void **wins;
    u8 pad4[0xC - 4];
    u32 up;
    u32 down;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    u8 pad1C[0x30 - 0x1C];
    Item *items;
    void *num;
    u8 pad38[0x56 - 0x38];
    s16 page;
    int total;
    u8 pad5C[0x7C - 0x5C];
    u8 g[4];
} Menu;

struct Obj;
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *v, u32 k);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021FB2F0(Menu *m, int page, int total);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);

void func_021FA2B0(Menu *m, int dir)
{
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)m->down, 1);
        CLACT_SetActorAnimSeq((struct Obj *)m->down, 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = 2;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)m->up, 1);
        CLACT_SetActorAnimSeq((struct Obj *)m->up, 0x26);
        if (m->page < 2) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB2F0(m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[4], m->page, func_021F9EEC((u8 *)m->total, 4));
}
