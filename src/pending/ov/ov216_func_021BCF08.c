/*
 * function: func_021BCF08
 * address: 0x021BCF08
 * packet: pkt_ov216_021BCF08
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 wave P6 lane U3. DIFF 21 B of 372 (size equal). Twin shape: ov216 021BD07C (same
 *   02045334/02045374/02045730/020409B4 tail). Window struct w = p+0x15C, 0x80 bytes per window: a[4] records of
 *   16 B, then two 32 B records at +0x40 and +0x60; k = 0x130 held as a local (handle at p+k, arg at p+k+0xC,
 *   loops 2 and 3 base p+k+0x2C). opt_lifetimes off gives the frame 0x2C and push list. Record address written
 *   inline at each use (named local costs the slot order). Residue: (1) the loop 2 counter x lives at [sp,#8]
 *   (lowest slot, below the b/a/rec temps) in the original, ours puts it at [sp,#0x14] and loads it into r4
 *   in loop 2; (2) loop 2 passes zero args as adds r2,r4,#0 (r4 = j = 0 held), ours uses movs. Not tried:
 *   a cast-free form of the (i*16) + (w + j*0x80) add order (u32 casts fix it, 19 B, not filed as a stand-in).
 *   Callees: no matched callee has fewer parameters than passed (021BDA54 6, 02045CAC 3, 02043B5C 2).
 * symbols:
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021BDA54 0x021BDA54 thumb ov216
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BDD8A 0x021BDD8A data a2
 */
struct Four { unsigned short a; unsigned char b, c; };
extern const struct Four d_021BDD8A[];
typedef unsigned int   u32;
typedef unsigned char  u8;
typedef unsigned short u16;
struct Descriptor;
struct Cfg;
extern void func_02043B5C(int, u8);
extern void func_02045CAC(int, int, int);
extern void func_021BDA54(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned int);

struct Rec { void *d; int h; int u, v; };
struct Rec32 { void *d; int h; char pad[24]; };
struct Win { struct Rec a[4]; struct Rec32 b; struct Rec32 c; };

#define REC1(w, j, i) ((struct Rec *)((char *)(w) + (j) * 0x80 + (i) * 16))
#define HANDLE(p, k) (*(int *)((p) + (k)))
#define ARG(p, k) (*(int *)((p) + (k) + 0xC))
#define CALLS(r) do { void *d = (r)->d; func_02045334(d); func_02045374(d); func_020409B4(func_02045730(d)); } while (0)

#pragma opt_lifetimes off
void func_021BCF08(char *p)
{
    int k = 0x130;
    struct Win *w3;
    struct Win *w2;
    struct Win *w;
    int i, j;
    int x;

    i = 0;
    w = (struct Win *)(p + 0x15C);

    for (; i < 4; i++) {
        func_02045CAC(HANDLE(p, k), i, ARG(p, k));
        for (j = 0; j < 2; j++) {
            func_02043B5C(REC1(w, j, i)->h, d_021BDD8A[i % 2].b);
            func_021BDA54(p, (char *)REC1(w, j, i), 0, 0, ARG(p, k), d_021BDD8A[i % 2].a);
            CALLS(REC1(w, j, i));
        }
    }
    func_02045CAC(HANDLE(p, k), 7, ARG(p, k));
    w2 = (struct Win *)(p + k + 0x2C);
    j = 0;
    for (x = 0; x < 2; x++) {
        func_02043B5C(w2[x].b.h, 3);
        func_021BDA54(p, (char *)&w2[x].b, 0, 0, ARG(p, k), 0x3DC3);
        CALLS(&w2[x].b);
    }
    func_02045CAC(HANDLE(p, k), 9, ARG(p, k));
    w3 = (struct Win *)(p + k + 0x2C);
    for (; j < 2; j++) {
        func_02043B5C(w3[j].c.h, 3);
        func_021BDA54(p, (char *)&w3[j].c, 0, 0, ARG(p, k), 0x3DC3);
        CALLS(&w3[j].c);
    }
}
#pragma opt_lifetimes reset
