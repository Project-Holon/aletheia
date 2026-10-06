/*
 * function: func_02208A78
 * address: 0x02208A78
 * packet: pkt_ov195_02208A78
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct Node { u16 id,pad02; int tx,ty,tz,sx,sy,sz; u8 mtx[0x24]; u32 f40; } Node;
typedef struct Anim { u16 heap; u8 pad02[0x12]; void *res; u16 f18,f1a,count,pad1e; Node *nodes; u32 f24,f28; } Anim;
extern u32 func_02048A18(u8 *a0, int i);
struct Transform;
struct Arg;
extern void func_02047A60(void *a0, struct Arg *a1);
void func_02208A78(Anim *p) { u16 i; Node *n; for(i=0;i<p->count;i++) { n=p->nodes+i; if(n->f40) func_02047A60((void *)func_02048A18(p->res,n->id),(struct Arg *)((struct Transform *)&n->tx)); } }
