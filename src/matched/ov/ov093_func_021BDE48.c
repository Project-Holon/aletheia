/*
 * function: func_021BDE48
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
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
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
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Unk021E8B80 func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Unk021E8B80 v);
extern int func_021D55A0(struct UtilWork *p, int id);

u16 func_021BDE48(void *p, struct Unk021BDE48 *m)
{
    u16 r = 0x17;
    if (func_021D62C4(p, 0x17) && m->species != 0xA5) {
        r = func_021E8B80(func_021D6314(p, r));
        if (r != m->species && func_021D55A0(p, r)) return r;
    }
    return 0;
}
