/*
 * function: func_02154560
 * address:  0x02154560
 * packet:   pkt_02154560
 * region:   ov001
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builder: guard + allocator, then a straight slab/field layout.
 *
 * symbols:
 *   func_020120F4   0x020120F4  thumb
 *   func_02012138   0x02012138  thumb
 *   func_020124E8   0x020124E8  thumb
 *   func_02026454   0x02026454  thumb
 *   func_02026400   0x02026400  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_02082BCC   0x02082BCC  arm
 *   func_02008468   0x02008468  thumb
 *   func_02030734   0x02030734  arm
 *   func_02012944   0x02012944  thumb
 *   func_02082D44   0x02082D44  arm
 *   d_021546A0      0x021546A0  data  ov001  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Comm;
struct Ctx;
struct Party;
void *func_020120F4(const struct Ctx *p);
struct Ctx;
struct Obj;
u32 func_02012138(const struct Ctx *p);
void *func_020124E8(struct Obj *p);
u32 func_02026454(void *obj);
void func_02026400(struct Comm *p);
struct Party *func_0201A920(u32 heap);
void func_02082BCC(void *p, int c, int n);
int func_02008468(void);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u8 *func_02012944(void *p);
void func_02082D44(u32 a, void *p, u32 b);

extern char d_021546A0[];

void *func_02154560(void *obj_in, void *p, int a, int b)
{
    void *obj;

    if (func_02026454((void *)func_02012138(p)))
        func_02026400((struct Comm *)func_02012138(p));
    obj = func_020124E8(obj_in);
    *(int *)((char *)obj + 0x17c) = (int)p;
    *(int *)((char *)obj + 0x3b0) = b;
    *(int *)((char *)obj + 0x3ac) = (int)func_0201A920(4);
    *(int *)((char *)obj + 0x354) = *(int *)((char *)obj + 0x3ac);
    func_02082BCC((char *)obj + 0x184, 0, 0x1b4);
    *(int *)((char *)obj + 0x184) = (int)func_020120F4(p);
    *(int *)((char *)obj + 0x198) = (int)func_02030734(4, func_02008468(), 1, d_021546A0, 0x123);
    *(int *)((char *)obj + 0x19c) = (int)func_02030734(4, func_02008468(), 1, d_021546A0, 0x124);
    func_02082D44((u32)func_02012944(func_020120F4(p)), (void *)*(int *)((char *)obj + 0x198), func_02008468());
    func_02082BCC((char *)obj + 0x368, 0, 0x28);
    *(int *)((char *)obj + 0x368) = (int)func_020120F4(p);
    *(int *)((char *)obj + 0x36c) = 0;
    *(int *)((char *)obj + 0x370) = 1;
    *(int *)((char *)obj + 0x390) = (int)func_020120F4(p);
    *(int *)((char *)obj + 0x394) = 0;
    *(int *)((char *)obj + 0x398) = 1;
    return obj;
}
