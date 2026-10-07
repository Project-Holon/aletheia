/*
 * file:     unit_021B95A0_p11.c
 * unit:     yes
 * function: func_021BAEC4, func_021BAF0C
 * address:  0x021BAEC4
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *   func_02040588  0x02040588  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021BA28C  0x021BA28C  thumb  ov068
 *   func_021BA278 0x021BA278 thumb ov068
 */
struct MsgBank;
struct Rec;
typedef unsigned int u32;

typedef signed short s16;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021BA28C(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_021BA278(u8 *p, u32 a, u32 b, u32 c);
void func_021BAEC4(void *a, u32 b, u32 c);
void func_021BAF0C(void *p, u32 id, u32 value);


void func_021BAEC4(void *a, u32 b, u32 c)
{
    void *h;

    func_0207D658((u32)((void *)0x04000050), 0x17, 8);
    func_02040588(3, 1);
    h = func_02045B38(0, 3, 0x9e, 0x801C);
    func_021BA28C(a, (u32)h, b, c, 1);
    func_02045C04(h);
}

/*
 * Interface: full-width r1 is forwarded through 021BA278 to 021BA28C;
 * the legacy u16 extern has no caller truncation witness here.
 */
void func_021BAF0C(void *p, u32 id, u32 value)
{
    func_0207D658(0x04000050, 23, 8);
    func_02040588(3, 1);
    func_021BA278(p, id, value, 1);
}
