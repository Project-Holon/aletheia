/*
 * file:     the_end_graphic_p04.c
 * unit:     yes
 * function: func_021B9B10, func_021B9B18, func_021B9B20
 * address:  0x021B9B10
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021B9840 0x021B9840 thumb ov182
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021B9BE4 0x021B9BE4 data a4
 *   d_021B9BD8 0x021B9BD8 data a4
 *   d_021B9BF0 0x021B9BF0 data a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(int,int,int,int,u16,u16,void *);
extern int func_02048A24(int,int,int,int,int,int,int,int,const void *,const void *,const void *,u16);
extern void func_021B9840(void);
void func_021B9B10(void *a0);
void func_021B9B18(void *a0);
void func_021B9B20(int *p,u16 heap);
extern const short d_020A1EB8[];
extern const int d_021B9BE4[],d_021B9BD8[],d_021B9BF0[];

void func_021B9B10(void *a0) { func_0204A600(); }

void func_021B9B18(void *a0) { func_0204A648(); }

void func_021B9B20(int *p,u16 heap)
{
    func_02046440(0,1,0,1,0,heap,func_021B9840);
    *p=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,d_021B9BE4,d_021B9BD8,d_021B9BF0,heap);
}
