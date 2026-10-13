/*
 * function: EVENTDATA_SYSTEM_CreateFieldLinkEnterEvent
 * address: 0x02164654
 * packet: pkt_ov010_02164654
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   EVENTDATA_SYSTEM_FieldLinkEnterEvent 0x021645E0 thumb ov010
 */

typedef unsigned int u32;
typedef struct { void *p; u32 n; } Work;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int EVENTDATA_SYSTEM_FieldLinkEnterEvent(void *, int *, int *);
void *EVENTDATA_SYSTEM_CreateFieldLinkEnterEvent(void *unused, void *a) { void *task; Work *w; int zero=0; task=func_020122C0(a,0,(void *)EVENTDATA_SYSTEM_FieldLinkEnterEvent,8); w=func_020124E8(task); w->p=a; w->n=zero; return task; }
