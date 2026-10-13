/*
 * function: func_021FA394
 * address:  0x021FA394
 * packet:   pkt_021FA394
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   func_021FA2B0  0x021FA2B0  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_021F9A1C  0x021F9A1C  thumb
 *   func_021FA330  0x021FA330  thumb
 *   tbl_02203216   0x02203216  data  a1
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

typedef struct {
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int cur;
} Menu;

extern const CurPos tbl_02203216[];

extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern unsigned int KEY_GetRepeat(void);
extern void func_021FA2B0(Menu *m, int dir);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021F9A1C(void *p, int mode);
extern int func_021FA330(Menu *m, int key);

int func_021FA394(Menu *m)
{
    int old;
    int r;

    old = m->cur;
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)m->cursor, 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (m->cur != 0) {
            m->cur = m->cur - 1;
        } else {
            m->cur = 4;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (m->cur != 4) {
            m->cur = m->cur + 1;
        } else {
            m->cur = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        func_021FA2B0(m, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        func_021FA2B0(m, 1);
    }
    if (old != m->cur) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(m->cursor, tbl_02203216[m->cur].x, tbl_02203216[m->cur].y);
        if (m->cur == 4) {
            CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 6);
        }
    }
    r = func_021F9A1C(m, 2);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203216[r].x, tbl_02203216[r].y);
            if (r == 4) {
                CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 5);
            } else {
                m->cur = r;
                CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 6);
            }
        }
        r = func_021FA330(m, r);
        if (r == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return func_021FA330(m, m->cur);
    }
    if (KEY_GetTrg() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}
