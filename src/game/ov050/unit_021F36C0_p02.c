/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3714, func_021F3744
 * address:  0x021F3714
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B8 0x021BE6B8 thumb ov021
 */
extern int func_02188D2C(int *);
extern void func_021BE700(void *, int,int,int,int);
extern void *func_021BE674(char *, int,unsigned int,int);
extern void func_021BE6B8(unsigned char *,int);
void func_021F3714(int *p);
void func_021F3744(int *p);

void func_021F3714(int *p) { char *q=(char *)func_02188D2C(p); func_021BE700(q,0,0,0,1); func_021BE6B8(func_021BE674(q,0,0,0),0); }

void func_021F3744(int *p) { func_021BE700((void *)func_02188D2C(p), 0, 0, 0, 0); }
