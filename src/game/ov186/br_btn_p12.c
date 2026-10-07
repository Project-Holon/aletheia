/*
 * file:     br_btn_p12.c
 * unit:     yes
 * function: func_021FB760, func_021FB788, func_021FB7B0
 * address:  0x021FB760
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D38 0x02200D38 data a1
 *   d_022007F0 0x022007F0 data a4
 */
typedef struct {unsigned short count,unused;void *records;int unknown;} Descriptor;

typedef unsigned int   u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
unsigned short func_021FB760(void *p,int i);
unsigned func_021FB788(void *p);
int func_021FB7B0(void *p,int i);
extern const Descriptor d_022007F0[];
extern char d_02200D38[];

unsigned short func_021FB760(void *p,int i) { if(i>=12)func_02034714(d_02200D38,0,d_02200D38);return d_022007F0[i].count; }

unsigned func_021FB788(void *p) { unsigned best=0;int i;for(i=0;i<12;i++){if(best<func_021FB760(p,i)) best=func_021FB760(p,i);}return best; }

int func_021FB7B0(void *p,int i) { if(i>=12)func_02034714(d_02200D38,0,d_02200D38);return *(unsigned short *)((unsigned)p+i*2); }
