/*
 * function: func_021D6888
 * address: 0x021D6888
 * packet: pkt_ov121_021D6888
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D6922.
 * symbols:
 *   func_021DE300 0x021DE300 thumb ov121
 *   func_021DA898 0x021DA898 thumb ov121
 *   func_021D9718 0x021D9718 thumb ov121
 *   func_021D972C 0x021D972C thumb ov121
 *   func_021D9738 0x021D9738 thumb ov121
 *   func_021D9238 0x021D9238 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021DA840 0x021DA840 thumb ov121
 *   func_021DA8AC 0x021DA8AC thumb ov121
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern void func_021DE300(char *p);
extern void func_021DA898(char *p);
extern void func_021D9718(u8 *p);
extern void func_021D972C(char *p);
extern void func_021D9738(char *p);
extern void func_021D9238(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021D9E50(u8 *p);
extern int func_021DA2C8(u8 *p);
extern int func_021DA840(void **);
extern int func_021DA8AC(u32 *p);
int func_021D6888(int a, int b, int c, char *p)
{
    func_021DE300(*(void **)(p + 0x3b0));
    func_021DA898(*(void **)(p + 0x290));
    if (*(void **)(p + 0x394)) {
        func_021D9718(*(void **)(p + 0x394));
        func_021D972C(*(void **)(p + 0x394));
        func_021D9738(*(void **)(p + 0x394));
    }
    func_021D9238(p + 0x138);
    func_0201C4E4(*(void **)(p + 0x39c));
    if (*(void **)(p + 0x284)) func_021D9E50(*(void **)(p + 0x284));
    if (*(void **)(p + 0x28c)) func_021DA2C8(*(void **)(p + 0x28c));
    if (*(void **)(p + 0x288)) func_021DA2C8(*(void **)(p + 0x288));
    if (*(void **)(p + 0x270)) func_021DA840(*(void ***)(p + 0x270));
    if (func_021DA8AC(*(void **)(p + 0x290))) return 1;
    return 0;
}
