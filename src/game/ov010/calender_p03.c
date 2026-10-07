/*
 * file:     calender_p03.c
 * unit:     yes
 * function: func_02164678, func_021646A0, func_021646C4, func_021646E8
 * address:  0x02164678
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02185140 0x02185140 thumb ov020
 *   func_02188CCC 0x02188CCC thumb ov021
 *   func_021A0F90 0x021A0F90 thumb ov021
 *   func_021A0F30 0x021A0F30 thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 */
struct Desc;
struct Obj;
typedef struct { int x,y,z; } Vec;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02185140(void *, int, const Vec *, int);
extern u32 func_02188CCC(u8 *p);
extern u32 func_021A0F90(u8 *p);
extern int func_021A0F30(u32 a, u32 b);
extern struct Desc *func_020122C0(void *,void *,void *,u32);
extern void *func_020124E8(struct Obj *p);
void func_02164678(void *unused, void *a);
int func_021646A0(void *a,void *b,void **p);
void *func_021646C4(void *a,void *b);
u16 func_021646E8(u32 n);

/*
 * extent: 2-byte zero alignment padding at 0x0216469E.
 */
void func_02164678(void *unused, void *a) { Vec v; v.x=0x200000; v.y=32; v.z=0x1E8000; func_02185140(a,279,&v,0); }

int func_021646A0(void *a,void *b,void **p){void *v=(void *)func_02188CCC(p[1]); if(func_021A0F90(v)==6)func_021A0F30((u32)v,0);else func_021A0F30((u32)v,6);return 1;}

void *func_021646C4(void *a,void *b){void *t=func_020122C0(b,0,(void *)func_021646A0,8);void **p=func_020124E8(t);p[0]=b;p[1]=a;return t;}

u16 func_021646E8(u32 n){if(n<8000 || n>8799)return 0;return n-8000;}
