/*
 * function: func_021902BC
 * address:  0x021902BC
 * packet:   pkt_ov021_021902BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02194798  0x02194798  thumb  ov021
 *   func_02031140  0x02031140  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef struct Obj {
    u16  f00;
    u16  f02;
    u16  f04;
    u16  f06;
    u32  f08;
    u32  f0c;
    Slot slot[4];
} Obj;

extern void func_020307B0(void *a);
struct PrintSys;
struct S02031140;
struct U16Vec;
extern void func_02194798(unsigned char *a);
extern void func_02031140(struct S02031140 *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020403F4(u8 a);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *ptr);

void func_021902BC(Obj *o)
{
    int i;
    Slot *s;

    i = 0;
    s = o->slot;

    if (((u32 *)o)[0x5d] != 0) {
        func_020307B0((void *)((u32 *)o)[0x5d]);
    }
    if (((u32 *)o)[0x57] != 0) {
        func_02194798((unsigned char *)(((u32 *)o)[0x57]));
    }
    if (((u32 *)o)[0x59] != 0) {
        func_02031140((struct S02031140 *)(((u32 *)o)[0x59]));
    }
    if (o->f02 != 0xff) {
        func_02040DA8(o->f02, 1, 0);
        func_020403F4(o->f02);
    }
    if (o->f04 != 0xff) {
        func_020403F4(o->f04);
    }
    do {
        if (s->f18 != 0) {
            func_02045808((struct U16Vec *)s->f18);
        }
        i++;
        s++;
    } while (i < 4);
    if (o->f0c != 0) {
        func_0201C4C0((struct PrintSys *)o->f0c);
    }
    if (o->f08 != 0) {
        func_0201D83C((void *)o->f08);
    }
    func_020307B0(o);
}
