/*
 * file:     unit_02173CB0_p04.c
 * unit:     yes
 * function: func_02173F9C, func_02173FC0, func_02173FF4
 * address:  0x02173F9C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203D378 0x0203D378 arm
 *   func_021759C0 0x021759C0 thumb ov011
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021759F8 0x021759F8 thumb ov011
 *   func_0203D4D0  0x0203D4D0  arm
 */
struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

u8 *func_02175B34(u8 *p);
u32 func_0203D378(void);
void func_021759C0(u8 *a, u8 b);
int func_021736D8(void);
struct Entry *func_020399A8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_021759F8(u8 *a, int b);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_02173F9C(int a, int b, void *c, u8 *d);
int func_02173FC0(int a, u8 *b);
void func_02173FE4(int a, int b, int *c, u8 *d);
int func_02173FF4(int a, int b, int c);


void func_02173F9C(int a, int b, void *c, u8 *d)
{
    func_02175B34(d + 0x1ac);
    if (func_0203D378()) func_021759C0(d + 0x1ac, a);
}


/*
 * note: Lead one run is EXACT*, followed by the root-claimed 02173FE4
 *       tail stub; tu verifies the complete 52-byte unit. func_021736D8's void forwarder
 *       leaves r0 live, tested at 02173FC8; func_0203D3A8's final send
 *       result is returned at 02173FE2. Follower loads a full word at
 *       02173FEA and forwards it without caller truncation.
 */
int func_02173FC0(int a, u8 *b)
{
    if (func_021736D8() == 0) return 0;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x214, 0x34, (u32)(b + 0x78));
}


void func_02173FE4(int a, int b, int *c, u8 *d)
{
    func_021759F8(d + 0x1ac, *c);
}


int func_02173FF4(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D4D0((int)func_020399A8(), (unsigned char)c, 0x215, 4, (u32)(&b), 0, 0, 0);
}
