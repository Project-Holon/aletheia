/*
 * function: func_02011F28
 * address:  0x02011F28
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02031324  0x02031324  arm
 *   func_020124F4  0x020124F4  thumb
 *   func_020261E4  0x020261E4  thumb
 *   func_0202B4BC  0x0202B4BC  thumb
 *   func_02012248  0x02012248  thumb
 *   func_020122A4  0x020122A4  thumb
 *   func_020139B0  0x020139B0  thumb
 *
 * Initialise an ica_anime record (struct IcaAnime, docs/families/ica_anime.h)
 * for resource id `id`: open the handle (+0x08), clear the clock words,
 * load the table (+0x1c) and build its companion (+0x24) and the +0x2c
 * object from it, clear +0x32 and bit 0 of +0x33, then reset and start.
 *
 * The note's 8-byte r0/r1 "tie" (docs/notes/pkt_02011F28.c.txt) was a
 * misread arity: func_020261E4 takes TWO arguments (its own matched file
 * reads r1), and the second is the table just stored at +0x1c, passed as
 * `p->f1c` -- which the compiler forwards from the register, hence the
 * `adds r1, r0, #0` the image has before the id reload.  Written as a
 * struct, not raw pointer casts.  EXACT* only because the 2-byte pad at
 * 0x02011F8E runs the extent to 0x02011F90.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct IcaAnime {
    u16   f00;
    u8    pad02[2];
    u32   f04;
    void *f08;
    u32   f0c;
    s32   f10;
    s32   f14;
    s32   f18;
    void *f1c;
    u32   f20;
    void *f24;
    u32   f28;
    void *f2c;
    u8    f30;
    u8    f31;
    u8    f32;
    u8    f33_0 : 1;
    u8    f33_1 : 7;
};

extern void *func_02031324(u16 id);
extern void *func_020124F4(u16 id);
extern void *func_020261E4(u16 id, void *res);
extern void *func_0202B4BC(void *a, u16 id);
extern void  func_02012248(struct IcaAnime *p);
extern void  func_020122A4(struct IcaAnime *p);
extern void func_020139B0(u32 heap);

void func_02011F28(struct IcaAnime *p, u16 id, u32 a2)
{
    p->f00 = id;
    p->f04 = a2;
    p->f08 = func_02031324(p->f00);
    p->f0c = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1c = func_020124F4(p->f00);
    p->f20 = 0;
    p->f24 = func_020261E4(p->f00, p->f1c);
    p->f28 = 0;
    p->f2c = func_0202B4BC(p->f1c, id);
    p->f32 = 0;
    p->f33_0 = 0;
    func_02012248(p);
    func_020122A4(p);
    func_020139B0(id);
}
