/*
 * file:     btl_server_p28.c
 * unit:     yes
 * function: func_021BDE18, func_021BDE48
 * address:  0x021BDE18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 */
struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021BDE48 { u32 lo : 7; u32 species : 16; u32 hi : 9; };

union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Unk021E8B80 func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Unk021E8B80 v);
extern int func_021D55A0(struct UtilWork *p, int id);
void func_021BDE18(u8 *p, u8 *a);
u16 func_021BDE48(void *p, struct Unk021BDE48 *m);

void func_021BDE18(u8 *p, u8 *a)
{
    func_021D74F8(3348);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x54);
    func_021D7540(3351);
}


u16 func_021BDE48(void *p, struct Unk021BDE48 *m)
{
    u16 r = 0x17;
    if (func_021D62C4(p, 0x17) && m->species != 0xA5) {
        r = func_021E8B80(func_021D6314(p, r));
        if (r != m->species && func_021D55A0(p, r)) return r;
    }
    return 0;
}
