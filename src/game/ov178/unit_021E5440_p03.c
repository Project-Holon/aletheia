/*
 * file:     unit_021E5440_p03.c
 * unit:     yes
 * function: func_021E5888, func_021E58BC, func_021E58F0
 * address:  0x021E5888
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E5A44  0x021E5A44  thumb  ov178
 *   func_021E5B1C  0x021E5B1C  thumb  ov178
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_021E58F4  0x021E58F4  thumb  ov178
 *   func_021E5A90  0x021E5A90  thumb  ov178
 */
struct S020315D4;
typedef unsigned int u32;

extern void func_021E5A44(void **pp, u32 *c);
extern void func_021E5B1C(int *p, void *c);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 v);
extern int func_021E58F4(char **out, u32 *ctx, u32 *state);
extern unsigned func_021E5A90(void **d, unsigned *c, unsigned *state);
int func_021E5888(void *a, u32 b, u32 *c, void *d);
int func_021E58BC(u32 a, u32 b, u32 *c, void *d);
void func_021E58F0(int a0, int *a1, int a2);


int func_021E5888(void *a, u32 b, u32 *c, void *d)
{
    switch (c[1]) {
    case 0:
        func_021E5A44(d, c);
        break;
    case 1:
        func_021E5B1C(d, c);
        break;
    }
    func_020315D4(a);
    func_020306F0(0x58);
    return 1;
}


int func_021E58BC(u32 a, u32 b, u32 *c, void *d)
{
    u32 r;

    switch (c[1]) {
    case 0:
        r = func_021E58F4(d, c, (u32 *)b);
        break;
    case 1:
        r = func_021E5A90(d, c, (unsigned int *)b);
        break;
    }
    return r != 0;
}

/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void func_021E58F0(int a0, int *a1, int a2) {}
