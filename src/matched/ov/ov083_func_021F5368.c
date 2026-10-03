/*
 * function: func_021F5368
 * address: 0x021F5368
 * packet: pkt_ov083_021F5368
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021F5390 0x021F5390 thumb ov083
 *   func_021F54CC 0x021F54CC thumb ov083
 */
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_021F5390(void *w,void *p,void *q);
extern void func_021F54CC(void);
void *func_021F5368(void *p,void *q) { void *task=func_020122C0(p,0,(void *)func_021F54CC,60); func_021F5390(func_020124E8(task),p,q); return task; }
