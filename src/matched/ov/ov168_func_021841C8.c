/*
 * function: func_021841C8
 * address:  0x021841C8
 * packet:   pkt_021841C8
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   d_02184964     0x02184964  data  a1
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020403F4(u32 v);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern u8 d_02184964[];

void func_021841C8(void *a0)
{
    u32 i;

    for (i = 0; i < 5; i++)
        func_020403F4(d_02184964[i * 0x24 + 0x20]);
    BMP_WIN_Exit();
    func_0203F9B4();
}
