/*
 * file:     btl_server_p64.c
 * unit:     yes
 * function: func_021C4B8C, func_021C4B9C, func_021C4BAC, func_021C4C24
 * address:  0x021C4B8C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06898D54 0x06898D54 thumb ov095
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021EF934 0x021EF934 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 */
#include "../../matched/include/Obj21095.h"
#include "../../matched/include/Obj21096.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021EF934(int, int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C4C40(int, void *);
void func_021C4B8C(u8 *p);
void func_021C4B9C(int v, int k, u8 *p);
void func_021C4BAC(u8 *p, int k, int v);
void func_021C4C24(u8 *p);


/*
 * C tail call through r3 into the ov095 walker func_06898D54 (ov095 is
 * loaded in VRAM at 0x0689xxxx), with the ov093 callback func_021C4B9C.
 * Earlier notes called this a linker thunk; it is plain mwcc C.
 * 2026-10-05 (D9r lane16): every byte right; MATCH only because the ABS32
 * to func_021C4B9C needs that file's manifest shard (filed EXACT this wave).
 * Re-run after the shard lands; expected EXACT, then move to src/matched/ov.
 */
void func_021C4B8C(u8 *p)
{
    func_06898D54((void (*)(u8,  u32,  u32))func_021C4B9C, (u32)p);
}


void func_021C4B9C(int v, int k, u8 *p)
{
    func_021C4BAC(p, k, v);
}


void func_021C4BAC(u8 *p, int k, int v)
{
    int r = -1;
    switch (k) {
    case 0: r = 0x7e; break;
    case 1: r = 0x82; break;
    case 2: r = 0x86; break;
    case 3: r = 0x8a; break;
    case 4: r = 0x8e; break;
    case 5: r = 0x92; break;
    case 6: r = 0x96; break;
    case 7: r = 0x9a; break;
    case 8: r = 0x9e; break;
    case 9: break;
    case 10: break;
    case 11: r = 0xa6; break;
    case 12: r = 0xaa; break;
    case 13: r = 0xae; break;
    }
    if (r >= 0) {
        func_021CD64C(((struct Obj21095 *)p)->fC, 0x5a, r, v, 0xffff0000);
    }
}

/*
 * The extent continues into the existing SDK CallbackForJpeg at 021C4C40.
 * DWC_StartUtilityEx takes two full-word payloads; the original passes
 * the callback address and p unchanged in r0/r1.
 */
void func_021C4C24(u8 *p)
{
    func_021EF934((int)func_021C4C40, (int)p);
    func_021CD4B0(((struct Obj21096 *)p)->fC, 47, 0);
}
