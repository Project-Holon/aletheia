/*
 * function: MUSICAL_STAGE_SYS_CreateNpcPerformer
 * address:  0x02156FD0
 * packet:   pkt_ov010_02156FD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F67E0  0x021F67E0  thumb  ov112
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct Obj {
    u32 kind;           /* 0x00 */
    u8 pad04[0x78 - 0x04];
    u16 f78;            /* 0x78 */
} Obj;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Obj *f04[4];        /* 0x04 */
} Stage;

extern char *func_021F67E0(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);

void MUSICAL_STAGE_SYS_CreateNpcPerformer(Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y)
{
    s->f04[idx] = (Obj *)func_021F67E0(id, v, 0, 0, w, y);
    s->f04[idx]->kind = 2;
    s->f04[idx]->f78 = x;
}
