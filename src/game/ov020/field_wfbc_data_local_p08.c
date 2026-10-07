/*
 * file:     field_wfbc_data_local_p08.c
 * unit:     yes
 * function: func_02186A58, func_02186AC8, func_02186B08
 * address:  0x02186A58
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186B2C  0x02186B2C  thumb
 *   func_02161E78  0x02161E78  thumb  ov010
 *   func_0218677C  0x0218677C  thumb
 */
typedef unsigned char u8;

extern int func_02161ECC(char *);
extern char *func_02186B2C(char *, char *);
extern void func_02161E78(void *a0);
extern void func_0218677C(u8 *p, void *src);
int func_02186A58(char *p, int id);
void func_02186AC8(char *p, int b, char *c, int d);
int func_02186B08(char *p);


int func_02186A58(char *p, int id)
{
    int i;
    char *b;
    char *a;

    i = 0;
    a = p + 8;
    for (; i < 10; i++) {
        if (func_02161ECC(a + i * 0x18) != 0 && (u8)p[i * 0x18 + 9] == id)
            return 1;
    }
    i = 0;
    b = p + 0xF8;
    for (; i < 10; i++) {
        if (func_02161ECC(b + i * 0x18) != 0 && (u8)p[i * 0x18 + 0xF9] == id)
            return 1;
    }
    return 0;
}


void func_02186AC8(char *p, int b, char *c, int d)
{
    char *q;

    if (func_02186B08(p + 8) == 1) {
        func_02186B2C(p + 0xF8, p + 0xE0);
        func_02161E78(p + 0xE0);
    }
    q = p + 8;
    q = func_02186B2C(q, c);
    if (d != 0)
        func_0218677C((u8 *)q, (void *)b);
}

int func_02186B08(char *p) { int i; for (i = 0; i < 10; i++) { if (func_02161ECC(p + i * 24) == 0) return 0; } return 1; }
