/*
 * file:     btl_server_p31.c
 * unit:     yes
 * function: func_021BE8F4, func_021BE924
 * address:  0x021BE8F4
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
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021BE95C  0x021BE95C  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int,u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021BE95C(u8 *p, u8 *a, u32 v);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021BE8F4(u8 *p,u8 *a);
void func_021BE924(u8 *p, u8 *a, u32 v);

void func_021BE8F4(u8 *p,u8 *a)
{
    func_021D74F8(3968);
    func_021D75EC(3,func_021D5440(a));
    func_021D70F0(p,7);
    func_021D7540(3971);
}


void func_021BE924(u8 *p, u8 *a, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1D74, 3985);
    func_021BE95C(p, a, v);
    func_021CC95C((u32 *)(p + 0x1D74), s, 3987);
}
