/*
 * file:     pokemontrade_3d_p11.c
 * unit:     yes
 * function: func_021E38D8, func_021E3910
 * address:  0x021E38D8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D84C 0x0207D84C arm
 *   func_0207D810 0x0207D810 arm
 *   func_021E3744 0x021E3744 thumb ov119
 *   func_021E3730 0x021E3730 thumb ov119
 *   func_021E3700 0x021E3700 thumb ov119
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021E8144 0x021E8144 data ov119 a4
 */
#define REG(a) (*(volatile u32 *)(a))
typedef unsigned long u32;

typedef unsigned short u16;

typedef short s16;

typedef long fx32;

extern void func_0207D84C(fx32,fx32);
extern void func_0207D810(fx32,fx32);
extern void func_021E3744(int);
extern void func_021E3730(int);
extern void func_021E3700(int);
void func_021E38D8(int a, int b);
void func_021E3910(int z,int index,u16 a,int b);
extern const s16 d_020A1B38[];
extern u16 d_021E8144[];

/*
 * Program the two register bits selected by the two flags.
 */
void func_021E38D8(int a, int b)
{
    *(volatile unsigned int *)0x040004c0 = 0x6b5a5ef7 | ((a != 0) << 15);
    *(volatile unsigned int *)0x040004c4 = 0x00007fff | ((b != 0) << 15);
}

/*
 * lever: u16 third argument places its spill before hardware writes; caller supplies u16.
 * volatile: hardware command stores 021E391C..021E3A22, 04000440..04000504
 */
void func_021E3910(int z,int index,u16 a,int b)
{
    REG(0x04000444)=0;
    REG(0x04000440)=1;
    func_0207D84C(d_020A1B38[(b>>4)*2],d_020A1B38[(b>>4)*2+1]);
    REG(0x04000444)=0;
    func_0207D84C(d_020A1B38[(a>>4)*2],d_020A1B38[(a>>4)*2+1]);
    REG(0x04000470)=0;
    REG(0x04000470)=0;
    REG(0x04000470)=z;
    func_0207D84C(d_020A1B38[(d_021E8144[0]>>4)*2],d_020A1B38[(d_021E8144[0]>>4)*2+1]);
    func_0207D810(d_020A1B38[(d_021E8144[1]>>4)*2],d_020A1B38[(d_021E8144[1]>>4)*2+1]);
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x04000440)=3;
    REG(0x04000454)=0;
    REG(0x04000440)=2;
    func_021E38D8(1,1);
    REG(0x040004a8)=0x4d200000|(((u32)index*512+0x3000)>>3);
    REG(0x040004ac)=512;
    REG(0x040004a4)=0x1f0041|((u32)index<<24);
    REG(0x04000500)=1;
    func_021E3744(1); func_021E3730(0); func_021E3700(2);
    func_021E3744(0); func_021E3730(0); func_021E3700(0);
    func_021E3744(2); func_021E3730(0); func_021E3700(4);
    func_021E3744(3); func_021E3730(0); func_021E3700(6);
    REG(0x04000504)=0;
    REG(0x04000448)=1;
    REG(0x04000448)=1;
}
