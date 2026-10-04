/*
 * function: func_021D55AC
 * address:  0x021D55AC
 * packet:   pkt_ov118_021D55AC
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3DC(u32, int);
extern void func_0204B9A0(u32);

void func_021D55AC(void *p)
{
    u32 v = *(u32 *)((char *)*(void **)((char *)p + 0xc) + 0xb0);
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        *(u32 *)((char *)*(void **)((char *)p + 0xc) + 0xb0) =
            (u32)func_0204B294((void *)*(u32 *)((char *)p + 0x9C4),
                          *(u32 *)((char *)p + 0x8A8),
                          *(u32 *)((char *)p + 0x88C),
                          *(u32 *)((char *)p + 0x8BC),
                          &s, 0, *(u16 *)((char *)p + 0x5F4));
        func_0204B92C((struct Obj *)*(u32 *)((char *)*(void **)((char *)p + 0xc) + 0xb0), 1);
        func_0204B3DC(*(u32 *)((char *)*(void **)((char *)p + 0xc) + 0xb0), 1);
    } else {
        func_0204B9A0(v);
    }
}
