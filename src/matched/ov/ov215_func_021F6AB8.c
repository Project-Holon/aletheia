/*
 * function: func_021F6AB8
 * address: 0x021F6AB8
 * packet: pkt_ov215_021F6AB8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 */
typedef unsigned int   u32;
extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *, unsigned int);
extern void func_02015BF0(void *);
void func_021F6AB8(char *p)
{
    *(void **)(p + 0x30) = func_02014B08(1, (void *)(*(unsigned short *)p));
    func_02016020(*(void **)(p + 0x30), 3 << 16);
    func_02015BF0(*(void **)(p + 0x30));
    *(unsigned int *)(p + 0x3c) = 0;
    *(unsigned char *)(p + 0x40) = 0;
}
