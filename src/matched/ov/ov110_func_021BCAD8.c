/*
 * function: func_021BCAD8
 * address: 0x021BCAD8
 * packet: pkt_ov110_021BCAD8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00295.h"
typedef unsigned char u8;
typedef struct { void *s; unsigned short x; unsigned short pad; int flag; } Record;
typedef struct { u8 pad[0x40]; Record records[3]; void *windows[3]; void *items[8]; void *other[2]; } Object;
typedef unsigned int   u32;
struct Obj;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020409B4(u32 index);
void func_021BCAD8(Object *p) {
    int i;
    for(i=0;i<3;i++) {
        if(p->records[i].s) { STRBUF_Delete(p->records[i].s); p->records[i].s=0; }
        if(p->windows[i]) { APP_TASKMENU_WIN_Delete(p->windows[i]); p->windows[i]=0; }
    }
    for(i=0;i<8;i++) func_0204B3DC(p->items[i],0);
    for(i=0;i<2;i++) func_0204B3DC(p->other[i],0);
    func_020409B4(0);
    func_0204B3DC(((struct Obj00295 *)p)->f28,0);
}
