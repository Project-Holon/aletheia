/*
 * file:     btl_server_p63.c
 * unit:     yes
 * function: func_021C4B3C, func_021C4B8C, func_021C4B9C, func_021C4BAC, func_021C4C24, func_021C4C40, func_021C4C50
 * address:  0x021C4B3C
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
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_06898D54 0x06898D54 thumb ov095
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021EF934 0x021EF934 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 *   func_021C43F0  0x021C43F0  thumb  ov093
 *   func_021C4CEC  0x021C4CEC  thumb  ov093
 *   func_021C4CFC  0x021C4CFC  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021C4D0C  0x021C4D0C  thumb  ov093
 */
#include "../../matched/include/Obj21095.h"
#include "../../matched/include/Obj21096.h"
#include "../../matched/include/Obj05192.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021EF934(int, int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C4C40(int, void *);
extern void func_021C43F0(u8 *p, u8 *a);
extern void func_021C4CEC(u8 *a);
extern u8 *func_021C4CFC(u8 *a);
extern int func_021D5B7C(void *m);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern u8 *func_021C4D0C(u8 *a);
int func_021C4B3C(u8 *p, u8 *a, u32 b, u32 c);
void func_021C4B8C(u8 *p);
void func_021C4B9C(int v, int k, u8 *p);
void func_021C4BAC(u8 *p, int k, int v);
void func_021C4C24(u8 *p);
void CallbackForJpeg(int result, void *arg);
void func_021C4C50(u8 *p, int k);



int func_021C4B3C(u8 *p, u8 *a, u32 b, u32 c)
{
    int r;
    func_021D74F8(9801);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x1d, b);
    func_021D75A8(0x32, c);
    func_021D70F0(p, 0x6b);
    r = func_021D775C(0x32);
    func_021D7540(9807);
    return r;
}




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



void CallbackForJpeg(int result, void *arg)
{
    func_021C4C50(arg, result);
}



void func_021C4C50(u8 *p, int k)
{
    int r = -1;
    u8 *q;
    switch (k) {
    case 0: break;
    case 1: r = 0x74; break;
    case 2: r = 0x76; break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: r = 0xb3; break;
    case 7: r = 0xb5; break;
    }
    if (r >= 0) {
        func_021CD64C(((struct Obj05192 *)p)->fC, 0x5a, r, 0xffff0000);
    }
    func_021CD4B0(((struct Obj05192 *)p)->fC, 0x24, (u8)k);
    if (k == 7) {
        func_021C43F0(p, *(u8 * *)&((struct Obj05192 *)p)->f868);
        func_021C4CEC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        q = func_021C4CFC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        while (q) {
            if (func_021D5B7C(q)) {
                func_021C195C(p, q, 0);
            }
            q = func_021C4D0C(*(u8 * *)&((struct Obj05192 *)p)->f868);
        }
    }
}
