/*
 * file:     p_sta_oam_p16.c
 * unit:     yes
 * function: func_021D7A1C, func_021D7A44
 * address:  0x021D7A1C
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_02015D94 0x02015D94 thumb
 *   func_021D6064 0x021D6064 thumb ov131
 */
typedef struct {int x,y,z;} Vec;

typedef unsigned int   u32;

extern void func_0207C9D0(Vec *,Vec *,Vec *);
extern void func_02015D94(char *p, int *src);
extern void *func_021D6064(unsigned char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
void func_021D7A1C(void *p,void **q,Vec *v);
void func_021D7A44(void *p,int unused,int *a,int *b);

void func_021D7A1C(void *p,void **q,Vec *v) {
 Vec r;
 func_0207C9D0(v,(Vec *)((char *)q+0x4c),&r);
 func_02015D94(q[0],(int *)(&r));
 func_02015D94(q[1],(int *)(&r));
}

void func_021D7A44(void *p,int unused,int *a,int *b) {
 int n=func_02017E88(func_021D6064(p),5,0);
 if(n==5) {b[1]=0x299a;a[1]=0xf4cd;return;}
 if(n==37) {a[1]=0xfb33;return;}
 if(n==86) {a[0]=0x10666;a[1]=0x10666;return;}
 if(n==155) {a[0]=0xfe66;a[1]=0xfb33;return;}
 if(n==179) {a[0]=0x10333;a[1]=0x10333;return;}
 if(n==225) {a[0]=0xfccd;a[1]=0xfccd;return;}
 if(n==248) {a[0]=0xfccd;a[1]=0xfccd;return;}
 if(n==310) {a[0]=0xf800;a[1]=0xf800;return;}
 if(n==311) {a[0]=0xfb33;a[1]=0xfb33;return;}
 if(n==391) {a[0]=0xfb33;a[1]=0xf99a;}
}
