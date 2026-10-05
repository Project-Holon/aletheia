/*
 * function: func_02185588
 * address:  0x02185588
 * packet:   pkt_ov020_02185588
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wD9r lane42): EXACT. Two source facts closed the last 18 bytes:
 *   (1) id is a u16 parameter, and func_02014184 takes a u16 id (its matched definition in
 *       src/matched/arm9/func_02014184.c). This fixed the asrs/ldr order at the 02014184 call.
 *   (2) the e->lo bitfield is read into its own block local (`int lo = e->lo; r = lo - getter;`),
 *       the same shape as sibling 02185140 (`r2 = r5 - func_02012B58(r4)`). This fixed the
 *       owner/r colour swap (owner r4, r r5).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_0218466C  0x0218466C  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int   u32;

typedef struct E { char pad[0x86]; u16 lo : 3; u16 hi : 13; } E;

typedef struct V3 { u32 x, y, z; } V3;

struct Desc;
struct Obj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_02013D5C(u32 a);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern u8 func_02012B58(const void *p);
extern void func_02184CEC(void *a, void *b);
extern int func_020142A4(int a);
extern void func_02014184(void *r, u16 id, s16 count, u32 a, u32 b, u32 c);
extern void func_0218466C(void);

void *func_02185588(void *owner, u16 id, const V3 *pos)
{
    V3 v = *pos;
    void *ctx = func_020120F4((const struct Ctx *)owner);
    void *node = func_020122C0(owner, 0, (void *)func_0218466C, 0x9C);
    char *x = func_020124E8((struct Obj *)node);
    int r = 0;

    if (func_02013D5C(id) == 1) {
        E *e = (E *)func_02158344(func_02012138((const struct Ctx *)owner));
        if (e != 0) {
            int lo = e->lo;
            r = lo - func_02012B58(ctx);
            if (r < 0)
                r += *(u8 *)((char *)e + 0x902);
        }
        v.x += (u32)r << 22;
    }
    func_02184CEC(x, owner);
    func_02014184(x + 0x10, id, (s16)func_020142A4(0), v.x, v.y, v.z);
    *(u32 *)(x + 0x2C) = 0;
    *(u32 *)(x + 0x40) = 0;
    return node;
}
