/*
 * function: SCRCMD_PROC_FLD_FinishOv170Event
 * address:  0x021B4D14
 * packet:   pkt_ov021_021B4D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BB58  0x0200BB58  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[8];
    u32 f8;
    u8  pad1[0x18];
    u32 f24;
    u16 f28;
} Sub;

typedef struct {
    u32 a;
    u16 *out;
    Sub *s;
} Work;

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void func_0200BB58(u8 *a0, u8 *a1);
extern u32 func_020307B0(void *p);

void SCRCMD_PROC_FLD_FinishOv170Event(volatile Work *w)
{
    u32 r1;
    u32 v;
    Sub *s;

    if (w->s->f24 == 4) {
        func_0200BB58(func_0200BAC8(GAME_DATA_GetSaveControl((struct Big *)w->a)), (u8 *)w->s->f8);
    }
    s = w->s;
    if (s->f24 == 4) {
        func_020307B0((void *)s->f8);
    }
    v = w->s->f28;
    if (v == 0 || v != 1)
        r1 = 0;
    else
        r1 = 1;
    *w->out = r1;
    func_020307B0(w->s);
}
