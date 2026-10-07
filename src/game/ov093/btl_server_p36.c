/*
 * file:     btl_server_p36.c
 * unit:     yes
 * function: func_021BF244, func_021BF27C, func_021BF2B4, func_021BF2EC
 * address:  0x021BF244
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
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

struct Lock { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };

extern u32 func_021CC8D8(struct Lock *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021D74F8(int);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
void func_021BF244(u8 *p, u32 a, u32 b);
void func_021BF27C(u8 *p, u32 a, u32 b);
void func_021BF2B4(u8 *p, u32 a, u32 b);
void func_021BF2EC(u8 *p, u32 a, u32 b, int k);

/*
 * interface: The four-byte Lock getter returns its entire original word in
 * r0 (021CC8DA,021CC900); restore 021CC95C stores that word unchanged.
 * Scalar payload follows matched caller 021BCEFC and preserves every bit.
 */
void func_021BF244(u8 *p, u32 a, u32 b)
{
    int line = 0x11e7;
    u32 old = func_021CC8D8((struct Lock *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x25);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}

void func_021BF27C(u8 *p, u32 a, u32 b)
{
    int line = 0x11f6;
    u32 old = func_021CC8D8((struct Lock *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x26);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}

void func_021BF2B4(u8 *p, u32 a, u32 b)
{
    int line = 0x1205;
    u32 old = func_021CC8D8((struct Lock *)(p + 0x1d74), line);
    func_021BF2EC(p, a, b, 0x27);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}

void func_021BF2EC(u8 *p, u32 a, u32 b, int k)
{
    int line = 0x1214;
    func_021D74F8(line);
    func_021D75EC(2, a);
    func_021D75EC(0x12, b);
    func_021D70F0(p, k);
    func_021D7540(line + 4);
}
