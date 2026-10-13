/*
 * function: func_021F5CFC
 * address:  0x021F5CFC
 * packet:   pkt_021F5CFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
 * symbols:
 *   func_021F5CA4  0x021F5CA4  thumb
 *   func_021F5F9C  0x021F5F9C  thumb
 *   func_021F68A4  0x021F68A4  thumb
 *   func_021F5F60  0x021F5F60  thumb
 *   func_021F5A7C  0x021F5A7C  thumb
 *   func_021F5B8C  0x021F5B8C  thumb
 *   func_021F5E44  0x021F5E44  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    int mode;
    u8 pad24[0x28 - 0x24];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xBFC - 0xBF8];
    u32 marker;
    u8 padC00[0xD2C - 0xC00];
    u32 arrows[2];
} Work;

extern int func_021F5CA4(Work *p);
struct Obj;
extern void func_0204B92C(struct Obj *obj, u32 v);
struct Actor;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021F5F9C(int a, int b, int c);
extern void func_021F68A4(Work *p, int box);
extern void func_020061E4(u32 se);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void func_021F5F60(u32 cursor, int i);
extern void func_021F5A7C(Work *p);
extern void func_021F5B8C(Work *p);
extern void func_021F5E44(Work *p);
extern u32 func_020362DC(void);

int func_021F5CFC(Work *p)
{
    int r = func_021F5CA4(p);

    if (r != -1) {
        switch (r) {
        case 0x1F:
            func_0204B92C((struct Obj *)p->arrows[0], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[0], 0x26);
            p->box = func_021F5F9C(p->box, p->boxes, 1);
            func_021F68A4(p, p->box);
            func_020061E4(0x548);
            break;
        case 0x20:
            func_0204B92C((struct Obj *)p->arrows[1], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[1], 0x27);
            p->box = func_021F5F9C(p->box, p->boxes, -1);
            func_021F68A4(p, p->box);
            func_020061E4(0x548);
            break;
        case 0x1E:
            func_0204B3DC((struct Obj *)p->marker, 1);
            CLACT_RestartActorAnim((struct Actor *)p->marker);
            p->state = 0x11;
            p->slot = r;
            func_020061E4(0x551);
            func_021F5F60(p->cursor, p->slot);
            break;
        default:
            p->slot = r;
            func_021F5F60(p->cursor, p->slot);
            if (p->mode == 5) {
                func_021F5A7C(p);
            } else if (p->mode == 6) {
                func_021F5B8C(p);
            }
            break;
        }
    } else {
        func_021F5E44(p);
        if (p->mode == 5) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->marker, 1);
                CLACT_RestartActorAnim((struct Actor *)p->marker);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5A7C(p);
            }
        } else if (p->mode == 6) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->marker, 1);
                CLACT_RestartActorAnim((struct Actor *)p->marker);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5B8C(p);
            }
        }
    }
    return 2;
}
