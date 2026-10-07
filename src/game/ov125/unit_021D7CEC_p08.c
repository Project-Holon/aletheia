/*
 * file:     unit_021D7CEC_p08.c
 * unit:     yes
 * function: func_021D8B44, func_021D8BC0
 * address:  0x021D8B44
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02088168 0x02088168 arm
 *   func_02162248 0x02162248 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8BF8 0x021D8BF8 arm ov125
 *   func_021D8BE4 0x021D8BE4 arm ov125
 *   d_021DAA8C 0x021DAA8C data a4
 *   d_021DAA88 0x021DAA88 data a4
 *   d_021DAAAC 0x021DAAAC data a4
 *   d_021D8D38 0x021D8D38 data a4
 *   func_021D8B3C 0x021D8B3C arm ov125
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

extern void func_02088168(u32 *buffer);
extern void func_02162248(void *, u32);
extern void func_02082BCC(void *, u32, u32);
extern void func_021D8BF8(int a, int b);
extern void func_021D8BE4(int a);
extern int func_021D8B3C(void);
void func_021D8B44(void);
void func_021D8BC0(u32 value);
extern u8 d_021DAA8C[], d_021DAAAC[];
extern u32 d_021DAA88;
extern const u32 d_021D8D38[];

void func_021D8B44(void)
{
    func_02088168((u32 *)d_021DAA8C);
    func_02162248(d_021DAA8C, 32);
    if (d_021DAA88) return;
    func_02082BCC(d_021DAAAC, 0, 0x830);
    *(u32 *)(d_021DAAAC + 0x800) = 0;
    func_021D8BC0((u32)d_021DAAAC);
    func_021D8BF8((int)((void *)d_021D8D38), 1);
    func_021D8BE4((int)func_021D8B3C);
}

void func_021D8BC0(u32 value)
{
    if (value != 0) d_021DAA88 = value;
    else d_021DAA88 = (u32)&d_021DAAAC;
}
