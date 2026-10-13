/*
 * function: GPOWER_EVENT_CreateListEvent
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
 *   GPOWER_EVENT_InitListWork 0x021F5390 thumb ov083
 *   GPOWER_EVENT_ListMain 0x021F54CC thumb ov083
 */
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void GPOWER_EVENT_InitListWork(void *w,void *p,void *q);
typedef unsigned char  u8;
extern int GPOWER_EVENT_ListMain(void *task, u32 *st, u8 *p);
void *GPOWER_EVENT_CreateListEvent(void *p,void *q) { void *task=func_020122C0(p,0,(void *)GPOWER_EVENT_ListMain,60); GPOWER_EVENT_InitListWork(func_020124E8(task),p,q); return task; }
