/*
 * function: func_021C4ADC
 * address: 0x021C4ADC
 * packet: pkt_ov127_021C4ADC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4AD0 0x021C4AD0 thumb ov127
 */
typedef unsigned char u8;
typedef signed short s16;
struct pair { s16 a, b; };
extern int func_021C49A4(u8 *, unsigned int);
extern struct pair func_021C4AC4(char *);
extern struct pair func_021C4AD0(char *);
struct pair func_021C4ADC(char *p)
{
    int n = func_021C49A4((u8 *)p, 8);
    int d = func_021C49A4((u8 *)p, 9);
    struct pair a = func_021C4AC4(p);
    struct pair b = func_021C4AD0(p);
    a.a -= b.a;
    a.b -= b.b;
    if (n > 0) {
        a.a = n * a.a / d;
        a.b = n * a.b / d;
    } else {
        a.a = 0;
        a.b = 0;
    }
    a.a += b.a;
    a.b += b.b;
    return a;
}
