/*
 * file:     palette_anime_p07.c
 * unit:     yes
 * function: func_021C1D28, func_021C1D64
 * address:  0x021C1D28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C1DF0  0x021C1DF0  thumb  ov217
 *   func_021C1E0C  0x021C1E0C  thumb  ov217
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 a;
    u32 b;
    u32 type;
} Rec;

typedef signed char    s8;

typedef signed short   s16;

extern void func_021C1DF0(char *p);
extern u32 func_021C1E0C();
s32 func_021C1D28(Rec *p);
u32 func_021C1D64(u32 a0);


/*
 * Small dense switch on the word at offset 8.
 *
 * Addresses are Black-image addresses.
 */
s32 func_021C1D28(Rec *p)
{
    switch (p->type) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 0;
    case 5:
        return 1;
    }
    return 0;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C1D64(u32 a0)
{
    func_021C1DF0((char *)a0);
    return func_021C1E0C(a0);
}
