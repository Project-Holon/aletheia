/*
 * function: func_021BC794
 * address:  0x021BC794
 * packet:   pkt_ov021_021BC794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 */

typedef struct {
    char pad[0x34];
    void *f34;
} Obj;

typedef unsigned short u16;
extern u16 func_021BD090(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);

void func_021BC794(Obj *p)
{
    p->f34 = func_0204B100(0x1E, 1, func_021BD090((unsigned char *)p));
    func_0204B22C(p->f34, 1);
}
