/*
 * function: func_021F46F4
 * address: 0x021F46F4
 * packet: pkt_ov194_021F46F4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021F47B2, then a function prologue.
 * symbols:
 *   sub_020310C4 0x020310C4 arm
 *   sub_0201CE30 0x0201CE30 thumb
 *   sub_0203630C 0x0203630C arm
 *   sub_02035C38 0x02035C38 arm
 *   sub_0201CE5C 0x0201CE5C thumb
 *   sub_020355D8 0x020355D8 arm
 *   sub_020362DC 0x020362DC arm
 *   sub_02035C60 0x02035C60 arm
 *   sub_0201CE38 0x0201CE38 thumb
 *   func_021F462C 0x021F462C thumb ov194
 */
struct Tcbl;
struct Rec;
extern void sub_020310C4(struct Tcbl *);
extern unsigned sub_0201CE30(void *);
extern unsigned int sub_0203630C(void);
extern int sub_02035C38(void);
extern void sub_0201CE5C(struct Rec *, int);
extern void sub_020355D8(unsigned char);
extern void *sub_020362DC(void);
extern int sub_02035C60(void);
extern void sub_0201CE38(void *);
extern void func_021F462C(unsigned char *, unsigned);
void func_021F46F4(unsigned char *a, int *state, char *p)
{
    char *q = p + 0x254;
    switch (*state) {
    case 0:
        sub_020310C4(*(struct Tcbl **)(q + 4));
        switch (sub_0201CE30(*(void **)q)) {
        case 0:
            if (((unsigned)sub_0203630C() & 3) != 0 || sub_02035C38() != 0) {
                sub_0201CE5C(*(struct Rec **)q, 0);
                if (((unsigned)sub_0203630C() & 3) != 0) sub_020355D8(0);
                else sub_020355D8(1);
            }
            break;
        case 2:
            *state = 1;
            break;
        case 1:
            if (((unsigned)sub_020362DC() & 3) != 0 || sub_02035C60() != 0) {
                sub_0201CE38(*(void **)q);
                if (((unsigned)sub_020362DC() & 3) != 0) sub_020355D8(0);
                else sub_020355D8(1);
            }
            break;
        }
        break;
    case 1:
        if (*(unsigned short *)(q + 0xE) >= *(unsigned short *)(q + 0xC)) *state = 2;
        else (*(unsigned short *)(q + 0xE))++;
        break;
    case 2:
        func_021F462C(a, *(unsigned *)(q + 8));
        break;
    }
}
