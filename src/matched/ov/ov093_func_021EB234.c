/*
 * function: func_021EB234
 * address:  0x021EB234
 * packet:   pkt_ov093_021EB234
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDBE8  0x021EDBE8  thumb  ov093
 *   func_021ED988  0x021ED988  thumb  ov093
 *   func_020452E8  0x020452E8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 pad0c[3];
    u32 f18;
    u32 pad1c[6];
    u32 f34;
    u32 f38;
    u32 f3c;
} Obj;

typedef unsigned char  u8;
extern void func_021EDBE8(char *s);
extern void func_021ED988(u8 *p);
struct Descriptor;
struct PrintSys;
struct U16Vec;
extern void func_020452E8(struct Descriptor *d);
extern void func_020403F4(u32 i);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_020307B0(void *p);

void func_021EB234(Obj *p)
{
    func_021EDBE8((char *)p);
    func_021ED988((u8 *)p);
    if (p->f08 != 0) {
        func_020452E8((struct Descriptor *)p->f08);
        p->f08 = 0;
    }
    if (p->f00 != 0) {
        func_020452E8((struct Descriptor *)p->f00);
        p->f00 = 0;
    }
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    if (p->f18 != 0) {
        func_0201C4C0((struct PrintSys *)p->f18);
        p->f18 = 0;
    }
    if (p->f3c != 0) {
        func_02045808((struct U16Vec *)p->f3c);
        p->f3c = 0;
    }
    if (p->f38 != 0) {
        func_02045808((struct U16Vec *)p->f38);
        p->f38 = 0;
    }
    func_02045808((struct U16Vec *)p->f34);
    func_020307B0(p);
}
