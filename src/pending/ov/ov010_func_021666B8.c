/*
 * function: func_021666B8
 * address: 0x021666B8
 * packet: pkt_ov010_021666B8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: overlay ID 0xCB reaches func_02012444 r1, absent from
 * OVERLAY_ID_CONSUMERS. The ov203-qualified descriptor at 0x021BFB3C
 * resolves sole-ref; its first word names ov203 func_021BDA40.
 * Store the flag in each branch to retain the original materialisation.
 * func_02166714 has an s16 parameter in its own source, but this caller
 * loads the complete f10 word without narrowing; its extern stays int.
 * symbols:
 *   func_020124E8 0x020124E8 thumb
 *   func_02012444 0x02012444 thumb
 *   func_02166714 0x02166714 thumb ov010
 *   ov203_id 0x000000CB data a1
 *   d_021BFB3C 0x021BFB3C data ov203 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Work {
    u8 pad00[0x10];
    u32 f10;
    u32 f14;
    u32 f18;
    u16 *f1c;
};
extern struct Work *func_020124E8(void *);
extern void func_02012444(void *, void *, void *, void *);
extern void func_02166714(u32, int);
extern u8 ov203_id[];
extern u8 d_021BFB3C[];
int func_021666B8(void *task, u32 *state)
{
    struct Work *w = func_020124E8(task);
    switch (*state) {
    case 0:
        func_02012444(task, ov203_id, d_021BFB3C, w);
        *state = *state + 1;
        break;
    case 1:
        if (w->f14 == 2) *w->f1c = 1;
        else *w->f1c = 0;
        func_02166714(w->f18, w->f10);
        return 1;
    }
    return 0;
}
