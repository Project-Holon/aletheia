/*
 * function: FIELD_LINK_EVENT_CreateToggleSubscreenEvent
 * address: 0x021646C4
 * packet: pkt_ov010_021646C4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   FIELD_LINK_EVENT_ToggleSubscreenEventMain 0x021646A0 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
extern struct Desc *func_020122C0(void *,void *,void *,u32);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int FIELD_LINK_EVENT_ToggleSubscreenEventMain(void *,void *,void **);
void *FIELD_LINK_EVENT_CreateToggleSubscreenEvent(void *a,void *b){void *t=func_020122C0(b,0,(void *)FIELD_LINK_EVENT_ToggleSubscreenEventMain,8);void **p=func_020124E8(t);p[0]=b;p[1]=a;return t;}
