/*
 * function: func_021F50EC
 * address:  0x021F50EC
 * packet:   pkt_021F50EC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021F4EFC  0x021F4EFC  thumb
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;

extern void func_02030EAC(void *p);
extern void func_021F4EFC(u8 *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);

void func_021F50EC(u8 *p)
{
    if (*(void **)(p + 0xf90) != 0) {
        func_02030EAC(*(void **)(p + 0xf90));
        *(void **)(p + 0xf90) = 0;
    }
    *(vu16 *)0x04000050 = 0;
    *(vu16 *)0x04001050 = 0;
    func_021F4EFC(p);
    func_020450C8();
    func_0203F9B4();
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32 *)0x04001000 &= 0xFFFF1FFF;
}
