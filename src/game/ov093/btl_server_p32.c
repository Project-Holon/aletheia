/*
 * file:     btl_server_p32.c
 * unit:     yes
 * function: func_021BE95C, func_021BE994, func_021BE9D0, func_021BEA14
 * address:  0x021BE95C
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
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern u32 func_021CC8D8(void *,int);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021BE95C(u8 *p, u8 *a, u32 v);
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d);
void func_021BE9D0(u8 *p, u8 *a, u32 c, u32 d);
void func_021BEA14(u8 *p, u8 *a, u8 *b, u32 c);


void func_021BE95C(u8 *p, u8 *a, u32 v)
{
    func_021D74F8(4000);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, v);
    func_021D70F0(p, 3);
    func_021D7540(4004);
}

/*
 * Interface: getter's matched Lock return is one full word; original
 * 021CC8DA loads old [r0] into r1; 021CC900 copies r1 to r0 unchanged.
 * This caller
 * saves r0 at 021BE9A8 and restores all bits through r1 at 021BE9BA;
 * 021CC95C is str r1,[r0]; bx lr. Scalar spelling follows matched caller
 * 021BC568 and retains the same word ABI. Struct/union locals used a
 * 12-byte frame and separate 4019 pool; scalar uses original 4-byte frame.
 */
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d)
{
    u32 old;
    old=func_021CC8D8(p+0x1d74,4017);
    func_021BE9D0(p,a,c,d);
    func_021CC95C((u32 *)(p+0x1d74),old,4019);
}


void func_021BE9D0(u8 *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(4032);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x51, d);
    func_021D70F0(p, 4);
    func_021D7540(4037);
}


void func_021BEA14(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4051);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D70F0(p, 8);
    func_021D7540(4056);
}
