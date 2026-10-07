/*
 * file:     tr_ai_p01.c
 * unit:     yes
 * function: func_02187F00, func_02187FB0, func_02188080, func_021880BC
 * address:  0x02187F00
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02020F14 0x02020F14 thumb
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_0201121C 0x0201121C thumb
 *   func_0201126C 0x0201126C thumb
 *   func_0201C408 0x0201C408 thumb
 *   func_0201C328 0x0201C328 thumb
 *   func_0218A41C 0x0218A41C thumb ov096
 *   D_0218A7A0 0x0218A7A0 data
 *   D_0218A574 0x0218A574 data
 *   func_02011324 0x02011324 thumb
 *   func_0218814C 0x0218814C thumb ov096
 *   func_02188284 0x02188284 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02011264 0x02011264 thumb
 *   func_0201C3C0 0x0201C3C0 thumb
 *   func_0218A458 0x0218A458 thumb ov096
 */
#include "../../matched/include/Obj00067.h"
#include "../../matched/include/Obj13649.h"
#include "../../matched/include/Obj02152.h"

struct ScriptVm;
struct ScriptVmParams;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned long long u64;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u16 heap);
extern void *func_02020F14(u16 heap);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***p);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern u32 func_0201C408(void);
extern void func_0201C328(s32 n, u32 heap);
extern void func_0218A41C(unsigned int a);
extern void *func_02011324(struct ScriptVm *vm);
extern int func_0218814C(u8 *, u8 *);
extern int func_02188284(u8 *, u8 *);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D5B68(void *m);
extern u32 func_0203F0A8(void);
extern void func_02049238(void *);
extern u32 func_020307B0(void *p);
extern void func_02011264(void *);
extern void func_0201C3C0(void);
extern void func_0218A458(void);
void *func_02187F00(void **a, u32 b, u32 c, u32 d, u16 heap);
int func_02187FB0(u8 *a);
void func_02188080(void *a);
void func_021880BC(int a, u8 *b, int c);
extern const char D_0218A7A0[];
extern u8 D_0218A574[];

void *func_02187F00(void **a, u32 b, u32 c, u32 d, u16 heap)
{
    u8 *p;
    void *v;
    p = func_02030734(heap, 0xD8, 1, D_0218A7A0, 0x1D9);
    *(u16 *)(p + 0xA0) = heap;
    *(u32 *)(p + 0xC4) = 1;
    *(u32 *)(p + 0x40) = d;
    *(void **)(p + 0xA4) = func_020490F4(0xAB, heap);
    *(void **)(p + 0xA8) = func_02020F14(heap);
    *(void ***)(p + 0xB0) = a;
    *(u32 *)(p + 0xB4) = b;
    *(u32 *)(p + 0xB8) = c;
    *(u32 *)(p + 0x98) = func_021B8588(a);
    *(void **)(p + 0x9C) = func_021B86B8((void ***)a);
    v = func_0201121C(heap, (const struct ScriptVmParams *)D_0218A574);
    func_0201126C(v, p);
    if (func_0201C408() == 0)
        func_0201C328(0x30, heap);
    func_0218A41C(*(u16 *)(p + 0xA0));
    return v;
}

/*
 * lever: unsigned count/u64 draw reproduce the guarded high multiply;
 *   the callee result is returned through the final flag clear, keeping r0 live.
 */
int func_02187FB0(u8 *a)
{
    u8 *p;
    u32 n;
    int candidates[3];
    u64 r;
    int result;
    p = func_02011324((struct ScriptVm *)a);
    if (((struct Obj00067 *)p)->f98 == 0) {
        p[0x95] = p[0x94] ^ 1;
        return func_0218814C(a, p);
    }
    if (((struct Obj00067 *)p)->f98 == 1 || ((struct Obj00067 *)p)->f98 == 2) {
        return func_02188284(a, p);
    }
    n = 0;
    for (p[0x95] = 0; p[0x95] < 6; p[0x95]++) {
        if (p[0x95] != p[0x94] && (p[0x95] & 1) != (p[0x94] & 1)) {
            if (func_021D5B68(func_0218A2FC(p, p[0x95])) != 1)
                candidates[n++] = p[0x95];
        }
    }
    r = func_0203F0A8();
    if (n != 0)
        r = (r * n) >> 32;
    p[0x95] = candidates[r];
    result = func_0218814C(a, p);
    if (result == 0)
        p[0x47] = 0;
    return result;
}

/*
 * note: Extent ends with two-byte zero alignment padding.
 */
void func_02188080(void *a)
{
    u8 *p;
    p = func_02011324(a);
    func_02049238(((struct Obj13649 *)p)->fA4);
    func_02049238(((struct Obj13649 *)p)->fA8);
    func_020307B0(p);
    func_02011264(a);
    if (func_0201C408() == 1) func_0201C3C0();
    func_0218A458();
}


void func_021880BC(int a, u8 *b, int c)
{
    u8 *p;
    int i;
    int z;

    p = func_02011324((struct ScriptVm *)a);
    p[0] = 0;
    ((struct Obj02152 *)p)->f2 = 0;
    p[1] = 0;
    ((struct Obj02152 *)p)->f38 = 0;
    p[0x44] = 0;
    p[0x45] = 0;
    p[0x94] = c;
    ((struct Obj02152 *)p)->f3C = ((struct Obj02152 *)p)->f40;
    ((struct Obj02152 *)p)->fC8 = 4;
    z = 0;
    for (i = 0; i < 4; i++) {
        if (b[i] == 0)
            *(int *)(p + 0x14 + i * 4) = z;
        else
            *(int *)(p + 0x14 + i * 4) = 100;
        p[0x48 + i] = 100 - (u32)(((u64)func_0203F0A8() * 0x10) >> 32);
    }
    ((struct Obj02152 *)p)->fCC = (u32)(((u64)func_0203F0A8() * 0x100) >> 32);
}
