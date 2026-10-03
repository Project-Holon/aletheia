/*
 * unit:     yes
 * function: func_02028D8C
 * address:  0x02028D8C
 * packet:   pkt_02028D8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c: pick the command slot the caller should look at.
 * While func_02028DB8 says the ring is idle that is the read cursor at +0xA0;
 * otherwise it is the slot just before the write cursor at +0xA1, which is
 * `(head + 9) % 10` rather than `head - 1` because the subtraction has to wrap
 * (the modulo is a real call to the runtime's signed divide helper, which
 * returns the remainder in r1 and so feeds the index computation directly).
 *
 * Both arms fall into one address computation, so the index is assigned in
 * each arm and the `&s->queue[i]` is written once after the `if`.
 *
 * symbols:
 *   func_02028DB8  0x02028DB8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028D8C.c \
 *       --addr 0x02028D8C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Sys {
    u8         pad_00[0x28];
    struct Cmd queue[10];   /* 0x28 */
    u8         tail;        /* 0xa0 */
    u8         head;        /* 0xa1 */
};

extern int func_02028DB8(void *obj);

struct Cmd *func_02028D8C(struct Sys *s)
{
    s32 i;

    if (func_02028DB8(s) == 0) {
        i = s->tail;
    } else {
        i = (s->head + 9) % 10;
    }
    return &s->queue[i];
}
