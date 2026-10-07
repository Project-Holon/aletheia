/*
 * file:     union_oneself_p12.c
 * unit:     yes
 * function: func_0217F948, func_0217F958
 * address:  0x0217F948
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217FC08 0x0217FC08 thumb ov019
 *   func_0217FCA4 0x0217FCA4 thumb ov019
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_0217FC08(char *p,u32 a,u32 b);
extern void func_0217FCA4(u32 *p);
void func_0217F948(char *p,u32 a,u32 b);
void func_0217F958(char *p,u32 key);

void func_0217F948(char *p,u32 a,u32 b) { if(p) func_0217FC08(p+0x20,a,b); }

void func_0217F958(char *p,u32 key) { char *base=p+0x20; int i; for(i=0;i<10;i++) { u32 value=*(u32 *)(base+i*20); if(value==key) { func_0217FCA4((u32 *)(base+i*20)); return; } } }
