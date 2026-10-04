/*
 * function: func_0215B158
 * address: 0x0215B158
 * packet: pkt_ov010_0215B158
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C308 0x0200C308 thumb
 */
typedef unsigned short u16;
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Blk34;
extern void *func_02012F08(int *p);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
int func_0215B158(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    if (func_0200C308(func_02012F08(func_0215A5E4((void *)b)),k) == 3) *out = 1; else *out = 0;
    return 0;
}
