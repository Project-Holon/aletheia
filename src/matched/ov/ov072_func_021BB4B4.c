/*
 * function: func_021BB4B4
 * address:  0x021BB4B4
 * packet:   pkt_ov072_021BB4B4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BB3E8  0x021BB3E8  thumb  ov072
 *   func_0204B404  0x0204B404  arm
 *   func_0204B84C  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Pt { u16 x; u16 y; };

extern void func_02082BCC(void *p, int v, int n);
extern void func_021BB3E8(void *p, u32 a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g, u16 h);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B84C(void *h, u32 a);
struct Actor;
struct Node;
struct Obj;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_StopActorAnim(struct Actor *a);

void func_021BB4B4(u32 *p, u32 a, u32 b, u32 c, u32 d, u16 e)
{
    struct Pt pt;

    func_02082BCC(p, 0, 0x20);
    p[4] = d;
    func_021BB3E8(p, a, b, c, 0, 0, 0x18, 3, e);
    pt.x = 0x80;
    pt.y = 0x60;
    func_0204B404((void *)p[4], (const struct Vec2 *)(&pt), 0);
    func_0204B84C((void *)p[4], 1);
    CLACT_SetActorDrawPriority((void *)p[4], 1);
    func_0204B3DC((void *)p[4], 1);
    func_0204B878((void *)p[4], 0);
    func_0204B92C((void *)p[4], 1);
    CLACT_StopActorAnim((void *)p[4]);
}
