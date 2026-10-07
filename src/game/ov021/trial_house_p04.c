/*
 * file:     trial_house_p04.c
 * unit:     yes
 * function: func_021CF194, func_021CF1AC
 * address:  0x021CF194
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CD624  0x021CD624  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_02008494  0x02008494  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CF110  0x021CF110  thumb  ov021
 */
struct Entry;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 name[0x20];
    u8 x[8];
} B;

extern u32 func_021CD624(u32, u32, u32, u32, u32);
extern void func_02082BCC(void *dst, int v, u32 n);
extern void func_02008494(void *src, void *dst);
extern void func_02087C6C(void *p);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021CF110(u8 *p, u32 v, void *a);
int func_021CF194(u32 a, u32 b, u32 c, u32 d);
u32 func_021CF1AC(u32 a, u32 b, u32 c);
void func_021CF214(u32 a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF194(u32 a, u32 b, u32 c, u32 d)
{
return func_021CD624(d, a, c, *(u8 *)((u8 *)((c + 38))), (c + 32));
}


/*
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void func_02082D44(const void *a, void *b, unsigned n);  (arm)
 *   void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * func_021CF214 (unlabelled) is a tail-call stub into func_021CF110.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CF1AC(u32 a, u32 b, u32 c)
{
    B buf;

    func_02082BCC(&buf, 0, 0x28);
    func_02008494((void *)a, &buf);
    func_02087C6C(buf.x);
    buf.x[6] = b;
    if (c == 1)
        func_0203D3F8((u32)func_020399A8(), 0xff, 0x2700, 0x28, (u32)(&buf), 0, 0, 0);
    else
        return func_0203D3F8((u32)func_020399A8(), 0, 0x2700, 0x28, (u32)(&buf), 0, 0, 0);
}


void func_021CF214(u32 a, u32 b, u32 c, u32 d)
{
    func_021CF110((u8 *)d, 1, (void *)c);
}
