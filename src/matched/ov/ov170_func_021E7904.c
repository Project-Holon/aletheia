/*
 * function: func_021E7904
 * address: 0x021E7904
 * packet: pkt_ov170_021E7904
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021EBD1C 0x021EBD1C thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021DD908 0x021DD908 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_021EBD50 0x021EBD50 thumb ov170
 *   func_021E8FE8 0x021E8FE8 thumb ov170
 */
extern void func_021ED55C(char **p, int flag);
extern void func_021EF57C(int mgr);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0190(unsigned char *p);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021EBD1C(unsigned char *p, int a, int b);
extern int func_021E8F50(unsigned char *p, int v);
extern int func_021DD908(unsigned char *p, unsigned idx);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021ECB60(char *w, int i, int f);
extern void func_021EBD50(unsigned char *p);
extern int func_021E8FE8(unsigned char *p, int sel);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int func_021E7904(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EF57C(*(int *)(WORK(p) + 0x74));
        STEP(p)++;
        return func_021E8FC0(p, func_021E0190, 0x4D);
    case 1:
        if (func_021DD25C(p, p[0x16], p[0x14], 0x4C, 0) != 0) {
            func_021EBD1C(p, 4, 0x18);
            *(int *)(p + 0x28) = 0xE;
            return func_021E8F50(p, 6);
        }
        if (func_021DD908(p, p[0x16]) == 0) {
            func_021EBD1C(p, 6, 0x1B);
            *(int *)(p + 0x28) = 0xE;
            return func_021E8F50(p, 6);
        }
        func_021ECB20(p, 1, 1);
        func_021ECB60(WORK(p), p[0x16], 0);
        func_021EBD50(p);
        STEP(p) = 0;
        return func_021E8FE8(p, 5);
    }
    return 0x4D;
}
