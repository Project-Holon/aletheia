/*
 * function: func_02185588
 * address:  0x02185588
 * packet:   pkt_ov020_02185588
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD8 lane04): still DIFF 18 bytes. Tried `int r;` declared after z with `r = 0;` as a statement just before the 02013D5C test (same 18). Same pattern as ov020 02186470: the parameter loses r4 to a later value (owner/r here, a0/id there); the image keeps the parameter in r4 and gives z the owner register.
 * note: 2026-10-05 (wD7 lane14): still DIFF 18 bytes. Tried: the v.x update written in both arms of the e != 0 test (123). Matched siblings 02185534/02185458 (same 020122C0/020124E8/02184CEC/020142A4/02014184 chain) give no new lever: they pass a parameter to 020142A4, here it is a literal 0. Residue unchanged: owner/r colour swap and the asrs/ldr order at the 02014184 call.
 *
 * note: 2026-10-05 (wD6 lane13): not improved, 18 bytes. Checked callee arities (020124E8, 02012B58, 020142A4, 02012138, 02013D5C, 02184CEC, 02158344, 020120F4): no hidden arguments. Tried: literal 0 instead of z (same), s16 return for 020142A4 (44 B), an s16 count local (42 B), int count parameter (same), r = 0 in an else arm (same), v.x update in each arm (123 B), the e/r block as a static inline helper (same).
 *
 * note: 2026-10-05 (wD5 lane17): still DIFF 18 bytes. New tests: count as an int local with (s16) cast (worse, 168 bytes), r declared inside the if block (same 18 bytes: the movs r5,#0 is hoisted regardless). Residue unchanged: owner/r colour swap plus asrs/ldr order at the 02014184 call.
 * 2026-10-05 (wD4 lane19): still DIFF 18 bytes. Tried t-local for the lo-minus-getter chain (4 bytes worse), z shared with r init, r declared first, ctx/node/x assigned after declarations: no change or worse. Residue stays the owner/r colour swap (r4/r5) plus the asrs/ldr order at the 02014184 call.
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
 *
 * 2026-10-04 (wD2 lane 02): improved from 172 to 164 bytes (size now matches): func_02014184 takes a u32 id (the
 * original passes the spilled id with no halfword truncation). 18 bytes differ now, all one pattern: owner/r colours
 * swapped (original owner=r4, r=r5; draft owner=r5, r=r4), plus one asrs/ldr ordering at the 02014184 call setup.
 * Tried: r declared after z and assigned just before the branch (same), r declared first (worse), v.x update moved
 * inside the e != 0 block (much worse). Earlier: bitfield lo:3 for the &7, z=0 local for the zero stores.
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
extern void func_02014184(void *r, u32 id, s16 count, u32 a, u32 b, u32 c);
extern void func_0218466C(void);

void *func_02185588(void *owner, u32 id, const V3 *pos)
{
    V3 v = *pos;
    void *ctx = func_020120F4((const struct Ctx *)owner);
    void *node = func_020122C0(owner, 0, (void *)func_0218466C, 0x9C);
    char *x = func_020124E8((struct Obj *)node);
    int r = 0;
    int z;

    if (func_02013D5C(id) == 1) {
        E *e = (E *)func_02158344(func_02012138((const struct Ctx *)owner));
        if (e != 0) {
            r = e->lo;
            r -= func_02012B58(ctx);
            if (r < 0)
                r += *(u8 *)((char *)e + 0x902);
        }
        v.x += (u32)r << 22;
    }
    func_02184CEC(x, owner);
    z = 0;
    func_02014184(x + 0x10, id, (s16)func_020142A4(z), v.x, v.y, v.z);
    *(u32 *)(x + 0x2C) = z;
    *(u32 *)(x + 0x40) = z;
    return node;
}
