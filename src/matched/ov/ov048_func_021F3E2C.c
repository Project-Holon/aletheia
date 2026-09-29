/*
 * function: func_021F3E2C
 * address:  0x021F3E2C
 * packet:   pkt_ov048_021F3E2C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F47B8  0x021F47B8  thumb
 *   func_021F4058  0x021F4058  thumb
 *   func_021F3E6C  0x021F3E6C  thumb
 *   func_021F3EE8  0x021F3EE8  thumb
 *   func_021F43E4  0x021F43E4  thumb
 *   func_021F4290  0x021F4290  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  func_021F47B8(u32 a);
extern void func_021F4058(void *p);
extern void func_021F3E6C(void *p);
extern void func_021F3EE8(void *p);
extern void func_021F43E4(void *p);
extern void func_021F4290(void *p);

void func_021F3E2C(u8 *p)
{
    if (func_021F47B8(*(u32 *)(p + 0x14)) == 0) {
        if (*(u32 *)(p + 0x20) != 0) {
            u32 q = *(u32 *)(p + 0x1c);

            if (q != 0 && *(u32 *)(q + 0x78) != 0) {
                func_021F4058(p);
                func_021F3E6C(p);
                func_021F3EE8(p);
                func_021F43E4(p);
                func_021F4290(p);
            }
        }
    }
}
