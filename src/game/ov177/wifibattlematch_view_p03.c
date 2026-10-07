/*
 * file:     wifibattlematch_view_p03.c
 * unit:     yes
 * function: func_021E5600, func_021E5604, func_021E560C
 * address:  0x021E5600
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020419E4  0x020419E4  arm
 *   d_021E8B10      0x021E8B10  data
 *   func_02082BCC   0x02082BCC  arm
 *   func_0204A48C   0x0204A48C  arm
 *   func_0204B100   0x0204B100  arm
 *   func_0204B270   0x0204B270  arm
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 */
struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_020419E4(void);
extern void func_02082BCC(int, int, int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
void func_021E5600(void *p);
void func_021E5604(int *a0);
void func_021E560C(int *p, int b, int c);
extern unsigned char d_021E8B10[];


void func_021E5600(void *p)
{
}


void func_021E5604(int *a0)
{
    func_020419E4();
}


/*
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */
void func_021E560C(int *p, int b, int c)
{
    func_02082BCC((int)p, 0, 4);
    func_0204A48C((const struct Cfg *)d_021E8B10, b, c);
    p[0] = (int)func_0204B100(0x80, 0, c);
    func_0204B270((void *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
