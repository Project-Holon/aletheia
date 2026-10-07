/*
 * file:     btlv_core_p06.c
 * unit:     yes
 * function: func_021E8DF8, func_021E8E28
 * address:  0x021E8DF8
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
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   func_021E8F08  0x021E8F08  thumb  ov093
 *   func_02034A5C  0x02034A5C  arm
 *   func_0203D29C  0x0203D29C  arm
 *   func_021E8E38   0x021E8E38  thumb ov093
 */
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021E8F08(void);
extern void func_02034A5C(int id);
extern u32 func_0203D29C(void);
extern void func_021E8E38(void *p);
void func_021E8DF8(void);
void func_021E8E28(void *p);
extern char ov094_id[], ov095_id[], ov096_id[];


void func_021E8DF8(void)
{
    func_021E8F08();
    func_02034A5C((int)ov094_id);
    func_02034A5C((int)ov095_id);
    if (func_0203D29C() == 0) {
        func_02034A5C((int)ov096_id);
    }
}


/*
 * wrapper over func_021E8F08, func_021E8E38
 */
void func_021E8E28(void *p)
{
    func_021E8F08();
    func_021E8E38(p);
}
