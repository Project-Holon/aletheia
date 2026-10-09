/*
 * file:     dwc_rap_p26.c
 * unit:     yes
 * function: func_02156BA8, func_02156BC4, func_02156BD8, func_02156C00
 * address:  0x02156BA8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264 0x021A8264 data ov009
 *   func_0203D7FC 0x0203D7FC arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_021770EC  0x021770EC  arm  ov009
 *   d_021A1C60  0x021A1C60  data  ov009  a4
 */
#include "../../matched/include/Obj18653.h"
#include "../../matched/include/Obj18654.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0203D7FC(void *);
extern void *func_0203D798(void);
extern void *func_0203D7C8(u32, u32, const char *, u16);
extern void func_021770EC(u8, u32, u32);
/* * evidence: BL sites in ov099021BF6E0 target this Thumb word-run start; * full body reads nullable global +0x780 as a signed halfword, else -1. */ int func_02156BA8(void);
/* * Recursive MATCH unblocker: callee of the ov099 veneer func_021C0C7C +0008. * Coherent Thumb code only in ov009 (ov010 decodes to a pop with no push), so * the ov009 shard makes that site attest as `matched`. */ void func_02156BC4(int v);
void func_02156BD8(u32 i);
void func_02156C00(u32 a);
extern char *g_021A8264;
extern u8 d_021A1C60[];



/*
 * evidence: BL sites in ov099021BF6E0 target this Thumb word-run start;
 *   full body reads nullable global +0x780 as a signed halfword, else -1.
 */
int func_02156BA8(void)
{
    char *p=g_021A8264;
    if(p)return ((struct Obj18653 *)p)->f780;
    return -1;
}




/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C0C7C +0008.
 * Coherent Thumb code only in ov009 (ov010 decodes to a pop with no push), so
 * the ov009 shard makes that site attest as `matched`.
 */
void func_02156BC4(int v)
{
    *(u16 *)((char *)(int *)g_021A8264 + 0x782) = v;
}


void func_02156BD8(u32 i)
{
    void *p;
    p = *(void **)(g_021A8264 + i * 4 + 0x174);
    if (p != 0) {
        func_0203D7FC(p);
        *(void **)(g_021A8264 + i * 4 + 0x174) = 0;
    }
}


void func_02156C00(u32 a)
{
    u8 *p = func_0203D798();
    func_02156BD8(a);
    if (*(u32 *)(g_021A8264 + a * 4 + 0x174) == 0) {
        u32 n = 0x1000;
        *(u32 *)(g_021A8264 + a * 4 + 0x174) =
            (u32)func_0203D7C8(((struct Obj18654 *)p)->f56, n, (const char *)d_021A1C60, 0xb74);
        func_021770EC(a, *(u32 *)(g_021A8264 + a * 4 + 0x174), n);
    }
}
