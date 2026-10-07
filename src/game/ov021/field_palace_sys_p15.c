/*
 * file:     field_palace_sys_p15.c
 * unit:     yes
 * function: func_021D3384, func_021D33A8, func_021D33E0, func_021D33F8, func_021D33FC, func_021D3478
 * address:  0x021D3384
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D6C0  0x0207D6C0  arm
 *   sub_02030734    0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02012138  0x02012138  thumb
 *   func_02013D74  0x02013D74  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_0215850C  0x0215850C  thumb  ov010
 *   func_02158468  0x02158468  thumb  ov010
 *   func_020490F4  0x020490F4  arm
 *   func_02013B38  0x02013B38  thumb
 *   func_0204A39C  0x0204A39C  arm
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02049238  0x02049238  arm
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../../matched/include/Obj09759.h"
#include "../../matched/include/Obj07605.h"

struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec {
    u8 k0;
    u8 k1;
    u8 pad[2];
    u8 data[0x20];
} Rec;

extern void func_0207D6C0(u32 addr, int brightness);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02013D74(u32 key);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021D3554(void *, int);
extern int func_0215850C(int a0, int a1);
extern int func_02158468(int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02013B38(u32 id);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_02049238(void *h);
void func_021D3384(u32 *p, int main);
void *func_021D33A8(u16 heapId, void *a1, void *a2, u16 a3);
void func_021D33E0(u32 *p);
void *func_021D33F8(u32 *p);
void func_021D33FC(u8 *a0, u16 a1, u16 a2);
void func_021D3478(u8 *a, u32 id, int c, int d, u16 heap);


void func_021D3384(u32 *p, int main)
{
    if (main) {
        func_0207D6C0(0x04000050, p[0]);
    } else {
        func_0207D6C0(0x04001050, p[0]);
    }
}


/*
 * Recursive MATCH unblocker: target named by the parked ov021 func_021881D8
 * (+0110 region) and part of the field_palace_sys.c tree
 * (layout/file_anchors.txt row 021D33DC -> 0x021DE6D4).  Allocates a 0xc-byte
 * record through the debug allocator, fills two words and a zero, and hands
 * it to func_021D33FC.
 *
 * Addresses are Black-image addresses.
 */
void *func_021D33A8(u16 heapId, void *a1, void *a2, u16 a3)
{
    void *p = sub_02030734(heapId, 0xc, 1, (const char *)0x021DE6D4, 0x43);

    ((struct Obj09759 *)p)->f0 = (u32)a1;
    ((struct Obj09759 *)p)->f4 = (u32)a2;
    ((struct Obj09759 *)p)->f8 = 0;
    func_021D33FC(p, a3, heapId);
    return p;
}


void func_021D33E0(u32 *p)
{
    if (p[2] != 0) {
        func_020307B0((void *)p[2]);
    }
    func_020307B0(p);
}


/*
 * Getter: returns the word at +0x08.  Unlabelled in the listing; called
 * from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void *func_021D33F8(u32 *p)
{
    return (void *)p[2];
}


/*
 * 2026-10-02: EXACT.  The prologue and final call-setup residue of the
 * earlier draft was parameter width: a1 and a2 are u16 (a1 is the u16 key
 * func_021D3554 compares, a2 the u16 heap id of func_021D3478), which pins
 * their home stores to the front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 *
 * Recursive MATCH unblocker attempt: non-SDK dep of the matched func_021D33A8
 * (its +0010 branch target in the field_palace_sys.c tree).  Every relocation
 * resolves (0x0215850C / 0x02158468 as EXACT ov010 `matched`, 0x021D3478 as
 * `sole-ref`), the size is exact, and the logic is recovered.  The residue
 * that remained was scheduling, closed by the u16 parameters above.
 *
 * Addresses are Black-image addresses.
 */
void func_021D33FC(u8 *a0, u16 a1, u16 a2)
{
    int r6;
    int r7;
    void *r4;
    int t;
    int s;

    r6 = (int)func_02012138(((struct Obj07605 *)a0)->f0);
    if (func_02013D74(a1) != 1)
        return;
    if (r6 == 0)
        return;
    r4 = func_020120F4(((struct Obj07605 *)a0)->f0);
    r7 = func_021D3554(r4, a1);
    t = func_0215850C(r6, (int)r4);
    s = 0xffff;
    if (t == 2) {
        if (r7 == 1)
            s = 1;
        else
            s = 0;
    } else if (t == 1) {
        if (r7 == 1)
            s = 3;
        else
            s = 2;
    }
    if (s == 0xffff)
        return;
    func_021D3478(a0, s, a1, func_02158468(r6), a2);
}


/*
 * field_palace_sys.c (layout/file_anchors.txt row 021D3550 -> 0x021DE6D4).
 *
 * Addresses are Black-image addresses.
 */
void func_021D3478(u8 *a, u32 id, int c, int d, u16 heap)
{
    u32 size;
    int found;
    void *h;
    u32 i;
    Rec *p;
    u32 hv;
    u16 v;

    found = 0;
    hv = (heap & 0x7fff) | 0x8000;
    h = func_020490F4(0xe0, hv);
    v = ((int)func_02013B38((int)c) - 2) / 4 + 1;
    p = func_0204A39C(h, (u32)id, (u32)0, (u16)hv, &size);
    for (i = 1; i < size / 0x24; i++) {
        if ((v == p[i].k0 || p[i].k0 == 0xff) && (d == p[i].k1 || p[i].k1 == 0xff)) {
            found = 1;
            break;
        }
    }
    if (!found) {
        i = 0;
    }
    ((struct Obj07605 *)a)->f8 = func_02030734(heap, 0x20, 0, (const char *)0x021DE6D4, 0xd4);
    func_02082D44(p[i].data, ((struct Obj07605 *)a)->f8, 0x20);
    func_020307B0(p);
    func_02049238(h);
}
