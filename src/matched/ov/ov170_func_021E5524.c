/*
 * function: func_021E5524
 * address: 0x021E5524
 * packet: pkt_ov170_021E5524
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 */
extern void func_021DD530(unsigned char *);
extern void func_021EA1E8(char *p);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
extern void func_021ED888(char *, int);
extern void func_021DEFEC(char *p, int b);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
int func_021E5524(unsigned char *p)
{
    unsigned r = *(unsigned *)(*(char **)(WORK(p) + 0x60) + 0xac);
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_021ED888(WORK(p), 1);
    func_021EE038((char *)p, 0, 0, 1);
    if (p[0x16] != 0xff) {
        func_021EBC58(p, p[0x16], 1, 0x18);
        r = 0x23;
    }
    func_020260E4(OBJ(p), r);
    func_021EE3E4((char **)p, r);
    return 0x2c;
}
