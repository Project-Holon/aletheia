/*
 * file:     unit_02173CB0_p03.c
 * unit:     yes
 * function: func_02173EEC, func_02173F4C, func_02173F74
 * address:  0x02173EEC
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
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021759B0 0x021759B0 thumb ov011
 *   func_0203D3A8 0x0203D3A8 arm
 */
struct Entry;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed int     s32;

typedef unsigned short u16;

int func_021736D8(void);
struct Entry *func_020399A8(void);
int func_0203D578(int a, int b);
void func_02082D44(char *d, char *s, int n);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u8 *func_02175B34(u8 *p);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
void func_021759B0(u8 *a);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
int func_02173EEC(char *a, char *b);
void func_02173F4C(int a, int b, void *c, u8 *d);
int func_02173F74(int a, u8 *b);


int func_02173EEC(char *a, char *b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x212) == 1) {
        return 0;
    }
    func_02082D44(b + 0x78, a + 0x3F0, 0x34);
    return func_0203D3F8((int)func_020399A8(), 0xFF, 0x212, 0x34, (u32)(a + 0x3F0), 0, 0, 1);
}


void func_02173F4C(int a, int b, void *c, u8 *d)
{
    void *p;
    p = func_02175B34(d + 0x1ac);
    if (p != 0 && func_0203EFC8(p, c, 0x34) == 0) func_021759B0(d + 0x1ac);
}


/*
 * note: The matched void forwarder func_021736D8 leaves r0 live and this
 *       caller tests it at 02173F7C. func_0203D3A8's final send result is
 *       returned in live r0 at 02173F94, so both externs return int here.
 */
int func_02173F74(int a, u8 *b)
{
    if (func_021736D8() == 0) return 0;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x213, 0x34, (u32)(b + 0x78));
}
