/*
 * file:     worldtrade_adapter_p17.c
 * unit:     yes
 * function: func_021FE6A0, func_021FE744, func_021FE7F0
 * address:  0x021FE6A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C8B18 0x021C8B18 arm ov114
 *   func_021C8BC4 0x021C8BC4 arm ov114
 *   func_02082BCC 0x02082BCC arm
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_02006210  0x02006210  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_021FF474 0x021FF474 thumb ov135
 */
#include "../../matched/include/Obj01161.h"
#include "../../matched/include/Obj04907.h"
#include "../../matched/include/Obj03832.h"

typedef signed char s8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { short id; s8 a, b, c, d; u8 mode, flag; } Request;

typedef signed int s32;

extern void func_021C8B18(void *, int, void *);
extern void func_021C8BC4(const void *p, unsigned int x);
extern void func_02082BCC(void *, int, u32);
extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_02006210(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_021FFB20(u8 *p, int count, int flag);
extern void func_021FF474(void *, void *, int, void *);
int func_021FE6A0(u8 *p);
int func_021FE744(u8 *p);
int func_021FE7F0(char *p);

int func_021FE6A0(u8 *p)
{
    Request q;
    if (((struct Obj01161 *)p)->fF84 == 0) {
        func_021C8B18(p + 0xb56, 7, p + 0x20c);
    } else {
        func_02082BCC(&q, 0, 8);
        q.id = *(short *)&((struct Obj01161 *)p)->fB56;
        q.a = *(s8 *)&((struct Obj01161 *)p)->fB58;
        q.b = *(s8 *)(p + 0xb59);
        q.c = *(s8 *)&((struct Obj01161 *)p)->fB5A;
        q.d = *(s8 *)(p + 0xb5b);
        q.mode = 7;
        q.flag = ((struct Obj01161 *)p)->fF84;
        func_021C8BC4(&q, (unsigned int)(p + 0x20c));
    }
    ((struct Obj01161 *)p)->fB5C = ((struct Obj01161 *)p)->fB56;
    ((struct Obj01161 *)p)->fB5E = ((struct Obj01161 *)p)->fB58;
    ((struct Obj01161 *)p)->fB60 = ((struct Obj01161 *)p)->fB5A;
    ((struct Obj01161 *)p)->fB64 = *(u32 *)&((struct Obj01161 *)p)->fF84;
    ((struct Obj01161 *)p)->fF8C = 0;
    ((struct Obj01161 *)p)->f28 = 18;
    ((struct Obj01161 *)p)->fE1A = 0;
    return 2;
}


/*
 * 23-slot switch on the 0x021C86A8 index (case value = index + 15, so the
 * bound is 22): the +0xd0 archive with state 0x13 for indexes 15..22, the
 * state-0x1e group with the four redraw calls for 1 and 13, the shared redraw
 * for 2 and the state-0x16 pair for 0 and 3; 4..12 and 14 are table holes.
 * The counter in the else arm compares against 0x1c20, not 0xe10.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_021FE744(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj04907 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            ((struct Obj04907 *)p)->fD0 = n;
            ((struct Obj04907 *)p)->f28 = 0x13;
            break;
        case 1:
        case 13:
            func_02006210();
            ((struct Obj04907 *)p)->f28 = 0x1e;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_02006210();
            func_021F513C(p);
            break;
        case 0:
        case 3:
            func_02006210();
            ((struct Obj04907 *)p)->f28 = 0x16;
            break;
        }
    } else {
        if (++((struct Obj04907 *)p)->fF8C == 0x1c20) {
            func_02006210();
            func_021F513C(p);
        }
    }
    return 2;
}

int func_021FE7F0(char *p)
{
    if (((struct Obj03832 *)p)->f12E8 == 0) {
        func_02006210();
        func_021FFB20((u8 *)p, ((struct Obj03832 *)p)->fD0, 1);
        if (((struct Obj03832 *)p)->fD0 == 0)
            func_021FF474(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 0, p + 0xfa0);
        else
            func_021FF474(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 1, p + 0xfa0);
        ((struct Obj03832 *)p)->f28 = 20;
    }
    return 2;
}
