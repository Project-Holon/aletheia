/*
 * file:     unit_021C75E4_p06.c
 * unit:     yes
 * function: func_021C83DC, func_021C840C, func_021C8414
 * address:  0x021C83DC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 */
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_020061E4(u32 a);
void func_021C83DC(u8 *p, int value);
void func_021C840C(u8 *p);
void func_021C8414(u8 *p, int idx);


void func_021C83DC(u8 *p, int value)
{
    if (p[5] == 0) {
        func_020061E4(value > 0x210 ? 0x661 : 0x660);
        p[5] = 5;
    } else {
        p[5]--;
    }
}


void func_021C840C(u8 *p) { p[2] = 0; p[3] = 0; }


/*
 * Addresses are Black-image addresses.
 */
void func_021C8414(u8 *p, int idx)
{
    s32 *count = (s32 *)(p + 0x188);

    if (count[idx] < 0x23F) {
        count[idx]++;
    }
}
