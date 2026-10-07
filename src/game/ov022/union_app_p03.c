/*
 * file:     union_app_p03.c
 * unit:     yes
 * function: func_02183FA8, func_02183FB8, func_0218401C, func_0218402C, func_02184060, func_021840A4, func_021840A8, func_021840AC, func_021840C8, func_021840FC, func_02184114, func_02184134, func_02184148, func_0218416C, func_02184174, func_0218417C, func_02184180, func_021841A0
 * address:  0x02183FA8
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 *   func_0203D1C0 0x0203D1C0 arm
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203CD98 0x0203CD98 arm
 */
#include "../../matched/include/Obj09764.h"
#include "../../matched/include/Obj20328.h"
#include "../../matched/include/Obj20329.h"
#include "../../matched/include/Obj20330.h"

struct Entry;
struct Link;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 w[10]; } Blk;

typedef struct { u8 pad[0x14]; u8 tab[1]; } Inner;

typedef void (*Cb)(void);

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int func_0217357C(u8 *self, const u8 *mac, u32 a2, u32 a3);
extern u32 func_0203D1C0(u32 index);
extern u32 func_0203D378(void);
extern void func_0203D1E8(u32 unused, void *arg);
extern int func_0203CD98(void);
void func_02183FA8(u8 *p, u8 index);
void func_02183FB8(u8 *self, u8 *peer, u32 idx, const Blk *src);
int func_0218401C(u8 *p);
int func_0218402C(u8 *p);
void func_02184060(u8 *s, int i);
void func_021840A4(void);
unsigned int func_021840A8(unsigned int entry);
void func_021840AC(u8 *s);
int func_021840C8(u8 *p);
void func_021840FC(u8 *p, Cb a, Cb b, void *arg);
int func_02184114(unsigned char *p);
void func_02184134(u8 *p);
void func_02184148(unsigned char *p, int a);
void func_0218416C(char *p);
void func_02184174(u8 *p);
u32 func_0218417C(u8 *p);
char *func_02184180(unsigned char *p, int i);
unsigned char func_021841A0(unsigned char *p);

/*
 * Unlabelled bit-set leaf; follower 02183FB8 is separate labelled code.
 */
void func_02183FA8(u8 *p, u8 index)
{
    p[13] = p[13] | (u8)(1 << index);
}



void func_02183FB8(u8 *self, u8 *peer, u32 idx, const Blk *src)
{
    Inner *in = (Inner *)&peer[0x2830];
    *(Blk *)(self + 0x2c + idx * 0x28) = *src;
    self[0xe] |= (u8)(1 << idx);
    if (idx != func_0203D1A4((struct Link *)func_020399A8())) {
        u32 a = func_02008554((const struct Sub0200852CObj *)src);
        u32 b = func_02008550((const struct Sub0200852CObj *)src);
        func_0217357C(in->tab, (const u8 *)src + 0x20, a, (u8)b);
    }
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s); blocker of ov012
 * func_021743A4.
 */
int func_0218401C(u8 *p)
{
    if (p[1] != 0)
        return 1;
    return 0;
}

int func_0218402C(u8 *p)
{
    int i;
    u32 m;
    for (i = 0; i < 5; i++) {
        m = 1 << i;
        if ((p[1] & m) && func_0203D1C0((u8)i) == 1 && !(p[14] & m)) return 0;
    }
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_02184060(u8 *s, int i)
{
    if (func_0203D378() == 1) {
        if ((s[0xe] & (1 << i)) && (s[4] & (1 << i))) {
            s[7] |= (u8)(1 << i);
        }
    } else {
        s[4] |= (u8)(1 << i);
        s[7] |= (u8)(1 << i);
    }
}

void func_021840A4(void)
{
}

/*
 * Unlabelled size-return leaf. Extent follower 021840AC already filed separately.
 */
unsigned int func_021840A8(unsigned int entry)
{
    return 4;
}


void func_021840AC(u8 *s)
{
    s[1] = s[1] | (u8)(1 << func_0203D1A4((struct Link *)((u32)func_020399A8())));
}


/*
 * Unlabelled leaf (prints as a .word run in asm/overlays/ov022.s); the
 * sole blocker of ov012 func_0217325C's MATCH. Of the five overlays whose
 * window holds 0x021840C8 only ov022 has a function start there.
 */
int func_021840C8(u8 *p)
{
    if (p == 0)
        return 0;
    switch (p[9]) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (p[10] >= p[11])
            return 1;
        return 0;
    }
    return 0;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): stores the two
 * callbacks and their argument at 0xf4/0xf8/0xfc (the fields
 * func_02183E48 reads). Blocker of ov023 func_02184674.
 */
void func_021840FC(u8 *p, Cb a, Cb b, void *arg)
{
    *(Cb *)&((struct Obj09764 *)p)->fF4 = a;
    *(Cb *)&((struct Obj09764 *)p)->fF8 = b;
    ((struct Obj09764 *)p)->fFC = arg;
}


int func_02184114(unsigned char *p)
{
    if (p[4] == 0) {
        func_0203D1E8((u32)func_020399A8(), 0);
        p[9] = 1;
        return 1;
    }
    return 0;
}

/*
 * Original r0 return from 020399A8 flows into unused parameter 0 of
 * 0203D1E8; its r1 argument is literal payload 1. No implicit arguments.
 */
void func_02184134(u8 *p)
{
    func_0203D1E8((u32)func_020399A8(), (void *)1);
    p[9] = 0;
}

void func_02184148(unsigned char *p, int a)
{
    if (func_0203CD98()) {
        func_0203D1E8((int)func_020399A8(), (void *)1);
        p[9] = 2;
        p[11] = a;
        p[10] = 0;
    }
}

/*
 * Extent followers 0x02184174, 0x0218417C and 0x02184180 are matched separately.
 */
void func_0218416C(char *p)
{
    ((struct Obj20328 *)p)->f14 = 1;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): sets the word at
 * 0x20. Blocker of ov023 func_02184674.
 */
void func_02184174(u8 *p)
{
    ((struct Obj20329 *)p)->f20 = 1;
}


/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): returns the word
 * at 0x28. Blocker of ov023 func_02184674.
 */
u32 func_0218417C(u8 *p)
{
    return ((struct Obj20330 *)p)->f28;
}

/*
 * Unlabelled leaf; callers in ov023 (func_02186170, func_02185EA0).
 */
char *func_02184180(unsigned char *p, int i)
{
    int m;

    m = 1 << i;
    if (!(p[0xe] & m) || !(p[1] & m))
        return 0;
    return (char *)p + 0x2c + i * 0x28;
}

unsigned char func_021841A0(unsigned char *p)
{
    return p[1];
}
