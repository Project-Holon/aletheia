/*
 * file:     field_wfbc_data_local_p01.c
 * unit:     yes
 * function: func_02185F18, func_02185F48
 * address:  0x02185F18
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201284C 0x0201284C thumb
 *   func_02013FEC 0x02013FEC thumb
 *   func_02012894 0x02012894 thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012B28 0x02012B28 thumb
 *   func_02012B2C 0x02012B2C thumb
 */
struct Rec44;
struct SaveBlock;
typedef struct { int f[7]; } S7;

typedef unsigned int   u32;

extern unsigned short *func_0201284C(void *);
extern u32 func_02013FEC(u32 id);
extern S7 *func_02012894(void *);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
void func_02185F18(void *p,S7 *out);
void func_02185F48(void *p);

void func_02185F18(void *p,S7 *out) { if (func_02013FEC(func_0201284C(p)[2])) *out=*func_02012894(p); }

void func_02185F48(void *p) { void *q; q=func_020127A4(p); if (func_02012B28(q)!=3) func_02012B2C(q,0); else func_02012B2C(q,2); }
