/*
 * function: func_021F3DF0
 * address:  0x021F3DF0
 * packet:   pkt_021F3DF0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F47B8  0x021F47B8  thumb
 *   func_021F4058  0x021F4058  thumb
 *   func_021F3E6C  0x021F3E6C  thumb
 *   func_021F3EE8  0x021F3EE8  thumb
 *   func_021F4314  0x021F4314  thumb
 *   func_021F4290  0x021F4290  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_021F47B8(void *p);
extern void func_021F4058(void *p);
extern void func_021F3E6C(void *p);
extern void func_021F3EE8(void *p);
extern void func_021F4314(void *p);
extern void func_021F4290(void *p);

void func_021F3DF0(u8 *p)
{
    if (func_021F47B8((void *)(*(u32 *)(p + 0x14))) == 0) {
        u32 q = *(u32 *)(p + 0x1c);

        if (q != 0 && *(u32 *)(q + 0x78) != 0) {
            func_021F4058(p);
            func_021F3E6C(p);
            func_021F3EE8(p);
            func_021F4314(p);
            func_021F4290(p);
        }
    }
}
