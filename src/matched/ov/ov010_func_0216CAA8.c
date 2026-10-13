/*
 * function: NAMEIN_SETUP_StartSceneEvent
 * address: 0x0216CAA8
 * packet: pkt_ov010_0216CAA8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   NAMEIN_SETUP_RunSceneEvent 0x0216C9F4 thumb ov010
 */
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int NAMEIN_SETUP_RunSceneEvent(int, int *, int *);
void *NAMEIN_SETUP_StartSceneEvent(void *a,void *b,void *c,void *d) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)NAMEIN_SETUP_RunSceneEvent,0x10); p=func_020124E8(t);
    p[0]=a; p[2]=c; p[3]=d; p[1]=b; return t;
}
