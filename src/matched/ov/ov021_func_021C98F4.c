/*
 * function: FIELD_DOOR_ANIME_StartClose
 * address:  0x021C98F4
 * packet:   pkt_ov021_021C98F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELD_DOOR_ANIME_CloseTask  0x021C9854  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } W;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int FIELD_DOOR_ANIME_CloseTask(u32 a, u32 *q, u32 *p);
u32 FIELD_DOOR_ANIME_StartClose(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, FIELD_DOOR_ANIME_CloseTask, 0x14);
    W *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    w->f10 = d;
    return t;
}
