/*
 * function: func_021F4DBC
 * address: 0x021F4DBC
 * packet: pkt_ov048_021F4DBC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021F4C20 0x021F4C20 thumb ov048
 */
typedef unsigned int   u32;
struct Desc;
struct Obj;
struct W;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021F4C20(int a0, int *state, struct W *w);
void *func_021F4DBC(int a,int b,unsigned short c) { void *d; unsigned char *p; d=func_020122C0((void *)a,0,(void *)func_021F4C20,0x20); p=func_020124E8(d); *(int *)p=a; *(int *)(p+4)=b; *(unsigned short *)(p+8)=c; return d; }
