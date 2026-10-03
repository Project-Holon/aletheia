/*
 * function: func_021DC428
 * address: 0x021DC428
 * packet: pkt_ov119_021DC428
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */
extern void func_021E36D8(void *, int);
typedef unsigned char  u8;
extern void func_02014BA8(u8 *a0);
extern void func_02048AC4(void *);
extern void func_02046788(void);
void func_021DC428(char *p)
{
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    func_02014BA8(*(void **)(p + 0x840));
    *(void **)(p + 0x840) = 0;
    func_02048AC4(*(void **)(p + 0x810));
    func_02046788();
}
