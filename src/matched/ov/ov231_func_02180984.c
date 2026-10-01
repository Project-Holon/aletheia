/*
 * function: func_02180984
 * address: 0x02180984
 * packet: pkt_ov231_02180984
 * region: ov231
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: SPI data register 040001A2 written at 021809BC and read at 021809C2.
 * symbols:
 *   func_020870D0 0x020870D0 arm
 *   func_02180904 0x02180904 thumb ov231
 *   _ull_mul 0x0209C054 arm
 *   _ll_udiv 0x0209C00C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
extern u64 func_020870D0(void);
extern void func_02180904(void);
void func_02180984(u8 *p)
{
    u64 start;
    start=func_020870D0();
    while((func_020870D0()-start)*64000/33514<50) ;
    *(volatile u16 *)0x040001A2=0;
    func_02180904();
    **(u8 **)(p+8)=*(volatile u16 *)0x040001A2;
    *(u8 **)(p+8)+=1;
}
