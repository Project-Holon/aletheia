/*
 * file:     unit_020737C0_p02.c
 * unit:     yes
 * function: func_02073A60, func_02073AB4
 * address:  0x02073A60
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02073B3C    0x02073B3C  arm
 */
struct Obj;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A {
    u8  p00[0x2c];
    union {
        u32 w;
        struct { int b0 : 1; int b1 : 1; int hi : 30; } f;
    } u;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

extern void func_020894B4(u32, u32, u32, u32);
extern void func_0208C808(void *);
extern void func_0208C828(void *);
void func_02073A60(struct A *a) {
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
    if (a->u.f.b1) return;
    func_0208C808((u8 *)a + 8);
    func_0208C828((u8 *)a + 0x18);
    a->u.w |= 2u;
}

typedef unsigned int u32;

typedef struct {
    u32 unk00[0xb];
    int unk2c : 1;
} Obj02073AB4;

extern void func_02073B3C(struct Obj *o);
void func_02073AB4(Obj02073AB4 *p);


/*
 * Guards the call on bit 0 of the flags word at +0x2C, which the original reads
 * as a signed one-bit field (lsl #31 / asrs #31).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073AB4.c \
 *       --func func_02073AB4 --addr 0x02073AB4 --cc 1.1p1 --arm
 */
void func_02073AB4(Obj02073AB4 *p)
{
    if (p->unk2c != 0) {
        func_02073B3C((struct Obj *)p);
    }
}
