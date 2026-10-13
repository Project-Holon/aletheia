/*
 * function: func_021BAE9C
 * address:  0x021BAE9C
 * packet:   pkt_ov072_021BAE9C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B84C  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

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
} W;

struct Node;
struct Obj;
extern int func_021BA774(char *p, int i);
extern void func_02082BCC(void *p, int v, int n);
struct Obj;
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pos, unsigned short f, unsigned short g);
extern void func_0204B84C(int obj, int v);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void func_0204B878(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B3DC(struct Obj *obj, unsigned int v);

void func_021BAE9C(W *p, int a, int b, int c, int s0, int s1, u16 s2)
{
    Pos pos;

    func_02082BCC(p, 0, 8);
    p->f4 = a;
    func_02082BCC(&pos, 0, 8);
    if (a != 0) {
        pos.x = func_021BA774((char *)a, 2);
        pos.y = func_021BA774((char *)a, 3);
    }
    p->obj = (int)func_0204B294((void *)b, c, s1, s0, &pos, 0, s2);
    func_0204B84C(p->obj, 2);
    CLACT_SetActorDrawPriority((struct Node *)p->obj, 2);
    func_0204B878((struct Obj *)p->obj, 6);
    func_0204B92C((struct Obj *)p->obj, 1);
    if (a == 0) {
        func_0204B3DC((struct Obj *)p->obj, 0);
    }
}
