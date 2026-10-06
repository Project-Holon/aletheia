/*
 * function: func_021F6CF0
 * address:  0x021F6CF0
 * packet:   pkt_ov094_021F6CF0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047504  0x02047504  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    int n;              /* 0x04 */
    void *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    char pad1c[0x58 - 0x1c];
    void *f58;
    void **f5c;
} Obj;

struct Rec;
struct Tagged;
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02046EFC(struct Tagged *p);
extern u32 func_020307B0(void *p);
extern void func_02047504(struct Rec *p);

void func_021F6CF0(Obj *o)
{
    int i;

    func_02047738(o->f18);
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            func_0204762C(o->f10[i]);
            func_02046EFC(o->fc[i]);
        }
        func_020307B0(o->f8);
        func_020307B0(o->f10);
        func_020307B0(o->fc);
    }
    func_02047504(o->f14);
    func_02046EFC(o->f0);
    func_020307B0(*o->f5c);
    func_020307B0(o->f5c);
    func_020307B0(o->f58);
    func_020307B0(o);
}
