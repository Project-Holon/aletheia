/*
 * file:     btl_rec_sel_graphic_p02.c
 * unit:     yes
 * function: func_021BB29C, func_021BB2A8
 * address:  0x021BB29C
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB46C 0x021BB46C thumb ov214
 *   func_021BB3D8 0x021BB3D8 thumb ov214
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021BB46C(void *);
extern u32 func_021BB3D8(u32 *);
void func_021BB29C(char *p);
u32 func_021BB2A8(u8 *p);

void func_021BB29C(char *p) { func_021BB46C(p+8); }

u32 func_021BB2A8(u8 *p) { return func_021BB3D8((u32 *)(p+4)); }
