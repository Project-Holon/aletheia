/*
 * function: func_02193378
 * address:  0x02193378
 * packet:   pkt_ov009_02193378
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiValueForKeyWithIndex (libdwcgsgp.TWL.HYB.a(gpiutility.o))
 *
 * symbols:
 *   func_02094B20  0x02094B20  arm
 *   func_0209477C  0x0209477C  arm
 */

extern unsigned char *func_02094B20(const unsigned char *s1, const unsigned char *s2);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);

int func_02193378(char *command, char *key, int *index, char *value, int len)
{
    char delimiter;
    char *start;
    int i;
    char c;

    command += *index;
    delimiter = key[0];
    start = (char *)func_02094B20((const unsigned char *)command, (const unsigned char *)key);
    if (start == 0)
        return 0;
    start += func_0209477C((const u8 *)key);
    for (i = 0; i < len - 1 && (c = start[i]) != 0 && c != delimiter; i++)
        value[i] = c;
    value[i] = 0;
    *index += (start - command) + func_0209477C((const u8 *)value);
    return 1;
}
