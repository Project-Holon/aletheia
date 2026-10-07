/*
 * file:     unit_021DF9D8.c
 * unit:     yes
 * function: func_021DF9D8, func_021DFA3C, func_021DFA6C
 * address:  0x021DF9D8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF7FC  0x021DF7FC  arm  ov175
 *   func_021DF884  0x021DF884  arm  ov175
 *   func_021DF8D4  0x021DF8D4  arm
 *   func_0217EAE0  0x0217EAE0  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int     s32_021DF9D8;

typedef int s32_021DFA3C;

extern int func_021DF7FC(void **);
extern s32_021DF9D8 func_021DF884(char *p);
extern void func_021DF8D4(char *p);
extern void func_0217EAE0(void *);
extern void func_021E0764(void *p);
int func_021DF9D8(u32 *p, u32 *out);
s32_021DFA3C func_021DFA3C(void *p);
int func_021DFA6C(int *p);


/*
 * SDK provenance: scInitialize (TwlDWC/libdwcgssc.TWL.HYB.a, scimain.o),
 * ov175.  Create and initialise the SCI interface, then bind the owning
 * object into it and publish the handle.
 */
int func_021DF9D8(u32 *p, u32 *out)
{
    int r;
    u8 *h = 0;

    if (out == 0)
        return 2;
    *out = 0;
    if ((r = func_021DF7FC((void **)&h)) != 0)
        return r;
    if ((r = func_021DF884((char *)h)) != 0)
        return r;
    *(u32 *)(h + 0x4c) = (u32)p;
    *out = (u32)h;
    return 0;
}


s32_021DFA3C func_021DFA3C(void *p)
{
    if (p == 0)
        return 2;
    if (*(u32 *)((char *)p + 0x50) != 0) {
        func_021DF8D4(p);
        func_0217EAE0(p);
    }
    return 0;
}


/*
 * note:     the listing extent (60 B) covers the two untraced ARM accessors
 *           that follow this 44-byte body; every compiled byte matches.
 *
 * Null-checked release: no object reports 2, an object with no +0x50 listener
 * reports 3, otherwise the listener path runs and the call reports 0.
 */
int func_021DFA6C(int *p)
{
    if (p == 0)
        return 2;
    if (p[0x14] == 0)
        return 3;
    func_021E0764(p);
    return 0;
}
