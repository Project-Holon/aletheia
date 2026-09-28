/*
 * function: func_021C19DC
 * address:  0x021C19DC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_021BB4D0  0x021BB4D0  thumb  ov099
 *   func_021BB4EC  0x021BB4EC  thumb  ov099
 *   func_021C1C70  0x021C1C70  thumb  ov099
 *   func_021BF29C  0x021BF29C  thumb  ov099
 *   func_021B98F0  0x021B98F0  thumb  ov099
 *   func_021C205C  0x021C205C  thumb  ov099
 *
 * The ordered teardown of the block: five one-argument steps on p, the re-arm
 * of the 0x274-offset sub-object, and finally func_021C205C with the selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021BB42C(void *p, int v);
extern void func_021BB4D0(void *p);
extern void func_021BB4EC(void *p);
extern void func_021C1C70(void *p);
extern void func_021BF29C(void *p);
extern void func_021B98F0(void *p);
extern void func_021C205C(void *p, int v);

void func_021C19DC(char *p, int v)
{
    func_021BB42C(p, v);
    func_021BB4D0(p);
    func_021BB4EC(p);
    func_021C1C70(p);
    func_021BF29C(p);
    func_021B98F0(p + 0x274);
    func_021C205C(p, v);
}
