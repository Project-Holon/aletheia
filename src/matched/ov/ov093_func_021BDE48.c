/*
 * function: BTL_SERVER_FLOW_GetEncoredMove
 * address:  0x021BDE48
 * packet:   pkt_ov093_021BDE48
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTL_SICKCONT_GetValue  0x021E8B80  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021BDE48 { u32 lo : 7; u32 species : 16; u32 hi : 9; };
union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern union Unk021E8B80 BTL_POKEPARAM_GetSickContRaw(void *p, int i);
extern u16 BTL_SICKCONT_GetValue(union Unk021E8B80 v);
extern int BTL_POKEPARAM_GetMovePPById(struct UtilWork *p, int id);

u16 BTL_SERVER_FLOW_GetEncoredMove(void *p, struct Unk021BDE48 *m)
{
    u16 r = 0x17;
    if (BTL_POKEPARAM_HasSick(p, 0x17) && m->species != 0xA5) {
        r = BTL_SICKCONT_GetValue(BTL_POKEPARAM_GetSickContRaw(p, r));
        if (r != m->species && BTL_POKEPARAM_GetMovePPById(p, r)) return r;
    }
    return 0;
}
