/*
 * function: func_0221372C
 * address: 0x0221372C
 * packet: pkt_ov199_0221372C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_0203133C 0x0203133C arm
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a4 ov199
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02034714(const char *, int, const char *);
extern const char d_02213D00[];
extern void func_0203133C(void *);
extern void func_020307B0(void *);
void func_0221372C(char *p)
{
    if (*(int *)(p + 4)) func_02034714(d_02213D00, 0, d_02213D00);
    func_0203133C(*(void **)p);
    func_020307B0(p);
}
