/*
 * function: func_021B64AC
 * address: 0x021B64AC
 * packet: pkt_ov172_021B64AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status:   EXACT*
 * note: 2026-10-02 byte-correct; the four arm veneers 021B655C..021B6574 are filed as matched asm files (no shards yet), so the blx sites are unresolved until the integrator manifests them.
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   func_021B657C 0x021B657C thumb ov172
 *   func_021B65C4 0x021B65C4 thumb ov172
 *   func_021B655C 0x021B655C arm ov172
 *   func_021B6564 0x021B6564 arm ov172
 *   func_021B656C 0x021B656C arm ov172
 *   func_021B6574 0x021B6574 arm ov172
 */
extern int func_02085D3C(void);
extern void func_021B657C(char *, int);
extern void func_021B65C4(void *p);
extern void func_021B655C(int, int);
extern int func_021B6564(void);
extern void func_021B656C(int, int);
extern int func_021B6574(void);

void func_021B64AC(char *p)
{
    int b;
    int a;
    int d;
    int c;
    int r;
    switch (*(unsigned char *)(p + 0x44)) {
    case 1:
        func_021B657C(p, 1);
        a = *(int *)(p + 0x4C);
        b = *(int *)(p + 0x48);
        if (func_02085D3C() != 0) func_021B655C(b, a);
        *(unsigned char *)(p + 0x44) = 2;
        break;
    case 2:
        r = 0;
        if (func_02085D3C() != 0) r = func_021B6564();
        if (r == 0) {
            func_021B65C4(p);
            *(unsigned char *)(p + 0x44) = 3;
        }
        break;
    case 4:
        func_021B657C(p, 0);
        c = *(int *)(p + 0x4C);
        d = *(int *)(p + 0x48);
        if (func_02085D3C() != 0) func_021B656C(d, c);
        *(unsigned char *)(p + 0x44) = 5;
        break;
    case 5:
        r = 0;
        if (func_02085D3C() != 0) r = func_021B6574();
        if (r == 0) {
            func_021B65C4(p);
            *(unsigned char *)(p + 0x44) = 6;
        }
        break;
    case 0:
    case 3:
    case 6:
    default:
        break;
    }
}
