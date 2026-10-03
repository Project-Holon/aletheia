/*
 * function: func_021FD9F0
 * address:  0x021FD9F0
 * packet:   pkt_ov094_021FD9F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02051774  0x02051774  arm
 *   func_0205189C  0x0205189C  arm
 *   func_02051A2C  0x02051A2C  arm
 *   func_02051A24  0x02051A24  arm
 *   func_021FDA28  0x021FDA28  thumb  ov094
 */
typedef struct {
    char pad00[0x0c];
    int k0c;                /* 0x0c */
    char pad10[0x2c];
    int k3c;                /* 0x3c */
} State;

extern State *func_02051774(void *p);
typedef unsigned int   u32;
struct Obj;
extern void func_0205189C(struct Obj *o, u32 v);
extern void func_02051A2C(void *p, State *s);
extern void func_02051A24(void *p, void (*fn)(void));
extern void func_021FDA28(void);

void func_021FD9F0(void *p)
{
    State *s = func_02051774(p);

    if (s->k3c != 0 && s->k0c < 0)
        func_0205189C(p, 0x800);
    func_02051A2C(p, s);
    func_02051A24(p, func_021FDA28);
}
