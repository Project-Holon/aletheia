/*
 * function: func_0215CEB0
 * address:  0x0215CEB0
 * packet:   pkt_0215CEB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Runs one helper with a flag derived from bit 0 of the object's byte 0xd
 * (defaulting to 1 for a null object); on a zero result runs a teardown and
 * returns -0x29, otherwise 0.
 *
 * symbols:
 *   func_02085DBC  0x02085DBC  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_02085DBC(int a0, char *a1, int r2);
void func_0215CE7C(char *a1);

int func_0215CEB0(int a0, char *a1)
{
    int r2;
    int r4;

    if (a1 == 0 || (a1[0xd] & 1))
        r2 = 1;
    else
        r2 = 0;
    r4 = func_02085DBC(a0, a1, r2);
    if (r4 == 0)
        func_0215CE7C(a1);
    return r4 ? 0 : -0x2A;
}
